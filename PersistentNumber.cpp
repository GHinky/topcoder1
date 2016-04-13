// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Given a number x, we can define p(x) as the product of the digits of x.  We can then form a sequence x, p(x), p(p(x))...  The persistence of x is then defined as the index (0-based) of the first single digit number in the sequence.  For example, using 99, we get the sequence 99, 9*9 = 81, 8*1 = 8.  Thus, the persistence of 99 is 2.  You will be given n, and you must return its persistence.

  DEFINITION
  Class:PersistentNumber
  Method:getPersistence
  Parameters:int
  Returns:int
  Method signature:int getPersistence(int n)


  CONSTRAINTS
  -n will be between 0 and 2,000,000,000, inclusive.


  EXAMPLES

  0)
  99

  Returns: 2

  The example from the problem statement.

  1)
  268

  Returns: 4

  The sequence here is 268, 96, 54, 20, 0.

  2)
  6

  Returns: 0

  6 is already a single-digit number.

  3)
  68889789

  Returns: 3



  4)
  86898

  Returns: 7



*/
// END CUT HERE
#line 58 "PersistentNumber.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class PersistentNumber {
public:
  VI digs (int n) {
    VI ret;
    while (n != 0) {
      int temp = n % 10;
      ret.push_back (temp);
      n /= 10;
    }
    return ret;
  }
  int getPersistence(int n) {
    int ret = 0;
    while (n > 9) {
      ++ret;
      VI d = digs (n);
      n = 1;
      for (int i = 0; i != d.size(); ++i) {
	n *= d[i];
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
      cout << "Testing PersistentNumber (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456287047;
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
      PersistentNumber _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int n = 99;
	    _expected = 2;
	    _received = _obj.getPersistence(n); break;
	  }
	case 1:
	  {
	    int n = 268;
	    _expected = 4;
	    _received = _obj.getPersistence(n); break;
	  }
	case 2:
	  {
	    int n = 6;
	    _expected = 0;
	    _received = _obj.getPersistence(n); break;
	  }
	case 3:
	  {
	    int n = 68889789;
	    _expected = 3;
	    _received = _obj.getPersistence(n); break;
	  }
	case 4:
	  {
	    int n = 86898;
	    _expected = 7;
	    _received = _obj.getPersistence(n); break;
	  }
	  /*case 5:
	    {
	    int n = ;
	    _expected = ;
	    _received = _obj.getPersistence(n); break;
	    }*/
	  /*case 6:
	    {
	    int n = ;
	    _expected = ;
	    _received = _obj.getPersistence(n); break;
	    }*/
	  /*case 7:
	    {
	    int n = ;
	    _expected = ;
	    _received = _obj.getPersistence(n); break;
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
