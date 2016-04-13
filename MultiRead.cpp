// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  In many computer systems, multiple processes can read from the same resource during the same clock cycle, but only a single process can write to the resource during a clock cycle.  Reads and writes cannot be mixed during the same clock cycle.  Given a history of the reads and writes that occurred during a particular computation as a string trace, and an int procs representing the number of processes used by the computation, calculate the minimum duration of the computation in clock cycles.  The trace represents each read as an 'R' and each write as a 'W'.



  For example, if trace is "RWWRRR" and procs is 3, then the minimum number of clock cycles is 4: one for the first read, one each for the two writes, and one for the last group of reads.


  DEFINITION
  Class:MultiRead
  Method:minCycles
  Parameters:string, int
  Returns:int
  Method signature:int minCycles(string trace, int procs)


  CONSTRAINTS
  -trace will contain between 1 and 50 characters, inclusive.
  -Each character in trace will be 'R' or 'W'.
  -procs will be between 1 and 10, inclusive.


  EXAMPLES

  0)
  "RWWRRR"
  3

  Returns: 4

  The example above.

  1)
  "RWWRRRR"
  3

  Returns: 5

  Now the final group of 'R's takes two cycles.

  2)
  "WWWWW"
  5

  Returns: 5

  3)
  "RRRRRRRRRR"
  4

  Returns: 3

  4)
  "RWRRWWRWRWRRRWWRRRRWRRWRRWRRRRRRRRRWRWRWRRRRWRRRRR"
  4

  Returns: 30

*/
// END CUT HERE
#line 65 "MultiRead.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class MultiRead {
public:
  int minCycles(string trace, int procs) {
    int ret = 0;
    string::size_type i, j;
    for (i=0; i!=trace.size();) {
      if (trace[i] == 'W') {
	++ret;
	++i;
      }
      else {
	j = i;
	while (trace[j] != 'W' && j != trace.size()) {
	  ++j;
	}
	int diff = j - i;
	ret += diff/procs;
	if (diff % procs != 0)
	  ++ret;
	i = j;
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
      cout << "Testing MultiRead (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1455081709;
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
      MultiRead _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string trace = "RWWRRR";
	    int procs = 3;
	    _expected = 4;
	    _received = _obj.minCycles(trace, procs); break;
	  }
	case 1:
	  {
	    string trace = "RWWRRRR";
	    int procs = 3;
	    _expected = 5;
	    _received = _obj.minCycles(trace, procs); break;
	  }
	case 2:
	  {
	    string trace = "WWWWW";
	    int procs = 5;
	    _expected = 5;
	    _received = _obj.minCycles(trace, procs); break;
	  }
	case 3:
	  {
	    string trace = "RRRRRRRRRR";
	    int procs = 4;
	    _expected = 3;
	    _received = _obj.minCycles(trace, procs); break;
	  }
	case 4:
	  {
	    string trace = "RWRRWWRWRWRRRWWRRRRWRRWRRWRRRRRRRRRWRWRWRRRRWRRRRR";
	    int procs = 4;
	    _expected = 30;
	    _received = _obj.minCycles(trace, procs); break;
	  }
	  /*case 5:
	    {
	    string trace = ;
	    int procs = ;
	    _expected = ;
	    _received = _obj.minCycles(trace, procs); break;
	    }*/
	  /*case 6:
	    {
	    string trace = ;
	    int procs = ;
	    _expected = ;
	    _received = _obj.minCycles(trace, procs); break;
	    }*/
	  /*case 7:
	    {
	    string trace = ;
	    int procs = ;
	    _expected = ;
	    _received = _obj.minCycles(trace, procs); break;
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
