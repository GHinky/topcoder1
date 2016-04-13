// BEGIN CUT HERE
/*
PROBLEM STATEMENT

You are currently at a point (x,y) inside a rectangle.  The rectangle's bottom left corner is at (0,0) and its top right corner is at (w,h). Return the shortest distance you must travel in order to reach the rectangle's boundary.



DEFINITION
Class:EscapeFromRectangle
Method:shortest
Parameters:int, int, int, int
Returns:int
Method signature:int shortest(int x, int y, int w, int h)


CONSTRAINTS
-w and h will be between 2 and 1000, inclusive.
-x will be between 1 and w - 1, inclusive.
-y will be between 1 and h - 1, inclusive.


EXAMPLES

0)
1
1
5
5

Returns: 1

We can go either straight down or straight to the left.

1)
6
2
10
3

Returns: 1

Go straight to the upper boundary here.

2)
653
375
1000
1000

Returns: 347

Going straight to the right leads to success.

3)
161
181
762
375

Returns: 161

*/
// END CUT HERE
#line 66 "EscapeFromRectangle.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class EscapeFromRectangle {
public:
  int shortest(int x, int y, int w, int h) {
    int temp1 = min (x, y);
    int x2, y2, temp2;
    x2 = w - x;
    y2 = h - y;
    temp2 = min (x2, y2);
    int ret = min (temp1, temp2);
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
		cout << "Testing EscapeFromRectangle (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456029597;
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
		EscapeFromRectangle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 1;
				int y = 1;
				int w = 5;
				int h = 5;
				_expected = 1;
				_received = _obj.shortest(x, y, w, h); break;
			}
			case 1:
			{
				int x = 6;
				int y = 2;
				int w = 10;
				int h = 3;
				_expected = 1;
				_received = _obj.shortest(x, y, w, h); break;
			}
			case 2:
			{
				int x = 653;
				int y = 375;
				int w = 1000;
				int h = 1000;
				_expected = 347;
				_received = _obj.shortest(x, y, w, h); break;
			}
			case 3:
			{
				int x = 161;
				int y = 181;
				int w = 762;
				int h = 375;
				_expected = 161;
				_received = _obj.shortest(x, y, w, h); break;
			}
			/*case 4:
			{
				int x = ;
				int y = ;
				int w = ;
				int h = ;
				_expected = ;
				_received = _obj.shortest(x, y, w, h); break;
			}*/
			/*case 5:
			{
				int x = ;
				int y = ;
				int w = ;
				int h = ;
				_expected = ;
				_received = _obj.shortest(x, y, w, h); break;
			}*/
			/*case 6:
			{
				int x = ;
				int y = ;
				int w = ;
				int h = ;
				_expected = ;
				_received = _obj.shortest(x, y, w, h); break;
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
