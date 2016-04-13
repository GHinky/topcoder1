// BEGIN CUT HERE
/*
PROBLEM STATEMENT

It is often helpful to have a mnemonic phrase handy for a math test.  For example, the number 25735 can be remembered as "is there anybody out there".  If we count the number of characters in every word, we would get the sequence 2, 5, 7, 3, 5, which represents the original number!


Unfortunately for you, your professor likes to make the students memorize random numbers and then test them.  To beat the system, your plan is to come up with mnemonic phrases that will represent the numbers you must memorize.


You are given a string number and a vector <string> dictionary.  Return a single space delimited list of words, where each word is an element of dictionary, and no element of dictionary is used more than once. The phrase must contain exactly n words, where n is the number of digits in the number, and the length of the i-th word must be equal to the i-th digit of the number for all i.  If more than one phrase is possible, return the one that comes first alphabetically (in other words, if you have several words of the same length, you should use them in alphabetical order).


DEFINITION
Class:MnemonicMemory
Method:getPhrase
Parameters:string, vector <string>
Returns:string
Method signature:string getPhrase(string number, vector <string> dictionary)


CONSTRAINTS
-dictionary will contain between 1 and 50 elements, inclusive.
-Each element of dictionary will contain between 1 and 9 characters, inclusive.
-Each element of dictionary will contain only lowercase letters ('a'-'z').
-number will contain between 1 and 50 characters, inclusive.
-number will contain only digits between '1' and '9', inclusive.
-There will always be a possible solution with the given dictionary.


EXAMPLES

0)
"25735"
{"is", "there", "anybody", "out", "there"}

Returns: "is there anybody out there"

The example from the problem statement.

1)
"31415926"
{"may", "i", "have", "a", "large", "container", "of", "coffee"}

Returns: "may a have i large container of coffee"

Make sure you use words of the same length in alphabetical order.

2)
"1212"
{"a", "aa", "a", "aa"}

Returns: "a aa a aa"



3)
"11111111122"
{"a", "b", "d", "c", "a", "e", "f", "z", "zz", "za", "az", "e"}

Returns: "a a b c d e e f z az za"



4)
"2222"
{"ab", "cd", "ef", "a", "b", "ab"}

Returns: "ab ab cd ef"



*/
// END CUT HERE
#line 76 "MnemonicMemory.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class MnemonicMemory {
public:
  static bool lcmp (string s1, string s2) {
    return (s1.length() < s2.length());
  }
  VI prs (string n) {
    VI ret;
    for (int i = 0; i != n.length(); ++i) {
      stringstream ss;
      ss << n[i];
      int temp;
      ss >> temp;
      ret.push_back(temp);
    }
    //reverse (ret.begin(), ret.end());
    return ret;
  }
  string getPhrase(string number, vector <string> dictionary) {
    //cout << number << endl;
    string ret;
    sort (dictionary.begin(), dictionary.end());
    stable_sort (dictionary.begin(), dictionary.end(), lcmp);
    VI vi = prs (number);
    for (int i = 0; i != vi.size(); ++i) { //i over vi
      int j;
      for (j = 0; dictionary[j].length() != vi[i]; ++j) { //  j over dict
      }
      ret = ret + dictionary[j] + " ";
      dictionary[j] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"; // sentinel for used word 51 z
      
      //      cout << dictionary[i].length() << endl;
      //cout << vi[i]; // << endl;
    }
    //cout << endl;
    //remove last space
    ret = ret.substr (0, ret.size() - 1);
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
		cout << "Testing MnemonicMemory (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456333214;
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
		MnemonicMemory _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		  	case 0:
			{
				string number = "25735";
				string dictionary[] = {"is", "there", "anybody", "out", "there"};
				_expected = "is there anybody out there";
				_received = _obj.getPhrase(number, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 1:
			{
				string number = "31415926";
				string dictionary[] = {"may", "i", "have", "a", "large", "container", "of", "coffee"};
				_expected = "may a have i large container of coffee";
				_received = _obj.getPhrase(number, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 2:
			{
				string number = "1212";
				string dictionary[] = {"a", "aa", "a", "aa"};
				_expected = "a aa a aa";
				_received = _obj.getPhrase(number, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 3:
			{
				string number = "11111111122";
				string dictionary[] = {"a", "b", "d", "c", "a", "e", "f", "z", "zz", "za", "az", "e"};
				_expected = "a a b c d e e f z az za";
				_received = _obj.getPhrase(number, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
				case 4:
			{
				string number = "2222";
				string dictionary[] = {"ab", "cd", "ef", "a", "b", "ab"};
				_expected = "ab ab cd ef";
				_received = _obj.getPhrase(number, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			/*case 5:
			{
				string number = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.getPhrase(number, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string number = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.getPhrase(number, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string number = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.getPhrase(number, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
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
