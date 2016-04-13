// BEGIN CUT HERE
/*
PROBLEM STATEMENT

	You are given numbers A0, X, Y, M and n. 
	Generate a list A of length n according to the following recurrence relation:
	A[0] = A0
	A[i] = (A[i - 1] * X + Y) MOD M, for 0 < i < n



	Return the minimal absolute difference between any two elements of A.



DEFINITION
Class:MinDifference
Method:closestElements
Parameters:int, int, int, int, int
Returns:int
Method signature:int closestElements(int A0, int X, int Y, int M, int n)


CONSTRAINTS
-A0, X, Y, M will each be between 1 and 10000, inclusive.
-n will be between 2 and 10000, inclusive.


EXAMPLES

0)
3
7
1
101
5

Returns: 6

The elements of the list are {3, 22, 54, 76, 28}. The minimal difference is between elements 22 and 28.

1)
3
9
8
32
8

Returns: 0

All elements are the same.

2)
67
13
17
4003
23

Returns: 14



3)
1
1221
3553
9889
11

Returns: 275



4)
1
1
1
2
10000

Returns: 0



5)
1567
5003
9661
8929
43

Returns: 14

*/
// END CUT HERE
#line 98 "MinDifference.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class MinDifference {
public:
  int closestElements(int A0, int X, int Y, int M, int n) {
    VI A;
    A.push_back (A0);

    for (int i = 1; i != n; ++i) {
      int topush;
      topush = (A[i-1] * X + Y) % M;
      A.push_back (topush);
    }


    int mindiff = 10001;
    for (int i = 0; i != n; ++i) {
      for (int j = i+1; j != n; ++j) {
	int diff = A[j] - A[i];
	mindiff = min (mindiff, abs(diff));
      }
    }


    /*
    cout << "list is :" << endl;
    for (int i = 0; i != n; ++i) {
      cout << A[i] << "  ";
      }*/
    cout << endl;
    
    
    
    
    
    return mindiff;
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
		cout << "Testing MinDifference (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456599105;
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
		MinDifference _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A0 = 3;
				int X = 7;
				int Y = 1;
				int M = 101;
				int n = 5;
				_expected = 6;
				_received = _obj.closestElements(A0, X, Y, M, n); break;
			}
			case 1:
			{
				int A0 = 3;
				int X = 9;
				int Y = 8;
				int M = 32;
				int n = 8;
				_expected = 0;
				_received = _obj.closestElements(A0, X, Y, M, n); break;
			}
			case 2:
			{
				int A0 = 67;
				int X = 13;
				int Y = 17;
				int M = 4003;
				int n = 23;
				_expected = 14;
				_received = _obj.closestElements(A0, X, Y, M, n); break;
			}
			case 3:
			{
				int A0 = 1;
				int X = 1221;
				int Y = 3553;
				int M = 9889;
				int n = 11;
				_expected = 275;
				_received = _obj.closestElements(A0, X, Y, M, n); break;
			}
			case 4:
			{
				int A0 = 1;
				int X = 1;
				int Y = 1;
				int M = 2;
				int n = 10000;
				_expected = 0;
				_received = _obj.closestElements(A0, X, Y, M, n); break;
			}
			case 5:
			{
				int A0 = 1567;
				int X = 5003;
				int Y = 9661;
				int M = 8929;
				int n = 43;
				_expected = 14;
				_received = _obj.closestElements(A0, X, Y, M, n); break;
			}
			/*case 6:
			{
				int A0 = ;
				int X = ;
				int Y = ;
				int M = ;
				int n = ;
				_expected = ;
				_received = _obj.closestElements(A0, X, Y, M, n); break;
			}*/
			/*case 7:
			{
				int A0 = ;
				int X = ;
				int Y = ;
				int M = ;
				int n = ;
				_expected = ;
				_received = _obj.closestElements(A0, X, Y, M, n); break;
			}*/
			/*case 8:
			{
				int A0 = ;
				int X = ;
				int Y = ;
				int M = ;
				int n = ;
				_expected = ;
				_received = _obj.closestElements(A0, X, Y, M, n); break;
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
