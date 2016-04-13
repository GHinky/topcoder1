// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Rugs come in various sizes. In fact, we can find a rug with any integer width
and length, except that no rugs have a distinct width and length that are both even integers. For example, we can find a 4x4 rug, but not a 2x4 rug.  We want to know how many different choices we have for a
given area.

Create a class RugSizes the contains a method rugCount that is given the desired
area and returns the number of different ways in which we can choose a rug size that
will cover that exact area.
Do not count the same size twice -- a 6 x 9 rug and a 9 x 6 rug should be 
counted as one choice.



DEFINITION
Class:RugSizes
Method:rugCount
Parameters:int
Returns:int
Method signature:int rugCount(int area)


CONSTRAINTS
-area will be between 1 and 100,000, inclusive.


EXAMPLES

0)
4

Returns: 2



   The choices are 1 x 4 (or equivalently 4 x 1) and 2 x 2.



1)
8

Returns: 1

 

   Only 1 x 8 is available. Note that 2 x 4 has the desired area, but is not
   available since its width and length differ and are both even numbers.


*/
// END CUT HERE
#line 56 "RugSizes.cpp"
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class RugSizes {
public:
  bool evenp (int i) {
    return (i % 2 == 0);
  }
  int rugCount(int area) {
    int res = 0;
    vector<int> factors1; //factors <= sqrt(area)
    vector<int> factors2; //factors > sqrt(area)
    double sa = sqrt (area);
    int sai = (int) sa;
    for (int i = 1; i != sai + 1; ++i) {
      if (area % i == 0) {
	factors1.push_back(i);
	factors2.push_back(area / i);
      }
    }
    for (vector<int>::size_type i = 0; i != factors1.size(); ++i) {
      if (!(evenp(factors1[i]) && evenp(factors2[i])))
	++res;
    }
    if (sa == sai && evenp(sai))
      ++res;
    return res;
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
		cout << "Testing RugSizes (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455079937;
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
		RugSizes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int area = 4;
				_expected = 2;
				_received = _obj.rugCount(area); break;
			}
			case 1:
			{
				int area = 8;
				_expected = 1;
				_received = _obj.rugCount(area); break;
			}
			/*case 2:
			{
				int area = ;
				_expected = ;
				_received = _obj.rugCount(area); break;
			}*/
			/*case 3:
			{
				int area = ;
				_expected = ;
				_received = _obj.rugCount(area); break;
			}*/
			/*case 4:
			{
				int area = ;
				_expected = ;
				_received = _obj.rugCount(area); break;
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
