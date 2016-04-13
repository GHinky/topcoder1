// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have decided to create your own simple encryption method for strings containing only lowercase letters and spaces. You start by splitting the alphabet into two groups. The first group consists of the first firstSize letters of the alphabet, and the second consists of the remaining 26 - firstSize letters. To encrypt a character in your message, you do the following:

If it a space, it is kept as is.
If it is a letter in the first group, it is moved firstRotate letters forward in the group, wrapping back to the start if necessary. For example, if firstSize is 6 and firstRotate is 2, then 'A' would become 'C', and 'F' would become 'B'.
If it is a letter in the second group, then it is moved secondRotate letters forward in the group, again wrapping back to the start of the group if necessary.


Given firstSize, firstRotate, secondRotate and a message, return the encrypted form of the message.

DEFINITION
Class:TwoRotationCypher
Method:encrypt
Parameters:int, int, int, string
Returns:string
Method signature:string encrypt(int firstSize, int firstRotate, int secondRotate, string message)


CONSTRAINTS
-firstSize will be between 1 and 25, inclusive.
-firstRotate will be between 0 and firstSize - 1, inclusive.
-secondRotate will be between 0 and 25 - firstSize, inclusive.
-message will contain between 1 and 50 characters, inclusive.
-message will contain only lowercase letters ('a' - 'z') and spaces.


EXAMPLES

0)
13
0
0
"this string will not change at all"

Returns: "this string will not change at all"



1)
13
7
0
"only the letters a to m in this string change"

Returns: "onfy tbl flttlrs h to g cn tbcs strcna jbhnal"



2)
9
0
16
"j to z will change here"

Returns: "z sn y vikk chamge heqe"



3)
17
9
5
"the quick brown fox jumped over the lazy dog"

Returns: "yqn izalc kwgsf ogt bzehnm grnw yqn djvu mgp"



4)
3
1
2
"  watch   out for strange  spacing "

Returns: "  ybvaj   qwv hqt uvtbpig  urbakpi "



*/
// END CUT HERE
#line 84 "TwoRotationCypher.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class TwoRotationCypher {
public:
  string encrypt(int firstSize, int firstRotate, int secondRotate, string message) {
    string ret;

    char arr[26];
    char a = 'a';
    for (int i = 0; i != 26; ++i) {
      arr[i] = a;
      ++a;
      cout << arr[i];
    }
    cout << "\n==============arr ends============" << endl;

    char arr2[26];
    char a2 = arr[firstSize];
    for (int i = 0; i != 26; ++i) {
      arr2[i] = a2;
      ++a2;
      cout << arr2[i];
    }
    cout << "\n==============arr2 ends============" << endl;
    
    for (int i = 0; i != message.size(); ++i) {
      char mi = message[i];
      int pos = mi - 'a';
      if (mi == ' ')
	ret += ' ';
      if ((pos < firstSize) && (mi != ' ')) {
	int toaddindex = (pos + firstRotate) % firstSize;
	ret += arr[toaddindex];
      }
      if ((pos >= firstSize) && (mi != ' ')) {
	int pos2 = mi - arr2[0];
	int toaddindex2 = (pos2 + secondRotate) % (26 - firstSize);
	ret += arr2[toaddindex2];
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
		cout << "Testing TwoRotationCypher (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456501377;
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
		TwoRotationCypher _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int firstSize = 13;
				int firstRotate = 0;
				int secondRotate = 0;
				string message = "this string will not change at all";
				_expected = "this string will not change at all";
				_received = _obj.encrypt(firstSize, firstRotate, secondRotate, message); break;
			}
			case 1:
			{
				int firstSize = 13;
				int firstRotate = 7;
				int secondRotate = 0;
				string message = "only the letters a to m in this string change";
				_expected = "onfy tbl flttlrs h to g cn tbcs strcna jbhnal";
				_received = _obj.encrypt(firstSize, firstRotate, secondRotate, message); break;
			}
			case 2:
			{
				int firstSize = 9;
				int firstRotate = 0;
				int secondRotate = 16;
				string message = "j to z will change here";
				_expected = "z sn y vikk chamge heqe";
				_received = _obj.encrypt(firstSize, firstRotate, secondRotate, message); break;
			}
			case 3:
			{
				int firstSize = 17;
				int firstRotate = 9;
				int secondRotate = 5;
				string message = "the quick brown fox jumped over the lazy dog";
				_expected = "yqn izalc kwgsf ogt bzehnm grnw yqn djvu mgp";
				_received = _obj.encrypt(firstSize, firstRotate, secondRotate, message); break;
			}
			case 4:
			{
				int firstSize = 3;
				int firstRotate = 1;
				int secondRotate = 2;
				string message = "  watch   out for strange  spacing ";
				_expected = "  ybvaj   qwv hqt uvtbpig  urbakpi ";
				_received = _obj.encrypt(firstSize, firstRotate, secondRotate, message); break;
			}
			/*case 5:
			{
				int firstSize = ;
				int firstRotate = ;
				int secondRotate = ;
				string message = ;
				_expected = ;
				_received = _obj.encrypt(firstSize, firstRotate, secondRotate, message); break;
			}*/
			/*case 6:
			{
				int firstSize = ;
				int firstRotate = ;
				int secondRotate = ;
				string message = ;
				_expected = ;
				_received = _obj.encrypt(firstSize, firstRotate, secondRotate, message); break;
			}*/
			/*case 7:
			{
				int firstSize = ;
				int firstRotate = ;
				int secondRotate = ;
				string message = ;
				_expected = ;
				_received = _obj.encrypt(firstSize, firstRotate, secondRotate, message); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
