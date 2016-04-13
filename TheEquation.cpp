// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You are given three positive integers, X, Y and P. Return the least sum of two positive integers a and b such that P is a divisor of a*X+b*Y.

DEFINITION
Class:TheEquation
Method:leastSum
Parameters:int, int, int
Returns:int
Method signature:int leastSum(int X, int Y, int P)


NOTES
-The answer is never greater than 2*P: if a = P and b = P, then P is definitely a divisor of a*X+b*Y.


CONSTRAINTS
-X, Y and P will each be between 1 and 1000, inclusive.


EXAMPLES

0)
2
6
5

Returns: 3

When a=2 and b=1, a*X+b*Y is 10, which is a multiple of P=5. No other valid pair of values for a and b has a smaller sum.

1)
5
5
5

Returns: 2

Don't forget that a and b must be positive.

2)
998
999
1000

Returns: 501



3)
1
1
1000

Returns: 1000



4)
347
873
1000

Returns: 34



*/
// END CUT HERE
#line 72 "TheEquation.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class TheEquation {
public:
  int leastSum(int X, int Y, int P) {
    int ret = (2*P + 1) * 2;
    for (int i = 1; i != 2*P + 1; ++i) {
      for (int j = 1; j != 2*P + 1; ++j) {
	int temp = i*X + j*Y;
	if (temp % P == 0) {
	  ret = min (ret, (i + j));
	}
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
		cout << "Testing TheEquation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456477364;
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
		TheEquation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X = 2;
				int Y = 6;
				int P = 5;
				_expected = 3;
				_received = _obj.leastSum(X, Y, P); break;
			}
			case 1:
			{
				int X = 5;
				int Y = 5;
				int P = 5;
				_expected = 2;
				_received = _obj.leastSum(X, Y, P); break;
			}
			case 2:
			{
				int X = 998;
				int Y = 999;
				int P = 1000;
				_expected = 501;
				_received = _obj.leastSum(X, Y, P); break;
			}
			case 3:
			{
				int X = 1;
				int Y = 1;
				int P = 1000;
				_expected = 1000;
				_received = _obj.leastSum(X, Y, P); break;
			}
			case 4:
			{
				int X = 347;
				int Y = 873;
				int P = 1000;
				_expected = 34;
				_received = _obj.leastSum(X, Y, P); break;
			}
			/*case 5:
			{
				int X = ;
				int Y = ;
				int P = ;
				_expected = ;
				_received = _obj.leastSum(X, Y, P); break;
			}*/
			/*case 6:
			{
				int X = ;
				int Y = ;
				int P = ;
				_expected = ;
				_received = _obj.leastSum(X, Y, P); break;
			}*/
			/*case 7:
			{
				int X = ;
				int Y = ;
				int P = ;
				_expected = ;
				_received = _obj.leastSum(X, Y, P); break;
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
