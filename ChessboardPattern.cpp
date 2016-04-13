// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  A chessboard pattern is a pattern that satisfies the following conditions:



  The pattern has a rectangular shape.
  The pattern contains only the characters '.' (a dot) and 'X' (an uppercase letter X). 
  No two symbols that are horizontally or vertically adjacent are the same.
  The symbol in the lower left corner of the pattern is '.' (a dot).



  You are given two ints rows and columns. 
  Write a method that computes the chessboard pattern with these dimensions, and returns
  it in a vector <string>. The elements of the return value correspond to
  rows of the pattern. Specifically, the first character of the last element of the return value represents the lower left corner (see example 0).


  DEFINITION
  Class:ChessboardPattern
  Method:makeChessboard
  Parameters:int, int
  Returns:vector <string>
  Method signature:vector <string> makeChessboard(int rows, int columns)


  CONSTRAINTS
  -rows will be between 1 and 50, inclusive.
  -columns will be between 1 and 50, inclusive.


  EXAMPLES

  0)
  8
  8

  Returns: {"X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X" }

  A standard chessboard. Note that the last element starts with a dot.

  1)
  1
  20

  Returns: {".X.X.X.X.X.X.X.X.X.X" }

  A single row is a special case of a rectangle.

  2)
  5
  1

  Returns: {".", "X", ".", "X", "." }

  And so is a single column.

  3)
  5
  13

  Returns: {".X.X.X.X.X.X.", "X.X.X.X.X.X.X", ".X.X.X.X.X.X.", "X.X.X.X.X.X.X", ".X.X.X.X.X.X." }



*/
// END CUT HERE
#line 72 "ChessboardPattern.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class ChessboardPattern {
public:
  vector <string> makeChessboard(int rows, int columns) {
    VS ret;
    string ldot, lX;
    char dot = '.';
    char x = 'X';
    for (int i = 0; i != columns; ++i) {
      if (i%2 == 0) {
	ldot.push_back(dot);
	lX.push_back(x);
      }
      else {
	ldot.push_back(x);
	lX.push_back(dot);
      }
    }
    //cout << "ldot = " << ldot << endl;
    //cout << "lX = " << lX << endl;
    if (rows%2 == 0) {
      for (int i = 0; i != rows; ++i) {
	if (i%2 == 0)
	  ret.push_back(lX);
	else
	  ret.push_back(ldot);
      }
    } else {
      for (int i = 0; i != rows; ++i) {
	if (i%2 == 0)
	  ret.push_back(ldot);
	else
	  ret.push_back(lX);
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
      cout << "Testing ChessboardPattern (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456220587;
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
      ChessboardPattern _obj;
      vector <string> _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int rows = 8;
	    int columns = 8;
	    string __expected[] = {"X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X", "X.X.X.X.", ".X.X.X.X" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.makeChessboard(rows, columns); break;
	  }
	case 1:
	  {
	    int rows = 1;
	    int columns = 20;
	    string __expected[] = {".X.X.X.X.X.X.X.X.X.X" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.makeChessboard(rows, columns); break;
	  }
	case 2:
	  {
	    int rows = 5;
	    int columns = 1;
	    string __expected[] = {".", "X", ".", "X", "." };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.makeChessboard(rows, columns); break;
	  }
	case 3:
	  {
	    int rows = 5;
	    int columns = 13;
	    string __expected[] = {".X.X.X.X.X.X.", "X.X.X.X.X.X.X", ".X.X.X.X.X.X.", "X.X.X.X.X.X.X", ".X.X.X.X.X.X." };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.makeChessboard(rows, columns); break;
	  }
	  /*case 4:
	    {
	    int rows = ;
	    int columns = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.makeChessboard(rows, columns); break;
	    }*/
	  /*case 5:
	    {
	    int rows = ;
	    int columns = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.makeChessboard(rows, columns); break;
	    }*/
	  /*case 6:
	    {
	    int rows = ;
	    int columns = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.makeChessboard(rows, columns); break;
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
	  cout << "           Expected: {";
	  for (unsigned i = 0; i < _expected.size(); i++)
	    {
	      if (i) cout << ",";
	      cout << " \"" << _expected[i] << "\"";
	    }
	  cout << " }" << endl;
	  cout << "           Received: {";
	  for (unsigned i = 0; i < _received.size(); i++)
	    {
	      if (i) cout << ",";
	      cout << " \"" << _received[i] << "\"";
	    }
	  cout << " }" << endl;
	}
    }
}

// END CUT HERE
