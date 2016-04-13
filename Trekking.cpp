// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  You are planning a small trek over at the local mountain range.  It will involve walking for several days and spending the nights in a tent.  The mountains are not very friendly (they're steep and rocky), and therefore many locations are not suitable for setting up a camp.  You will be given a string trail which represents the locations in the order in which you are visiting them.  trail[i] is '.' if it's possible to camp at the i-th location, and '^' otherwise.

  You have several alternative plans to follow, given in the vector <string> plans.  plans[i][j] is lowercase 'w' if according to the i-th plan you are going to walk through location j, and uppercase 'C' if you are going to camp there.  A plan is invalid if it involves camping at a location that's not suitable for it.

  Given trail and plans return the minimum number of nights that must be spent in the mountains, according to one of the valid plans.  If all plans are invalid, return -1

  DEFINITION
  Class:Trekking
  Method:findCamps
  Parameters:string, vector <string>
  Returns:int
  Method signature:int findCamps(string trail, vector <string> plans)


  CONSTRAINTS
  -trail will contain between 2 and 50 characters, inclusive.
  -trail will contain only the characters '.' and '^'.
  -plans will contain between 2 and 50 elements, inclusive.
  -Each element of plans will contain the same number of characters as trail.
  -Each element of plans will contain only the characters 'w' and 'C'.


  EXAMPLES

  0)
  "^^....^^^..."
  {"CwwCwwCwwCww",
  "wwwCwCwwwCww",
  "wwwwCwwwwCww"}

  Returns: 2

  The first plan is not valid because it involves camping in the first visited location, which is not suitable for camping.  The other two plans are valid, but the third involves only two camps, so it's the best one.

  1)
  "^^^^"
  {"wwww",
  "wwwC"
  }

  Returns: 0



  2)
  "^^.^^^^"
  {"wwCwwwC",
  "wwwCwww",
  "wCwwwCw"}

  Returns: -1



  3)
  "^^^^....^.^.^."
  {"wwwwCwwwwCwCwC",
  "wwwwCwwCwCwwwC",
  "wwwCwwwCwwwCww",
  "wwwwwCwwwCwwwC"}

  Returns: 3



  4)
  ".............."
  {"CwCwCwCwCwCwCw",
  "CwwCwwCwwCwwCw"}

  Returns: 5



*/
// END CUT HERE
#line 81 "Trekking.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class Trekking {
public:
  int camps (string t) {
    int ret = 0;
    for (int i = 0; i != t.size(); ++i) {
      if (t[i] == 'C')
	++ret;
    }
    return ret;
  }
  int findCamps(string trail, vector <string> plans) {
    int ret = 71;
    for (int i = 0; i != plans.size(); ++i) { // check each plan
      int c = camps (plans[i]);
      for (int j = 0; j != trail.length(); ++j) { // check each char in trail
	if (plans[i][j] == 'C' && trail[j] == '^') {
	  c = 70; // 70 => invalid plan
	}
      }
      ret = min (ret, c);
    }
    if (ret == 70) // all plans are invalid
      ret = -1;
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
      cout << "Testing Trekking (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456289030;
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
      Trekking _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string trail = "^^....^^^...";
	    string plans[] = {"CwwCwwCwwCww",
			      "wwwCwCwwwCww",
			      "wwwwCwwwwCww"};
	    _expected = 2;
	    _received = _obj.findCamps(trail, vector <string>(plans, plans+sizeof(plans)/sizeof(string))); break;
	  }
	case 1:
	  {
	    string trail = "^^^^";
	    string plans[] = {"wwww",
			      "wwwC"
	    };
	    _expected = 0;
	    _received = _obj.findCamps(trail, vector <string>(plans, plans+sizeof(plans)/sizeof(string))); break;
	  }
	case 2:
	  {
	    string trail = "^^.^^^^";
	    string plans[] = {"wwCwwwC",
			      "wwwCwww",
			      "wCwwwCw"};
	    _expected = -1;
	    _received = _obj.findCamps(trail, vector <string>(plans, plans+sizeof(plans)/sizeof(string))); break;
	  }
	case 3:
	  {
	    string trail = "^^^^....^.^.^.";
	    string plans[] = {"wwwwCwwwwCwCwC",
			      "wwwwCwwCwCwwwC",
			      "wwwCwwwCwwwCww",
			      "wwwwwCwwwCwwwC"};
	    _expected = 3;
	    _received = _obj.findCamps(trail, vector <string>(plans, plans+sizeof(plans)/sizeof(string))); break;
	  }
	case 4:
	  {
	    string trail = "..............";
	    string plans[] = {"CwCwCwCwCwCwCw",
			      "CwwCwwCwwCwwCw"};
	    _expected = 5;
	    _received = _obj.findCamps(trail, vector <string>(plans, plans+sizeof(plans)/sizeof(string))); break;
	  }
	  /*case 5:
	    {
	    string trail = ;
	    string plans[] = ;
	    _expected = ;
	    _received = _obj.findCamps(trail, vector <string>(plans, plans+sizeof(plans)/sizeof(string))); break;
	    }*/
	  /*case 6:
	    {
	    string trail = ;
	    string plans[] = ;
	    _expected = ;
	    _received = _obj.findCamps(trail, vector <string>(plans, plans+sizeof(plans)/sizeof(string))); break;
	    }*/
	  /*case 7:
	    {
	    string trail = ;
	    string plans[] = ;
	    _expected = ;
	    _received = _obj.findCamps(trail, vector <string>(plans, plans+sizeof(plans)/sizeof(string))); break;
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
