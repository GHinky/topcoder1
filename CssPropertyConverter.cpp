// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  CSS property names are typically all lowercase and written in dash-separated notation, which means that each pair of adjacent words is separated by a single dash.  For example, "z-index", "padding-left", and "border-collapse" are typical names.  However, if you use JavaScript to set CSS style properties, you need to use camel notation, where each word except the first starts with an uppercase letter, and adjacent words are not separated. All other letters are lowercase. For example, "z-index" would become "zIndex" in camel notation.


  You are given a String cssPropertyName containing a property name written in dash-separated notation.  Convert cssPropertyName to camel notation and return the result.



  DEFINITION
  Class:CssPropertyConverter
  Method:getCamelized
  Parameters:string
  Returns:string
  Method signature:string getCamelized(string cssPropertyName)


  CONSTRAINTS
  -cssPropertyName will contain between 1 and 50 characters, inclusive.
  -cssPropertyName will contain only lowercase letters ('a'-'z') and dashes ('-').
  -Each dash in cssPropertyName will be surrounded by two letters.


  EXAMPLES

  0)
  "z-index"

  Returns: "zIndex"



  1)
  "border-collapse"

  Returns: "borderCollapse"



  2)
  "top-border-width"

  Returns: "topBorderWidth"



*/
// END CUT HERE
#line 52 "CssPropertyConverter.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class CssPropertyConverter {
public:
  static bool is_sep (char c) {
    return (c == '-');
  }
  static bool is_alpha (char c) {
    return isalpha(c);
  }

  string getCamelized(string cssPropertyName) {
    string ret;
    VS vs;
    typedef string::iterator iter;
    iter i, j;
    i = cssPropertyName.begin();
    while (i != cssPropertyName.end()){
      i = find_if (i, cssPropertyName.end(), is_alpha);
      j = find_if (i, cssPropertyName.end(), is_sep);
      vs.push_back (string(i, j));
      i = j;
    }
    ret += vs[0]; // first one w/o capitalizaion
    for (int i = 1; i != vs.size(); ++i) {
      vs[i][0] = toupper (vs[i][0]);
      ret += vs[i];
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
      cout << "Testing CssPropertyConverter (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456227206;
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
      CssPropertyConverter _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string cssPropertyName = "z-index";
	    _expected = "zIndex";
	    _received = _obj.getCamelized(cssPropertyName); break;
	  }
	case 1:
	  {
	    string cssPropertyName = "border-collapse";
	    _expected = "borderCollapse";
	    _received = _obj.getCamelized(cssPropertyName); break;
	  }
	case 2:
	  {
	    string cssPropertyName = "top-border-width";
	    _expected = "topBorderWidth";
	    _received = _obj.getCamelized(cssPropertyName); break;
	  }
	  /*case 3:
	    {
	    string cssPropertyName = ;
	    _expected = ;
	    _received = _obj.getCamelized(cssPropertyName); break;
	    }*/
	  /*case 4:
	    {
	    string cssPropertyName = ;
	    _expected = ;
	    _received = _obj.getCamelized(cssPropertyName); break;
	    }*/
	  /*case 5:
	    {
	    string cssPropertyName = ;
	    _expected = ;
	    _received = _obj.getCamelized(cssPropertyName); break;
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
