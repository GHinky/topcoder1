// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  A sequence of characters is called a fence if it consists of alternating '|' and '-' characters, like "|-|-|-|" or "-|-|" (quotes for clarity only). Notice that "|-||-|" or "--" are not fences, because each contains two equal characters adjacent to each other.

  Given a string s, find the longest consecutive substring of it that is a fence, and return its length.

  DEFINITION
  Class:FunnyFence
  Method:getLength
  Parameters:string
  Returns:int
  Method signature:int getLength(string s)


  CONSTRAINTS
  -s will contain between 1 and 50 characters, inclusive.
  -Each character of s will be either '|' or '-'.


  EXAMPLES

  0)
  "|-|-|"

  Returns: 5

  The entire string is a fence.

  1)
  "-|-|-|-"

  Returns: 7

  Still a fence.

  2)
  "||||||"

  Returns: 1

  A fence can be just 1 character long, so every 1 character substring here is a fence.

  3)
  "|-||-|-"

  Returns: 4

  The last 4 characters form the longest consecutive substring that is a fence.

  4)
  "|-|---|-|---|-|"

  Returns: 5

  "-|-|-" right in the middle gives the longest fence.

  5)
  "|||-||--|--|---|-||-|-|-|--||---||-||-||-|--||"

  Returns: 8

*/
// END CUT HERE
#line 66 "FunnyFence.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class FunnyFence {
public:
  int getLength(string s) {
    int ret = 1;
    for (int i = 0; i < s.size();) {
      int temp = 1;
      while ((s[i+1] != s[i]) && (i+1) < s.size()){
	++temp;
	++i;
      }
      ret = max (ret, temp);
      ++i;
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
      cout << "Testing FunnyFence (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456212278;
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
      FunnyFence _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string s = "|-|-|";
	    _expected = 5;
	    _received = _obj.getLength(s); break;
	  }
	case 1:
	  {
	    string s = "-|-|-|-";
	    _expected = 7;
	    _received = _obj.getLength(s); break;
	  }
	case 2:
	  {
	    string s = "||||||";
	    _expected = 1;
	    _received = _obj.getLength(s); break;
	  }
	case 3:
	  {
	    string s = "|-||-|-";
	    _expected = 4;
	    _received = _obj.getLength(s); break;
	  }
	case 4:
	  {
	    string s = "|-|---|-|---|-|";
	    _expected = 5;
	    _received = _obj.getLength(s); break;
	  }
	case 5:
	  {
	    string s = "|||-||--|--|---|-||-|-|-|--||---||-||-||-|--||";
	    _expected = 8;
	    _received = _obj.getLength(s); break;
	  }
	  /*case 6:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.getLength(s); break;
	    }*/
	  /*case 7:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.getLength(s); break;
	    }*/
	  /*case 8:
	    {
	    string s = ;
	    _expected = ;
	    _received = _obj.getLength(s); break;
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
