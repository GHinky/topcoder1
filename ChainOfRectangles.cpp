// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A sequence of rectangles is drawn on a plane that is initially completely white. Each rectangle lies strictly inside the previous one. Each rectangle is completely colored in one of three colors - red, green or blue. The colors do not mix, so when a rectangle is drawn inside another rectangle, the new color replaces any existing color in that same area.

The rectangles are described by the vector <int>s width and height, and the string color. The width and height of the i-th drawn rectangle are width[i] and height[i], respectively, and its color is the i-th character of color. The characters 'R', 'G' and 'B' represent red, green and blue, respectively.

After all the rectangles are drawn, calculate the total area occupied by red, the total area occupied by green, and the total area occupied by blue. Return the maximum of these three areas.

DEFINITION
Class:ChainOfRectangles
Method:getMaximalArea
Parameters:vector <int>, vector <int>, string
Returns:int
Method signature:int getMaximalArea(vector <int> width, vector <int> height, string color)


NOTES
-You won't be given the information about the exact location of each rectangle, since it's not needed to solve the problem.


CONSTRAINTS
-width will contain between 1 and 50 elements, inclusive.
-height will contain the same number of elements as width.
-color will contain the same number of characters as the number of elements in width.
-Each element of width and height will be between 1 and 10000, inclusive.
-Elements of width and height will be in strictly descending order.
-Each character of color will be 'R', 'G' or 'B'.


EXAMPLES

0)
{10000}
{10000}
"R"

Returns: 100000000

There is only one 10,000x10,000 rectangle. It's colored red, so the area covered by red is 10,000 * 10,000 = 100,000,000. The areas covered by the other two colors are 0.

1)
{10, 5}
{10, 5}
"GB"

Returns: 75

Here, the area covered by blue is 5 * 5 = 25 and the area, covered by green is 10 * 10 - 5 * 5 = 75. We return max{75, 25} = 75.


2)
{10, 9}
{8, 7}
"GB"

Returns: 63

Now, the area covered by green is 17, and the area covered by blue is 63.


3)
{10, 8, 6, 4, 2}
{9, 7, 5, 3, 1}
"GBRRG"

Returns: 36



*/
// END CUT HERE
#line 74 "ChainOfRectangles.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class ChainOfRectangles {
public:
  int getMaximalArea(vector <int> width, vector <int> height, string color) {
    int ret = 1000 * 1000 + 1;
    VI area;
    int sentinel = 0; // last rect of (0, 0) dimension inserted
    width.push_back(sentinel);
    height.push_back(sentinel);
    for (int i = 0; i != width.size() - 1; ++i) {
      area.push_back (width[i] * height[i] - width[i+1] * height[i+1]);
    }
    
    int ra = 0, ga = 0, ba = 0; // red, green, blue areas
    
    for (int i = 0; i != color.length(); ++i) {
      if (color[i] == 'R') {
	ra += area[i];
      }
      if (color[i] == 'G') {
	ba += area[i];
      }
      if (color[i] == 'B') {
	ga += area[i];
      }
    }
    ret = max (ra, ga);
    ret = max (ret, ba);
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
		cout << "Testing ChainOfRectangles (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456406899;
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
		ChainOfRectangles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width[] = {10000};
				int height[] = {10000};
				string color = "R";
				_expected = 100000000;
				_received = _obj.getMaximalArea(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int)), color); break;
			}
			case 1:
			{
				int width[] = {10, 5};
				int height[] = {10, 5};
				string color = "GB";
				_expected = 75;
				_received = _obj.getMaximalArea(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int)), color); break;
			}
			case 2:
			{
				int width[] = {10, 9};
				int height[] = {8, 7};
				string color = "GB";
				_expected = 63;
				_received = _obj.getMaximalArea(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int)), color); break;
			}
			case 3:
			{
				int width[] = {10, 8, 6, 4, 2};
				int height[] = {9, 7, 5, 3, 1};
				string color = "GBRRG";
				_expected = 36;
				_received = _obj.getMaximalArea(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int)), color); break;
			}
			/*case 4:
			{
				int width[] = ;
				int height[] = ;
				string color = ;
				_expected = ;
				_received = _obj.getMaximalArea(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int)), color); break;
			}*/
			/*case 5:
			{
				int width[] = ;
				int height[] = ;
				string color = ;
				_expected = ;
				_received = _obj.getMaximalArea(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int)), color); break;
			}*/
			/*case 6:
			{
				int width[] = ;
				int height[] = ;
				string color = ;
				_expected = ;
				_received = _obj.getMaximalArea(vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(height, height+sizeof(height)/sizeof(int)), color); break;
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
