// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A sequence of distinct numbers A is going to be sorted using insertion sort. Insertion sort works as follows:

insertion-sort(A)
   initialize a new empty sequence R
   for each number N in A (in the original order) do:
      determine the index i in R where N should be inserted so that R remains sorted
      move each element in R with index greater than or equal to i to the following index
      set R[i]=N
   return R

For example, an insertion sort on {20,40,30,10} would produce the following states for R after each step:
20          (first element is inserted at index 0)
20,40       (inserting 40 at index 1 requires no moves)
20,30,40    (30 is inserted at index 1, so 40 has to be moved)
10,20,30,40 (10 is inserted at index 0, so 20, 30 and 40 have to be moved)
In total, 4 moves were needed.
Given a vector <int> A, which contains a sequence of distinct numbers, return the number of moves that would be performed by an insertion sort on A.


DEFINITION
Class:InsertionSortCount
Method:countMoves
Parameters:vector <int>
Returns:int
Method signature:int countMoves(vector <int> A)


CONSTRAINTS
-A will have between 1 and 50 elements, inclusive.
-Each element of A will be between -1000 and 1000, inclusive.
-All elements of A will be distinct.


EXAMPLES

0)
{20,40,30,10}

Returns: 4

The example from the problem statement.

1)
{-1,1,0}

Returns: 1

Only one move needed to insert 0.

2)
{-1000,0,1000}

Returns: 0

Since elements are inserted in sorted order, all of them are appended at the end of R. Therefore, there's no need to move anything.

*/
// END CUT HERE
#line 63 "InsertionSortCount.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class InsertionSortCount {
	public:
	int countMoves(vector<int> A) {
	  int ret = 0;
	  vector<int>::size_type i, j;
	  for (i = 0; i != A.size(); ++i) {
	    for (j = 0; j != i; ++j) {
	      if(A[i] < A[j])
		++ret;
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
		cout << "Testing InsertionSortCount (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454935601;
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
		InsertionSortCount _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {20,40,30,10};
				_expected = 4;
				_received = _obj.countMoves(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {-1,1,0};
				_expected = 1;
				_received = _obj.countMoves(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {-1000,0,1000};
				_expected = 0;
				_received = _obj.countMoves(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 3:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.countMoves(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.countMoves(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.countMoves(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
