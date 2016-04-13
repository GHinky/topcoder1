// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Some texts contain hidden messages. In the context of this problem, the hidden message of a text is composed of the first letter from each word in the text, in the order they appear.

  Given a string text, consisting of only lowercase letters and spaces, return the hidden message.  A word is a maximal sequence of consecutive letters.  There may be multiple spaces between words.  Also, text may contain only spaces.


  DEFINITION
  Class:HiddenMessage
  Method:getMessage
  Parameters:string
  Returns:string
  Method signature:string getMessage(string text)


  CONSTRAINTS
  -text will contain between 1 and 50 characters, inclusive.
  -Each character of text will be either a lowercase letter ('a'-'z'), or a space (' ').


  EXAMPLES

  0)
  "compete online design event rating"

  Returns: "coder"

  Taking the first letter from each word yields the return "coder".

  1)
  "  c    o d     e      r    "

  Returns: "coder"

  Watch out for the leading spaces.

  2)
  "round  elimination during  onsite  contest"

  Returns: "redoc"

  "coder" written backwards.

  3)
  " "

  Returns: ""

  Since there are no words here, the empty string must be returned.

*/
// END CUT HERE
#line 55 "HiddenMessage.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
class HiddenMessage {
public:
   string getMessage(string text) {
    string ret;
    const int N = text.length();
    int i=0, j;
    while (i != N) {
      while (i != N  &&  isspace(text[i]) )
	++i;
      j = i;
      while (j != N && !isspace(text[j]))
	++j;
      if (i != N) {
	ret = ret + text[i];
      }
      i = j;
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
      cout << "Testing HiddenMessage (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456061889;
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
      HiddenMessage _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string text = "compete online design event rating";
	    _expected = "coder";
	    _received = _obj.getMessage(text); break;
	  }
	case 1:
	  {
	    string text = "  c    o d     e      r    ";
	    _expected = "coder";
	    _received = _obj.getMessage(text); break;
	  }
	case 2:
	  {
	    string text = "round  elimination during  onsite  contest";
	    _expected = "redoc";
	    _received = _obj.getMessage(text); break;
	  }
	case 3:
	  {
	    string text = " ";
	    _expected = "";
	    _received = _obj.getMessage(text); break;
	  }
	  /*case 4:
	    {
	    string text = ;
	    _expected = ;
	    _received = _obj.getMessage(text); break;
	    }*/
	  /*case 5:
	    {
	    string text = ;
	    _expected = ;
	    _received = _obj.getMessage(text); break;
	    }*/
	  /*case 6:
	    {
	    string text = ;
	    _expected = ;
	    _received = _obj.getMessage(text); break;
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
