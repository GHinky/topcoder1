// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  A string is considered to be a composite of several maximal segments of identical characters. For example, "aaabbaaac" is a composite of the segments: "aaa", "bb", "aaa" and "c". Given a string, return the average length of all the segments which form that string.


  DEFINITION
  Class:StringSegment
  Method:average
  Parameters:string
  Returns:double
  Method signature:double average(string s)


  NOTES
  -A return value with either an absolute or relative error of less than 1.0E-9 is considered correct.


  CONSTRAINTS
  -s will contain between 1 and 50 characters, inclusive.
  -s will contain only lowercase letters ('a'-'z').


  EXAMPLES

  0)
  "aaabbaaac"

  Returns: 2.25

  Average length of all the segments = ( 3 + 2 + 3 + 1 ) / 4 = 2.25

  1)
  "aabbccdd"

  Returns: 2.0



  2)
  "abba"

  Returns: 1.3333333333333333



*/
// END CUT HERE
#line 50 "StringSegment.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class StringSegment {
public:
  double average(string s) {
    double ret = s.size();
    int types = 0; // types of chars in s
    for (int i=0; i!=s.size(); ++types) {
      char sin = s[i];
      int j;
      for (j=i+1; s[j] == sin; ++j) {
      }
      i = j;
    }
    ret /= types;
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
      cout << "Testing StringSegment (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456117594;
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
      StringSegment _obj;
      double _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string s = "aaabbaaac";
	    _expected = 2.25;
	    _received = _obj.average(s); break;
	  }
	case 1:
	  {
	    string s = "aabbccdd";
	    _expected = 2.0;
	    _received = _obj.average(s); break;
	  }
	case 2:
	  {
	    string s = "abba";
	    _expected = 1.3333333333333333;
	    _received = _obj.average(s); break;
	  }
	  /*case 3:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.average(s); break;
	    }*/
	  /*case 4:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.average(s); break;
	    }*/
	  /*case 5:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.average(s); break;
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
