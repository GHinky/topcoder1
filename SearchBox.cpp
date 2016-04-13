// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You are writing a simple text editor, and one of the features you need to implement is a text search. Given a pattern, the search mechanism should return the position of its first occurrence, starting from the current position, or indicate that the pattern cannot be found. Searches are case sensitive, and do not wrap. The search dialog contains a text box and a checkbox labeled "Whole Word". When the "Whole Word" option is selected, the matched sequence must either be preceded by a space to its left or be at the very beginning of the text.  Similarly, it must also either be followed by a space to its right or be at the very end of the text.
You are given a string text consisting of letters and spaces. 
You are also given a string search, a sequence of letters representing the search pattern, and a string wholeWord, which is either "Y" or "N", indicating whether or not the "Whole Word" option is checked. An int start represents the current position in the text from where you start searching. 
Return the index of the first match, or -1 if there is none. The index of the match here means the index of its first character. Both the starting index and the return index are zero based.


DEFINITION
Class:SearchBox
Method:find
Parameters:string, string, string, int
Returns:int
Method signature:int find(string text, string search, string wholeWord, int start)


CONSTRAINTS
-text will contain between 1 and 50 characters, inclusive.
-text will contain only letters ('a'-'z', 'A'-'Z') and spaces.
-search will contain between 1 and 50 characters, inclusive.
-search will contain only letters ('a'-'z', 'A'-'Z').
-wholeWord will contain a single letter 'Y' or 'N'.
-start will be between 0 and N-1, inclusive, where N is the number of characters in text.


EXAMPLES

0)
"We dont need no education"
"ed"
"N"
13

Returns: 16

The whole text has two occurrences of "ed", but since we start the search at the 13th character we find the second one.

1)
"We dont need no thought control"
"We"
"Y"
0

Returns: 0

"We" is exactly at the beginning of the text.

2)
"No dark sarcasm in the classroom"
"The"
"Y"
5

Returns: -1

Remember that the search is case sensitive.

3)
"Teachers leave them kids alone"
"kid"
"Y"
1

Returns: -1

With the "Whole Word" option selected the "kid" won't be matched even though it's present in "kids".

4)
"All in all its just another brick in the wall"
"all"
"Y"
9

Returns: -1



5)
"All in all youre just another brick in the wall"
"just"
"Y"
17

Returns: 17



*/
// END CUT HERE
#line 92 "SearchBox.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class SearchBox {
public:
  int find(string text, string search1, string wholeWord, int start) {
    int ret = 0;
    string t = " " + text + " ";
    string s = search1;
    if (wholeWord == "Y")
      s = " " + s + " ";
    else
      start += 1;
    //    cout << "t = " << t << endl;
    //    cout << "s = " << s << endl;
    string::iterator iter;
    iter = search (t.begin() + start, t.end(), s.begin(), s.end());
    //    cout << "iter = " << *iter << endl;
    if (iter != t.end()) {
      if (wholeWord == "N")
	ret = iter - t.begin() - 1;
      else
	ret = iter - t.begin();
    } else
      ret = -1;
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
		cout << "Testing SearchBox (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456371644;
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
		SearchBox _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text = "We dont need no education";
				string search = "ed";
				string wholeWord = "N";
				int start = 13;
				_expected = 16;
				_received = _obj.find(text, search, wholeWord, start); break;
			}
			case 1:
			{
				string text = "We dont need no thought control";
				string search = "We";
				string wholeWord = "Y";
				int start = 0;
				_expected = 0;
				_received = _obj.find(text, search, wholeWord, start); break;
			}
			case 2:
			{
				string text = "No dark sarcasm in the classroom";
				string search = "The";
				string wholeWord = "Y";
				int start = 5;
				_expected = -1;
				_received = _obj.find(text, search, wholeWord, start); break;
			}
			case 3:
			{
				string text = "Teachers leave them kids alone";
				string search = "kid";
				string wholeWord = "Y";
				int start = 1;
				_expected = -1;
				_received = _obj.find(text, search, wholeWord, start); break;
			}
			case 4:
			{
				string text = "All in all its just another brick in the wall";
				string search = "all";
				string wholeWord = "Y";
				int start = 9;
				_expected = -1;
				_received = _obj.find(text, search, wholeWord, start); break;
			}
			case 5:
			{
				string text = "All in all youre just another brick in the wall";
				string search = "just";
				string wholeWord = "Y";
				int start = 17;
				_expected = 17;
				_received = _obj.find(text, search, wholeWord, start); break;
			}
			case 6:
			{
			        string text = "bAab aaBaBa Ab aa abbb ab ba aaba aab Ba aba aa a";
				string search = "Ba";
				string wholeWord = "N";
				int start = 8;
				_expected = 9;
				_received = _obj.find(text, search, wholeWord, start); break;
			}
			/*case 7:
			{
				string text = ;
				string search = ;
				string wholeWord = ;
				int start = ;
				_expected = ;
				_received = _obj.find(text, search, wholeWord, start); break;
			}*/
			/*case 8:
			{
				string text = ;
				string search = ;
				string wholeWord = ;
				int start = ;
				_expected = ;
				_received = _obj.find(text, search, wholeWord, start); break;
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
