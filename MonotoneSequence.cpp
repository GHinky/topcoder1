// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  A strictly increasing sequence is a sequence of numbers where each number is strictly greater than the previous one. A strictly decreasing sequence is a sequence where each number is strictly less than the previous one. A strictly monotone sequence is a sequence that is either strictly increasing or strictly decreasing. For example, 1, 5, 6, 10 and 9, 8, 7, 1, are strictly monotone sequences, while 1, 5, 2, 6 and 1, 2, 2, 3 are not.

  Given a sequence seq, determine the length of the longest contiguous subsequence that is strictly monotone (see examples for clarifications).

  DEFINITION
  Class:MonotoneSequence
  Method:longestMonotoneSequence
  Parameters:vector <int>
  Returns:int
  Method signature:int longestMonotoneSequence(vector <int> seq)


  CONSTRAINTS
  -seq will contain between 1 and 50 elements, inclusive.
  -Each element of seq will be between 1 and 100, inclusive.


  EXAMPLES

  0)
  {1, 7, 7, 8, 3, 6, 7, 2}

  Returns: 3

  The longest contiguous monotone subsequence is 3, 6, 7. The sequence 1, 3, 6, 7 is not valid because 1 and 3 are not adjacent, and 1, 7, 7, 8 is not valid because it is not strictly increasing.

  1)
  {1, 1, 1, 1, 1}

  Returns: 1

  A sequence of one element is valid.

  2)
  {10, 20, 30, 25, 20, 19, 20, 18, 23}

  Returns: 4



  3)
  {3, 2, 1, 4}

  Returns: 3



*/
// END CUT HERE
#line 54 "MonotoneSequence.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class MonotoneSequence {
public:
  int longestMonotoneSequence(vector <int> seq) {
    int ret = 1;
    int mem = seq[0];
    for (int i = 0; i != seq.size(); ++i) {
      for (int j = i + 1; j != seq.size() + 1; ++j) {

	// [i, j) is now a general subsequence
	int k = i + 1;
	mem = seq [k - 1];

	if (seq[k] > mem) { // if increasing subsequence
	  while  ((seq[k] > mem) && k != j) {
	    mem = seq[k];
	    ++k;
	  }
	  if (k == j)
	    ret = max (ret, j-i);
	}
	else if (seq[k] < mem) { // if decreasing subsequence
	  while ((seq[k] < mem) && k != j) {
	    mem = seq[k];
	    ++k;
	  }
	  if (k == j) 
	    ret = max (ret, j-i);
	}
	else { // mem = seq[k-1] == seq[k] discard such subsequence
	  break;
	}
	
	
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
      cout << "Testing MonotoneSequence (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456569895;
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
      MonotoneSequence _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int seq[] = {1, 7, 7, 8, 3, 6, 7, 2};
	    _expected = 3;
	    _received = _obj.longestMonotoneSequence(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int seq[] = {1, 1, 1, 1, 1};
	    _expected = 1;
	    _received = _obj.longestMonotoneSequence(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int seq[] = {10, 20, 30, 25, 20, 19, 20, 18, 23};
	    _expected = 4;
	    _received = _obj.longestMonotoneSequence(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int seq[] = {3, 2, 1, 4};
	    _expected = 3;
	    _received = _obj.longestMonotoneSequence(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
	  }
	  /*case 4:
	    {
	    int seq[] = ;
	    _expected = ;
	    _received = _obj.longestMonotoneSequence(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
	    }*/
	  /*case 5:
	    {
	    int seq[] = ;
	    _expected = ;
	    _received = _obj.longestMonotoneSequence(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
	    }*/
	  /*case 6:
	    {
	    int seq[] = ;
	    _expected = ;
	    _received = _obj.longestMonotoneSequence(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
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
