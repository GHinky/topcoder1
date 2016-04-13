// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You enjoy working with numbers that contain only square digits (namely, 0, 1, 4 and 9).  The sequence containing only these digits is 0, 1, 4, 9, 10, 11, 14...   Return the n-th term (indexed from 0) in this sequence.

DEFINITION
Class:SquareDigitNumbers
Method:getNumber
Parameters:int
Returns:int
Method signature:int getNumber(int n)


CONSTRAINTS
-n will be between 0 and 1000, inclusive.


EXAMPLES

0)
0

Returns: 0

The first square digit number is 0.

1)
5

Returns: 11



2)
16

Returns: 100



3)
121

Returns: 1941



4)
123

Returns: 1949



*/
// END CUT HERE
#line 58 "SquareDigitNumbers.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class SquareDigitNumbers {
public:
  string rprs (int i) {
    string ret;
    stringstream ss;
    ss << i;
    ss >> ret;
    return ret;
  }
  int prs (string s) {
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
  }

  int getNumber(int n) {
    int ret = 0;
    string base4 = "";
    while (n != 0) {
      int temp = n % 4;
      base4 = rprs (temp) + base4;
      n = n / 4;
    }
    replace (base4.begin(), base4.end(), '0', '0');
    replace (base4.begin(), base4.end(), '1', '1');
    replace (base4.begin(), base4.end(), '2', '4');
    replace (base4.begin(), base4.end(), '3', '9');
    if (!base4.empty())
      ret = prs (base4);
    return ret;
  }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing SquareDigitNumbers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456592844;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SquareDigitNumbers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 0;
				_expected = 0;
				_received = _obj.getNumber(n); break;
			}
			case 1:
			{
				int n = 5;
				_expected = 11;
				_received = _obj.getNumber(n); break;
			}
			case 2:
			{
				int n = 16;
				_expected = 100;
				_received = _obj.getNumber(n); break;
			}
			case 3:
			{
				int n = 121;
				_expected = 1941;
				_received = _obj.getNumber(n); break;
			}
			case 4:
			{
				int n = 123;
				_expected = 1949;
				_received = _obj.getNumber(n); break;
			}
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.getNumber(n); break;
			}*/
			/*case 6:
			{
				int n = ;
				_expected = ;
				_received = _obj.getNumber(n); break;
			}*/
			/*case 7:
			{
				int n = ;
				_expected = ;
				_received = _obj.getNumber(n); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
