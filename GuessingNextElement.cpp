// BEGIN CUT HERE
/*
PROBLEM STATEMENT

An integer arithmetic progression is a sequence defined by two positive integers, p and q, where p is the first element in the sequence, and all other elements are obtained by adding q to the previous element.  For example, if p = 1 and q = 2, the sequence would be: 1, 3, 5, 7, ...



An integer geometric progression is a sequence defined by two positive integers, p and q, where p is the first element in the sequence, and all other elements are obtained by multiplying the previous element by q.  For example, if p = 3 and q = 2, the sequence would be: 3, 6, 12, ...



You are given a vector <int> A, which contains either an integer arithmetic or geometric progression. Determine which one it is and return the next element in the sequence. It is guaranteed that A will uniquely represent either an arithmetic or geometric progression and that result will fit in a 32-bit signed integer.



DEFINITION
Class:GuessingNextElement
Method:guess
Parameters:vector <int>
Returns:int
Method signature:int guess(vector <int> A)


CONSTRAINTS
-A will contain between 3 and 50 elements, inclusive.
-Each element of A will be between 1 and 10^6, inclusive.
-A will be sorted in ascending order.
-A will uniquely represent either an arithmetic or geometric progression.


EXAMPLES

0)
{364,843,1322,1801}

Returns: 2280

This sequence represents an arithmetic progression where p = 364 and q = 479. The next element is 1801 + 479 = 2280.

1)
{394,1172,1950,2728,3506,4284,5062,5840}

Returns: 6618

2)
{13,117,1053,9477,85293}

Returns: 767637

This sequence represents a geometric progression where p = 13 and q = 9. The next element is 85293 * 9 = 76737.


3)
{22,220,2200,22000}

Returns: 220000

4)
{250000, 500000, 1000000}

Returns: 2000000



*/
// END CUT HERE
#line 69 "GuessingNextElement.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class GuessingNextElement {
public:
  int guess(vector <int> A) {
    int ret;
    int a = A[0];
    int d = A[1] - A[0];
    double r = A[1] / A[0];
    if (A[1] == a + d && A[2] == a + 2*d) {
      ret = a + A.size() * d;
    } else {
      ret = a * pow (r ,A.size());
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
		cout << "Testing GuessingNextElement (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456569260;
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
		GuessingNextElement _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {364,843,1322,1801};
				_expected = 2280;
				_received = _obj.guess(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {394,1172,1950,2728,3506,4284,5062,5840};
				_expected = 6618;
				_received = _obj.guess(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {13,117,1053,9477,85293};
				_expected = 767637;
				_received = _obj.guess(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {22,220,2200,22000};
				_expected = 220000;
				_received = _obj.guess(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {250000, 500000, 1000000};
				_expected = 2000000;
				_received = _obj.guess(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.guess(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.guess(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.guess(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
