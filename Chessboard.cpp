// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  A 8x8 chessboard is usually marked as follows: rows are marked by digits, 1 through 8, and columns are marked by letters, 'a' through 'h'. A cell is described by its column mark and then its row mark, like "e4".

  While working on a chess program, you need to convert these descriptions into your internal cell numbers and back. Internally, cells are numbered row-by-row from 1 to 64 in your program, i.e., cell "a1" has number 1, cell "b1" has number 2, cell "c1" has number 3, ..., cell "h8" has number 64.

  Given a String cell, describing either the cell mark or the cell number, change the notation (i.e., if you're given the mark you need to return the number, and vice versa).

  DEFINITION
  Class:Chessboard
  Method:changeNotation
  Parameters:string
  Returns:string
  Method signature:string changeNotation(string cell)


  CONSTRAINTS
  -cell will contain either a cell mark or a cell number.
  -If cell contains a cell mark, it will contain exactly 2 characters: a lowercase letter between 'a' and 'h', inclusive, followed by a digit between '1' and '8', inclusive.
  -If cell contains a cell number, it will be an integer between 1 and 64, inclusive, without leading zeros.


  EXAMPLES

  0)
  "1"

  Returns: "a1"

  1)
  "2"

  Returns: "b1"

  2)
  "26"

  Returns: "b4"

  3)
  "c1"

  Returns: "3"

  4)
  "e4"

  Returns: "29"

  5)
  "h8"

  Returns: "64"

*/
// END CUT HERE
#line 59 "Chessboard.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class Chessboard {
public:
  string changeNotation(string cell) {
    string ret;
    if (isalpha(cell[0])) {
      char ch = cell[0];
      stringstream oss;
      oss << cell[1];
      int ih;
      oss >> ih;
      int i = (ih - 1) * 8 + (ch - 'a' + 1);
      stringstream oss2;
      oss2 << i;
      oss2 >> ret;
    } else {
      stringstream oss;
      oss << cell;
      int i;
      oss >> i;
      int r = (i - 1) / 8 + 1;
      int c = (i - 1) % 8;
      char ch = 'a' + c;
      ret.push_back(ch);
      stringstream oss2;
      oss2 << r;
      char ih;
      oss2 >> ih;
      ret.push_back(ih);
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
      cout << "Testing Chessboard (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456287529;
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
      Chessboard _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string cell = "1";
	    _expected = "a1";
	    _received = _obj.changeNotation(cell); break;
	  }
	case 1:
	  {
	    string cell = "2";
	    _expected = "b1";
	    _received = _obj.changeNotation(cell); break;
	  }
	case 2:
	  {
	    string cell = "26";
	    _expected = "b4";
	    _received = _obj.changeNotation(cell); break;
	  }
	case 3:
	  {
	    string cell = "c1";
	    _expected = "3";
	    _received = _obj.changeNotation(cell); break;
	  }
	case 4:
	  {
	    string cell = "e4";
	    _expected = "29";
	    _received = _obj.changeNotation(cell); break;
	  }
	case 5:
	  {
	    string cell = "h8";
	    _expected = "64";
	    _received = _obj.changeNotation(cell); break;
	  }
	  /*case 6:
	    {
	    string cell = ;
	    _expected = ;
	    _received = _obj.changeNotation(cell); break;
	    }*/
	  /*case 7:
	    {
	    string cell = ;
	    _expected = ;
	    _received = _obj.changeNotation(cell); break;
	    }*/
	  /*case 8:
	    {
	    string cell = ;
	    _expected = ;
	    _received = _obj.changeNotation(cell); break;
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
