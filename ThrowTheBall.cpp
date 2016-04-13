// BEGIN CUT HERE
/*
PROBLEM STATEMENT
There are N friends sitting in a circle, numbered clockwise in increasing order from 1 to N. At the beginning of the game, player 1 receives a ball. The players take turns passing the ball to each other. At the beginning of the game and before each next pass the following actions are performed. If the player with the ball has already received the ball M times, the game is over. Otherwise, if the player has received the ball p times, he'll pass the ball directly to the person L places to his left if p is even, or L places to his right if p is odd (see examples for clarification). 

Given N, M and L, return the number of times that the ball is passed.

DEFINITION
Class:ThrowTheBall
Method:timesThrown
Parameters:int, int, int
Returns:int
Method signature:int timesThrown(int N, int M, int L)


CONSTRAINTS
-N will be between 3 and 50, inclusive.
-M will be between 1 and 50, inclusive.
-L will be between 1 and N-1, inclusive.


EXAMPLES

0)
5
3
2

Returns: 10

First, player 1 gets the ball.  Since he has held the ball 1 time, he passes the ball to player 4, who is two places to his right.  This is player 4's first time holding the ball, so he gives it to player 2, who passes it to player 5.  Player 5 then passes the ball to player 3, who passes it back to player 1.  Since player 1 has now held the ball 2 times, he passes it to player 3, who passes it to player 5, who then passes the ball to player 2.  Finally, player 2 passes the ball to player 4, who then passes it to player 1.  Player 1 has now held the ball 3 times, and the game ends.

14253135241

1)
4
1
3

Returns: 0

Here, the ball is never passed.

2)
10
3
5

Returns: 4



3)
15
4
9

Returns: 15



*/
// END CUT HERE
#line 65 "ThrowTheBall.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class ThrowTheBall {
public:
  int timesThrown(int N, int M, int L) {
    int ret = 0;
    //    int arr[nn] = {};
    // variable length arrays not allowed in c++
    VI arr;
    int temp = 0;
    for (int i = 0; i != N; ++i) {
      arr.push_back (temp);
    }

    //    memset (arr, 0, sizeof(arr)); // only for -1 or 0
    /*
    for (int i = 0; i != N; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;*/
    
    // each player's receive count 0 initially

    
    for (int i = 0; (++arr[i] < M); ) { // (i < N ) && (i > -1) && 
      ++ret;
      //cout << "***i = " << i << endl;
      //      cout << "arr[" << i+1 << "] = " << arr[i] << endl << endl;
      if (arr[i] % 2 == 0) {
	i = (i + L) % N;
      } else {
	i = (i + N - L) % N;
      }
    }

    
    /*
    for (int i = 0; i != N; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;*/
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
		cout << "Testing ThrowTheBall (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456373707;
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
		ThrowTheBall _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int M = 3;
				int L = 2;
				_expected = 10;
				_received = _obj.timesThrown(N, M, L); break;
			}
				case 1:
			{
				int N = 4;
				int M = 1;
				int L = 3;
				_expected = 0;
				_received = _obj.timesThrown(N, M, L); break;
			}
			case 2:
			{
				int N = 10;
				int M = 3;
				int L = 5;
				_expected = 4;
				_received = _obj.timesThrown(N, M, L); break;
			}
			case 3:
			{
				int N = 15;
				int M = 4;
				int L = 9;
				_expected = 15;
				_received = _obj.timesThrown(N, M, L); break;
			}
			/*case 4:
			{
				int N = ;
				int M = ;
				int L = ;
				_expected = ;
				_received = _obj.timesThrown(N, M, L); break;
			}*/
			/*case 5:
			{
				int N = ;
				int M = ;
				int L = ;
				_expected = ;
				_received = _obj.timesThrown(N, M, L); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				int L = ;
				_expected = ;
				_received = _obj.timesThrown(N, M, L); break;
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
