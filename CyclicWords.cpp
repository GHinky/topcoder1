// BEGIN CUT HERE
/*
PROBLEM STATEMENT
We can think of a cyclic word as a word written in a circle. To represent a cyclic word, we choose an arbitrary starting position and read the characters in clockwise order. So, "picture" and "turepic" are representations for the same cyclic word.

You are given a vector <string> words, each element of which is a representation of a cyclic word. Return the number of different cyclic words that are represented.

DEFINITION
Class:CyclicWords
Method:differentCW
Parameters:vector <string>
Returns:int
Method signature:int differentCW(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.


EXAMPLES

0)
{ "picture", "turepic", "icturep", "word", "ordw" }

Returns: 2

"picture", "turepic" and "iceturep" are representations of the same cyclic word.  "word" and "ordw" are representations of a second cyclic word.

1)
{ "ast", "ats", "tas", "tsa", "sat", "sta", "ttt" }

Returns: 3



2)
{"aaaa", "aaa", "aa", "aaaa", "aaaaa"}

Returns: 4



*/
// END CUT HERE
#line 47 "CyclicWords.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class CyclicWords {
public:
  string lp (string s) { //lowest_permutation
    string ret = s;
    for (int i = 0; i != s.size(); ++i) {
      string temp = s.substr(i, s.size() - i) + s.substr(0, i);
      ret = (temp < ret)? temp : ret;
    }
    return ret;
  }
  int differentCW(vector <string> words) {
    int ret = 0;
    VS wd;
    for (int i = 0; i != words.size(); ++i) {
      wd.push_back (lp (words[i]));
    }
    sort (wd.begin(), wd.end());
    VS::iterator iter = unique (wd.begin(), wd.end());
    ret = iter - wd.begin();
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
		cout << "Testing CyclicWords (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456335524;
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
		CyclicWords _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = { "picture", "turepic", "icturep", "word", "ordw" };
				_expected = 2;
				_received = _obj.differentCW(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = { "ast", "ats", "tas", "tsa", "sat", "sta", "ttt" };
				_expected = 3;
				_received = _obj.differentCW(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"aaaa", "aaa", "aa", "aaaa", "aaaaa"};
				_expected = 4;
				_received = _obj.differentCW(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 3:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.differentCW(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.differentCW(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.differentCW(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
