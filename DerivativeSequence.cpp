// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  Given a sequence of K elements, we can calculate its difference sequence by taking the difference between each pair of adjacent elements.  For instance, the difference sequence of {5,6,3,9,-1} is {6-5,3-6,9-3,-1-9} = {1,-3,6,-10}. Formally, the difference sequence of the sequence a1, a2, ... , ak is b1, b2, ... , bk-1, where bi = ai+1 - ai.

  The derivative sequence of order N of a sequence A is the result of iteratively applying the above process N times. For example, if A = {5,6,3,9,-1}, the derivative sequence of order 2 is: {5,6,3,9,-1} -> {1,-3,6,-10} -> {-3-1,6-(-3),-10-6} = {-4,9,-16}.

  You will be given a sequence a as a vector <int> and the order n. Return a vector <int> representing the derivative sequence of order n of a.



  DEFINITION
  Class:DerivativeSequence
  Method:derSeq
  Parameters:vector <int>, int
  Returns:vector <int>
  Method signature:vector <int> derSeq(vector <int> a, int n)


  NOTES
  -The derivative sequence of order 0 is the original sequence. See example 4 for further clarification.


  CONSTRAINTS
  -a will contain between 1 and 20 elements, inclusive.
  -Each element of a will be between -100 and 100, inclusive.
  -n will be between 0 and K-1, inclusive, where K is the number of elements in a.


  EXAMPLES

  0)
  {5,6,3,9,-1}
  1

  Returns: {1, -3, 6, -10 }

  The first example given in the problem statement.

  1)
  {5,6,3,9,-1}
  2

  Returns: {-4, 9, -16 }

  The second example given in the problem statement.

  2)
  {5,6,3,9,-1}
  4

  Returns: {-38 }



  3)
  {4,4,4,4,4,4,4,4}
  3

  Returns: {0, 0, 0, 0, 0 }

  After 1 step, they all become 0.

  4)
  {-100,100}
  0

  Returns: {-100, 100 }



*/
// END CUT HERE
#line 76 "DerivativeSequence.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class DerivativeSequence {
public:
  vector<int> derOnce (vector<int>& a) {
    typedef vector<int>::size_type vs;
    for (vs i = 0; i != a.size() - 1; ++i) {
      a[i] = a[i+1] - a[i];
    }
    //    a.pop_back();
    // or
    a.erase (a.end() - 1, a.end());
    return a;
  }
  vector <int> derSeq(vector <int> a, int n) {
    for (int i = 0; i != n; ++i) {
      derOnce (a);
    }
    return a;
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
      cout << "Testing DerivativeSequence (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456207402;
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
      DerivativeSequence _obj;
      vector <int> _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int a[] = {5,6,3,9,-1};
	    int n = 1;
	    int __expected[] = {1, -3, 6, -10 };
	    _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
	    _received = _obj.derSeq(vector <int>(a, a+sizeof(a)/sizeof(int)), n); break;
	  }
	case 1:
	  {
	    int a[] = {5,6,3,9,-1};
	    int n = 2;
	    int __expected[] = {-4, 9, -16 };
	    _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
	    _received = _obj.derSeq(vector <int>(a, a+sizeof(a)/sizeof(int)), n); break;
	  }
	case 2:
	  {
	    int a[] = {5,6,3,9,-1};
	    int n = 4;
	    int __expected[] = {-38 };
	    _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
	    _received = _obj.derSeq(vector <int>(a, a+sizeof(a)/sizeof(int)), n); break;
	  }
	case 3:
	  {
	    int a[] = {4,4,4,4,4,4,4,4};
	    int n = 3;
	    int __expected[] = {0, 0, 0, 0, 0 };
	    _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
	    _received = _obj.derSeq(vector <int>(a, a+sizeof(a)/sizeof(int)), n); break;
	  }
	case 4:
	  {
	    int a[] = {-100,100};
	    int n = 0;
	    int __expected[] = {-100, 100 };
	    _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
	    _received = _obj.derSeq(vector <int>(a, a+sizeof(a)/sizeof(int)), n); break;
	  }
	  /*case 5:
	    {
	    int a[] = ;
	    int n = ;
	    int __expected[] = ;
	    _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
	    _received = _obj.derSeq(vector <int>(a, a+sizeof(a)/sizeof(int)), n); break;
	    }*/
	  /*case 6:
	    {
	    int a[] = ;
	    int n = ;
	    int __expected[] = ;
	    _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
	    _received = _obj.derSeq(vector <int>(a, a+sizeof(a)/sizeof(int)), n); break;
	    }*/
	  /*case 7:
	    {
	    int a[] = ;
	    int n = ;
	    int __expected[] = ;
	    _expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
	    _received = _obj.derSeq(vector <int>(a, a+sizeof(a)/sizeof(int)), n); break;
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
	  cout << "           Expected: {";
	  for (unsigned i = 0; i < _expected.size(); i++)
	    {
	      if (i) cout << ",";
	      cout << " " << _expected[i];
	    }
	  cout << " }" << endl;
	  cout << "           Received: {";
	  for (unsigned i = 0; i < _received.size(); i++)
	    {
	      if (i) cout << ",";
	      cout << " " << _received[i];
	    }
	  cout << " }" << endl;
	}
    }
}

// END CUT HERE
