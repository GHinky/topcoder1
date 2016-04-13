// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Billy is going to his grandmother's house. To help him do that, his mother has written down a detailed list of instructions for him to follow. Each instruction is a character 'N', 'S', 'W' or 'E', telling him to go exactly 1 block to the north, south, west or east, respectively. Billy's city consists of an infinitely large grid of streets, where each street extends infinitely to both sides, and the space between 2 adjacent streets going in the same direction is always 1 block.  Billy's house and his grandmother's house are both located at street corners in this city.

Billy knows that his mother does not always choose the shortest path.  Therefore, he wants to make a new list of instructions that will also lead him to his grandmother's house, but uses the minimum possible number of instructions.

You will be given inst, a string with the original list made by Billy's mom. Return the new list Billy wants. If
there are several solutions, return the one that comes first alphabetically.


DEFINITION
Class:OptimalList
Method:optimize
Parameters:string
Returns:string
Method signature:string optimize(string inst)


CONSTRAINTS
-inst will contain between 1 and 50 characters, inclusive.
-Each character of inst will be either 'N', 'S', 'W' or 'E'.


EXAMPLES

0)
"NENENNWWWWWS"

Returns: "NNNWWW"



1)
"NNEESSWW"

Returns: ""

Billy's grandmother lives in the same place as him, so he can get there without walking the big roundabout path his mother suggests.

2)
"NEWSNWESWESSEWSENSEWSEWESEWWEWEEWESSSWWWWWW"

Returns: "SSSSSSSSWWW"



3)
"NENENE"

Returns: "EEENNN"

The list is already optimal in the number of instructions, but Billy wants the alphabetically first optimal list.

*/
// END CUT HERE
#line 59 "OptimalList.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class OptimalList {
public:
  string optimize(string inst) {
    string ret;
    int r=0, u=0; //right , up
    //N=1, S=-1; E=1, W=-1;
    for (int i = 0; i != inst.size(); ++i) {
      if (inst[i] == 'E')
	++r;
      if (inst[i] == 'W')
	--r;
      if (inst[i] == 'N')
	++u;
      if (inst[i] == 'S')
	--u;
    }
    string c1 = "", c2 = "";
    c1 += (r > 0)? "E" : "W";
    c2 += (u > 0)? "N" : "S";
    if (r == 0)
      c1 = "";
    if (u == 0)
      c2 = "";
    string s1, s2;
    for (int i = 0; i != abs(r); ++i) {
      s1 += c1;
    }
    for (int i = 0; i != abs(u); ++i) {
      s2 += c2;
    }
    if (s1 < s2)
      ret = s1 + s2;
    else
      ret = s2 + s1;
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
		cout << "Testing OptimalList (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456302655;
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
		OptimalList _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string inst = "NENENNWWWWWS";
				_expected = "NNNWWW";
				_received = _obj.optimize(inst); break;
			}
			case 1:
			{
				string inst = "NNEESSWW";
				_expected = "";
				_received = _obj.optimize(inst); break;
			}
			case 2:
			{
				string inst = "NEWSNWESWESSEWSENSEWSEWESEWWEWEEWESSSWWWWWW";
				_expected = "SSSSSSSSWWW";
				_received = _obj.optimize(inst); break;
			}
			case 3:
			{
				string inst = "NENENE";
				_expected = "EEENNN";
				_received = _obj.optimize(inst); break;
			}
			/*case 4:
			{
				string inst = ;
				_expected = ;
				_received = _obj.optimize(inst); break;
			}*/
			/*case 5:
			{
				string inst = ;
				_expected = ;
				_received = _obj.optimize(inst); break;
			}*/
			/*case 6:
			{
				string inst = ;
				_expected = ;
				_received = _obj.optimize(inst); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
