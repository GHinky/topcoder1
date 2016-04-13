// BEGIN CUT HERE
/*
PROBLEM STATEMENT
On January 1, 2007, a confectioner made several candies.

On the last day of each month she allows her children to eat several of those candies.

The lifetime of a candy is the number of days between January 1 and the day the candy is eaten, inclusive. For example, the lifetime of a candy eaten on January 31 is 31, and the lifetime of a candy eaten on December 31 is 365 (note that 2007 wasn't a leap year).

You are given a vector <int> eatenCandies, the i-th element of which is the number of candies eaten on the last day of the i-th month of 2007 (January is month 0, February is month 1, etc.).  Return the average lifetime of the candies.

DEFINITION
Class:AverageCandyLifetime
Method:getAverage
Parameters:vector <int>
Returns:double
Method signature:double getAverage(vector <int> eatenCandies)


NOTES
-The year 2007 was not a leap year.
-The number of days in the months of 2007, in order, were 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 and 31.
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-eatenCandies will contain exactly 12 elements.
-Each element of eatenCandies will be between 0 and 1000, inclusive.
-The sum of all the elements in eatenCandies will be greater than 0.


EXAMPLES

0)
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Returns: 60.5

One candy was eaten on January 31 and the other was eaten on March 31.

The lifetimes of the candies are 31 and 31+28+31=90. The average lifetime is (31+90)/2=60.5.

1)
{0, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Returns: 59.0

All candies were eaten on February 28. The lifetime of each candy is 31+28=59, so the average candy lifetime is 59.0.

2)
{0, 0, 0, 0, 0, 1, 0, 0, 0, 50, 0, 0}

Returns: 301.5882352941176

Most of the candies were eaten on October 31 (Halloween), and the lifetime of each of those candies is 304. The average lifetime is smaller than 304, because of a candy with lifetime 181, eaten on June 30.

3)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}

Returns: 252.80769230769232



*/
// END CUT HERE
#line 67 "AverageCandyLifetime.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class AverageCandyLifetime {
public:
  double getAverage(vector <int> eatenCandies) {
    double ret = 0.0;
    double tot_candies = 0.0;
    const int yr [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int yr2 [12];
    for (int i = 0; i != 12; ++i) {
      yr2[i] = 0;
      for (int j = i; j != -1; --j) {
	yr2[i] += yr[j];
      }
    }
    for (int i = 0; i != 12; ++i) {
      //      cout << yr2[i] << " *** ";
    }
    // cout << endl;
    for (int i = 0; i != 12; ++i) {
      int ein = eatenCandies[i];
      tot_candies += ein;
      ret += yr2[i] * ein;
    }
    ret /= tot_candies;
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
		cout << "Testing AverageCandyLifetime (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456580273;
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
		AverageCandyLifetime _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int eatenCandies[] = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = 60.5;
				_received = _obj.getAverage(vector <int>(eatenCandies, eatenCandies+sizeof(eatenCandies)/sizeof(int))); break;
			}
			case 1:
			{
				int eatenCandies[] = {0, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = 59.0;
				_received = _obj.getAverage(vector <int>(eatenCandies, eatenCandies+sizeof(eatenCandies)/sizeof(int))); break;
			}
			case 2:
			{
				int eatenCandies[] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 50, 0, 0};
				_expected = 301.5882352941176;
				_received = _obj.getAverage(vector <int>(eatenCandies, eatenCandies+sizeof(eatenCandies)/sizeof(int))); break;
			}
			case 3:
			{
				int eatenCandies[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
				_expected = 252.80769230769232;
				_received = _obj.getAverage(vector <int>(eatenCandies, eatenCandies+sizeof(eatenCandies)/sizeof(int))); break;
			}
			/*case 4:
			{
				int eatenCandies[] = ;
				_expected = ;
				_received = _obj.getAverage(vector <int>(eatenCandies, eatenCandies+sizeof(eatenCandies)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int eatenCandies[] = ;
				_expected = ;
				_received = _obj.getAverage(vector <int>(eatenCandies, eatenCandies+sizeof(eatenCandies)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int eatenCandies[] = ;
				_expected = ;
				_received = _obj.getAverage(vector <int>(eatenCandies, eatenCandies+sizeof(eatenCandies)/sizeof(int))); break;
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
