// BEGIN CUT HERE
/*
PROBLEM STATEMENT
In soccer leagues, the winner of a match is awarded with 3 points and the loser 0 points. In case of a tie, both teams are awarded with 1 point each.

Create a class Soccer containing the method maxPoints which takes a vector <int> wins, the number of wins for each team in the league, and a vector <int> ties, the number of ties for each team in the league and returns an int, the maximum points a team in the league has. The
i'th elements of wins and ties correspond to the number of wins and ties respectively for team i.

DEFINITION
Class:Soccer
Method:maxPoints
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxPoints(vector <int> wins, vector <int> ties)


NOTES
-Two or more teams may have the same number of points.


CONSTRAINTS
-wins will contain between 1 and 50 elements, inclusive.
-ties will contain between 1 and 50 elements, inclusive.
-wins will contain the same number of elements as ties.
-Each element in wins will be between 0 and 100, inclusive.
-Each element in ties will be between 0 and 100, inclusive.


EXAMPLES

0)
{1,4,3,0,0}
{3,1,5,3,1}

Returns: 14

The number of points for each team are:

Team 0: 3*1 + 1*3 = 6 points
Team 1: 3*4 + 1*1 = 13 points
Team 2: 3*3 + 1*5 = 14 points
Team 3: 3*0 + 1*3 = 3 points
Team 4: 3*0 + 1*1 = 1 point

So team 2 has the most number of points, 14. The method should thus return 14.


1)
{12,45,20,17,48,0}
{48,10,53,94,0,100}

Returns: 145

Both team 1 and team 3 got 145 points, which is the maximum.

2)
{35,0}
{0,76}

Returns: 105

3)
{0,0,0,0}
{0,0,0,0}

Returns: 0

4)
{13,79,26,73,14,89,71,37,89,71,19,59,39}
{88,27,5,70,84,94,20,50,2,11,31,22,50}

Returns: 361

*/
// END CUT HERE
#line 77 "Soccer.cpp"
#include <string>
#include <vector>
using namespace std;
class Soccer {
	public:
	int maxPoints(vector <int> wins, vector <int> ties) {
	  int ret = 0;
	  vector<int>::size_type no_of_matches = wins.size();
	  for (vector<int>::size_type i = 0; i != no_of_matches; ++i)
	    ret = max (ret, 3*wins[i] + ties[i]);
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
		cout << "Testing Soccer (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454922537;
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
		Soccer _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int wins[] = {1,4,3,0,0};
				int ties[] = {3,1,5,3,1};
				_expected = 14;
				_received = _obj.maxPoints(vector <int>(wins, wins+sizeof(wins)/sizeof(int)), vector <int>(ties, ties+sizeof(ties)/sizeof(int))); break;
			}
			case 1:
			{
				int wins[] = {12,45,20,17,48,0};
				int ties[] = {48,10,53,94,0,100};
				_expected = 145;
				_received = _obj.maxPoints(vector <int>(wins, wins+sizeof(wins)/sizeof(int)), vector <int>(ties, ties+sizeof(ties)/sizeof(int))); break;
			}
			case 2:
			{
				int wins[] = {35,0};
				int ties[] = {0,76};
				_expected = 105;
				_received = _obj.maxPoints(vector <int>(wins, wins+sizeof(wins)/sizeof(int)), vector <int>(ties, ties+sizeof(ties)/sizeof(int))); break;
			}
			case 3:
			{
				int wins[] = {0,0,0,0};
				int ties[] = {0,0,0,0};
				_expected = 0;
				_received = _obj.maxPoints(vector <int>(wins, wins+sizeof(wins)/sizeof(int)), vector <int>(ties, ties+sizeof(ties)/sizeof(int))); break;
			}
			case 4:
			{
				int wins[] = {13,79,26,73,14,89,71,37,89,71,19,59,39};
				int ties[] = {88,27,5,70,84,94,20,50,2,11,31,22,50};
				_expected = 361;
				_received = _obj.maxPoints(vector <int>(wins, wins+sizeof(wins)/sizeof(int)), vector <int>(ties, ties+sizeof(ties)/sizeof(int))); break;
			}
			/*case 5:
			{
				int wins[] = ;
				int ties[] = ;
				_expected = ;
				_received = _obj.maxPoints(vector <int>(wins, wins+sizeof(wins)/sizeof(int)), vector <int>(ties, ties+sizeof(ties)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int wins[] = ;
				int ties[] = ;
				_expected = ;
				_received = _obj.maxPoints(vector <int>(wins, wins+sizeof(wins)/sizeof(int)), vector <int>(ties, ties+sizeof(ties)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int wins[] = ;
				int ties[] = ;
				_expected = ;
				_received = _obj.maxPoints(vector <int>(wins, wins+sizeof(wins)/sizeof(int)), vector <int>(ties, ties+sizeof(ties)/sizeof(int))); break;
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
