// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have several trophies sitting on a shelf in a straight line.  Their heights are given in a vector <int> trophies, from left to right.  The shelf is positioned so that whenever people enter your room, they see it directly from the left side.  In other words, the leftmost trophy is completely visible to the viewer, the next trophy in line is directly behind it, and so on.

Unfortunately, tall trophies near the left side of the shelf might block the view of other trophies.  A trophy is visible only if every trophy in front of it (from the viewer's perspective) is strictly shorter than it is.  You wonder if rotating the shelf 180 degrees would increase the number of visible trophies.

Return a vector <int> containing exactly two elements.  The first element should be the number of trophies visible when viewing the shelf directly from the left side, and the second element should be the number of trophies visible when viewing the shelf directly from the right side.

DEFINITION
Class:TrophyShelf
Method:countVisible
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> countVisible(vector <int> trophies)


CONSTRAINTS
-trophies will contain between 1 and 50 elements, inclusive.
-Each element of trophies will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,2,3,4,5}

Returns: {5, 1 }

When viewed from the left, each trophy is taller than all the trophies in front of it.  However, when viewed from the right, the first trophy blocks the view of all the other trophies.

1)
{5,5,5,5}

Returns: {1, 1 }

Since all trophies have the same height, only the first is visible when viewed from each direction.

2)
{1,2,5,2,1}

Returns: {3, 3 }

This trophy shelf is symmetric.

3)
{1,4,2,5,3,7,1}

Returns: {4, 2 }



*/
// END CUT HERE
#line 56 "TrophyShelf.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class TrophyShelf {
public:
  vector <int> countVisible(vector <int> trophies) {
    VI ret;

    int l = 1;
    int running_lmax = trophies[0];
    for (int i = 1; i != trophies.size(); ++i) {
      if (trophies[i] > running_lmax) {
	running_lmax = trophies[i];
	++l;
      }
    }

    int r = 1;
    int running_rmax = trophies[trophies.size() - 1];
    if (trophies.size() > 1) {
      for (int i = trophies.size() - 2; i != -1; --i) {
	if (trophies[i] > running_rmax) {
	  running_rmax = trophies[i];
	  ++r;
	}
      }
    }

    ret.push_back (l);
    ret.push_back (r);
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
		cout << "Testing TrophyShelf (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456568481;
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
		TrophyShelf _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int trophies[] = {1,2,3,4,5};
				int __expected[] = {5, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countVisible(vector <int>(trophies, trophies+sizeof(trophies)/sizeof(int))); break;
			}
			case 1:
			{
				int trophies[] = {5,5,5,5};
				int __expected[] = {1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countVisible(vector <int>(trophies, trophies+sizeof(trophies)/sizeof(int))); break;
			}
			case 2:
			{
				int trophies[] = {1,2,5,2,1};
				int __expected[] = {3, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countVisible(vector <int>(trophies, trophies+sizeof(trophies)/sizeof(int))); break;
			}
			case 3:
			{
				int trophies[] = {1,4,2,5,3,7,1};
				int __expected[] = {4, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countVisible(vector <int>(trophies, trophies+sizeof(trophies)/sizeof(int))); break;
			}
			/*case 4:
			{
				int trophies[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countVisible(vector <int>(trophies, trophies+sizeof(trophies)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int trophies[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countVisible(vector <int>(trophies, trophies+sizeof(trophies)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int trophies[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.countVisible(vector <int>(trophies, trophies+sizeof(trophies)/sizeof(int))); break;
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
