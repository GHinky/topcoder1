// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Some writers like to super-emphasize certain points by using multiple exclamation points instead of one.  For example, "This cheese is really great!!!  I like exclamation points!!!!!!!!"  Other times, writers express surprise by mixing exclamation points and question marks.  For example, "You really like THIS cheese!?!?!?!!!?".
   

  You are editing a document for publication, and you'd like to get rid of some of the extra punctuation.  Wherever you see a group of multiple consecutive exclamation points, replace it with a single exclamation point.  Wherever you see a group of multiple consecutive punctuation characters containing at least one question mark and zero or more exclamation points (and no other characters), replace that group with a single question mark.  See the examples for further clarification.  Return the string after these changes have been made.

  DEFINITION
  Class:PunctuationCleaner
  Method:clearExcess
  Parameters:string
  Returns:string
  Method signature:string clearExcess(string document)


  CONSTRAINTS
  -document will contain between 1 and 50 characters, inclusive.
  -document will contain only letters ('a'-'z', 'A'-'Z'), spaces (' '), question marks ('?'), and exclamation points ('!').


  EXAMPLES

  0)
  "This cheese is really great!!!!!"

  Returns: "This cheese is really great!"



  1)
  "You really like THIS cheese!?!?!?!!!?"

  Returns: "You really like THIS cheese?"



  2)
  " !!?X! ?? This is delicious!!! ??!a!?!"

  Returns: " ?X! ? This is delicious! ?a?"

  Sometimes writers get very carried away.  Remember to preserve spaces and other characters from the input.

*/
// END CUT HERE
#line 48 "PunctuationCleaner.cpp"
//// need to write better solution to this problem
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class PunctuationCleaner {
public:

  static bool punct (char c) {
    return ispunct (c);
  }
  static bool notpunct (char c) {
    return !ispunct (c);
  }

  string clearExcess(string document) {
    string ret;

    // note space ' ' is not a punct
    string::iterator iter = document.begin(), iter2 = document.begin();

    int while_count = 0;

    while (iter2 != document.end()) {
      ++while_count;

      iter = find_if (iter2, document.end(), punct);

      if (iter2 != document.end()) {
	ret += string (iter2, iter);
	iter2 = find_if (iter, document.end(), notpunct);
	if (iter != iter2) {
	  string p = string (iter, iter2); // to modify puctuations only
	  string::iterator iterp;
	  iterp = remove (p.begin(), p.end(), '!');
	  if (iterp == p.begin())
	    ret += '!';
	  else
	    ret += '?';
	}
      }

      // case of no modifications required
      if (iter == document.end() && while_count == 1) {
	ret = document;
      }

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
      cout << "Testing PunctuationCleaner (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456480895;
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
      PunctuationCleaner _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string document = "This cheese is really great!!!!!";
	    _expected = "This cheese is really great!";
	    _received = _obj.clearExcess(document); break;
	  }
	case 1:
	  {
	    string document = "You really like THIS cheese!?!?!?!!!?";
	    _expected = "You really like THIS cheese?";
	    _received = _obj.clearExcess(document); break;
	  }
	case 2:
	  {
	    string document = " !!?X! ?? This is delicious!!! ??!a!?!";
	    _expected = " ?X! ? This is delicious! ?a?";
	    _received = _obj.clearExcess(document); break;
	  }
	  case 3:
	    {
	    string document = "Aso!idjf ?owiej !?foj w!?efoji o!!wIEJ";
	    _expected = "Aso!idjf ?owiej ?foj w?efoji o!wIEJ";
	    _received = _obj.clearExcess(document); break;
	    }
	  /*case 4:
	    {
	    string document = ;
	    _expected = ;
	    _received = _obj.clearExcess(document); break;
	    }*/
	  /*case 5:
	    {
	    string document = ;
	    _expected = ;
	    _received = _obj.clearExcess(document); break;
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
