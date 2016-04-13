// BEGIN CUT HERE
/*
PROBLEM STATEMENT

The great pirate Silver has buried a treasure on a tropical island. You
managed to find a map of the island with an X marking a spot on the island,
and a set of instructions.
Each instruction is of the form "walk A steps in the direction B".
If you start at the X and follow the instructions in the given order,
at the end you will arrive at the location where the treasure is buried.



Your evil twin has a copy of the map, and has already started to follow
the instructions. To beat him, you must find the location of the treasure
and walk straight to that place.



You will be given the set of instructions as a vector <int> steps and a vector <string>
directions. 
Element i of directions corresponds to element i of steps.
Write a method that will find the location of the treasure, and
return the straight-line distance (in steps) from the place
where you start to the place where the treasure is buried.



Each direction in directions will be one of the eight basic directions on a compass.
Refer to the image below for clarification.






DEFINITION
Class:PirateTreasure
Method:getDistance
Parameters:vector <int>, vector <string>
Returns:double
Method signature:double getDistance(vector <int> steps, vector <string> directions)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.
-Assume that the island lies on a plane, and that it is large enough to accomodate the entire walk.
-Note that making a step northwest is not the same as making a step north and then a step west. See Example 3.
-The Euclidean distance between two points A=(ax,ay) and B=(bx,by) in a plane is equal to sqrt( (ax-bx)^2 + (ay-by)^2 ).


CONSTRAINTS
-steps will contain between 1 and 50 elements, inclusive.
-Each element in steps will be between 1 and 50, inclusive.
-directions will contain the same number of elements as steps.
-Each element of directions will be one of NORTH, SOUTH, EAST, WEST, NORTHEAST, NORTHWEST, SOUTHEAST, and SOUTHWEST.


EXAMPLES

0)
{1}
{"NORTH"}

Returns: 1.0

After one step north, you will be (surprisingly) one step away from where you started.

1)
{2}
{"NORTHWEST"}

Returns: 2.0

Two steps northwest will take you two steps away from where you started.

2)
{3,10,7}
{"EAST","WEST","EAST"}

Returns: 0.0

After following these instructions you'll end exactly where you started.

3)
{34,48,34}
{"NORTH","SOUTHWEST","EAST"}

Returns: 0.08326112068522587

Following these instructions won't get you exactly to the same place where you started, but you will be pretty close.

4)
{2,2,2,1}
{"NORTH","NORTH","NORTH","NORTHWEST"}

Returns: 6.744277676240694

After six steps north and one step northwest, your straight line distance from where you started is a little less than seven steps.

*/
// END CUT HERE
#line 104 "PirateTreasure.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class PirateTreasure {
public:
  double getDistance(vector <int> steps, vector <string> directions) {
    double ret;
    int r = 0, u = 0, ru = 0, rd = 0; // right, up, rightup, right-down
    
    for (int i = 0; i != directions.size(); ++i) {
      if (directions[i] == "NORTH")
	u += 1 * steps[i];
      if (directions[i] == "SOUTH")
	u -= 1 * steps[i];
      if (directions[i] == "EAST")
	r += 1 * steps[i];
      if (directions[i] == "WEST")
	r -= 1 * steps[i];
      if (directions[i] == "NORTHEAST") {
	ru += 1 * steps[i];
      }
      if (directions[i] == "NORTHWEST") {
	rd -= 1 * steps[i];
      }
      if (directions[i] == "SOUTHEAST") {
	rd += 1 * steps[i];
      }
      if (directions[i] == "SOUTHWEST") {
	ru -= 1 * steps[i];
      }
    }
    const double c = sqrt (0.5);
    double right = r + ru * c + rd * c; // right
    double up = u + ru * c - rd * c; // up
    ret = sqrt (right * right + up * up);
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
		cout << "Testing PirateTreasure (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456404232;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PirateTreasure _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int steps[] = {1};
				string directions[] = {"NORTH"};
				_expected = 1.0;
				_received = _obj.getDistance(vector <int>(steps, steps+sizeof(steps)/sizeof(int)), vector <string>(directions, directions+sizeof(directions)/sizeof(string))); break;
			}
			case 1:
			{
				int steps[] = {2};
				string directions[] = {"NORTHWEST"};
				_expected = 2.0;
				_received = _obj.getDistance(vector <int>(steps, steps+sizeof(steps)/sizeof(int)), vector <string>(directions, directions+sizeof(directions)/sizeof(string))); break;
			}
			case 2:
			{
				int steps[] = {3,10,7};
				string directions[] = {"EAST","WEST","EAST"};
				_expected = 0.0;
				_received = _obj.getDistance(vector <int>(steps, steps+sizeof(steps)/sizeof(int)), vector <string>(directions, directions+sizeof(directions)/sizeof(string))); break;
			}
			case 3:
			{
				int steps[] = {34,48,34};
				string directions[] = {"NORTH","SOUTHWEST","EAST"};
				_expected = 0.08326112068522587;
				_received = _obj.getDistance(vector <int>(steps, steps+sizeof(steps)/sizeof(int)), vector <string>(directions, directions+sizeof(directions)/sizeof(string))); break;
			}
			case 4:
			{
				int steps[] = {2,2,2,1};
				string directions[] = {"NORTH","NORTH","NORTH","NORTHWEST"};
				_expected = 6.744277676240694;
				_received = _obj.getDistance(vector <int>(steps, steps+sizeof(steps)/sizeof(int)), vector <string>(directions, directions+sizeof(directions)/sizeof(string))); break;
			}
			/*case 5:
			{
				int steps[] = ;
				string directions[] = ;
				_expected = ;
				_received = _obj.getDistance(vector <int>(steps, steps+sizeof(steps)/sizeof(int)), vector <string>(directions, directions+sizeof(directions)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int steps[] = ;
				string directions[] = ;
				_expected = ;
				_received = _obj.getDistance(vector <int>(steps, steps+sizeof(steps)/sizeof(int)), vector <string>(directions, directions+sizeof(directions)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int steps[] = ;
				string directions[] = ;
				_expected = ;
				_received = _obj.getDistance(vector <int>(steps, steps+sizeof(steps)/sizeof(int)), vector <string>(directions, directions+sizeof(directions)/sizeof(string))); break;
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
