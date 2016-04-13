// BEGIN CUT HERE
/*
PROBLEM STATEMENT

You are walking in the city on a holiday. Suddenly, you are told to go to your office as soon as possible by your boss via cell phone. The city is infinite in size, with vertical streets located at every integer X value and horizontal streets located at every Y value. You are currently located at (0, 0) and your office is located at (gX, gY). There are some taxi stands in the city and their locations are (tXs[i], tYs[i]). You can either go to the office by foot or go to some taxi stand, get a taxi there and go to the office by taxi. It takes walkTime seconds to go along the street to proceed to a horizontally or vertically adjacent intersection by foot and it takes taxiTime seconds by a taxi.


Return the least amount of time that it will take you to go to your office.


DEFINITION
Class:GrabbingTaxi
Method:minTime
Parameters:vector <int>, vector <int>, int, int, int, int
Returns:int
Method signature:int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime)


CONSTRAINTS
-tXs will contain between 0 and 50 elements, inclusive.
-tXs and tYs will contain the same number of elements.
-Each element of tXs and tYs will be between -10000 and 10000, inclusive.
-gX and gY will be between -10000 and 10000, inclusive.
-walkTime and taxiTime will be between 1 and 1000, inclusive.


EXAMPLES

0)
{}
{}
3
2
10
2

Returns: 50

There are no taxi stands. You have to walk to the goal.

1)
{-2, -2}
{0, -2}
-4
-2
15
3

Returns: 42

First, you walk to (-2, 0) and get a taxi. Then you go to the goal by it.

2)
{3}
{0}
5
0
10
20

Returns: 50

taxiTime may be larger than walkTime.

3)
{34, -12, 1, 0, 21, -43, -98, 11, 86, -31}
{11, 5, -68, 69, -78, -49, -36, -2, 1, 70}
-97
-39
47
13

Returns: 2476



4)
{82, -60, 57, 98, 30, -67, 84, -42, -100, 62}
{-7, 90, 53, -56, -15, -87, 22, -3, -61, -30}
21
15
53
2

Returns: 1908



*/
// END CUT HERE
#line 92 "GrabbingTaxi.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <climits>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class GrabbingTaxi {
public:
  int dist (int x1, int y1, int x2, int y2) { //min dist bet 2 pts
    return abs(x2 - x1) + abs (y2 - y1);
  }
  int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime) {
    int ret;
    int foot_time = dist (0, 0, gX, gY) * walkTime;
    const int N = tXs.size(); // N taxies

    VI to, st;// taxi-2-office, start-2-taxi
    VI so; // start-2-taxi-2-office
    for (int i = 0; i != N; ++i) {
      int d1 = dist (tXs[i], tYs[i], gX, gY);
      to.push_back (d1*taxiTime);

      int d2 = dist (0, 0, tXs[i], tYs[i]);
      st.push_back (d2*walkTime);

      int topush = d1*taxiTime + d2*walkTime;
      so.push_back (topush);
      
    }

    int taxi_time = INT_MAX;
    for (int i = 0; i != N; ++i) {
      taxi_time = min (taxi_time, so[i]);
    }
    
    ret = min (foot_time, taxi_time);
        
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
		cout << "Testing GrabbingTaxi (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456601363;
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
		GrabbingTaxi _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int tXs[] = {};
				int tYs[] = {};
				int gX = 3;
				int gY = 2;
				int walkTime = 10;
				int taxiTime = 2;
				_expected = 50;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			case 1:
			{
				int tXs[] = {-2, -2};
				int tYs[] = {0, -2};
				int gX = -4;
				int gY = -2;
				int walkTime = 15;
				int taxiTime = 3;
				_expected = 42;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			case 2:
			{
				int tXs[] = {3};
				int tYs[] = {0};
				int gX = 5;
				int gY = 0;
				int walkTime = 10;
				int taxiTime = 20;
				_expected = 50;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			case 3:
			{
				int tXs[] = {34, -12, 1, 0, 21, -43, -98, 11, 86, -31};
				int tYs[] = {11, 5, -68, 69, -78, -49, -36, -2, 1, 70};
				int gX = -97;
				int gY = -39;
				int walkTime = 47;
				int taxiTime = 13;
				_expected = 2476;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			case 4:
			{
				int tXs[] = {82, -60, 57, 98, 30, -67, 84, -42, -100, 62};
				int tYs[] = {-7, 90, 53, -56, -15, -87, 22, -3, -61, -30};
				int gX = 21;
				int gY = 15;
				int walkTime = 53;
				int taxiTime = 2;
				_expected = 1908;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			/*case 5:
			{
				int tXs[] = ;
				int tYs[] = ;
				int gX = ;
				int gY = ;
				int walkTime = ;
				int taxiTime = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}*/
			/*case 6:
			{
				int tXs[] = ;
				int tYs[] = ;
				int gX = ;
				int gY = ;
				int walkTime = ;
				int taxiTime = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}*/
			/*case 7:
			{
				int tXs[] = ;
				int tYs[] = ;
				int gX = ;
				int gY = ;
				int walkTime = ;
				int taxiTime = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
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
