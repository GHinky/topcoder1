// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  A palindrome is a string that reads the same from left to right as it does from right to left.  Given a string s, return the shortest palindrome that can be produced by adding zero or more characters to the right end of s.  There is always one unique answer.


  DEFINITION
  Class:Palindromize
  Method:minAdds
  Parameters:string
  Returns:string
  Method signature:string minAdds(string s)


  CONSTRAINTS
  -s will contain between 1 and 50 characters, inclusive.
  -Each character of s will be a lowercase letter ('a'-'z').


  EXAMPLES

  0)
  "add"

  Returns: "adda"

  Add 'a' to make a palindrome. "adddda" is also a valid palindrome, but it is not the shortest possible one.

  1)
  "cigartragic"

  Returns: "cigartragic"

  This is already a palindrome, so the shortest solution is to add 0 letters.

  2)
  "redocpot"

  Returns: "redocpotopcoder"



  3)
  "acaba"

  Returns: "acabaca"



  4)
  "abczyxyz"

  Returns: "abczyxyzcba"



*/
// END CUT HERE
#line 61 "Palindromize.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class Palindromize {
public:
  static bool palindrome (string s) {
    bool ret = false;
    string s2 = s;
    reverse(s.begin(), s.end());
    if (s2 == s)
      ret = true;
    return ret;
  }
  string minAdds(string s) {
    string sb = s; // sbackup
    string ret = sb;
    typedef string::iterator iter;
    iter i = s.begin();
    while (!palindrome (string (i, s.end())) ) {
      ++i;
    }
    string toadd = string(s.begin(), i);
    reverse (toadd.begin(), toadd.end());
    ret = sb + toadd;
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
      cout << "Testing Palindromize (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456222994;
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
      Palindromize _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string s = "add";
	    _expected = "adda";
	    _received = _obj.minAdds(s); break;
	  }
	case 1:
	  {
	    string s = "cigartragic";
	    _expected = "cigartragic";
	    _received = _obj.minAdds(s); break;
	  }
	case 2:
	  {
	    string s = "redocpot";
	    _expected = "redocpotopcoder";
	    _received = _obj.minAdds(s); break;
	  }
	case 3:
	  {
	    string s = "acaba";
	    _expected = "acabaca";
	    _received = _obj.minAdds(s); break;
	  }
	case 4:
	  {
	    string s = "abczyxyz";
	    _expected = "abczyxyzcba";
	    _received = _obj.minAdds(s); break;
	  }
	  /*case 5:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.minAdds(s); break;
	    }*/
	  /*case 6:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.minAdds(s); break;
	    }*/
	  /*case 7:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.minAdds(s); break;
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
