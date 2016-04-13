// BEGIN CUT HERE
/*
PROBLEM STATEMENT

There's a circular subway line that contains n stations numbered 0 through n-1.  The time to travel between stations 0 and 1 is t[0], the time to travel between stations 1 and 2 is t[1], ..., the time to travel between stations n-1 and 0 is t[n-1].  You can travel between stations in either direction, so there are always two ways to get from one station to another without visiting the same station more than once.  For example, if there are 4 stations, the two ways of getting from station 1 to station 3 are 1-2-3 and 1-0-3.  The total travel time in the first case is t[1] + t[2], and in the second case, it is t[0] + t[3].  When a person needs to get from one station to another, she always chooses the faster of the two ways.


You are given a vector <int> t.  Find two stations such that the fastest travel time between them is the maximal possible.  Return this time.


DEFINITION
Class:CircularLine
Method:longestTravel
Parameters:vector <int>
Returns:int
Method signature:int longestTravel(vector <int> t)


CONSTRAINTS
-t will contain between 3 and 50 elements, inclusive.
-Each element of t will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,1,1,1}

Returns: 2



1)
{1,4,4,1,5}

Returns: 7

The longest travel time is between stations 1 and 3.

2)
{1,1,1000}

Returns: 2

You must never travel from station 2 to station 0 using the 1000 segment.

3)
{1,1000,1,1000}

Returns: 1001



4)
{1,1,1,1,4}

Returns: 4



*/
// END CUT HERE
#line 64 "CircularLine.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class CircularLine {
public:
  int longestTravel(vector <int> t) {
    const int N = t.size();
    int ret = 0;
    int cycletime = accumulate (t.begin(), t.end(), 0);
    
    for (int i = 0; i != N; ++i) {
      for (int j = 0; j != N; ++j) { // (i, j) is a general station to station

	int time = 0;
	for (int k = i; k % N != j; ++k) {
	  time += t[k % N];
	}
	time = (time < (cycletime - time))? time : (cycletime - time);
	ret = max (ret, time);
	
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
		cout << "Testing CircularLine (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456600109;
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
		CircularLine _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int t[] = {1,1,1,1};
				_expected = 2;
				_received = _obj.longestTravel(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 1:
			{
				int t[] = {1,4,4,1,5};
				_expected = 7;
				_received = _obj.longestTravel(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 2:
			{
				int t[] = {1,1,1000};
				_expected = 2;
				_received = _obj.longestTravel(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 3:
			{
				int t[] = {1,1000,1,1000};
				_expected = 1001;
				_received = _obj.longestTravel(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 4:
			{
				int t[] = {1,1,1,1,4};
				_expected = 4;
				_received = _obj.longestTravel(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			/*case 5:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.longestTravel(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.longestTravel(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.longestTravel(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
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
