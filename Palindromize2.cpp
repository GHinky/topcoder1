// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  A palindrome is a string that reads the same from left to right as it does from right to left. 
  Given a String s, return a palindrome that is produced by changing the minimum possible 
  number of characters in s. Changing a character means replacing it with any single
  character at the same position.  You are not allowed to remove or add any characters.
  If there are multiple answers, return the one that comes first alphabetically.


  DEFINITION
  Class:Palindromize2
  Method:minChanges
  Parameters:string
  Returns:string
  Method signature:string minChanges(string s)


  CONSTRAINTS
  -s will contain between 1 and 50 characters, inclusive.
  -Each character of s will be a lowercase letter ('a'-'z').


  EXAMPLES

  0)
  "ameba"

  Returns: "abeba"

  You can get "abeba" or "amema" with only 1 change. Among those two, "abeba" comes earlier alphabetically.

  1)
  "cigartragic"

  Returns: "cigartragic"

  The input is already a palindrome, so the best choice is to do 0 changes.

  2)
  "abcdef"

  Returns: "abccba"



  3)
  "cxbpaxz"

  Returns: "cxapaxc"



*/
// END CUT HERE
#line 58 "Palindromize2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class Palindromize2 {
public:
  string minChanges(string s) {
    string ret = s;
    for (int i = 0, j = s.size() - 1; i != s.size() / 2; ++i, --j) {
      if (s[i] != s[j]) {
	s[i] = (s[i] < s[j])? s[i] : s[j];
	s[j] = s[i];
      }
    }
    ret = s;
    return s;
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
      cout << "Testing Palindromize2 (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456225545;
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
      Palindromize2 _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string s = "ameba";
	    _expected = "abeba";
	    _received = _obj.minChanges(s); break;
	  }
	case 1:
	  {
	    string s = "cigartragic";
	    _expected = "cigartragic";
	    _received = _obj.minChanges(s); break;
	  }
	case 2:
	  {
	    string s = "abcdef";
	    _expected = "abccba";
	    _received = _obj.minChanges(s); break;
	  }
	case 3:
	  {
	    string s = "cxbpaxz";
	    _expected = "cxapaxc";
	    _received = _obj.minChanges(s); break;
	  }
	  /*case 4:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.minChanges(s); break;
	    }*/
	  /*case 5:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.minChanges(s); break;
	    }*/
	  /*case 6:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.minChanges(s); break;
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
