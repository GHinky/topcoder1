// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  Most modern text editors are able to give some statistics about the text they are editing.  One nice statistic is the average word length in the text.


  A word is a maximal continuous sequence of letters ('a'-'z', 'A'-'Z').  Words can be separated by spaces, digits, and punctuation marks.


  The average word length is the sum of all the words' lengths divided by the total number of words.  For example, in the text "This is div2 easy problem.", there are 5 words: "This", "is", "div", "easy", and "problem".  The sum of the word lengths is 4+2+3+4+7=20, so the average word length is 20/5=4.


  Given a string text, return the average word length in it.  If there are no words in the text, return 0.0.



  DEFINITION
  Class:TextStatistics
  Method:averageLength
  Parameters:string
  Returns:double
  Method signature:double averageLength(string text)


  NOTES
  -The returned value must be accurate to within a relative or absolute value of 1E-9.


  CONSTRAINTS
  -text will contain between 0 and 50 characters, inclusive.
  -text will contain only letters ('a'-'z', 'A'-'Z'), digits ('0'-'9'), spaces, and the following punctuation marks: ',', '.', '?', '!', '-'.


  EXAMPLES

  0)
  "This is div2 easy problem."

  Returns: 4.0

  The example from the problem statement.

  1)
  "Hello, world!"

  Returns: 5.0

  In this case all words have the same length.

  2)
  "Simple"

  Returns: 6.0

  One word.

  3)
  ""

  Returns: 0.0

  No words here, so return 0.

  4)
  "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

  Returns: 50.0



*/
// END CUT HERE
#line 75 "TextStatistics.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
//typedef vector<string> VS;
//typedef vector<int> VI;
using namespace std;
class TextStatistics {
public:
  static bool is_sep (char c) {
    return !isalpha(c);
  }
  static bool is_alpha (char c) {
    return isalpha(c);
  }
  double averageLength(string text) {
    double ret = 0;
    vector<string> vs;
    typedef string::iterator iter;
    iter i, j;
    i = text.begin();
    while (i != text.end()){
      i = find_if (i, text.end(), is_alpha);
      j = find_if (i, text.end(), is_sep);
      vs.push_back (string(i, j));
      i = j;
    }
    int n = 0; // non-empty count in vs
    double rs = 0; //running sum
    for (int i = 0; i != vs.size(); ++i) {
      if (!vs[i].empty()) { 
	rs += vs[i].length();
	++n;
      }
      //      cout << vs[i] << " | size =" << vs[i].length() << endl;
    }
    if (n == 0)
      ret = 0;
    else
      ret = rs / n;
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
      cout << "Testing TextStatistics (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456219651;
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
      TextStatistics _obj;
      double _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string text = "This is div2 easy problem.";
	    _expected = 4.0;
	    _received = _obj.averageLength(text); break;
	  }
	case 1:
	  {
	    string text = "Hello, world!";
	    _expected = 5.0;
	    _received = _obj.averageLength(text); break;
	  }
	case 2:
	  {
	    string text = "Simple";
	    _expected = 6.0;
	    _received = _obj.averageLength(text); break;
	  }
	case 3:
	  {
	    string text = "";
	    _expected = 0.0;
	    _received = _obj.averageLength(text); break;
	  }
	case 4:
	  {
	    string text = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	    _expected = 50.0;
	    _received = _obj.averageLength(text); break;
	  }
	  /*case 5:
	    {
	    string text = ;
	    _expected = ;
	    _received = _obj.averageLength(text); break;
	    }*/
	  /*case 6:
	    {
	    string text = ;
	    _expected = ;
	    _received = _obj.averageLength(text); break;
	    }*/
	  /*case 7:
	    {
	    string text = ;
	    _expected = ;
	    _received = _obj.averageLength(text); break;
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
