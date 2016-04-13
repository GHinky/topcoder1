// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  The sortness of a sequence of distinct numbers is the average of the sortness of each element. The sortness of an element is the number of higher elements that come before it in the sequence plus the number of lower elements that come after it in the sequence. The lower the sortness of a sequence, the closer it is to being sorted. Only a sorted sequence has a sortness of 0.

  For example, in the sequence {3,2,1,4,6,7,5,8} the numbers 1,2,3 and 5 have a sortness of 2, numbers 6 and 7 have a sortness of 1 and numbers 4 and 8 have a sortness of 0. The sortness of the sequence is the average of all those sortness values: (2+2+2+2+1+1+0+0)/8 = 1.25.

  You will be given a sequence of distinct numbers a as a vector <int>. Return the sortness of a.


  DEFINITION
  Class:Sortness
  Method:getSortness
  Parameters:vector <int>
  Returns:double
  Method signature:double getSortness(vector <int> a)


  CONSTRAINTS
  -a will contain between 1 and 50 elements, inclusive.
  -a will contain exactly one occurrence of each integer between 1 and the number of elements in a, inclusive.


  EXAMPLES

  0)
  {3,2,1,4,6,7,5,8}

  Returns: 1.25

  The example in the problem statement.

  1)
  {1,2,3}

  Returns: 0.0

  A sorted sequence has a sortness of zero.

  2)
  {5,4,3,2,1}

  Returns: 4.0

  A reversed sequence has maximum sortness.

  3)
  {1,5,8,7,9,6,10,12,11,3,4,2}

  Returns: 5.166666666666667



*/
// END CUT HERE
#line 58 "Sortness.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sortness {
public:
  double getSortness(vector <int> a) {
    double ret = 0;
    double running_sni_sum = 0;
    for (int i = 0; i != a.size(); ++i) {
      int sni = 0;
      for (int j = 0; j != i; ++j) { //before i
	if (a[j] > a[i])
	  ++sni;
      }
      for (int j = i+1; j != a.size(); ++j) { //after i
	if (a[j] < a[i])
	  ++sni;
      }
      running_sni_sum += sni;
    }
    ret = running_sni_sum / a.size();
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
      cout << "Testing Sortness (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456217282;
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
      Sortness _obj;
      double _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int a[] = {3,2,1,4,6,7,5,8};
	    _expected = 1.25;
	    _received = _obj.getSortness(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int a[] = {1,2,3};
	    _expected = 0.0;
	    _received = _obj.getSortness(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int a[] = {5,4,3,2,1};
	    _expected = 4.0;
	    _received = _obj.getSortness(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int a[] = {1,5,8,7,9,6,10,12,11,3,4,2};
	    _expected = 5.166666666666667;
	    _received = _obj.getSortness(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	  }
	  /*case 4:
	    {
	    int a[] = ;
	    _expected = ;
	    _received = _obj.getSortness(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	    }*/
	  /*case 5:
	    {
	    int a[] = ;
	    _expected = ;
	    _received = _obj.getSortness(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
	    }*/
	  /*case 6:
	    {
	    int a[] = ;
	    _expected = ;
	    _received = _obj.getSortness(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
