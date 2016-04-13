// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A robot is moving in a plane following a set of instructions.

The following instructions are possible (quotes for clarity only):
"LEFT" - turn left 90 degrees
"RIGHT" - turn right 90 degrees
"TURN AROUND" - turn around (a 180 degree turn)
"LEFT X" - turn left X degrees, where X is a positive integer
"RIGHT X" - turn right X degrees, where X is a positive integer
"HALT" - stop executing instructions; further instructions are not executed

You are given a vector <string> containing the robot's instructions. Initially, the robot is facing north. Return the robot's final azimuth - the angle between north and the direction the robot is facing.  Azimuth is always measured clockwise, and is a number between 0, inclusive, and 360, exclusive.  For example, west corresponds to azimuth 270.

DEFINITION
Class:AzimuthMonitoring
Method:getAzimuth
Parameters:vector <string>
Returns:int
Method signature:int getAzimuth(vector <string> instructions)


NOTES
-Turning right corresponds to turning clockwise, turning left corresponds to turning counterclockwise.


CONSTRAINTS
-instructions will contain between 1 and 50 elements, inclusive.
-Each element of instructions will be a valid instruction, as listed in the problem statement.
-In an instruction of the form "LEFT X" or "RIGHT X", X will be an integer between 1 and 179, inclusive, with no leading zeroes.


EXAMPLES

0)
{"RIGHT"}

Returns: 90

Turning 90 degrees right changes the azimuth from 0 to 90.

1)
{"LEFT", "LEFT", "TURN AROUND"}

Returns: 0

After turning left, the robot is facing west (azimuth 270). After turning left again, the robot is facing south (azimuth 180). Finally, turning around makes the robot face north, azimuth 0.

2)
{"LEFT 5", "RIGHT 10", "LEFT 15", "RIGHT 20", "LEFT 25", "RIGHT 30", "LEFT 35", "RIGHT 40"}

Returns: 20

There are four pairs of instructions, each pair making the robot turn right 5 degrees.

3)
{"RIGHT 59", "RIGHT", "RIGHT", "HALT", "LEFT", "LEFT", "LEFT"}

Returns: 239

The fourth instruction is "HALT", thus none of the following "LEFT" instructions are executed.

4)
{"TURN AROUND", "HALT", "LEFT 5", "HALT", "LEFT 5", "HALT"}

Returns: 180

Note that there might be more then one "HALT" instruction.

5)
{"LEFT", "LEFT", "LEFT", "LEFT", "LEFT", "HALT"}

Returns: 270

After the first 4 turns the robot is facing north again, and the fifth instruction turns him west. The last instruction doesn't change anything.

*/
// END CUT HERE
#line 81 "AzimuthMonitoring.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class AzimuthMonitoring {
public:

  int extract_angle (string s) {
    int ret;
    stringstream ss;
    ss << s;
    string discard;
    ss >> discard;
    ss >> ret;
    return ret;
  }

  int getAzimuth(vector <string> instructions) {
    int ret = 0;
    VS ins;
    for (int i = 0; (i != instructions.size()) && (instructions[i] != "HALT"); ++i) {
      string temp = instructions[i];
      if (temp == "LEFT" || temp == "RIGHT")
	temp += " 90";
      ins.push_back (temp);
    }
    for (int i = 0; i != ins.size(); ++i) {
      string temp = ins[i];
      if (temp[0] == 'R') {
	ret += extract_angle (temp);
      }
      if (temp[0] == 'L') {
	ret -= extract_angle (temp);
      }
      if (temp[0] == 'T') {
	ret += 180;
      }
    }
    while (ret < 0)
      ret += 360;
    ret %= 360; 
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
		cout << "Testing AzimuthMonitoring (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456336806;
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
		AzimuthMonitoring _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string instructions[] = {"RIGHT"};
				_expected = 90;
				_received = _obj.getAzimuth(vector <string>(instructions, instructions+sizeof(instructions)/sizeof(string))); break;
			}
			case 1:
			{
				string instructions[] = {"LEFT", "LEFT", "TURN AROUND"};
				_expected = 0;
				_received = _obj.getAzimuth(vector <string>(instructions, instructions+sizeof(instructions)/sizeof(string))); break;
			}
			case 2:
			{
				string instructions[] = {"LEFT 5", "RIGHT 10", "LEFT 15", "RIGHT 20", "LEFT 25", "RIGHT 30", "LEFT 35", "RIGHT 40"};
				_expected = 20;
				_received = _obj.getAzimuth(vector <string>(instructions, instructions+sizeof(instructions)/sizeof(string))); break;
			}
			case 3:
			{
				string instructions[] = {"RIGHT 59", "RIGHT", "RIGHT", "HALT", "LEFT", "LEFT", "LEFT"};
				_expected = 239;
				_received = _obj.getAzimuth(vector <string>(instructions, instructions+sizeof(instructions)/sizeof(string))); break;
			}
			case 4:
			{
				string instructions[] = {"TURN AROUND", "HALT", "LEFT 5", "HALT", "LEFT 5", "HALT"};
				_expected = 180;
				_received = _obj.getAzimuth(vector <string>(instructions, instructions+sizeof(instructions)/sizeof(string))); break;
			}
			case 5:
			{
				string instructions[] = {"LEFT", "LEFT", "LEFT", "LEFT", "LEFT", "HALT"};
				_expected = 270;
				_received = _obj.getAzimuth(vector <string>(instructions, instructions+sizeof(instructions)/sizeof(string))); break;
			}
			/*case 6:
			{
				string instructions[] = ;
				_expected = ;
				_received = _obj.getAzimuth(vector <string>(instructions, instructions+sizeof(instructions)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string instructions[] = ;
				_expected = ;
				_received = _obj.getAzimuth(vector <string>(instructions, instructions+sizeof(instructions)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string instructions[] = ;
				_expected = ;
				_received = _obj.getAzimuth(vector <string>(instructions, instructions+sizeof(instructions)/sizeof(string))); break;
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
