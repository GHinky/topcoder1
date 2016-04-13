// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  You are given two line segments on the plane. Each segment is parallel to either the X axis or the Y axis. Your task is to figure out how the segments intersect and return one of the following strings:

  "NO", if the segments do not intersect
  "POINT", if the segments' intersection forms a point
  "SEGMENT", if the segments' intersection forms a line segment



  The segments will be given as two int[]s s1 and s2. Each of them will contain four integers x1, y1, x2, y2 (in that order) where (x1, y1), (x2, y2) are segment endpoints.


  DEFINITION
  Class:Segments
  Method:intersection
  Parameters:vector <int>, vector <int>
  Returns:string
  Method signature:string intersection(vector <int> s1, vector <int> s2)


  CONSTRAINTS
  -       Each of s1 and s2 will contain exactly four elements
  -       All integers in s1 and s2 will be between -1000 and 1000, inclusive
  -       Each segment will be parallel to either the X axis or the Y axis 


  EXAMPLES

  0)
  {0, 0, 0, 1}	
  {1, 0, 1, 1}

  Returns: "NO"

  The segments are parallel and there is no intersection.

  1)
  {0, 0, 0, 1}
  {0, 1, 0, 2}

  Returns: "POINT"

  The segments are located on the same line and have only one common point (0,1).

  2)
  {0, -1, 0, 1}
  {-1, 0, 1, 0}

  Returns: "POINT"

  The segments intersect at point (0,0).

  3)
  {0, 0, 2, 0}
  {1, 0, 10, 0}

  Returns: "SEGMENT"

  The segments have a common line segment from (1,0) to (2,0).

  4)
  {5, 5, 5, 5}
  {6, 6, 6, 6}

  Returns: "NO"

  These are two different points.

  5)
  {10, 0, -10, 0}
  {5, 0, -5, 0}

  Returns: "SEGMENT"

  The segments have a common line segment from (-5,0) to (5,0).

*/
// END CUT HERE
#line 83 "Segments.cpp"
#include <string>
#include <vector>
using namespace std;
class Segments {
public:
  string intersection(vector <int> s1, vector <int> s2) {
    string res;
    int s1x1 = s1[0];
    int s1y1 = s1[1];
    int s1x2 = s1[2];
    int s1y2 = s1[3];

    int s2x1 = s2[0];
    int s2y1 = s2[1];
    int s2x2 = s2[2];
    int s2y2 = s2[3];

    

    return res;
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
      cout << "Testing Segments (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1454952673;
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
      Segments _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int s1[] = {0, 0, 0, 1}	;
	    int s2[] = {1, 0, 1, 1};
	    _expected = "NO";
	    _received = _obj.intersection(vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int s1[] = {0, 0, 0, 1};
	    int s2[] = {0, 1, 0, 2};
	    _expected = "POINT";
	    _received = _obj.intersection(vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int s1[] = {0, -1, 0, 1};
	    int s2[] = {-1, 0, 1, 0};
	    _expected = "POINT";
	    _received = _obj.intersection(vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int s1[] = {0, 0, 2, 0};
	    int s2[] = {1, 0, 10, 0};
	    _expected = "SEGMENT";
	    _received = _obj.intersection(vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int))); break;
	  }
	case 4:
	  {
	    int s1[] = {5, 5, 5, 5};
	    int s2[] = {6, 6, 6, 6};
	    _expected = "NO";
	    _received = _obj.intersection(vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int))); break;
	  }
	case 5:
	  {
	    int s1[] = {10, 0, -10, 0};
	    int s2[] = {5, 0, -5, 0};
	    _expected = "SEGMENT";
	    _received = _obj.intersection(vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int))); break;
	  }
	  /*case 6:
	    {
	    int s1[] = ;
	    int s2[] = ;
	    _expected = ;
	    _received = _obj.intersection(vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int))); break;
	    }*/
	  /*case 7:
	    {
	    int s1[] = ;
	    int s2[] = ;
	    _expected = ;
	    _received = _obj.intersection(vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int))); break;
	    }*/
	  /*case 8:
	    {
	    int s1[] = ;
	    int s2[] = ;
	    _expected = ;
	    _received = _obj.intersection(vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int))); break;
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
