// BEGIN CUT HERE
/*
PROBLEM STATEMENT
In order to make its roads safer, the government of a particular country has decided to introduce a speed limit that varies throughout the day. At busy times, the speed limit will decrease to reduce the risk of a dangerous accident. You need to drive a distance of journeyLength units and want to know how long it will take you.
You are given details of the speed limit in a vector <int> speedLimit. Element i (zero-based) gives the speed limit in DISTANCE UNITS/TIME UNITS that is in force between times T = i and T = i + 1. speedLimit describes the speed limit for a full day, so after this the pattern repeats (i.e., if N is the number of elements in speedLimit, the speed limit between times N and N+1  is given by speedLimit[0], etc.). You start your journey at time T = 0 and should assume that you travel exactly at the speed limit for your entire journey. Return a double containing the amount of time it takes to complete your journey.

DEFINITION
Class:VariableSpeedLimit
Method:journeyTime
Parameters:int, vector <int>
Returns:double
Method signature:double journeyTime(int journeyLength, vector <int> speedLimit)


NOTES
-Your return value must be accurate to an absolute or relative tolerance of 1E-9.


CONSTRAINTS
-journeyLength will be between 1 and 100000 (10^5), inclusive.
-speedLimit will contain between 1 and 50 elements, inclusive.
-Each element of speedLimit will be between 1 and 100, inclusive.


EXAMPLES

0)
100
{50}

Returns: 2.0

Here the speed limit doesn't change. The journey therefore takes a time of DISTANCE/SPEED = 100/50 = 2 time units.

1)
100
{50,25}

Returns: 2.5

Now the speed limit drops to 25 every other time unit. You drive 50 units in the first time unit and 25 in the second. You reach the end of your journey halfway through the third time unit.

2)
1000
{50,40,30,40,50}

Returns: 24.0



3)
2058
{80,43,57,23,28,45,60,75,73,80}

Returns: 37.4



4)
17216
{26,30,62,55,51,56,58,4,60,23,31}

Returns: 415.03333333333336

5)
9839
{45,90,13,4,81,50,81,10,64,86,69}

Returns: 182.8395061728395

*/
// END CUT HERE
#line 74 "VariableSpeedLimit.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class VariableSpeedLimit {
public:
  double journeyTime(int journeyLength, vector <int> speedLimit) {
    double journeyTime = 0.0;
    double l = journeyLength;
    int jt = 0;
    while (l - speedLimit[jt % speedLimit.size()] >= 0) {
      l -= speedLimit[jt % speedLimit.size()];
      ++jt;
    }

    journeyTime = jt + l / speedLimit[jt % speedLimit.size()];

    return journeyTime;
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
		cout << "Testing VariableSpeedLimit (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456581056;
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
		VariableSpeedLimit _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int journeyLength = 100;
				int speedLimit[] = {50};
				_expected = 2.0;
				_received = _obj.journeyTime(journeyLength, vector <int>(speedLimit, speedLimit+sizeof(speedLimit)/sizeof(int))); break;
			}
			case 1:
			{
				int journeyLength = 100;
				int speedLimit[] = {50,25};
				_expected = 2.5;
				_received = _obj.journeyTime(journeyLength, vector <int>(speedLimit, speedLimit+sizeof(speedLimit)/sizeof(int))); break;
			}
			case 2:
			{
				int journeyLength = 1000;
				int speedLimit[] = {50,40,30,40,50};
				_expected = 24.0;
				_received = _obj.journeyTime(journeyLength, vector <int>(speedLimit, speedLimit+sizeof(speedLimit)/sizeof(int))); break;
			}
			case 3:
			{
				int journeyLength = 2058;
				int speedLimit[] = {80,43,57,23,28,45,60,75,73,80};
				_expected = 37.4;
				_received = _obj.journeyTime(journeyLength, vector <int>(speedLimit, speedLimit+sizeof(speedLimit)/sizeof(int))); break;
			}
			case 4:
			{
				int journeyLength = 17216;
				int speedLimit[] = {26,30,62,55,51,56,58,4,60,23,31};
				_expected = 415.03333333333336;
				_received = _obj.journeyTime(journeyLength, vector <int>(speedLimit, speedLimit+sizeof(speedLimit)/sizeof(int))); break;
			}
			case 5:
			{
				int journeyLength = 9839;
				int speedLimit[] = {45,90,13,4,81,50,81,10,64,86,69};
				_expected = 182.8395061728395;
				_received = _obj.journeyTime(journeyLength, vector <int>(speedLimit, speedLimit+sizeof(speedLimit)/sizeof(int))); break;
			}
			/*case 6:
			{
				int journeyLength = ;
				int speedLimit[] = ;
				_expected = ;
				_received = _obj.journeyTime(journeyLength, vector <int>(speedLimit, speedLimit+sizeof(speedLimit)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int journeyLength = ;
				int speedLimit[] = ;
				_expected = ;
				_received = _obj.journeyTime(journeyLength, vector <int>(speedLimit, speedLimit+sizeof(speedLimit)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int journeyLength = ;
				int speedLimit[] = ;
				_expected = ;
				_received = _obj.journeyTime(journeyLength, vector <int>(speedLimit, speedLimit+sizeof(speedLimit)/sizeof(int))); break;
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
