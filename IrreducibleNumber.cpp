// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  You are given a vector <int> A. An integer K is irreducible with respect to A if K cannot be represented as a sum of one or more elements from A, where each element of A may be used at most once.  Return the smallest positive integer that is irreducible with respect to A.

  DEFINITION
  Class:IrreducibleNumber
  Method:getIrreducible
  Parameters:vector <int>
  Returns:int
  Method signature:int getIrreducible(vector <int> A)


  CONSTRAINTS
  -A will contain between 1 and 3 elements, inclusive.
  -Each element of A will be between 1 and 100, inclusive.


  EXAMPLES

  0)
  {1,1}

  Returns: 3

  1 can be expressed as 1, and 2 can be expressed as 1+1.

  1)
  {1,2}

  Returns: 4



  2)
  {1,3}

  Returns: 2



  3)
  {4, 1, 3}

  Returns: 2



*/
// END CUT HERE
#line 52 "IrreducibleNumber.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class IrreducibleNumber {
public:
  int getIrreducible(vector <int> A) {
    const int S = A.size();
    int ret = -69;
    sort (A.begin(), A.end());
    reverse (A.begin(), A.end());
    for (int i2 = 1; i2 != 301; ++i2) { // try different guesses for ret
      int i = i2;
      ret = i;
      //cout << "__________guessed ret = " << ret << "_________________\n";
      for (int j = 0; j < S; ++j) { // iterate over elements of A
	while (i < A[j])
	  ++j;
	if (i > 0) {
	  i -= A[j];
	}
	//cout << "inside j = " << j << " & i = " << i << " for loop\n";
      }
      if (i == 0)
	continue; //reducible ret, so continue
      else {
	break;
      }
      //cout << "inside i******** for loop";
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
      cout << "Testing IrreducibleNumber (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456208244;
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
      IrreducibleNumber _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int A[] = {1,1};
	    _expected = 3;
	    _received = _obj.getIrreducible(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int A[] = {1,2};
	    _expected = 4;
	    _received = _obj.getIrreducible(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int A[] = {1,3};
	    _expected = 2;
	    _received = _obj.getIrreducible(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int A[] = {4, 1, 3};
	    _expected = 2;
	    _received = _obj.getIrreducible(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
	  }
	  case 4:
	    {
	      int A[] = {1, 2, 2};
	    _expected = 6;
	    _received = _obj.getIrreducible(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
	    }
	  /*case 5:
	    {
	    int A[] = ;
	    _expected = ;
	    _received = _obj.getIrreducible(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
	    }*/
	  /*case 6:
	    {
	    int A[] = ;
	    _expected = ;
	    _received = _obj.getIrreducible(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
