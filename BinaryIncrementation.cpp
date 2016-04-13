// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  The binary numeral system (base 2 numerals) represents numeric values using two symbols: 0 and 1. 
  Counting in binary is similar to counting in any other number system.
  If you want to increase a number by 1, try to increase its last digit by 1.  
  If this fails, set the last digit to zero, and try to increase the previous digit, 
  and so on, until you succeed.



  For example, the decimal sequence:
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
  converted to binary looks as follows:
  1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, ...



  You are given a string x that contains the binary representation of a positive integer X.
  Write a method that will return a string containing the binary representation of (X+1).
  The returned string must not contain leading zeroes.


  DEFINITION
  Class:BinaryIncrementation
  Method:plusOne
  Parameters:string
  Returns:string
  Method signature:string plusOne(string x)


  CONSTRAINTS
  -x will contain between 1 and 30 characters, inclusive.
  -Each character in x will be a one ('1') or a zero ('0').
  -The first character in x will be a one ('1').


  EXAMPLES

  0)
  "10011"

  Returns: "10100"

  "10011" is binary for 16+2+1 = 19. The next integer is 20 = 16+4, which is "10100" in binary.

  1)
  "10000"

  Returns: "10001"



  2)
  "1111"

  Returns: "10000"

  Be careful not to miss the case when the result is a power of two.

  3)
  "1"

  Returns: "10"



  4)
  "101010101010101010101010101010"

  Returns: "101010101010101010101010101011"



*/
// END CUT HERE
#line 79 "BinaryIncrementation.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class BinaryIncrementation {
public:
  string plusOne(string x) {
    string ret;
    int i;
    for (i = x.size() - 1; i != -1; --i) {
      if (x[i] == '0') {
	x[i] = '1';
	break;
      } else {
	x[i] = '0';
      }
    }
    if (i == -1) {
      x = "1" + x;
    }
    ret = x;
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
      cout << "Testing BinaryIncrementation (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456226047;
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
      BinaryIncrementation _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string x = "10011";
	    _expected = "10100";
	    _received = _obj.plusOne(x); break;
	  }
	case 1:
	  {
	    string x = "10000";
	    _expected = "10001";
	    _received = _obj.plusOne(x); break;
	  }
	case 2:
	  {
	    string x = "1111";
	    _expected = "10000";
	    _received = _obj.plusOne(x); break;
	  }
	case 3:
	  {
	    string x = "1";
	    _expected = "10";
	    _received = _obj.plusOne(x); break;
	  }
	case 4:
	  {
	    string x = "101010101010101010101010101010";
	    _expected = "101010101010101010101010101011";
	    _received = _obj.plusOne(x); break;
	  }
	  /*case 5:
	    {
	    string x = ;
	    _expected = ;
	    _received = _obj.plusOne(x); break;
	    }*/
	  /*case 6:
	    {
	    string x = ;
	    _expected = ;
	    _received = _obj.plusOne(x); break;
	    }*/
	  /*case 7:
	    {
	    string x = ;
	    _expected = ;
	    _received = _obj.plusOne(x); break;
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
