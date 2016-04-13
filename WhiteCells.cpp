// BEGIN CUT HERE
/*
PROBLEM STATEMENT

A chessboard is an 8 x 8 grid of cells. Within each column and within each row, cells alternate between black and white. The cell in the upper left corner (0, 0) is white. You are given a vector <string> board, where the j-th character of the i-th element is 'F' if the cell in the j-th column from the left and i-th row from the top is occupied, or '.' if it is empty. Return the number of occupied white cells on the board.



DEFINITION
Class:WhiteCells
Method:countOccupied
Parameters:vector <string>
Returns:int
Method signature:int countOccupied(vector <string> board)


CONSTRAINTS
-board will contain exactly 8 elements.
-Each element of board will contain exactly 8 characters.
-board will contain only the characters '.' and 'F'.


EXAMPLES

0)
{"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}

Returns: 0



1)
{"FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF",
 "FFFFFFFF"}

Returns: 32



2)
{".F.F...F",
 "F...F.F.",
 "...F.F.F",
 "F.F...F.",
 ".F...F..",
 "F...F.F.",
 ".F.F.F.F",
 "..FF..F."}

Returns: 1



3)
{"........",
 "..F.....",
 ".....F..",
 ".....F..",
 "........",
 "........",
 ".......F",
 ".F......"}

Returns: 2



*/
// END CUT HERE
#line 84 "WhiteCells.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class WhiteCells {
public:
  int countOccupied(vector <string> board) {
    int ret = 0;
    for (int i = 0; i != 8; ++i) {
      for (int j = 0; j != 8; ++j) {
	if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 != 0) && (j % 2 != 0))) { // if (white)
	  if (board[i][j] == 'F')
	    ++ret;
	}
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
		cout << "Testing WhiteCells (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456403518;
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
		WhiteCells _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........"};
				_expected = 0;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF"};
				_expected = 32;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {".F.F...F",
				                  "F...F.F.",
				                  "...F.F.F",
				                  "F.F...F.",
				                  ".F...F..",
				                  "F...F.F.",
				                  ".F.F.F.F",
				                  "..FF..F."};
				_expected = 1;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"........",
				                  "..F.....",
				                  ".....F..",
				                  ".....F..",
				                  "........",
				                  "........",
				                  ".......F",
				                  ".F......"};
				_expected = 2;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 4:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
