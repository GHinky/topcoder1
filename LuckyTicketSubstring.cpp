// BEGIN CUT HERE
/*
PROBLEM STATEMENT

A lucky ticket is an integer with exactly 2*n digits (written without leading zeroes), where the sum of the leftmost n digits is equal to the sum of the rightmost n digits.



You are given a string s, which contains only non-zero digits. Find the longest contiguous substring of s that is a lucky ticket and return its length. If there is no such lucky ticket, return 0 instead.



DEFINITION
Class:LuckyTicketSubstring
Method:maxLength
Parameters:string
Returns:int
Method signature:int maxLength(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-s will contain non-zero digits ('1'-'9') only.


EXAMPLES

0)
"123231"

Returns: 6

The entire string, 123231, is a lucky ticket because the first 3 digits sum up to 1+2+3=6, and the last 3 digits sum up to 2+3+1=6.

1)
"74233285"

Returns: 4

4233 is the longest lucky ticket here.

2)
"986561517416921217551395112859219257312"

Returns: 36



3)
"1"

Returns: 0



4)
"112"

Returns: 2

A lucky ticket must contain an even number of digits.

*/
// END CUT HERE
#line 66 "LuckyTicketSubstring.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class LuckyTicketSubstring {
public:
  int prs (char c) {
    int ret;
    stringstream ss;
    ss << c;
    ss >> ret;
    return ret;
  }
  bool lucky (string s) {
    bool ret = false;
    int sum1 = 0, sum2 = 0;
    if (s.size() % 2 == 0) {
      for (int i = 0; i != s.size()/2; ++i) {
	sum1 += prs (s[i]);
      }
      for (int j = s.size()/2; j != s.size(); ++j) {
	sum2 += prs (s[j]);
      }
    }
    if ((sum1 == sum2) && ((sum1 + sum2) != 0))
      ret = true;
    return ret;
  }
  int maxLength(string s) {
    int ret = 0;
    for (int i = 0; i != s.size(); ++i) {
      for (int j = i + 1; j != s.size() + 1; ++j) {
	string sij = s.substr (i, j - i);
	//	cout << sij << endl;
	if (lucky (sij))
	  ret = max (ret, j - i);
      }
    }
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
		cout << "Testing LuckyTicketSubstring (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456510785;
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
		LuckyTicketSubstring _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "123231";
				_expected = 6;
				_received = _obj.maxLength(s); break;
			}
			case 1:
			{
				string s = "74233285";
				_expected = 4;
				_received = _obj.maxLength(s); break;
			}
			case 2:
			{
				string s = "986561517416921217551395112859219257312";
				_expected = 36;
				_received = _obj.maxLength(s); break;
			}
			case 3:
			{
				string s = "1";
				_expected = 0;
				_received = _obj.maxLength(s); break;
			}
			case 4:
			{
				string s = "112";
				_expected = 2;
				_received = _obj.maxLength(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.maxLength(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.maxLength(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.maxLength(s); break;
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
