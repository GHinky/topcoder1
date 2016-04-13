// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  In some forms of geometry, like the kind used in geographical longitude/latitude measurements, angles are measured in base-60.  The base unit is the degree.  One degree contains 60 minutes, and one minute contains 60 seconds.


  You will be given the measurement of an angle in degrees, minutes, and seconds.  Return the given angle in radians.  Note that n degrees is equal to  n*PI/180 radians.


  DEFINITION
  Class:DegreesToRadians
  Method:convertToRadians
  Parameters:int, int, int
  Returns:double
  Method signature:double convertToRadians(int degrees, int minutes, int seconds)


  NOTES
  -The return value must have an absolute or relative error less than 1e-9.


  CONSTRAINTS
  -degrees will be between 0 and 359, inclusive.
  -minutes will be between 0 and 59, inclusive.
  -seconds will be between 0 and 59, inclusive.


  EXAMPLES

  0)
  0
  0
  0

  Returns: 0.0

  Zero is zero, in either measurement system.

  1)
  180
  0
  0

  Returns: 3.141592653589793

  180 degrees is PI radians.

  2)
  359
  59
  59

  Returns: 6.283180459042776

  This is as close to a full circle as it gets.

  3)
  23
  30
  5

  Returns: 0.41017661490272295

*/
// END CUT HERE
#line 68 "DegreesToRadians.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath> // for M_PI if need be
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class DegreesToRadians {
public:
  double convertToRadians(int degrees, int minutes, int seconds) {
    const double pi = 3.141592653589793;
    double ret = 0;
    //double deg = degrees + minutes / 60 + seconds / 60 / 60;
    double sec = degrees*60*60 + minutes * 60 + seconds;
    //ret = deg * pi / 180;
    ret = (sec*pi) / (60*60*180);
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
      cout << "Testing DegreesToRadians (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456286127;
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
      DegreesToRadians _obj;
      double _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int degrees = 0;
	    int minutes = 0;
	    int seconds = 0;
	    _expected = 0.0;
	    _received = _obj.convertToRadians(degrees, minutes, seconds); break;
	  }
	case 1:
	  {
	    int degrees = 180;
	    int minutes = 0;
	    int seconds = 0;
	    _expected = 3.141592653589793;
	    _received = _obj.convertToRadians(degrees, minutes, seconds); break;
	  }
	case 2:
	  {
	    int degrees = 359;
	    int minutes = 59;
	    int seconds = 59;
	    _expected = 6.283180459042776;
	    _received = _obj.convertToRadians(degrees, minutes, seconds); break;
	  }
	case 3:
	  {
	    int degrees = 23;
	    int minutes = 30;
	    int seconds = 5;
	    _expected = 0.41017661490272295;
	    _received = _obj.convertToRadians(degrees, minutes, seconds); break;
	  }
	  /*case 4:
	    {
	    int degrees = ;
	    int minutes = ;
	    int seconds = ;
	    _expected = ;
	    _received = _obj.convertToRadians(degrees, minutes, seconds); break;
	    }*/
	  /*case 5:
	    {
	    int degrees = ;
	    int minutes = ;
	    int seconds = ;
	    _expected = ;
	    _received = _obj.convertToRadians(degrees, minutes, seconds); break;
	    }*/
	  /*case 6:
	    {
	    int degrees = ;
	    int minutes = ;
	    int seconds = ;
	    _expected = ;
	    _received = _obj.convertToRadians(degrees, minutes, seconds); break;
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
