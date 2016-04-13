// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Jane tries her best to stay fit. Knowing this, her sister decided to play a prank on Jane: after Jane's old scale broke down, her sister got her a new scale that shows the square of a person's weight, instead of the real weight.

Not noticing the change, Jane has been using the scale for a while. One morning she screamed "Oh no! I gained apparentGain pounds!". Given an int apparentGain (the difference between the square of Jane's current weight and the square of her previous weight), return a vector <int> containing Jane's possible real weights after the latest measurement, sorted in ascending order.

All weights (displayed and real, previous and current) are positive integers.


DEFINITION
Class:Prank
Method:realWeight
Parameters:int
Returns:vector <int>
Method signature:vector <int> realWeight(int apparentGain)


CONSTRAINTS
-apparentGain will be between 1 and 100000, inclusive.


EXAMPLES

0)
233

Returns: {117 }

If Jane had previously weighed 116 pounds, the scale would have shown 116^2 = 13456. If she gained 1 pound, the scale would show 117^2 = 13689, for an apparent gain of 13689 - 13456 = 233.


1)
15

Returns: {4, 8 }

Assuming in this example Jane is actually a small animal, she could have gone from 1 to 4 or from 7 to 8.


2)
1440

Returns: {38, 39, 42, 46, 49, 53, 66, 77, 94, 123, 182, 361 }



3)
100000

Returns: {325, 350, 550, 665, 1025, 1270, 2510, 3133, 5005, 6254, 12502, 25001 }

This is the largest input.

4)
93301

Returns: {3595, 46651 }

Watch out for overflow!

5)
16

Returns: {5 }



*/
// END CUT HERE
#line 72 "Prank.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class Prank {
public:
  vector <int> realWeight(int a) {
    VI ret;
    int sra = sqrt(a) + 1;
    for (int n = 1; ((n*n - (n-1)*(n-1)) <= a); ++n) {
      for (int o = n - sra; o != n; ++o) {
	if ((n*n - o*o == a) && (o >= 1)) {
	  //	  cout << "n = " << n << " & o = " << o << endl;
	  ret.push_back(n);
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
		cout << "Testing Prank (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456551368;
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
		Prank _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int apparentGain = 233;
				int __expected[] = {117 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.realWeight(apparentGain); break;
			}
			case 1:
			{
				int apparentGain = 15;
				int __expected[] = {4, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.realWeight(apparentGain); break;
			}
			case 2:
			{
				int apparentGain = 1440;
				int __expected[] = {38, 39, 42, 46, 49, 53, 66, 77, 94, 123, 182, 361 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.realWeight(apparentGain); break;
			}
			case 3:
			{
				int apparentGain = 100000;
				int __expected[] = {325, 350, 550, 665, 1025, 1270, 2510, 3133, 5005, 6254, 12502, 25001 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.realWeight(apparentGain); break;
			}
			case 4:
			{
				int apparentGain = 93301;
				int __expected[] = {3595, 46651 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.realWeight(apparentGain); break;
			}
			case 5:
			{
				int apparentGain = 16;
				int __expected[] = {5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.realWeight(apparentGain); break;
			}
			/*case 6:
			{
				int apparentGain = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.realWeight(apparentGain); break;
			}*/
			/*case 7:
			{
				int apparentGain = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.realWeight(apparentGain); break;
			}*/
			/*case 8:
			{
				int apparentGain = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.realWeight(apparentGain); break;
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
