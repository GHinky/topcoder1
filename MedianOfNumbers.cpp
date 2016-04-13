// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  In a set of distinct numbers, the median is an element M such that the number of elements greater than M is equal to the number of elements smaller than M. For example, in a set {1, 4, 2, 5, 7} the median is 4 because two elements (5 and 7) are greater than 4 and 2 elements (1 and 2) smaller than 4. The set {1, 5, 8, 3} has no median because no element from it satisfies the definition above.
  You are given a vector <int> numbers. Return the median of numbers or -1 if numbers has no median.


  DEFINITION
  Class:MedianOfNumbers
  Method:findMedian
  Parameters:vector <int>
  Returns:int
  Method signature:int findMedian(vector <int> numbers)


  CONSTRAINTS
  -numbers will contain between 1 and 50 elements, inclusive.
  -Each element of numbers will be between 1 and 100, inclusive.
  -All elements of numbers will be distinct.


  EXAMPLES

  0)
  {1, 4, 2, 5, 7}

  Returns: 4

  The example from the statement.

  1)
  {1, 5, 8, 3}

  Returns: -1

  2)
  {7}

  Returns: 7

  There are zero elements that are greater than 7 and zero elements that are smaller than 7. 

  3)
  {7, 12}

  Returns: -1

  4)
  {66, 53, 47, 86, 18, 21, 97, 92, 15}

  Returns: 53

  5)
  {32, 54, 27, 4, 69, 96, 73, 1, 100, 15, 21}

  Returns: 32

*/
// END CUT HERE
#line 61 "MedianOfNumbers.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class MedianOfNumbers {
public:
  int findMedian(vector <int> numbers) {
    int ret = -69;
    typedef vector<int>::size_type VS;
    VS size = numbers.size();
    if (size % 2 == 0)
      return -1;
    sort (numbers.begin(), numbers.end());
    ret = numbers [(size-1) / 2];
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
      cout << "Testing MedianOfNumbers (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1455727870;
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
      MedianOfNumbers _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int numbers[] = {1, 4, 2, 5, 7};
	    _expected = 4;
	    _received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int numbers[] = {1, 5, 8, 3};
	    _expected = -1;
	    _received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int numbers[] = {7};
	    _expected = 7;
	    _received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int numbers[] = {7, 12};
	    _expected = -1;
	    _received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
	  }
	case 4:
	  {
	    int numbers[] = {66, 53, 47, 86, 18, 21, 97, 92, 15};
	    _expected = 53;
	    _received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
	  }
	case 5:
	  {
	    int numbers[] = {32, 54, 27, 4, 69, 96, 73, 1, 100, 15, 21};
	    _expected = 32;
	    _received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
	  }
	  /*case 6:
	    {
	    int numbers[] = ;
	    _expected = ;
	    _received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
	    }*/
	  /*case 7:
	    {
	    int numbers[] = ;
	    _expected = ;
	    _received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
	    }*/
	  /*case 8:
	    {
	    int numbers[] = ;
	    _expected = ;
	    _received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
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
