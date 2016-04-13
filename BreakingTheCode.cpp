// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have been given a secret mission where you must break the enemy's code.  You have already figured out that they encode messages using the following method.  Each letter between 'a' and 'z', inclusive, is assigned a distinct two-digit number between 01 and 26, inclusive.  A message is encoded by simply replacing each letter with its assigned number.  For example, if 't' is assigned 20, 'e' is assigned 05 and 's' is assigned 19, then the message "test" is encoded as "20051920".  All original messages contain only lowercase letters.
You are given a string code containing the assignment of numbers to letters.  The first letter of code is assigned 01, the second is assigned 02 and so on.  You are also given a string message which is either an original unencoded message or an encoded message.  If you are given an unencoded message, return the encoded version of that message, and if you are given an encoded message, return the original unencoded message.

DEFINITION
Class:BreakingTheCode
Method:decodingEncoding
Parameters:string, string
Returns:string
Method signature:string decodingEncoding(string code, string message)


CONSTRAINTS
-code will contain exactly 26 characters.
-Each lowercase letter between 'a' and 'z', inclusive, will occur exactly once in code.
-message will contain between 1 and 50 characters, inclusive.
-message will either contain only lowercase letters ('a'-'z') or only digits ('0'-'9').
-If message contains only digits, it will be a concatenation of two-digit numbers, each between 01 and 26, inclusive.


EXAMPLES

0)
"abcdefghijklmnopqrstuvwxyz"
"test"

Returns: "20051920"

Example from the problem statement. Here, the letters are coded in an alphabetical order.

1)
"abcdefghijklmnopqrstuvwxyz"
"20051920"

Returns: "test"

Now, we're decoding it.

2)
"qesdfvujrockgpthzymbnxawli"
"mwiizkelza"

Returns: "19242626171202251723"

3)
"faxmswrpnqdbygcthuvkojizle"
"02170308060416192402"

Returns: "ahxpwmtvza"

*/
// END CUT HERE
#line 56 "BreakingTheCode.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class BreakingTheCode {
public:
  int prs (string s) {
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
  }
  string rprs (int i) {
    string ret;
    stringstream ss;
    ss << i;
    ss >> ret;
    if (ret.length() != 2)
      ret = "0" + ret;
    return ret;
  }

  string decodingEncoding(string code, string message) {
    string ret;
    if (isdigit(message[0])) { // to char
      for (int i = 0; i != message.size(); i = i + 2) {
	int temp = prs (message.substr (i, 2));
	//	cout << "temp = " << temp << endl;
	//	cout << "code[temp] = " << code[temp - 1] << endl;
	ret += code[temp-1];
      }
    }
    else { // to nums
      for (int i = 0; i != message.size(); ++i) {
	string::iterator iter = find (code.begin(), code.end(), message[i]);
	int pos = iter - code.begin() + 1; // 1-indexed
	ret += rprs (pos);
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
		cout << "Testing BreakingTheCode (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456597387;
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
		BreakingTheCode _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string code = "abcdefghijklmnopqrstuvwxyz";
				string message = "test";
				_expected = "20051920";
				_received = _obj.decodingEncoding(code, message); break;
			}
			case 1:
			{
				string code = "abcdefghijklmnopqrstuvwxyz";
				string message = "20051920";
				_expected = "test";
				_received = _obj.decodingEncoding(code, message); break;
			}
			case 2:
			{
				string code = "qesdfvujrockgpthzymbnxawli";
				string message = "mwiizkelza";
				_expected = "19242626171202251723";
				_received = _obj.decodingEncoding(code, message); break;
			}
			case 3:
			{
				string code = "faxmswrpnqdbygcthuvkojizle";
				string message = "02170308060416192402";
				_expected = "ahxpwmtvza";
				_received = _obj.decodingEncoding(code, message); break;
			}
			/*case 4:
			{
				string code = ;
				string message = ;
				_expected = ;
				_received = _obj.decodingEncoding(code, message); break;
			}*/
			/*case 5:
			{
				string code = ;
				string message = ;
				_expected = ;
				_received = _obj.decodingEncoding(code, message); break;
			}*/
			/*case 6:
			{
				string code = ;
				string message = ;
				_expected = ;
				_received = _obj.decodingEncoding(code, message); break;
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
