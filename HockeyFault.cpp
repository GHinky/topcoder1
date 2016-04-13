// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Last week, MyOwnBusiness Inc. received an urgent call from the IIHF (International Ice Hockey Federation) requesting a system to raise an alarm to the referee when there are too many players from the same team inside the rink. The system will be composed of three parts:


A digital camera in the ceiling to take photos of the rink every second.
A software module to extract the position of each player from the photo taken by the digital camera.
A software module to count the number of players from the same team inside the hockey rink.


The hockey rink consists of a width x height rectangle whose lower-left corner is at (x, y), and two circles with radius height / 2, one centered at (x, y + radius) and the other centered at (x + width, y + radius). See the image below for a graphic description. The players are specified by the vector <int>s px and py, where the k-th player's position is (px[k], py[k]).



You have been assigned the task of implementing the system's third module, following the specification given by the project leader: "Given the rink's specification and the players' positions, create a method numPlayers that returns the number of players on the boundary or inside the rink."


DEFINITION
Class:HockeyFault
Method:numPlayers
Parameters:int, int, int, int, vector <int>, vector <int>
Returns:int
Method signature:int numPlayers(int width, int height, int x, int y, vector <int> px, vector <int> py)


NOTES
-For those who know about ice hockey, the rink described in this problem is different than a real hockey rink.


CONSTRAINTS
-width will be between 1 and 100, inclusive.
-height will be between 2 and 100, inclusive.
-height will be an even number.
-x will be between -100 and 100, inclusive.
-y will be between -100 and 100, inclusive.
-px will contain between 1 and 50 elements, inclusive.
-Each element of px will be between -300 and 300, inclusive.
-py will contain the same number of elements as px.
-Each element of py will be between -300 and 300, inclusive.


EXAMPLES

0)
20
10
5
0
{15, 1, 1}
{5, 5, 1}

Returns: 2

The first player is exactly in the middle of the rink, the second player is exactly at the left border of the left circle and the third player is outside the rink.

1)
20
10
0
0
{-5, -4, -4, -3, -3, 0, 0, 20, 20, 23, 23, 24, 24, 25}
{5, 2, 8, 1, 9, 0, 10, 0, 10, 1, 9, 2, 8, 5}

Returns: 14

All players are on the rink boundary.

2)
52
84
-44
66
{26, -33, -49, 40, -10, 47, 25, -16, -82, 7}
{118, 106, 128, 114, 101, 85, 142, 140, 126, 145}

Returns: 8

3)
24
100
-61
71
{-63, -26, -9, -113, -124, -95, -89, -55}
{109, 164, 91, 80, 75, 140, 116, 113}

Returns: 6



*/
// END CUT HERE
#line 94 "HockeyFault.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class HockeyFault {
public:
  int sq (int x) {
    return x * x;
  }
  int numPlayers(int w, int h, int x, int y, VI px, VI py) {
    int ret = 0;
    const int r = h / 2;

    //2circle centers:
    int x1 = x, y1 = y + r, x2 = x + w, y2 = y + r;

    for (int i = 0; i != px.size(); ++i) {
      if (px[i] < x) {
	int cmp = sq (px[i] - x1) + sq (py[i] - y1);
	if (cmp <= sq(r))
	  ++ret;
      }
      if (px[i] > (x + w)) {
	int cmp = sq (px[i] - x2) + sq (py[i] - y2);
	if (cmp <= sq(r))
	  ++ret;
      }
      if (px[i] >= x && px[i] <= (x + w) && py[i] >= y && py[i] <= (y + h)) {
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
		cout << "Testing HockeyFault (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456477756;
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
		HockeyFault _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 20;
				int height = 10;
				int x = 5;
				int y = 0;
				int px[] = {15, 1, 1};
				int py[] = {5, 5, 1};
				_expected = 2;
				_received = _obj.numPlayers(width, height, x, y, vector <int>(px, px+sizeof(px)/sizeof(int)), vector <int>(py, py+sizeof(py)/sizeof(int))); break;
			}
			case 1:
			{
				int width = 20;
				int height = 10;
				int x = 0;
				int y = 0;
				int px[] = {-5, -4, -4, -3, -3, 0, 0, 20, 20, 23, 23, 24, 24, 25};
				int py[] = {5, 2, 8, 1, 9, 0, 10, 0, 10, 1, 9, 2, 8, 5};
				_expected = 14;
				_received = _obj.numPlayers(width, height, x, y, vector <int>(px, px+sizeof(px)/sizeof(int)), vector <int>(py, py+sizeof(py)/sizeof(int))); break;
			}
			case 2:
			{
				int width = 52;
				int height = 84;
				int x = -44;
				int y = 66;
				int px[] = {26, -33, -49, 40, -10, 47, 25, -16, -82, 7};
				int py[] = {118, 106, 128, 114, 101, 85, 142, 140, 126, 145};
				_expected = 8;
				_received = _obj.numPlayers(width, height, x, y, vector <int>(px, px+sizeof(px)/sizeof(int)), vector <int>(py, py+sizeof(py)/sizeof(int))); break;
			}
			case 3:
			{
				int width = 24;
				int height = 100;
				int x = -61;
				int y = 71;
				int px[] = {-63, -26, -9, -113, -124, -95, -89, -55};
				int py[] = {109, 164, 91, 80, 75, 140, 116, 113};
				_expected = 6;
				_received = _obj.numPlayers(width, height, x, y, vector <int>(px, px+sizeof(px)/sizeof(int)), vector <int>(py, py+sizeof(py)/sizeof(int))); break;
			}
			/*case 4:
			{
				int width = ;
				int height = ;
				int x = ;
				int y = ;
				int px[] = ;
				int py[] = ;
				_expected = ;
				_received = _obj.numPlayers(width, height, x, y, vector <int>(px, px+sizeof(px)/sizeof(int)), vector <int>(py, py+sizeof(py)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int width = ;
				int height = ;
				int x = ;
				int y = ;
				int px[] = ;
				int py[] = ;
				_expected = ;
				_received = _obj.numPlayers(width, height, x, y, vector <int>(px, px+sizeof(px)/sizeof(int)), vector <int>(py, py+sizeof(py)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int width = ;
				int height = ;
				int x = ;
				int y = ;
				int px[] = ;
				int py[] = ;
				_expected = ;
				_received = _obj.numPlayers(width, height, x, y, vector <int>(px, px+sizeof(px)/sizeof(int)), vector <int>(py, py+sizeof(py)/sizeof(int))); break;
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
