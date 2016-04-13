// BEGIN CUT HERE
/*
PROBLEM STATEMENT
In a chess tournament, each pair of distinct players played a single match against each other.  Each match resulted in one of three outcomes: the first player won, the second player won, or there was a draw.  The ambiguity number of the tournament is defined as the number of distinct triples of players (a, b, c) such that player a defeated b, player b defeated player c, and player c defeated player a.

You are given the results of all the matches as a vector <string> table.  The j-th character of the i-th element of table is '1' (one) if player i defeated player j, '0' (zero) if player j defeated player i, or '-' if the match between players i and j resulted in a draw.  Return the ambiguity number of the given tournament.

DEFINITION
Class:TournamentsAmbiguityNumber
Method:scrutinizeTable
Parameters:vector <string>
Returns:int
Method signature:int scrutinizeTable(vector <string> table)


CONSTRAINTS
-table will contain between 1 and 50 elements, inclusive.
-Each element of table will contain exactly n characters, where n is the number of elements in table.
-Each character in each element of table will be '1' (one), '0' (zero), or '-'.
-The i-th character of the j-th element of table will be '1' if and only if the j-th character of the i-th element of table is '0'.
-The i-th character of the j-th element of table will be '-' if and only if the j-th character of the i-th element of table is '-'.
-The i-th character of the i-th element of table will be '-'.


EXAMPLES

0)
{"-10",
 "0-1",
 "10-"}

Returns: 3

Player 0 defeated player 1, player 1 defeated player 2, and player 2 defeated player 0.

1)
{"----",
 "----",
 "----",
 "----"}

Returns: 0

All matches ended in a draw.

2)
{"-1",
 "0-"}

Returns: 0

Too few players to form a triple.

3)
{"--1-10-1---1--1-00",
 "--0110000--0---10-",
 "01--00000100-00011",
 "-0---0010-11110100",
 "001--01-00-0001-1-",
 "11111--100--1-1-01",
 "-1110--00110-11-01",
 "0110-01--100110-10",
 "-111111---01--0-01",
 "--0-1100----10011-",
 "--10--011--1--101-",
 "01101-110-0--1-0-1",
 "---010-0-0---00-11",
 "--101-00-1-01-0-0-",
 "0-110001110-11-110",
 "-010-----011--0--0",
 "11010110100-010--0",
 "1-01-0010--00-111-"}

Returns: 198



*/
// END CUT HERE
#line 81 "TournamentsAmbiguityNumber.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class TournamentsAmbiguityNumber {
public:
  int scrutinizeTable(vector <string> t) {// t = table
    int ret = 0;
    const int N = t.size();
    for (int i = 0; i != N; ++i) { // a
      for (int j = 0; j != N; ++j) { // b
	if (t[i][j] == '1') { // if i defeats j
	  for (int k = 0; k != N; ++k) {// c
	    if (t[j][k] == '1' && t[k][i] == '1') { // if j defeats k & k defeats i
	      //cout << "pair : " << i << " " << j << " " << k << endl;
	      ++ret;
	    }
	  }
	}
      }
    }
    //    cout << ret << endl;
    // ret /= 3;
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
		cout << "Testing TournamentsAmbiguityNumber (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456400822;
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
		TournamentsAmbiguityNumber _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string table[] = {"-10",
				                  "0-1",
				                  "10-"};
				_expected = 3;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 1:
			{
				string table[] = {"----",
				                  "----",
				                  "----",
				                  "----"};
				_expected = 0;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 2:
			{
				string table[] = {"-1",
				                  "0-"};
				_expected = 0;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 3:
			{
				string table[] = {"--1-10-1---1--1-00",
				                  "--0110000--0---10-",
				                  "01--00000100-00011",
				                  "-0---0010-11110100",
				                  "001--01-00-0001-1-",
				                  "11111--100--1-1-01",
				                  "-1110--00110-11-01",
				                  "0110-01--100110-10",
				                  "-111111---01--0-01",
				                  "--0-1100----10011-",
				                  "--10--011--1--101-",
				                  "01101-110-0--1-0-1",
				                  "---010-0-0---00-11",
				                  "--101-00-1-01-0-0-",
				                  "0-110001110-11-110",
				                  "-010-----011--0--0",
				                  "11010110100-010--0",
				                  "1-01-0010--00-111-"};
				_expected = 198;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			/*case 4:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
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
