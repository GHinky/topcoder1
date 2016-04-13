// BEGIN CUT HERE
/*
PROBLEM STATEMENT
An integer N greater than 1 is called almost prime if and only if the following conditions hold:

N is not prime.  In other words, it is divisible by some positive integer other than 1 and itself.
Each positive divisor of N (other than 1) is greater than 10.


Return the smallest almost prime number that is strictly greater than m.


DEFINITION
Class:AlmostPrimeNumbers
Method:getNext
Parameters:int
Returns:int
Method signature:int getNext(int m)


CONSTRAINTS
-m will be between 1 and 10^6, inclusive.


EXAMPLES

0)
200

Returns: 209

201 is divisible by 3, which is less than 10, so 201 is not almost prime.  202, 204, 206, and 208 are all divisible by 2.  203 is divisible by 7, 205 by 5, and 207 by 3.  So, the smallest almost prime number greater than 200 is 209 = 11*19.

1)
666

Returns: 667

667 = 23*29, so it's almost prime.

2)
1000

Returns: 1003

3)
1591

Returns: 1633

4)
6

Returns: 121

The smallest almost prime number is 11*11 = 121.

*/
// END CUT HERE
#line 61 "AlmostPrimeNumbers.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class AlmostPrimeNumbers {
public:
  bool prime (int n) {
    bool ret = true;
    int L = sqrt (n) + 1;
    for (int i = 2; i < L; ++i) {
      if (n % i == 0)
	ret = false;
    }
    return ret;
  }
  bool div10orMore (int n) {
    bool ret = true;
    for (int i = 2; i < 10; ++i) {
      if (n % i == 0)
	ret = false;
    }
    return ret;
  }
  int getNext(int m) {
    int ret = -69;
    int i = m+1;
    while (prime(i) || !div10orMore(i)) {
      ++i;
    }
    ret = i;
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
		cout << "Testing AlmostPrimeNumbers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456500466;
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
		AlmostPrimeNumbers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 200;
				_expected = 209;
				_received = _obj.getNext(m); break;
			}
			case 1:
			{
				int m = 666;
				_expected = 667;
				_received = _obj.getNext(m); break;
			}
			case 2:
			{
				int m = 1000;
				_expected = 1003;
				_received = _obj.getNext(m); break;
			}
			case 3:
			{
				int m = 1591;
				_expected = 1633;
				_received = _obj.getNext(m); break;
			}
			case 4:
			{
				int m = 6;
				_expected = 121;
				_received = _obj.getNext(m); break;
			}
			/*case 5:
			{
				int m = ;
				_expected = ;
				_received = _obj.getNext(m); break;
			}*/
			/*case 6:
			{
				int m = ;
				_expected = ;
				_received = _obj.getNext(m); break;
			}*/
			/*case 7:
			{
				int m = ;
				_expected = ;
				_received = _obj.getNext(m); break;
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
