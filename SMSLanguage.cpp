// BEGIN CUT HERE
/*
PROBLEM STATEMENT
SMS messages are short messages sent between mobile phones.  The maximum length of a single message is 160 characters, so it is often necessary to abbreviate words.

You are given a string text, and your task is to translate it to SMS language according to the following rules:

  Remove all punctuation symbols ('.', ',', '?' and '!').
  Replace all uppercase letters with their lowercase equivalents.
  Replace all occurrences of "and" with '&'.
  Replace all occurrences of "ate" with '8'.
  Replace all occurrences of "at" with '@'.
  Replace all occurrences of "you" with 'U'.

All quotes are for clarity only.  The rules must be applied in the order they appear in the list. For example, "I HATE rats, and you?" will be translated to "i h8 r@s & U".
Return the resulting translation as a string.

DEFINITION
Class:SMSLanguage
Method:translate
Parameters:string
Returns:string
Method signature:string translate(string text)


CONSTRAINTS
-text will contain between 1 and 50 characters, inclusive.
-text will contain only letters ('a'-'z', 'A'-'Z'), the characters ',', '.', '!', '?', and spaces (' ').


EXAMPLES

0)
"I HATE rats, and you?"

Returns: "i h8 r@s & U"

The example from the problem statement.

1)
"What is the weather like today?"

Returns: "wh@ is the we@her like today"



2)
"It is not too late to.."

Returns: "it is not too l8 to"



3)
"this text is already in sms language"

Returns: "this text is already in sms language"



*/
// END CUT HERE
#line 64 "SMSLanguage.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class SMSLanguage {
public:
  string myreplace (string ret, string old, char nw) {
    for (int i = 0; i != ret.size(); ++i) {
      string::iterator iter;
      iter = search (ret.begin(), ret.end(), old.begin(), old.end());
      if (iter != ret.end()) {
	for (int j = 0; j != old.length() - 1; ++j, ++iter) {
	  *iter = '0';
	}
	*iter = nw;
      }
    }
    //remove sentinels
    string ret2;
    remove_copy (ret.begin(), ret.end(), back_inserter (ret2), '0');
    ret = ret2;
    return ret;
  }
  string translate(string text) {
    string ret = text;
    //remove punct : replace it with sentinel '0'
    for (int i = 0; i != ret.size(); ++i) {
      if (ispunct (ret[i]))
	ret[i] = '0';
      ret[i] = tolower(ret[i]);
    }
    //remove sentinels
    string ret2;
    remove_copy (ret.begin(), ret.end(), back_inserter (ret2), '0');
    ret = ret2;
    ret2 = "";
    
    //word replace
    ret = myreplace (ret, "and", '&');
    ret = myreplace (ret, "ate", '8');
    ret = myreplace (ret, "at", '@');
    ret = myreplace (ret, "you", 'U');
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
		cout << "Testing SMSLanguage (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456331237;
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
		SMSLanguage _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text = "I HATE rats, and you?";
				_expected = "i h8 r@s & U";
				_received = _obj.translate(text); break;
			}
			case 1:
			{
				string text = "What is the weather like today?";
				_expected = "wh@ is the we@her like today";
				_received = _obj.translate(text); break;
			}
			case 2:
			{
				string text = "It is not too late to..";
				_expected = "it is not too l8 to";
				_received = _obj.translate(text); break;
			}
			case 3:
			{
				string text = "this text is already in sms language";
				_expected = "this text is already in sms language";
				_received = _obj.translate(text); break;
			}
			/*case 4:
			{
				string text = ;
				_expected = ;
				_received = _obj.translate(text); break;
			}*/
			/*case 5:
			{
				string text = ;
				_expected = ;
				_received = _obj.translate(text); break;
			}*/
			/*case 6:
			{
				string text = ;
				_expected = ;
				_received = _obj.translate(text); break;
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
