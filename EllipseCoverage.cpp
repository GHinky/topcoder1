// BEGIN CUT HERE
/*
PROBLEM STATEMENT
An ellipse is a figure on a plane where the sum of the distances from any point on its perimeter to two fixed points is constant. The two fixed points are called foci (plural of focus). In this problem we are interested in the number of points with integral coordinates that lie strictly inside of the given ellipse.

The foci are (x1, y1) and (x2, y2), and the fixed sum of distances is d.

DEFINITION
Class:EllipseCoverage
Method:calculateCoverage
Parameters:int, int, int, int, int
Returns:int
Method signature:int calculateCoverage(int x1, int y1, int x2, int y2, int d)


CONSTRAINTS
-x1, y1, x2, y2 will be between -100 and 100, inclusive.
-d will be between 1 and 200, inclusive.
-The arguments will define a valid ellipse with positive area.


EXAMPLES

0)
0
0
0
0
4

Returns: 9

This is a circle with radius 2.  The points (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0) and (-1, 1) lie strictly inside the circle.  The points (-2, 0), (0, -2), (0, 2) and (2, 0) are on the perimeter, so they do not lie strictly inside the circle and should not be counted.

1)
-3
0
3
0
10

Returns: 59

Be careful with (0, 4), (-5, 0), (0, -4) and (5, 0).

2)
10
12
8
14
50

Returns: 1941



3)
0
0
0
0
200

Returns: 31397



4)
13
-23
49
91
200

Returns: 25187



*/
// END CUT HERE
#line 82 "EllipseCoverage.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class EllipseCoverage {
public:
  int sq (int i) {
    return i*i;
  }
  int calculateCoverage(int x1, int y1, int x2, int y2, int d) {
    int ret = 0;
    for (int x = -301; x != 301; ++x) {
      for (int y = -301; y != 301; ++y) {
	//	cout << x << " , " << y << endl;
	int cmp = sqrt (sq(x-x1) + sq(y-y1)) + sqrt (sq(x-x2) + sq(y-y2));
	if (cmp < d)
	  ++ret;
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
		cout << "Testing EllipseCoverage (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456328560;
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
		EllipseCoverage _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x1 = 0;
				int y1 = 0;
				int x2 = 0;
				int y2 = 0;
				int d = 4;
				_expected = 9;
				_received = _obj.calculateCoverage(x1, y1, x2, y2, d); break;
			}
			
			case 1:
			{
				int x1 = -3;
				int y1 = 0;
				int x2 = 3;
				int y2 = 0;
				int d = 10;
				_expected = 59;
				_received = _obj.calculateCoverage(x1, y1, x2, y2, d); break;
			}
			case 2:
			{
				int x1 = 10;
				int y1 = 12;
				int x2 = 8;
				int y2 = 14;
				int d = 50;
				_expected = 1941;
				_received = _obj.calculateCoverage(x1, y1, x2, y2, d); break;
			}
			case 3:
			{
				int x1 = 0;
				int y1 = 0;
				int x2 = 0;
				int y2 = 0;
				int d = 200;
				_expected = 31397;
				_received = _obj.calculateCoverage(x1, y1, x2, y2, d); break;
			}
			case 4:
			{
				int x1 = 13;
				int y1 = -23;
				int x2 = 49;
				int y2 = 91;
				int d = 200;
				_expected = 25187;
				_received = _obj.calculateCoverage(x1, y1, x2, y2, d); break;
			}
			/*case 5:
			{
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				int d = ;
				_expected = ;
				_received = _obj.calculateCoverage(x1, y1, x2, y2, d); break;
			}*/
			/*case 6:
			{
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				int d = ;
				_expected = ;
				_received = _obj.calculateCoverage(x1, y1, x2, y2, d); break;
			}*/
			/*case 7:
			{
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				int d = ;
				_expected = ;
				_received = _obj.calculateCoverage(x1, y1, x2, y2, d); break;
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
