// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Thimbles is a hazard game with the following rules. The dealer puts three identical thimbles on the table, with a small ball underneath the first one. Then, he repeatedly selects a pair of thimbles and swaps their positions. Finally, he asks you "Where is the ball?". You win if you point to the right thimble and lose otherwise. 


You are writing the computer version of this game, and in this problem, you must write the module that determines the position of the ball after all the thimble swaps have been done. 
You will be given a vector <string> swaps which describes the swaps made, in order. Each element of swaps will be in the format "X-Y" (quotes for clarity), which means that the thimble in position X was swapped with the thimble in position Y. The positions are 1, 2 or 3. Your method should return the position of the thimble with the ball after all the swaps. 


DEFINITION
Class:Thimbles
Method:thimbleWithBall
Parameters:vector <string>
Returns:int
Method signature:int thimbleWithBall(vector <string> swaps)


CONSTRAINTS
-swaps will contain between 1 and 50 elements, inclusive.
-Each element of swaps will be in the format "X-Y" (quotes for clarity) where X and Y are distinct digits between 1 and 3, inclusive.


EXAMPLES

0)
{"1-2", "3-1"}
The path of the ball is:
12
Returns: 2

Initially the ball is under the first thimble. After the first swap it moves to the second position. The second swap doesn't affect the ball. So, the final position of the ball is 2.


1)
{"3-1", "2-3", "3-1", "3-2"}

Returns: 3

The path of the ball is:
1->3->2->2->3.

2)
{"2-3", "1-3", "2-3", "2-1", "3-1"}

Returns: 3

3)
{"1-2", "3-2", "1-2", "2-1", "2-1", "3-2", "1-3", "3-1", "1-2"}

Returns: 1



*/
// END CUT HERE
#line 58 "Thimbles.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class Thimbles {
public:
  int thimbleWithBall(vector <string> swaps) {
    int ret = 1;
    char r = '1';
    for (int i = 0; i != swaps.size(); ++i) { // each swap
      for (int j = 0; j != 3; ++j) { // each char of a swap
	if (swaps[i][j] == r) {
	  r = (j == 0)? swaps[i][2] : swaps[i][0];
	  break;
	}
      }
    }
    ret = r - '1' + 1;
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
		cout << "Testing Thimbles (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456329810;
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
		Thimbles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string swaps[] = {"1-2", "3-1"};
				_expected = 2;
				_received = _obj.thimbleWithBall(vector <string>(swaps, swaps+sizeof(swaps)/sizeof(string))); break;
			}
			case 1:
			{
				string swaps[] = {"3-1", "2-3", "3-1", "3-2"};
				_expected = 3;
				_received = _obj.thimbleWithBall(vector <string>(swaps, swaps+sizeof(swaps)/sizeof(string))); break;
			}
			case 2:
			{
				string swaps[] = {"2-3", "1-3", "2-3", "2-1", "3-1"};
				_expected = 3;
				_received = _obj.thimbleWithBall(vector <string>(swaps, swaps+sizeof(swaps)/sizeof(string))); break;
			}
			case 3:
			{
				string swaps[] = {"1-2", "3-2", "1-2", "2-1", "2-1", "3-2", "1-3", "3-1", "1-2"};
				_expected = 1;
				_received = _obj.thimbleWithBall(vector <string>(swaps, swaps+sizeof(swaps)/sizeof(string))); break;
			}
			/*case 4:
			{
				string swaps[] = ;
				_expected = ;
				_received = _obj.thimbleWithBall(vector <string>(swaps, swaps+sizeof(swaps)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string swaps[] = ;
				_expected = ;
				_received = _obj.thimbleWithBall(vector <string>(swaps, swaps+sizeof(swaps)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string swaps[] = ;
				_expected = ;
				_received = _obj.thimbleWithBall(vector <string>(swaps, swaps+sizeof(swaps)/sizeof(string))); break;
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
