// BEGIN CUT HERE
/*
PROBLEM STATEMENT

As some of you may know, there is no name better than JOHN. Let's define the rules for comparing names. Each letter has a weight ('A' - 1, 'B' - 2, ..., 'Z' - 26). The weight of a name is the sum of the weights of all its letters. For example, the name MARK has weight 13 + 1 + 18 + 11 = 43.



When comparing two names, the one with the larger weight is considered better. In case of a tie, the one that comes earlier lexicographically is better. But there is one exception - the name JOHN is the best name of all.



You are given a vector <string> names, each element of which contains a single name. Sort the names from best to worst and return the sorted vector <string>.



DEFINITION
Class:TheBestName
Method:sort
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> sort(vector <string> names)


CONSTRAINTS
-names will contain between 1 and 50 elements, inclusive.
-Each element of names will contain between 1 and 50 characters, inclusive.
-Each element of names will contain only uppercase letters ('A'-'Z').


EXAMPLES

0)
{"JOHN", "PETR", "ACRUSH"}

Returns: {"JOHN", "ACRUSH", "PETR" }

PETR has weight 59, ACRUSH has weight 70 and JOHN has a weight of only 47. But nevertheless JOHN is the best name, ACRUSH takes second place and PETR is the last.

1)
{"GLUK", "MARGARITKA"}

Returns: {"MARGARITKA", "GLUK" }

MARGARITKA is definitely better than GLUK.


2)
{"JOHN", "A", "AA", "AAA", "JOHN", "B", "BB", "BBB", "JOHN", "C", "CC", "CCC", "JOHN"}

Returns: {"JOHN", "JOHN", "JOHN", "JOHN", "CCC", "BBB", "CC", "BB", "AAA", "C", "AA", "B", "A" }

AA and B both have the same weight, but AA is better as it comes earlier lexicographically. For the same reason, AAA is better than C and BBB is better than CC.

3)
{"BATMAN", "SUPERMAN", "SPIDERMAN", "TERMINATOR"}

Returns: {"TERMINATOR", "SUPERMAN", "SPIDERMAN", "BATMAN" }

Here are some superheroes sorted by their names.

*/
// END CUT HERE
#line 65 "TheBestName.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class TheBestName {
public:
  static bool wt (string s1, string s2) {
    int wt1 = accumulate (s1.begin(), s1.end(), 0) - ('A' - 1) * s1.size();
    int wt2 = accumulate (s2.begin(), s2.end(), 0) - ('A' - 1) * s2.size();;
    return wt1 > wt2;
  }
  vector <string> sort(vector <string> names) {
    VS ret;
    std::sort (names.begin(), names.end());
    stable_sort (names.begin(), names.end(), wt);
    int john = 0;
    for (int i = 0; i != names.size(); ++i) {
      if (names[i] != "JOHN")
	ret.push_back (names[i]);
      else
	++john;
    }
    reverse (ret.begin(), ret.end());
    for (int i = 0; i != john; ++i) {
      ret.push_back ("JOHN");
    }
    reverse (ret.begin(), ret.end());
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
		cout << "Testing TheBestName (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456512010;
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
		TheBestName _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string names[] = {"JOHN", "PETR", "ACRUSH"};
				string __expected[] = {"JOHN", "ACRUSH", "PETR" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sort(vector <string>(names, names+sizeof(names)/sizeof(string))); break;
			}
			case 1:
			{
				string names[] = {"GLUK", "MARGARITKA"};
				string __expected[] = {"MARGARITKA", "GLUK" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sort(vector <string>(names, names+sizeof(names)/sizeof(string))); break;
			}
			case 2:
			{
				string names[] = {"JOHN", "A", "AA", "AAA", "JOHN", "B", "BB", "BBB", "JOHN", "C", "CC", "CCC", "JOHN"};
				string __expected[] = {"JOHN", "JOHN", "JOHN", "JOHN", "CCC", "BBB", "CC", "BB", "AAA", "C", "AA", "B", "A" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sort(vector <string>(names, names+sizeof(names)/sizeof(string))); break;
			}
			case 3:
			{
				string names[] = {"BATMAN", "SUPERMAN", "SPIDERMAN", "TERMINATOR"};
				string __expected[] = {"TERMINATOR", "SUPERMAN", "SPIDERMAN", "BATMAN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sort(vector <string>(names, names+sizeof(names)/sizeof(string))); break;
			}
			/*case 4:
			{
				string names[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sort(vector <string>(names, names+sizeof(names)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string names[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sort(vector <string>(names, names+sizeof(names)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string names[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sort(vector <string>(names, names+sizeof(names)/sizeof(string))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
