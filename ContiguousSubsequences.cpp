// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Given an integer sequence a[0], a[1], ..., a[N-1], find a contiguous subsequnce a[i], a[i+1], ..., a[j] such that:

The length of the subsequence (j-i+1) is at least K.
The average value in the subsequence (a[i] + a[i+1] + ... + a[j])/(j-i+1) is maximized.



You are given a vector <int> a containing the original sequence, and an int K. Return a vector <int> containing exactly two elements.  The first element is the first index of the contiguous subsequence described above, and the second element is the last index. Both indices are 0-based. If there are multiple subsequences that satisfy the conditions above, return the longest one among them. If there are still multiple subsequences, return the one among them with the smallest first index.



DEFINITION
Class:ContiguousSubsequences
Method:findMaxAverage
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> findMaxAverage(vector <int> a, int K)


CONSTRAINTS
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 0 and 1000000, inclusive.
-K will be between 1 and number of elements in a, inclusive.


EXAMPLES

0)
{1,3,7}
2

Returns: {1, 2 }

There are 3 possible contiguous subsequences:

{1,3}, average = 2.
{1,3,7}, average = 11/3.
{3,7}, average = 5.

So {3,7} is the best case.

1)
{5,1,3,4}
2

Returns: {2, 3 }



2)
{10}
1

Returns: {0, 0 }

There is only one possible subsequence - the whole sequence.

3)
{381,921,513,492,135,802,91,519}
1

Returns: {1, 1 }

When K = 1, we can select the subsequence containing only the maximal elements.

4)
{381,921,513,492,135,802,91,519}
4

Returns: {0, 3 }



5)
{3,5,7,7,2,5,4,7,7,2,4}
1

Returns: {2, 3 }



6)
{3, 1, 3, 3, 3, 1, 3, 3, 3}
1

Returns: {2, 4 }



7)
{1, 3, 2, 1, 1, 2, 2, 2, 2}
3

Returns: {5, 8 }



*/
// END CUT HERE
#line 104 "ContiguousSubsequences.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class ContiguousSubsequences {
public:
  vector <int> findMaxAverage(vector <int> a, int K) {
    VI ret;
    ret.push_back (0);
    ret.push_back (0);
    double mavg = 0;
    double mlen = 0;
    for (int i = 0; i != a.size(); ++i) {
      for (int j = i + K - 1; j < a.size(); ++j) {
	int sz = j - i + 1;
	double avg;
	avg = accumulate (a.begin() + i, a.begin() + i + sz, 0.0) / sz;

	if ((avg > mavg) ||
	    ((avg == mavg) && (sz > mlen)) ||
	    ((avg == mavg) && (sz == mlen) && (i < ret[0]))) {
	  ret[0] = i;
	  ret[1] = j;
	  mlen = sz;
	  mavg = avg;
	}

	
      }
      // cout << "for i = " << i << endl;
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
		cout << "Testing ContiguousSubsequences (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456513420;
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
		ContiguousSubsequences _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,3,7};
				int K = 2;
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 1:
			{
				int a[] = {5,1,3,4};
				int K = 2;
				int __expected[] = {2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 2:
			{
				int a[] = {10};
				int K = 1;
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 3:
			{
				int a[] = {381,921,513,492,135,802,91,519};
				int K = 1;
				int __expected[] = {1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 4:
			{
				int a[] = {381,921,513,492,135,802,91,519};
				int K = 4;
				int __expected[] = {0, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 5:
			{
				int a[] = {3,5,7,7,2,5,4,7,7,2,4};
				int K = 1;
				int __expected[] = {2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 6:
			{
				int a[] = {3, 1, 3, 3, 3, 1, 3, 3, 3};
				int K = 1;
				int __expected[] = {2, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 7:
			{
				int a[] = {1, 3, 2, 1, 1, 2, 2, 2, 2};
				int K = 3;
				int __expected[] = {5, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			/*case 8:
			{
				int a[] = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}*/
			/*case 9:
			{
				int a[] = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}*/
			/*case 10:
			{
				int a[] = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxAverage(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
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
