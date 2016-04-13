// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The "taxicab distance" between two points in space is defined to be the distance
that would need to be travelled to get from one to the other using segments
that are parallel to the axes.  This is generally longer than the (straight-line)
distance between the two points.

We know the taxicab distance between two points. We want to know the maximum
straight-line distance between them if they lie in the
rectangular region { (x,y) |  0<=x<=maxX, 0<=y<=maxY }. 
Create a class Taxi that contains a method maxDis that is given maxX, maxY,
and taxiDis and that returns the largest possible straight-line distance between
the two points. If no two points within the given region have the given taxicab
distance, return -1.0.



DEFINITION
Class:Taxi
Method:maxDis
Parameters:int, int, int
Returns:double
Method signature:double maxDis(int maxX, int maxY, int taxiDis)


NOTES
-A return value with either an absolute or relative error of less than 1.0E-9 is considered correct.


CONSTRAINTS
-maxX and maxY are both between 1 and 1,000,000, inclusive.
-taxiDis is between 0 and 1,000,000, inclusive.


EXAMPLES

0)
10
3
3

Returns: 3.0



   The two points could lie in a straight line parallel to one of the axes. Then
   the straight-line distance would be the same as the taxicab distance.




1)
10
3
24

Returns: -1.0



   No two points with 0<=x<=10, 0<=y<=3, have a taxicab distance between them
   that is as big as 24.


2)
7
10
13

Returns: 10.44030650891055



   (5,0) and (2,10) are two points in this region whose taxicab distance is |2-5| + |10-0| = 13 and whose straight-line distance is sqrt(3*3 + 10*10) = sqrt(109).

3)
4
4
7

Returns: 5.0

4)
976421
976421
1000000

Returns: 976705.6560100387

*/
// END CUT HERE
#line 94 "Taxi.cpp"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#define EPS 1e-9
using namespace std;
class Taxi {
	public:
	double maxDis(int maxX, int maxY, int taxiDis) {
	  double ret = -69;
	  double m = (maxX > maxY)? maxX : maxY;
	  if (taxiDis <= m)
	    ret = taxiDis;
	  if (taxiDis > m && taxiDis <= maxX + maxY) {
	    // note: m*m outflows an integer, hence we need m to be double
	    ret = sqrt (m * m +  (taxiDis - m) * (taxiDis - m));
	  }
	  if (taxiDis > maxX + maxY)
	    ret = -1;
	  streamsize default_prec = cout.precision();
	  cout << fixed << setprecision(9);
	  cout << "ret=" << ret << endl;
	  cout << setprecision(default_prec);
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
		cout << "Testing Taxi (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454923893;
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
		Taxi _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int maxX = 10;
				int maxY = 3;
				int taxiDis = 3;
				_expected = 3.0;
				_received = _obj.maxDis(maxX, maxY, taxiDis); break;
			}
			case 1:
			{
				int maxX = 10;
				int maxY = 3;
				int taxiDis = 24;
				_expected = -1.0;
				_received = _obj.maxDis(maxX, maxY, taxiDis); break;
			}
			case 2:
			{
				int maxX = 7;
				int maxY = 10;
				int taxiDis = 13;
				_expected = 10.44030650891055;
				_received = _obj.maxDis(maxX, maxY, taxiDis); break;
			}
			case 3:
			{
				int maxX = 4;
				int maxY = 4;
				int taxiDis = 7;
				_expected = 5.0;
				_received = _obj.maxDis(maxX, maxY, taxiDis); break;
			}
			case 4:
			{
				int maxX = 976421;
				int maxY = 976421;
				int taxiDis = 1000000;
				_expected = 976705.6560100387;
				_received = _obj.maxDis(maxX, maxY, taxiDis); break;
			}
			/*case 5:
			{
				int maxX = ;
				int maxY = ;
				int taxiDis = ;
				_expected = ;
				_received = _obj.maxDis(maxX, maxY, taxiDis); break;
			}*/
			/*case 6:
			{
				int maxX = ;
				int maxY = ;
				int taxiDis = ;
				_expected = ;
				_received = _obj.maxDis(maxX, maxY, taxiDis); break;
			}*/
			/*case 7:
			{
				int maxX = ;
				int maxY = ;
				int taxiDis = ;
				_expected = ;
				_received = _obj.maxDis(maxX, maxY, taxiDis); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
