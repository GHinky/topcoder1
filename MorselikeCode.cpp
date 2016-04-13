// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Marge is rather concerned about the hoodlums that her son has been spending time with.  Aside from all of the time spent at the arcade, they communicate with each other through encrypted messages.  As a concerned parent, Marge wants to discover what the boys are talking about.

Marge knows parts of the boys' code library, given as a vector <string>.  Each element is formatted as "C SEQUENCE" (quotes for clarity), where C is an uppercase letter, SEQUENCE consists of only '-' and '.' characters, and exactly one space separates the two.  When writing their message, the boys will replace C with SEQUENCE, separating multiple letters with spaces.  So, if O is represented as "---" and S is represented as "...", then the message "SOS" can be encoded as "... --- ...".

Marge has recovered an encoded message that she would like to decode.  Unfortunately, she does not have a full copy of the library, so there may be some SEQUENCEs that do not correspond to any entries in the library; if this happens, you are to replace it with a '?' (Marge is a smart mom, and might be able to figure out what the word is with only partial information).  You are to return a string containing the decoded message.


DEFINITION
Class:MorselikeCode
Method:decrypt
Parameters:vector <string>, string
Returns:string
Method signature:string decrypt(vector <string> library, string message)


CONSTRAINTS
-library will contain between 1 and 50 elements, inclusive.
-Each element of library will contain between 3 and 50 characters, inclusive.
-Each element of library will be formatted as "C SEQUENCE" as described in the problem statement.
-In each element of library, C will be an uppercase letter ('A'-'Z').
-In each element of library, SEQUENCE will consist only of '.' and '-'.
-There will be no duplicate SEQUENCEs in library.
-message will contain between 1 and 50 characters, inclusive.
-Each character of message will be '-', '.', or a space (' ').
-There will be no leading, trailing, or consecutive spaces in message.


EXAMPLES

0)
{"O ---",
 "S ..."}
"... --- ..."

Returns: "SOS"

The example from the problem statement.

1)
{"O ---"}
"... --- ..."

Returns: "?O?"

This time we don't have the S, so we replace the three dashes with question marks.

2)
{"H -",
 "E .",
 "L --",
 "L ..",
 "O -."}
"- . -- .. -."

Returns: "HELLO"

Note that the clever boys can have multiple ways to encode the same letter.

3)
{"H -.-.-.-.-.-.-.-.-.-.",
 "I .-.-.-.-.-.-.-.-.-.-",
 "K -.-.-.-.-.",
 "E .-.-.-.-.-"}
"-.-.-.-.-.-.-.-.-.-. .-.-.-.-.-.-.-.-.-.-"

Returns: "HI"

A long message doesn't always mean a long word.

4)
{"O ---",
 "S ...",
 "B -...",
 "T -",
 "R .-.",
 "E .",
 "N -.",
 "X -..-",
 "D -.." }
"-... --- ... - --- -. .-. . -.. ... --- -..-"

Returns: "BOSTONREDSOX"



5)
{"B -...",
 "N -.",
 "H ....",
 "O --",
 "Z --..",
 "G ---",
 "I ..",
 "J .---" }
"--- -- -... .- -. .- -. .-"

Returns: "GOB?N?N?"



6)
{"A --",
 "B -.",
 "N ...-",
 "I --..",
 "F -.-.-."}
"-. -- -.-.-. -.-.-. --- --.. ...- .-..--."

Returns: "BAFF?IN?"



*/
// END CUT HERE
#line 120 "MorselikeCode.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class MorselikeCode {
public:
  static bool space (char c) {
    return isspace (c);
  }
  static bool notspace (char c) {
    return !isspace (c);
  }
  VS prs (string mes) {
    VS ret;
    string::iterator i = mes.begin(), j;
    while (i != mes.end()) {
      i = find_if (i, mes.end(), notspace);
      j = find_if (i, mes.end(), space);
      if (i != mes.end()) {
	string temp = string(i, j);
	ret.push_back (temp);
      }
      i = j;
    }
    return ret;
  }
  VS libprs (VS lib) {
    VS ret;
    for (int i = 0; i != lib.size(); ++i) {
      ret.push_back (lib[i].substr (2));
    }
    return ret;
  }
  string decrypt(vector <string> library, string message) {
    string ret;
    VS m = prs (message);
    VS l = libprs (library);
    for (int i = 0; i != m.size(); ++i) { // iterate over m
      string mi = m[i];
      int j;
      for (j = 0; j != l.size(); ++j) { // iterate over l
	if (l[j] == mi) {
	  ret += library[j].substr (0, 1);
	  break;
	}
      }
      if (j == l.size())
	ret += "?";
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
		cout << "Testing MorselikeCode (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456399422;
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
		MorselikeCode _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string library[] = {"O ---",
				                    "S ..."};
				string message = "... --- ...";
				_expected = "SOS";
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
			}
			case 1:
			{
				string library[] = {"O ---"};
				string message = "... --- ...";
				_expected = "?O?";
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
			}
			case 2:
			{
				string library[] = {"H -",
				                    "E .",
				                    "L --",
				                    "L ..",
				                    "O -."};
				string message = "- . -- .. -.";
				_expected = "HELLO";
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
			}
			case 3:
			{
				string library[] = {"H -.-.-.-.-.-.-.-.-.-.",
				                    "I .-.-.-.-.-.-.-.-.-.-",
				                    "K -.-.-.-.-.",
				                    "E .-.-.-.-.-"};
				string message = "-.-.-.-.-.-.-.-.-.-. .-.-.-.-.-.-.-.-.-.-";
				_expected = "HI";
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
			}
			case 4:
			{
				string library[] = {"O ---",
				                    "S ...",
				                    "B -...",
				                    "T -",
				                    "R .-.",
				                    "E .",
				                    "N -.",
				                    "X -..-",
				                    "D -.." };
				string message = "-... --- ... - --- -. .-. . -.. ... --- -..-";
				_expected = "BOSTONREDSOX";
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
			}
			case 5:
			{
				string library[] = {"B -...",
				                    "N -.",
				                    "H ....",
				                    "O --",
				                    "Z --..",
				                    "G ---",
				                    "I ..",
				                    "J .---" };
				string message = "--- -- -... .- -. .- -. .-";
				_expected = "GOB?N?N?";
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
			}
			case 6:
			{
				string library[] = {"A --",
				                    "B -.",
				                    "N ...-",
				                    "I --..",
				                    "F -.-.-."};
				string message = "-. -- -.-.-. -.-.-. --- --.. ...- .-..--.";
				_expected = "BAFF?IN?";
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
			}
			/*case 7:
			{
				string library[] = ;
				string message = ;
				_expected = ;
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
			}*/
			/*case 8:
			{
				string library[] = ;
				string message = ;
				_expected = ;
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
			}*/
			/*case 9:
			{
				string library[] = ;
				string message = ;
				_expected = ;
				_received = _obj.decrypt(vector <string>(library, library+sizeof(library)/sizeof(string)), message); break;
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
