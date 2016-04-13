// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Little Josh has found several sticks that are each 1 inch long.  He wants to form a rectangle with the biggest possible area, using these sticks as the perimeter.  He is allowed to glue sticks together, but he is not allowed to break a single stick into multiple shorter sticks.

  For example, if Josh has 11 sticks, he can create a 2 x 3 rectangle using 10 sticks.  This rectangle has an area of 6 square inches, which is the biggest area that can be achieved in this case.

  You will be given an int N, and you must return the maximal area (in square inches) of a rectangle that can be created using N or less sticks.


  DEFINITION
  Class:BiggestRectangleEasy
  Method:findArea
  Parameters:int
  Returns:int
  Method signature:int findArea(int N)


  CONSTRAINTS
  -N will be between 4 and 10000, inclusive.


  EXAMPLES

  0)
  11

  Returns: 6

  The example from the problem statement.

  1)
  5

  Returns: 1

  The only rectangle that can be created is a square with 1 inch side.

  2)
  64

  Returns: 256

  Josh can create a square with the 16 inches side.

  3)
  753

  Returns: 35344

  4)
  7254

  Returns: 3288782

*/
// END CUT HERE
#line 59 "BiggestRectangleEasy.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BiggestRectangleEasy {
public:
  int findArea(int N) {
    int ret = -69;
    if (N % 2 != 0)
      --N;
    N /= 2;
    int n1 = N/2;
    int n2 = N - n1;
    ret = n1*n2;
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
      cout << "Testing BiggestRectangleEasy (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456072660;
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
      BiggestRectangleEasy _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int N = 11;
	    _expected = 6;
	    _received = _obj.findArea(N); break;
	  }
	case 1:
	  {
	    int N = 5;
	    _expected = 1;
	    _received = _obj.findArea(N); break;
	  }
	case 2:
	  {
	    int N = 64;
	    _expected = 256;
	    _received = _obj.findArea(N); break;
	  }
	case 3:
	  {
	    int N = 753;
	    _expected = 35344;
	    _received = _obj.findArea(N); break;
	  }
	case 4:
	  {
	    int N = 7254;
	    _expected = 3288782;
	    _received = _obj.findArea(N); break;
	  }
	  /*case 5:
	    {
	    int N = ;
	    _expected = ;
	    _received = _obj.findArea(N); break;
	    }*/
	  /*case 6:
	    {
	    int N = ;
	    _expected = ;
	    _received = _obj.findArea(N); break;
	    }*/
	  /*case 7:
	    {
	    int N = ;
	    _expected = ;
	    _received = _obj.findArea(N); break;
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
