// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  A boot shop has received a shipment from the factory consisting of N
  left boots and N right boots. Each boot has some integer size, and a
  left and right boot will form a proper pair if they have equal sizes.
  Each boot can only belong to a single pair. The employees of the boot
  store want to create N proper pairs of boots. Fortunately, the factory
  has offered to exchange any number of boots in the shipment with new
  boots of different sizes.


  You are given a vector <int> left and a vector <int> right containing the sizes of the left boots and right boots, respectively.
  Return the least number of boots that must be exchanged.


  DEFINITION
  Class:BootsExchange
  Method:leastAmount
  Parameters:vector <int>, vector <int>
  Returns:int
  Method signature:int leastAmount(vector <int> left, vector <int> right)


  CONSTRAINTS
  -Each element in left will be between 1 and 1000, inclusive.
  -Each element in right will be between 1 and 1000, inclusive.
  -left and right will have the same number of elements.
  -left will contain between 1 and 50 elements, inclusive.


  EXAMPLES

  0)
  {1, 3, 1}
  {2, 1, 3}

  Returns: 1

  They can exchange a size 1 left shoe for a size 2 left shoe, or they can exchange the size 2 right shoe for a size 1 right shoe.

  1)
  {1, 3}
  {2, 2}

  Returns: 2

  They can exchange both left shoes for size 2 left shoes, or they can exchange the right shoes for a size 1 right shoe and a size 3 right shoe, or they can mix these two possibilities.

  2)
  {1, 2, 3, 4, 5, 6, 7}
  {2, 4, 6, 1, 3, 7, 5}

  Returns: 0

  Nothing to exchange.

*/
// END CUT HERE
#line 56 "BootsExchange.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class BootsExchange {
public:
  int leastAmount(vector <int> left, vector <int> right) {
    int ret = -69;
    vector<int> l, r;
    l = left;
    r = right;
    int matches = 0;
    for (vector<int>::size_type i = 0; i != l.size(); ++i) {
      for (vector<int>::size_type j = 0; j != r.size(); ++j) {
	if (l[i] == r[j]) {
	  ++matches;
	  r[j] = -1;
	  break;
	}
      }
    }
    ret = l.size() - matches;
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
      cout << "Testing BootsExchange (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1455726522;
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
      BootsExchange _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int left[] = {1, 3, 1};
	    int right[] = {2, 1, 3};
	    _expected = 1;
	    _received = _obj.leastAmount(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int left[] = {1, 3};
	    int right[] = {2, 2};
	    _expected = 2;
	    _received = _obj.leastAmount(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int left[] = {1, 2, 3, 4, 5, 6, 7};
	    int right[] = {2, 4, 6, 1, 3, 7, 5};
	    _expected = 0;
	    _received = _obj.leastAmount(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
	  }
	  /*case 3:
	    {
	    int left[] = ;
	    int right[] = ;
	    _expected = ;
	    _received = _obj.leastAmount(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
	    }*/
	  /*case 4:
	    {
	    int left[] = ;
	    int right[] = ;
	    _expected = ;
	    _received = _obj.leastAmount(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
	    }*/
	  /*case 5:
	    {
	    int left[] = ;
	    int right[] = ;
	    _expected = ;
	    _received = _obj.leastAmount(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
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
