// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  We have a sorting machine that works on a list of distinct numbers.  This machine only has one instruction named MOVE that takes one element of the list as a parameter.  The MOVE instruction removes the element from the list and then appends it to the end of the remaining list.
  For example, the sequence {19,7,8,25} can be sorted in ascending order using 2 instructions:
  MOVE 19, to get {7,8,25,19}
  MOVE 25, to get {7,8,19,25}
  You will be given a vector <int> a containing a list of distinct numbers.  Return the minimum number of instructions required to sort the list in ascending order.

  DEFINITION
  Class:SortMachine
  Method:countMoves
  Parameters:vector <int>
  Returns:int
  Method signature:int countMoves(vector <int> a)


  CONSTRAINTS
  -a will have between 1 and 50 elements, inclusive.
  -Each element of a will be between -1000 and 1000, inclusive.
  -All elements of a will be distinct.


  EXAMPLES

  0)
  {19,7,8,25}

  Returns: 2

  The example from the problem statement.

  1)
  {1,2,3,4,5}

  Returns: 0

  This list is already sorted, so no instructions are needed.

  2)
  {1000,-1000,0}

  Returns: 1

  This list can be sorted with a single instruction: MOVE 1000.

  3)
  {1,3,4,5,6,7,8,9,2}

  Returns: 7

  4)
  {-2, -8, 9, 0}

  Returns: 3

  5)
  {976, -946, -824, 680, -644, -95, 128, -892, 816, -263,
  -592, -669, 887, 447, -653, -759, 572, 171, 635, 98,
  -904, 78, 143, -416, -40, -846, 784, -702, -738, -858,
  582, 603, -535, 529, 84, -964, 934, 36, 783} 

  Returns: 38

*/
// END CUT HERE
#line 68 "SortMachine.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class SortMachine {
public:
  int countMoves(vector<int> a) {
    int ret = 0;
    vector<int> b;
    b = a;
    sort (b.begin(), b.end());
    vector<int>::size_type j = 0;
    for (vector<int>::size_type i = 0; i != a.size();) {
      if (a[i] == b[j]) {
	++i;
	++j;
      }else
	++i;
    }
    ret = a.size() - j;
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
      cout << "Testing SortMachine (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1455100359;
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
      SortMachine _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int a[] = {19,7,8,25};
	    _expected = 2;
	    _received = _obj.countMoves(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int a[] = {1,2,3,4,5};
	    _expected = 0;
	    _received = _obj.countMoves(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int a[] = {1000,-1000,0};
	    _expected = 1;
	    _received = _obj.countMoves(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int a[] = {1,3,4,5,6,7,8,9,2};
	    _expected = 7;
	    _received = _obj.countMoves(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	case 4:
	  {
	    int a[] = {-2, -8, 9, 0};
	    _expected = 3;
	    _received = _obj.countMoves(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	case 5:
	  {
	    int a[] = {976, -946, -824, 680, -644, -95, 128, -892, 816, -263,
		       -592, -669, 887, 447, -653, -759, 572, 171, 635, 98,
		       -904, 78, 143, -416, -40, -846, 784, -702, -738, -858,
		       582, 603, -535, 529, 84, -964, 934, 36, 783} ;
	    _expected = 38;
	    _received = _obj.countMoves(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	  /*case 6:
	    {
	    int a[] = ;
	    _expected = ;
	    _received = _obj.countMoves(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	    }
	  /*case 7:
	    {
	    int a[] = ;
	    _expected = ;
	    _received = _obj.countMoves(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	    }*/
	  /*case 8:
	    {
	    int a[] = ;
	    _expected = ;
	    _received = _obj.countMoves(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
