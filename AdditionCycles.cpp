// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Start with any integer between 00 and 99, inclusive, written as two digits (use a leading zero if the number is less than 10).  Add the two digits together.  Now concatenate the rightmost digit of the first number with the rightmost digit of the sum to get a new number.  If you repeat this process enough times, you'll end up back at the original number.  For example:

  Combine Second Digits of
  Start With    Add Digits    the Original and the Sum
  ------------------------------------------------------
  26     :   2+6 = 08   :   "6" and "8" = 68 
  68     :   6+8 = 14   :   "8" and "4" = 84
  84     :   8+4 = 12   :   "4" and "2" = 42
  42     :   4+2 = 06   :   "2" and "6" = 26

  In this case, it took us 4 steps to get back to where we started, so we would return 4.  Starting with n, return the number of steps it takes to get back to n.

  DEFINITION
  Class:AdditionCycles
  Method:cycleLength
  Parameters:int
  Returns:int
  Method signature:int cycleLength(int n)


  CONSTRAINTS
  -n will be between 0 and 99, inclusive.


  EXAMPLES

  0)
  26

  Returns: 4

  The example from the problem statement.  It goes 26->68->84->42->26, so there's 4 steps for the cycle.

  1)
  55

  Returns: 3

  The cycle is 55->50->05->55.  Remember to treat numbers under 10 as though there was a leading zero.

  2)
  0

  Returns: 1

  Zero comes back to zero at every step - so the length of the cycle is one (00->00)

  3)
  71

  Returns: 12



*/
// END CUT HERE
#line 61 "AdditionCycles.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class AdditionCycles {
public:
  int cycleLength(int n) {
    int ret = 0;
    int n2 = n;
    do {
      int u = n2 % 10;
      int t = n2 / 10;
      int t2 = u;
      int u2 = (u+t) % 10;
      n2 = t2 * 10 + u2;
      ++ret;
      //      cout << "inside ";
    } while (n2 != n);
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
      cout << "Testing AdditionCycles (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456211697;
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
      AdditionCycles _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int n = 26;
	    _expected = 4;
	    _received = _obj.cycleLength(n); break;
	  }
	case 1:
	  {
	    int n = 55;
	    _expected = 3;
	    _received = _obj.cycleLength(n); break;
	  }
	case 2:
	  {
	    int n = 0;
	    _expected = 1;
	    _received = _obj.cycleLength(n); break;
	  }
	case 3:
	  {
	    int n = 71;
	    _expected = 12;
	    _received = _obj.cycleLength(n); break;
	  }
	  /*case 4:
	    {
	    int n = ;
	    _expected = ;
	    _received = _obj.cycleLength(n); break;
	    }*/
	  /*case 5:
	    {
	    int n = ;
	    _expected = ;
	    _received = _obj.cycleLength(n); break;
	    }*/
	  /*case 6:
	    {
	    int n = ;
	    _expected = ;
	    _received = _obj.cycleLength(n); break;
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
