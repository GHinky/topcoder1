// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  There is an unsafe way to write encrypted messages that works as follows.  At most one contiguous substring of the original string is reversed and enclosed in square brackets.  For example, the encrypted string "he[row oll]ld" represents the string "hello world".  You will be given s, a string encrypted with this method, and you must return the original unencrypted string.



  DEFINITION
  Class:ReversingBrackets
  Method:removeBrackets
  Parameters:string
  Returns:string
  Method signature:string removeBrackets(string s)


  CONSTRAINTS
  -s will contain between 1 and 50 characters, inclusive.
  -Each character of s will be a lowercase letter ('a'-'z'), a space (' ') or a bracket ('[' and ']').
  -s will contain either no bracket or exactly one '[' and one ']', and the '[' character will appear before the ']'.


  EXAMPLES

  0)
  "he[row oll]ld"

  Returns: "hello world"

  The example from the problem statement.

  1)
  "ab[edc]f"

  Returns: "abcdef"



  2)
  "topcoder"

  Returns: "topcoder"

  Note that there can be no brackets.

  3)
  "[desrever lla]"

  Returns: "all reversed"

*/
// END CUT HERE
#line 54 "ReversingBrackets.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class ReversingBrackets {
public:
  string removeBrackets(string s) {
    string ret;
    typedef string::iterator iter;
    iter  i, j;
    i = find (s.begin(), s.end(), '[');
    j = find (s.begin(), s.end(), ']');
    //cout << "*i, *j" << *i << *j << endl;

    if (i != s.end()) {
      string temp(s.begin(), i);
      //cout << "temp = " << temp << endl;
      ret += temp;
      string temp2;
      reverse_copy(i+1, j, back_inserter(temp2));
      ret += temp2;
      if (j+1 != s.end()) {
	string temp3(j+1, s.end());
	ret += temp3;
      }
    } else {
      ret = s;
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
      cout << "Testing ReversingBrackets (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456070982;
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
      ReversingBrackets _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string s = "he[row oll]ld";
	    _expected = "hello world";
	    _received = _obj.removeBrackets(s); break;
	  }
	case 1:
	  {
	    string s = "ab[edc]f";
	    _expected = "abcdef";
	    _received = _obj.removeBrackets(s); break;
	  }
	case 2:
	  {
	    string s = "topcoder";
	    _expected = "topcoder";
	    _received = _obj.removeBrackets(s); break;
	  }
	case 3:
	  {
	    string s = "[desrever lla]";
	    _expected = "all reversed";
	    _received = _obj.removeBrackets(s); break;
	  }
	  /*case 4:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.removeBrackets(s); break;
	    }*/
	  /*case 5:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.removeBrackets(s); break;
	    }*/
	  /*case 6:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.removeBrackets(s); break;
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
