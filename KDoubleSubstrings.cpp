// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  A k-double string is a non-empty string consisting of two equal length halves, where the first half differs from the second half at no more than k positions. For example, "contestcontest", "oopoop" and "aa" are 0-double strings. "contestkontest" is a 1-double string, and "poorpork", "artbat", and "yesyep" are 2-double strings. Obviously, all 0-double strings are also 1-double strings, all 1-double strings are also 2-double strings, etc.


  You will be given a vector <string> str and an int k. Concatenate the elements of str to form one long string, and return the number of k-double substrings contained in that string.


  If the same string exists in several different positions, count it as many times as it exists. Also, k-double substrings can overlap. See the examples for more details.


  DEFINITION
  Class:KDoubleSubstrings
  Method:howMuch
  Parameters:vector <string>, int
  Returns:int
  Method signature:int howMuch(vector <string> str, int k)


  CONSTRAINTS
  -str will contain between 1 and 5 elements, inclusive.
  -Each element of str will contain between 1 and 50 characters, inclusive.
  -Each element of str will contain only lowercase letters ('a'-'z').
  -k will be between 0 and 100, inclusive.


  EXAMPLES

  0)
  {"aa"}
  0

  Returns: 1

  "aa" is the only 0-double substring.

  1)
  {"aaaa"}
  0

  Returns: 4

  There are four substrings of even length and all of them are 0-double strings.

  2)
  {"contest", "kontest"}
  1

  Returns: 14

  Each pair of consecutive letters form a 1-double substring and the whole string form one more 1-double substring.

  3)
  {"abacaba", "d", "abacaba"}
  1

  Returns: 34



  4)
  {"areyouready"}
  2

  Returns: 18



*/
// END CUT HERE
#line 74 "KDoubleSubstrings.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class KDoubleSubstrings {
public:
  int howMuch(vector <string> str, int k) {
    int ret = 0;
    string s = accumulate (str.begin(), str.end(), string (""));
    //cout << s << endl;
    const int N = s.size();
    for (int i = 0; i != N; ++i) {
      for (int j = i+1; j != N+1; ++j) {
	int len = j - i;
	if (len % 2 != 0)
	  continue;
	int i1 = i;
	int i2 = i + len / 2;
	//	cout << "i=" << i << " & j=" << j << "  ";
	//	cout << "i1=" << i1 << " & i2 = " << i2 << endl;
	int count = 0;
	for (;i2 != j; ++i1,++i2) {
	  if (s[i1] != s[i2])
	    ++count;
	}
	if (count <= k)
	  ++ret;
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
      cout << "Testing KDoubleSubstrings (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456118505;
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
      KDoubleSubstrings _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string str[] = {"aa"};
	    int k = 0;
	    _expected = 1;
	    _received = _obj.howMuch(vector <string>(str, str+sizeof(str)/sizeof(string)), k); break;
	  }
	case 1:
	  {
	    string str[] = {"aaaa"};
	    int k = 0;
	    _expected = 4;
	    _received = _obj.howMuch(vector <string>(str, str+sizeof(str)/sizeof(string)), k); break;
	  }
	case 2:
	  {
	    string str[] = {"contest", "kontest"};
	    int k = 1;
	    _expected = 14;
	    _received = _obj.howMuch(vector <string>(str, str+sizeof(str)/sizeof(string)), k); break;
	  }
	case 3:
	  {
	    string str[] = {"abacaba", "d", "abacaba"};
	    int k = 1;
	    _expected = 34;
	    _received = _obj.howMuch(vector <string>(str, str+sizeof(str)/sizeof(string)), k); break;
	  }
	case 4:
	  {
	    string str[] = {"areyouready"};
	    int k = 2;
	    _expected = 18;
	    _received = _obj.howMuch(vector <string>(str, str+sizeof(str)/sizeof(string)), k); break;
	  }
	  /*case 5:
	    {
	    string str[] = ;
	    int k = ;
	    _expected = ;
	    _received = _obj.howMuch(vector <string>(str, str+sizeof(str)/sizeof(string)), k); break;
	    }*/
	  /*case 6:
	    {
	    string str[] = ;
	    int k = ;
	    _expected = ;
	    _received = _obj.howMuch(vector <string>(str, str+sizeof(str)/sizeof(string)), k); break;
	    }*/
	  /*case 7:
	    {
	    string str[] = ;
	    int k = ;
	    _expected = ;
	    _received = _obj.howMuch(vector <string>(str, str+sizeof(str)/sizeof(string)), k); break;
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
