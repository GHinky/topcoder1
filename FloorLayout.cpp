// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You are building a house and are about to lay the floorboards in a particular room. Your architect has designed the layout of the floorboards and you now want to know how many boards you need to buy. Each board is 1 unit wide and can be of any positive integer length. The room is rectangular and the boards are to be laid out on a unit-square grid inside the room, parallel to the walls of the room.
You are given a vector <string> layout describing the layout of the floorboards. Character j of element i of layout describes the grid-square at position (i, j) and will either be a '-' or a '|', depending on which direction the floorboard covering that square is oriented. If two '-' characters are adjacent at the same value of i, then they form part of the same east/west-oriented floorboard. Similarly, if two '|' characters are adjacent at the same value of j, they are part of the same north/south-oriented floorboard. Return an int containing the number of distinct floorboards in the layout.

DEFINITION
Class:FloorLayout
Method:countBoards
Parameters:vector <string>
Returns:int
Method signature:int countBoards(vector <string> layout)


CONSTRAINTS
-layout will contain between 1 and 50 elements, inclusive.
-Each element of layout will contain between 1 and 50 characters, inclusive.
-Each element of layout will contain the same number of characters.
-Each character in layout will be a '-' or a '|'.


EXAMPLES

0)
{"----"
,"----"
,"----"
,"----"}

Returns: 4

This layout contains 4 boards laid east/west.

1)
{"-||--||--"
,"--||--||-"
,"|--||--||"
,"||--||--|"
,"-||--||--"
,"--||--||-"}

Returns: 31

This is an aesthetic pattern made up of boards of lengths 1 and 2.

2)
{"--------"
,"|------|"
,"||----||"
,"|||--|||"
,"||----||"
,"|------|"
,"--------"}

Returns: 13



3)
{"||-||-|||-"
,"||--||||||"
,"-|-|||||||"
,"-|-||-||-|"
,"||--|-||||"
,"||||||-||-"
,"|-||||||||"
,"||||||||||"
,"||---|--||"
,"-||-||||||"}

Returns: 41



4)
{"-||--|"
,"||||||"
,"|||-|-"
,"-||||-"
,"||||-|"
,"||-||-"}

Returns: 19



*/
// END CUT HERE
#line 90 "FloorLayout.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class FloorLayout {
public:
  int countBoards(vector <string> layout) {
    const int H = layout.size(), W = layout[0].length();
    int ret = H * W;
   
    int count1 = 0;
    for (int i = 0; i != H; ++i) {
      char mem = '*';
      for (int j = 0; j != W; ++j) {
	if ((layout[i][j] != mem) || ((layout[i][j] == mem) && (mem == '|'))) {
	  ++count1;
	  mem = layout[i][j];
	}

      }
    }
    int diff1 = H*W - count1;
    cout << "diff1 = " << diff1 << endl;

    int count2 = 0;
    for (int j = 0; j != W; ++j) {
      char mem = '*';
      for (int i = 0; i != H; ++i) {
	if ((layout[i][j] != mem) || ((layout[i][j] == mem) && (mem == '-'))) {
	  ++count2;
	  mem = layout[i][j];	
	}

      }
    }
    cout << "count2 = " << count2 << endl;
    int diff2 = H*W - count2;
    cout << "diff2 = " << diff2 << endl;
    
    ret = H*W - diff1 - diff2;
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
		cout << "Testing FloorLayout (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456549669;
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
		FloorLayout _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string layout[] = {"----"
				                  ,"----"
				                  ,"----"
				                  ,"----"};
				_expected = 4;
				_received = _obj.countBoards(vector <string>(layout, layout+sizeof(layout)/sizeof(string))); break;
			}
			case 1:
			{
				string layout[] = {"-||--||--"
				                  ,"--||--||-"
				                  ,"|--||--||"
				                  ,"||--||--|"
				                  ,"-||--||--"
				                  ,"--||--||-"};
				_expected = 31;
				_received = _obj.countBoards(vector <string>(layout, layout+sizeof(layout)/sizeof(string))); break;
			}
			case 2:
			{
				string layout[] = {"--------"
				                  ,"|------|"
				                  ,"||----||"
				                  ,"|||--|||"
				                  ,"||----||"
				                  ,"|------|"
				                  ,"--------"};
				_expected = 13;
				_received = _obj.countBoards(vector <string>(layout, layout+sizeof(layout)/sizeof(string))); break;
			}
			case 3:
			{
				string layout[] = {"||-||-|||-"
				                  ,"||--||||||"
				                  ,"-|-|||||||"
				                  ,"-|-||-||-|"
				                  ,"||--|-||||"
				                  ,"||||||-||-"
				                  ,"|-||||||||"
				                  ,"||||||||||"
				                  ,"||---|--||"
				                  ,"-||-||||||"};
				_expected = 41;
				_received = _obj.countBoards(vector <string>(layout, layout+sizeof(layout)/sizeof(string))); break;
			}
			case 4:
			{
				string layout[] = {"-||--|"
				                  ,"||||||"
				                  ,"|||-|-"
				                  ,"-||||-"
				                  ,"||||-|"
				                  ,"||-||-"};
				_expected = 19;
				_received = _obj.countBoards(vector <string>(layout, layout+sizeof(layout)/sizeof(string))); break;
			}
			/*case 5:
			{
				string layout[] = ;
				_expected = ;
				_received = _obj.countBoards(vector <string>(layout, layout+sizeof(layout)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string layout[] = ;
				_expected = ;
				_received = _obj.countBoards(vector <string>(layout, layout+sizeof(layout)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string layout[] = ;
				_expected = ;
				_received = _obj.countBoards(vector <string>(layout, layout+sizeof(layout)/sizeof(string))); break;
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
