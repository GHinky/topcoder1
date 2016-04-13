// BEGIN CUT HERE
/*
PROBLEM STATEMENT

You are packing a stack of books into some boxes,
packing as many books as you can into each box without exceeding a given weight limit.
Once you have packed as many books into a box as you can, you close and seal that box, and then begin filling the next one.
You take the books off the stack in order, packing each one before picking up the next.



The weights of the books will be given as a vector <int> weights,
where the first element is the weight of the book on top of the stack
and the last element is the weight of the book on the bottom of the stack.
The maximum weight that can fit into each box will be given as an int maxWeight.
Return the minimum number of boxes you will need.



DEFINITION
Class:BoxesOfBooks
Method:boxes
Parameters:vector <int>, int
Returns:int
Method signature:int boxes(vector <int> weights, int maxWeight)


CONSTRAINTS
-weights will contain between 0 and 50 elements, inclusive.
-maxWeight will be between 1 and 1000, inclusive.
-Each element of weights will be between 1 and maxWeight, inclusive.


EXAMPLES

0)
{ 5, 5, 5, 5, 5, 5 }
10

Returns: 3

You have 6 books that weigh 5 kilograms each.  Each box can hold 10 kilograms (2 books).  Therefore, you need 3 boxes.

1)
{ 51, 51, 51, 51, 51 }
100

Returns: 5

Each box can hold 100 kg, but since the books weigh 51 kg each, you can only put one in each box.

2)
{ 1, 1, 1, 7, 7, 7 }
8

Returns: 4

You would like to put one 1 kg book and one 7 kg book in each of 3 boxes.  But, since you must pack the books in order, you end up putting the three 1 kg books in one box and each of the three 7 kg books in its own box, for a total of 4 boxes.

3)
{ 12, 1, 11, 2, 10, 3, 4, 5, 6, 6, 1 }
12

Returns: 6



4)
{ }
7

Returns: 0



5)
{ 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20 }
1000

Returns: 1



*/
// END CUT HERE
#line 91 "BoxesOfBooks.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class BoxesOfBooks {
public:
  int boxes(vector <int> weights, int maxWeight) {
    int ret = 1;
    
    int spaceleft = maxWeight;
    for (int i = 0; i != weights.size(); ++i) {
      
      if (weights[i] <= spaceleft) {
	spaceleft = spaceleft - weights[i];
      }
      else {
	++ret;
	spaceleft = maxWeight - weights[i];
      }
    }

    if (weights.size() == 0)
      ret = 0;
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
		cout << "Testing BoxesOfBooks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456571712;
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
		BoxesOfBooks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int weights[] = { 5, 5, 5, 5, 5, 5 };
				int maxWeight = 10;
				_expected = 3;
				_received = _obj.boxes(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), maxWeight); break;
			}
			case 1:
			{
				int weights[] = { 51, 51, 51, 51, 51 };
				int maxWeight = 100;
				_expected = 5;
				_received = _obj.boxes(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), maxWeight); break;
			}
			case 2:
			{
				int weights[] = { 1, 1, 1, 7, 7, 7 };
				int maxWeight = 8;
				_expected = 4;
				_received = _obj.boxes(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), maxWeight); break;
			}
			case 3:
			{
				int weights[] = { 12, 1, 11, 2, 10, 3, 4, 5, 6, 6, 1 };
				int maxWeight = 12;
				_expected = 6;
				_received = _obj.boxes(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), maxWeight); break;
			}
			case 4:
			{
				int weights[] = { };
				int maxWeight = 7;
				_expected = 0;
				_received = _obj.boxes(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), maxWeight); break;
			}
			case 5:
			{
				int weights[] = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
				                  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
				                  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
				                  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
				                  20, 20, 20, 20, 20, 20, 20, 20, 20, 20 };
				int maxWeight = 1000;
				_expected = 1;
				_received = _obj.boxes(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), maxWeight); break;
			}
			/*case 6:
			{
				int weights[] = ;
				int maxWeight = ;
				_expected = ;
				_received = _obj.boxes(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), maxWeight); break;
			}*/
			/*case 7:
			{
				int weights[] = ;
				int maxWeight = ;
				_expected = ;
				_received = _obj.boxes(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), maxWeight); break;
			}*/
			/*case 8:
			{
				int weights[] = ;
				int maxWeight = ;
				_expected = ;
				_received = _obj.boxes(vector <int>(weights, weights+sizeof(weights)/sizeof(int)), maxWeight); break;
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
