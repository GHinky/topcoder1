// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The distance between two strings with respect to a letter is defined as (n1 - n2)2, where n1 and n2 are the number of occurrences (both lowercase and uppercase) of that letter in the first and second strings, respectively.  The distance between two strings with respect to a third string is the sum of the distances between the two strings with respect to each letter in the third string.

You will be given three strings a, b and letterSet.  All the letters in letterSet will be distinct. Return the distance between a and b with respect to letterSet.

DEFINITION
Class:DistanceBetweenStrings
Method:getDistance
Parameters:string, string, string
Returns:int
Method signature:int getDistance(string a, string b, string letterSet)


CONSTRAINTS
-a will contain between 1 and 50 characters, inclusive.
-a will contain only letters ('a'-'z', 'A'-'Z').
-b will contain between 1 and 50 characters, inclusive.
-b will contain only letters ('a'-'z', 'A'-'Z').
-letterSet will contain between 1 and 26 characters, inclusive.
-letterSet will contain only lowercase letters ('a'-'z').
-Each character in letterSet will be distinct.


EXAMPLES

0)
"topcoder"
"contest"
"tcp"

Returns: 2

The letter 't' occurs once in the first string and twice in the second; the letter 'c' occurs once in the first string and once in the second; the letter 'p' occurs once in the first string and does not occur in the second one. The total distance is 1+0+1=2.

1)
"abcdef"
"fedcba"
"fed"

Returns: 0

The second string is a permutation of the letters in the first one thus the distance is 0.

2)
"aaaaa"
"bbbbb"
"a"

Returns: 25

The distance with respect to a single character in this case is 5*5=25.

3)
"aaAaB"
"BbaAa"
"ab"

Returns: 2

Lowercase and uppercase letters are regarded the same.

4)
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
"ba"

Returns: 5000

These two strings are quite far away.

5)
"ToPcOdEr"
"tOpCoDeR"
"wxyz"

Returns: 0



*/
// END CUT HERE
#line 85 "DistanceBetweenStrings.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class DistanceBetweenStrings {
public:
  int gd2 (string a, string b, char c) {
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i != a.size(); ++i) {
      if (tolower (a[i]) == tolower (c))
	++n1;
    }
    for (int i = 0; i != b.size(); ++i) {
      if (tolower (b[i]) == tolower (c))
	++n2;
    }
    return (n1 - n2) * (n1 - n2);
  }
  int getDistance(string a, string b, string letterSet) {
    int ret = 0;
    for (int i = 0; i != letterSet.size(); ++i) {
      ret += gd2 (a, b, letterSet[i]);
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
		cout << "Testing DistanceBetweenStrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456322992;
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
		DistanceBetweenStrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string a = "topcoder";
				string b = "contest";
				string letterSet = "tcp";
				_expected = 2;
				_received = _obj.getDistance(a, b, letterSet); break;
			}
			case 1:
			{
				string a = "abcdef";
				string b = "fedcba";
				string letterSet = "fed";
				_expected = 0;
				_received = _obj.getDistance(a, b, letterSet); break;
			}
			case 2:
			{
				string a = "aaaaa";
				string b = "bbbbb";
				string letterSet = "a";
				_expected = 25;
				_received = _obj.getDistance(a, b, letterSet); break;
			}
			case 3:
			{
				string a = "aaAaB";
				string b = "BbaAa";
				string letterSet = "ab";
				_expected = 2;
				_received = _obj.getDistance(a, b, letterSet); break;
			}
			case 4:
			{
				string a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
				string b = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
				string letterSet = "ba";
				_expected = 5000;
				_received = _obj.getDistance(a, b, letterSet); break;
			}
			case 5:
			{
				string a = "ToPcOdEr";
				string b = "tOpCoDeR";
				string letterSet = "wxyz";
				_expected = 0;
				_received = _obj.getDistance(a, b, letterSet); break;
			}
			/*case 6:
			{
				string a = ;
				string b = ;
				string letterSet = ;
				_expected = ;
				_received = _obj.getDistance(a, b, letterSet); break;
			}*/
			/*case 7:
			{
				string a = ;
				string b = ;
				string letterSet = ;
				_expected = ;
				_received = _obj.getDistance(a, b, letterSet); break;
			}*/
			/*case 8:
			{
				string a = ;
				string b = ;
				string letterSet = ;
				_expected = ;
				_received = _obj.getDistance(a, b, letterSet); break;
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
