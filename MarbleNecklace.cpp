// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Consider a necklace composed of marbles of various colors arranged in a circle.  The colors are represented by uppercase letters.  We can describe a necklace with a string of characters as follows: start with any marble and go through all the marbles in either a clockwise or counter-clockwise direction, until the starting marble is reached again, meanwhile appending to the string the colors of the marbles in the order they are visited.  Obviously, there could be many different strings describing the same necklace.  For example, the necklace described by the string "CDAB" can also be described by seven other strings (see example 0).

  You are given a string necklace containing the description of a necklace.  Return the description for that necklace that comes earliest alphabetically.


  DEFINITION
  Class:MarbleNecklace
  Method:normalize
  Parameters:string
  Returns:string
  Method signature:string normalize(string necklace)


  CONSTRAINTS
  -necklace will contain between 1 and 50 characters, inclusive.
  -Each character of necklace will be an uppercase letter ('A'-'Z').


  EXAMPLES

  0)
  "CDAB"

  Returns: "ABCD"

  This necklace can be described by the eight strings "CDAB", "DABC", "ABCD", "BCDA", "CBAD", "DCBA", "ADCB", "BADC". "ABCD" comes first lexicographically.

  1)
  "RGB"

  Returns: "BGR"



  2)
  "TOPCODER"

  Returns: "CODERTOP"

  3)
  "SONBZELGFEQMSULZCNPJODOWPEWLHJFOEW"

  Returns: "BNOSWEOFJHLWEPWODOJPNCZLUSMQEFGLEZ"

*/
// END CUT HERE
#line 51 "MarbleNecklace.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class MarbleNecklace {
public:
  string normalize(string necklace) {
    string ret = necklace;
    string n = necklace;
    vector<string> all;
    all.push_back(n);
    do {
      char first = n[0];
      n.erase (n.begin(), n.begin()+1);
      n.push_back(first);
      all.push_back(n);
    } while (n != necklace);

    //counterclockwise also push_back
    int temp_size = all.size();
    for (int i = 0; i != temp_size; ++i) {
      string temp = all[i];
      reverse (temp.begin(), temp.end());
      all.push_back (temp);
    }

    
    
    
    for (int i = 0; i != all.size(); ++i) {
      ret = min (ret, all[i]);
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
      cout << "Testing MarbleNecklace (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456215637;
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
      MarbleNecklace _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string necklace = "CDAB";
	    _expected = "ABCD";
	    _received = _obj.normalize(necklace); break;
	  }
	case 1:
	  {
	    string necklace = "RGB";
	    _expected = "BGR";
	    _received = _obj.normalize(necklace); break;
	  }
	case 2:
	  {
	    string necklace = "TOPCODER";
	    _expected = "CODERTOP";
	    _received = _obj.normalize(necklace); break;
	  }
	case 3:
	  {
	    string necklace = "SONBZELGFEQMSULZCNPJODOWPEWLHJFOEW";
	    _expected = "BNOSWEOFJHLWEPWODOJPNCZLUSMQEFGLEZ";
	    _received = _obj.normalize(necklace); break;
	  }
	  /*case 4:
	    {
	    string necklace = ;
	    _expected = ;
	    _received = _obj.normalize(necklace); break;
	    }*/
	  /*case 5:
	    {
	    string necklace = ;
	    _expected = ;
	    _received = _obj.normalize(necklace); break;
	    }*/
	  /*case 6:
	    {
	    string necklace = ;
	    _expected = ;
	    _received = _obj.normalize(necklace); break;
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
