// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  You are given two strings A and B that have the same length and contain only lowercase letters ('a'-'z').  The distance between two letters is defined as the absolute value of their difference.  The distance between A and B is defined as the sum of the differences between each letter in A and the letter in B at the same position. For example, the distance between "abcd" and "bcda" is 6 (1 + 1 + 1 + 3).

  You must change exactly K characters in A into other lowercase letters.  Return the minimum possible distance between A and B after you perform that change.

  DEFINITION
  Class:ChangingString
  Method:distance
  Parameters:string, string, int
  Returns:int
  Method signature:int distance(string A, string B, int K)


  CONSTRAINTS
  -A and B will each contain between 1 and 50 characters, inclusive.
  -K will be between 1 and the length of A, inclusive.
  -A and B will contain the same number of characters.
  -A and B will contain only lowercase letters ('a' - 'z').


  EXAMPLES

  0)
  "ab"
  "ba"
  2

  Returns: 0

  The minimum distance (equal to 0) can be achieved when we change 'a' to 'b' and 'b' to 'a'.

  1)
  "aa"
  "aa"
  2

  Returns: 2

  We must change both letters 'a' to some other letters. Changing them to 'b' results in the smallest distance.


  2)
  "aaa"
  "baz"
  1

  Returns: 1



  3)
  "fdfdfdfdfdsfabasd"
  "jhlakfjdklsakdjfk"
  8

  Returns: 24



  4)
  "aa"
  "bb"
  2

  Returns: 0



*/
// END CUT HERE
#line 74 "ChangingString.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class ChangingString {
public:
  VI diffs (string a, string b) { // they are also sorted
    VI ret;
    for (int i = 0; i != a.size(); ++i) {
      ret.push_back (abs (a[i] - b[i]));
    }
    sort (ret.begin(), ret.end());
    return ret;
  }
  int eqs (string a, string b)  { // they are also sorted
    int ret = 0;
    for (int i = 0; i != a.size(); ++i) {
      if (a[i] == b[i])
	++ret;
    }
    return ret;
  }
  int distance(string A, string B, int K) {
    int ret = 0;
    VI ds = diffs (A, B);
    int unchanged_chars = A.size() - K;
    for (int i = 0; i != unchanged_chars; ++i) {
      ret += ds[i];
    }
    int eq_num = eqs (A, B);
    int correction = (eq_num - unchanged_chars);
    if ((K != 0) && (correction > 0))
      ret += (eq_num - unchanged_chars);
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
      cout << "Testing ChangingString (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456227954;
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
      ChangingString _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string A = "ab";
	    string B = "ba";
	    int K = 2;
	    _expected = 0;
	    _received = _obj.distance(A, B, K); break;
	  }
	case 1:
	  {
	    string A = "aa";
	    string B = "aa";
	    int K = 2;
	    _expected = 2;
	    _received = _obj.distance(A, B, K); break;
	  }
	case 2:
	  {
	    string A = "aaa";
	    string B = "baz";
	    int K = 1;
	    _expected = 1;
	    _received = _obj.distance(A, B, K); break;
	  }
	case 3:
	  {
	    string A = "fdfdfdfdfdsfabasd";
	    string B = "jhlakfjdklsakdjfk";
	    int K = 8;
	    _expected = 24;
	    _received = _obj.distance(A, B, K); break;
	  }
	case 4:
	  {
	    string A = "aa";
	    string B = "bb";
	    int K = 2;
	    _expected = 0;
	    _received = _obj.distance(A, B, K); break;
	  }
	  case 5:
	    {
	    string A = "aaaabcd";
	    string B = "aabcaaa";
	    int K = 6;
	    _expected = 1;
	    _received = _obj.distance(A, B, K); break;
	    }
	  /*case 6:
	    {
	    string A = ;
	    string B = ;
	    int K = ;
	    _expected = ;
	    _received = _obj.distance(A, B, K); break;
	    }*/
	  /*case 7:
	    {
	    string A = ;
	    string B = ;
	    int K = ;
	    _expected = ;
	    _received = _obj.distance(A, B, K); break;
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
