// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Your little son is counting numbers with his left hand.  Starting with his thumb and going toward his pinky, he counts each finger in order.  After counting his pinky, he reverses direction and goes back toward his thumb.  He repeats this process until he reaches his target number.  He never skips a finger.  For example, to count to ten, he would count: thumb, index, middle, ring, pinky, ring, middle, index, thumb, index.

Sadly, one of his fingers hurts and he can only count on it a limited number of times.  His fingers are numbered 1 through 5 from thumb to pinky.  You are given an int weakFinger, the finger that hurts, and an int maxCount, the maximum number of times he can use that finger.  Return the largest number he can count to.  If he cannot even begin counting, return 0.

DEFINITION
Class:FingerCounting
Method:maxNumber
Parameters:int, int
Returns:int
Method signature:int maxNumber(int weakFinger, int maxCount)


CONSTRAINTS
-weakFinger will be between 1 and 5, inclusive.
-maxCount will be between 0 and 100000, inclusive.


EXAMPLES

0)
2
3

Returns: 15

The first 15 numbers are counted with fingers 1,2,3,4,5,4,3,2,1,2,3,4,5,4,3. He would then have to use finger 2 for the next number, but since he has already used it 3 times, he has to stop.

1)
1
0

Returns: 0

He needs to use his thumb when counting the first number, 1, but it's too weak to be used even once.

2)
5
0

Returns: 4

Even though his pinky cannot be used at all, he can count 1,2,3,4 with the other fingers.

3)
2
48

Returns: 193



4)
5
973

Returns: 7788



5)
3
99999

Returns: 399998



*/
// END CUT HERE
#line 74 "FingerCounting.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class FingerCounting {
public:
  int maxNumber(int weakFinger, int maxCount) {
    int ret;
    weakFinger -= 1; // 0-index
    int arr[5] = {0, 0, 0, 0, 0};
    int indexes[8] = { 0, 1, 2, 3, 4, 3, 2, 1 };

    ret = 0;
    while (arr[weakFinger] != maxCount + 1) {
      memset (arr, 0, sizeof arr);
      int rem = ret % 8;
      int cycles = ret / 8;
      arr[0] = cycles;
      arr[1] = 2*cycles;
      arr[2] = 2*cycles;
      arr[3] = 2*cycles;
      arr[4] = cycles;
      for (int i = 0; i != rem; ++i) {
	arr[indexes[i]] += 1;
      }
      ++ret;
    }
    //ret -= 2;
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
		cout << "Testing FingerCounting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456572555;
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
		FingerCounting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int weakFinger = 2;
				int maxCount = 3;
				_expected = 15;
				_received = _obj.maxNumber(weakFinger, maxCount); break;
			}
			case 1:
			{
				int weakFinger = 1;
				int maxCount = 0;
				_expected = 0;
				_received = _obj.maxNumber(weakFinger, maxCount); break;
			}
			case 2:
			{
				int weakFinger = 5;
				int maxCount = 0;
				_expected = 4;
				_received = _obj.maxNumber(weakFinger, maxCount); break;
			}
			case 3:
			{
				int weakFinger = 2;
				int maxCount = 48;
				_expected = 193;
				_received = _obj.maxNumber(weakFinger, maxCount); break;
			}
			case 4:
			{
				int weakFinger = 5;
				int maxCount = 973;
				_expected = 7788;
				_received = _obj.maxNumber(weakFinger, maxCount); break;
			}
			case 5:
			{
				int weakFinger = 3;
				int maxCount = 99999;
				_expected = 399998;
				_received = _obj.maxNumber(weakFinger, maxCount); break;
			}
			/*case 6:
			{
				int weakFinger = ;
				int maxCount = ;
				_expected = ;
				_received = _obj.maxNumber(weakFinger, maxCount); break;
			}*/
			/*case 7:
			{
				int weakFinger = ;
				int maxCount = ;
				_expected = ;
				_received = _obj.maxNumber(weakFinger, maxCount); break;
			}*/
			/*case 8:
			{
				int weakFinger = ;
				int maxCount = ;
				_expected = ;
				_received = _obj.maxNumber(weakFinger, maxCount); break;
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
