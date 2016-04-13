// BEGIN CUT HERE
/*
PROBLEM STATEMENT

You are a diamond hunter looking for diamonds in a peculiar mine. This mine is a string of '<' and '>' characters, and each diamond is a substring of the form "<>". Each time you find a diamond, you remove it and the residual mine is updated by removing the 2 characters from the string.

For example, if you have a mine like "><<><>>><", you can start by removing the first appearance of "<>" to get "><<>>><", then remove the only remaining diamond to get "><>><". Note that this produces a new diamond which you can remove to get ">><". Since there are no diamonds left, your expedition is done.

Given a string mine, return the number of diamonds that can be found. Note that the order in which you remove simultaneous appearances of diamonds is irrelevant; any order will lead to the same result.


DEFINITION
Class:DiamondHunt
Method:countDiamonds
Parameters:string
Returns:int
Method signature:int countDiamonds(string mine)


CONSTRAINTS
-mine will contain between 1 and 50 characters, inclusive.
-Each character of mine will be either '<' or '>'.


EXAMPLES

0)
"><<><>>><"

Returns: 3

The example from the problem statement.

1)
">>>><<"

Returns: 0

No diamonds here.

2)
"<<<<<<<<<>>>>>>>>>"

Returns: 9



3)
"><<><><<>>>><<>><<><<>><<<>>>>>><<<"

Returns: 14



*/
// END CUT HERE
#line 58 "DiamondHunt.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class DiamondHunt {
public:
  string trans (string m, int i, int j) { // mine one diamond
    string ret;
    ret = m.substr (0, i) + m.substr (j+1, m.size() - j - 1);
    return ret;
  }
  int countDiamonds(string mine) {
    //    cout << mine << endl;
    int ret = 0;
    for (int i = 0, j = i + 1; j < mine.size() + 1; ++i, ++j) {
      if (mine[i] == '<' && mine[j] == '>') {
	mine = trans (mine, i, j);
	//	cout << mine << endl;
	++ret;
	i = -1;
	j = 0;
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
		cout << "Testing DiamondHunt (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456290057;
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
		DiamondHunt _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string mine = "><<><>>><";
				_expected = 3;
				_received = _obj.countDiamonds(mine); break;
			}
			case 1:
			{
				string mine = ">>>><<";
				_expected = 0;
				_received = _obj.countDiamonds(mine); break;
			}
			case 2:
			{
				string mine = "<<<<<<<<<>>>>>>>>>";
				_expected = 9;
				_received = _obj.countDiamonds(mine); break;
			}
			case 3:
			{
				string mine = "><<><><<>>>><<>><<><<>><<<>>>>>><<<";
				_expected = 14;
				_received = _obj.countDiamonds(mine); break;
			}
			/*case 4:
			{
				string mine = ;
				_expected = ;
				_received = _obj.countDiamonds(mine); break;
			}*/
			/*case 5:
			{
				string mine = ;
				_expected = ;
				_received = _obj.countDiamonds(mine); break;
			}*/
			/*case 6:
			{
				string mine = ;
				_expected = ;
				_received = _obj.countDiamonds(mine); break;
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
