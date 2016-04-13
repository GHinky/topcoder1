// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have been tasked with writing a function that will scan through a given document, and determine how many times a given word or phrase appears in that document.  However, it is important that your function does not count overlapping occurrences.  For instance, if the document were "abababa", and the search keyword was "ababa", you could find the keyword starting at index 0, or at index 2, but not both, since they would overlap.

You must concatenate the elements of the given vector <string> doc into a single string.  Then, return the maximum number of non-overlapping occurrences of the string search.

To find a maximal set of non-overlapping occurrences, perform the following procedure.  Starting from the left, find the first occurrence of the search string.  Then, continuing with the character immediately following the search string, continue looking for the next occurrence.  Repeat until no new occurrences can be found.  By continuing immediately following each found occurrence, we guarantee that we will not count overlaps.



DEFINITION
Class:DocumentSearch
Method:nonIntersecting
Parameters:vector <string>, string
Returns:int
Method signature:int nonIntersecting(vector <string> doc, string search)


CONSTRAINTS
-doc will contain between 1 and 50 elements, inclusive.
-Each element of doc will contain between 1 and 50 characters, inclusive.
-Each character of each element of doc will be a lowercase letter ('a'-'z') or a space (' ').
-search will contain between 1 and 50 characters, inclusive.
-Each character of search will be a lowercase letter ('a'-'z') or a space (' ').


EXAMPLES

0)
{"ababababa"}
"ababa"

Returns: 1

The example from the problem statement.

1)
{"ababababa"}
"aba"

Returns: 2

There are multiple ways to find the string twice, but it doesn't matter how we do it.

2)
{"abcdefghijklmnop",
 "qrstuvwxyz"}
"pqrs"

Returns: 1

Be sure to concatenate the document first.

3)
{"aaa", "aa", "a", "a"}
"aa"

Returns: 3



*/
// END CUT HERE
#line 66 "DocumentSearch.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;

class DocumentSearch {
public:
  int nonIntersecting(vector <string> doc, string search1) {
    int ret = 0;
    string s;
    s = accumulate (doc.begin(), doc.end(), s);
    const int l = search1.length();
    for (string::iterator i = s.begin(); i < s.end();) {
      i = search(i, s.end(), search1.begin(), search1.end());
      if (i < s.end()) {
	++ret;
	i += l;
      }
    }
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
		cout << "Testing DocumentSearch (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456304052;
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
		DocumentSearch _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string doc[] = {"ababababa"};
				string search = "ababa";
				_expected = 1;
				_received = _obj.nonIntersecting(vector <string>(doc, doc+sizeof(doc)/sizeof(string)), search); break;
			}
			case 1:
			{
				string doc[] = {"ababababa"};
				string search = "aba";
				_expected = 2;
				_received = _obj.nonIntersecting(vector <string>(doc, doc+sizeof(doc)/sizeof(string)), search); break;
			}
			case 2:
			{
				string doc[] = {"abcdefghijklmnop",
				                "qrstuvwxyz"};
				string search = "pqrs";
				_expected = 1;
				_received = _obj.nonIntersecting(vector <string>(doc, doc+sizeof(doc)/sizeof(string)), search); break;
			}
			case 3:
			{
				string doc[] = {"aaa", "aa", "a", "a"};
				string search = "aa";
				_expected = 3;
				_received = _obj.nonIntersecting(vector <string>(doc, doc+sizeof(doc)/sizeof(string)), search); break;
			}
			/*case 4:
			{
				string doc[] = ;
				string search = ;
				_expected = ;
				_received = _obj.nonIntersecting(vector <string>(doc, doc+sizeof(doc)/sizeof(string)), search); break;
			}*/
			/*case 5:
			{
				string doc[] = ;
				string search = ;
				_expected = ;
				_received = _obj.nonIntersecting(vector <string>(doc, doc+sizeof(doc)/sizeof(string)), search); break;
			}*/
			/*case 6:
			{
				string doc[] = ;
				string search = ;
				_expected = ;
				_received = _obj.nonIntersecting(vector <string>(doc, doc+sizeof(doc)/sizeof(string)), search); break;
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
