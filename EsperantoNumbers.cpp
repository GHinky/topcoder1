// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Numbers are far easier to spell in Esperanto than in English.  Numbers 1 through 10 are spelled as follows: "unu", "du", "tri", "kvar", "kvin", "ses", "sep", "ok", "nau", "dek".  Numbers 11 through 19 are spelled: "dek unu", "dek du", ..., "dek nau" - a "dek" followed by a single space and the number for the last digit.  Numbers 20 through 29 are spelled: "dudek", "dudek unu", "dudek du", ..., "dudek nau".  Similarly, 30 is "tridek", ..., 90 is "naudek" - we just join together the number of tens and "dek".  There are no exceptions like "twelve" or "thirty" in English.

  Given an int x between 1 and 99, inclusive, return its Esperanto spelling.

  DEFINITION
  Class:EsperantoNumbers
  Method:nameThisNumber
  Parameters:int
  Returns:string
  Method signature:string nameThisNumber(int x)


  CONSTRAINTS
  -x will be between 1 and 99, inclusive.


  EXAMPLES

  0)
  1

  Returns: "unu"



  1)
  90

  Returns: "naudek"



  2)
  11

  Returns: "dek unu"



  3)
  57

  Returns: "kvindek sep"



*/
// END CUT HERE
#line 53 "EsperantoNumbers.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class EsperantoNumbers {
public:
  vector<int> rdigits (int x) {
    vector<int> ret;
    while (x > 0) {
      int temp = x % 10;
      ret.push_back(temp);
      x /= 10;
    }
    return ret;
  }
  string nameThisNumber(int x) {
    string ret;
    vector<int> rdigits_x = rdigits (x);
    const string names_units[] = {"", "unu", "du", "tri", "kvar", "kvin",
			    "ses", "sep", "ok", "nau", "dek"};
    const string names_tens[] = {"\b", "", "du", "tri", "kvar", "kvin",
			    "ses", "sep", "ok", "nau", "dek"};
    
    cout << endl;
    cout << "0th: " << rdigits_x [0] << endl;
    cout << "1st: " << rdigits_x [1] << endl;
    if (rdigits_x.size() == 1)
      ret = names_units [rdigits_x[0]];
    else {
      ret = names_tens [rdigits_x[1]] + "dek";
      if (rdigits_x[0] != 0)
	ret += " " + names_units [rdigits_x[0]];
      else
	ret += names_units [rdigits_x[0]];
    }
    cout << "___________________________\n";

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
      cout << "Testing EsperantoNumbers (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456029725;
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
      EsperantoNumbers _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int x = 1;
	    _expected = "unu";
	    _received = _obj.nameThisNumber(x); break;
	  }
	case 1:
	  {
	    int x = 90;
	    _expected = "naudek";
	    _received = _obj.nameThisNumber(x); break;
	  }
	case 2:
	  {
	    int x = 11;
	    _expected = "dek unu";
	    _received = _obj.nameThisNumber(x); break;
	  }
	case 3:
	  {
	    int x = 57;
	    _expected = "kvindek sep";
	    _received = _obj.nameThisNumber(x); break;
	  }
	  /*case 4:
	    {
	    int x = ;
	    _expected = ;
	    _received = _obj.nameThisNumber(x); break;
	    }*/
	  /*case 5:
	    {
	    int x = ;
	    _expected = ;
	    _received = _obj.nameThisNumber(x); break;
	    }*/
	  /*case 6:
	    {
	    int x = ;
	    _expected = ;
	    _received = _obj.nameThisNumber(x); break;
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
