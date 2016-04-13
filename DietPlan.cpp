// BEGIN CUT HERE
/*
PROBLEM STATEMENT

The doctor has given you your diet, in which each character corresponds to some food that you should eat.  You also know what you have eaten for breakfast and lunch, in which each character corresponds to a type of food that you have already eaten that day.  You have decided that you will eat all of the remaining food in your diet during dinner, and you want to return that as a string (sorted in alphabetical order).  If you have cheated in anyway (either by eating too much of one type of food, or by eating some food that is not in the dietPlan), you should return the string "CHEATER" (quotes for clarity).


DEFINITION
Class:DietPlan
Method:chooseDinner
Parameters:string, string, string
Returns:string
Method signature:string chooseDinner(string diet, string breakfast, string lunch)


CONSTRAINTS
-diet will contain between 0 and 26 characters, inclusive.
-Each character in diet will be an uppercase letter ('A'-'Z').
-There will be no duplicate characters in diet.
-breakfast will contain between 0 and 26 characters, inclusive.
-Each character in breakfast will be an uppercase letter ('A'-'Z').
-lunch will contain between 0 and 26 characters, inclusive.
-Each character in lunch will be an uppercase letter ('A'-'Z').
-There will be no duplicate characters in breakfast.
-There will be no duplicate characters in lunch.
-No character will appear in both breakfast and lunch.


EXAMPLES

0)
"ABCD"
"AB"
"C"

Returns: "D"

Here, you have eaten most of your food for the day.  So, you can only eat a single 'D' for dinner.

1)
"ABEDCS"
""
""

Returns: "ABCDES"

Here you've saved all of your food for dinner.

2)
"EDSMB"
"MSD"
"A"

Returns: "CHEATER"

You cheated at lunch time by eating an 'A'!

3)
""
""
""

Returns: ""



4)
"IWANTSODER"
"SOW"
"RAT"

Returns: "DEIN"



*/
// END CUT HERE
#line 79 "DietPlan.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class DietPlan {
public:
  string chooseDinner(string diet, string breakfast, string lunch) {
    string ret;
    string bl = breakfast + lunch;
    bool cheated = false;
    for (int i = 0; i != bl.size(); ++i) {
      for (int j = 0; j != diet.size(); ++j) {
	if (bl[i] == diet[j]) {
	  diet[j] = '0'; // sentinel indicating consumed diet
	  bl[i] = '*'; // sentinel indicating consumed bl that was part of diet recommendation
	} 
      }
    }

    for (int i = 0; i != bl.size(); ++i) {
      if (bl[i] != '*')
	cheated = true;
    }
        
    sort (diet.begin(), diet.end());
    string::iterator iter = remove (diet.begin(), diet.end(), '0');
    
    if (cheated == false)
      ret = string (diet.begin(), iter);
    else
      ret = "CHEATER";
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
		cout << "Testing DietPlan (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456424103;
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
		DietPlan _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string diet = "ABCD";
				string breakfast = "AB";
				string lunch = "C";
				_expected = "D";
				_received = _obj.chooseDinner(diet, breakfast, lunch); break;
			}
			case 1:
			{
				string diet = "ABEDCS";
				string breakfast = "";
				string lunch = "";
				_expected = "ABCDES";
				_received = _obj.chooseDinner(diet, breakfast, lunch); break;
			}
			case 2:
			{
				string diet = "EDSMB";
				string breakfast = "MSD";
				string lunch = "A";
				_expected = "CHEATER";
				_received = _obj.chooseDinner(diet, breakfast, lunch); break;
			}
			case 3:
			{
				string diet = "";
				string breakfast = "";
				string lunch = "";
				_expected = "";
				_received = _obj.chooseDinner(diet, breakfast, lunch); break;
			}
			case 4:
			{
				string diet = "IWANTSODER";
				string breakfast = "SOW";
				string lunch = "RAT";
				_expected = "DEIN";
				_received = _obj.chooseDinner(diet, breakfast, lunch); break;
			}
			/*case 5:
			{
				string diet = ;
				string breakfast = ;
				string lunch = ;
				_expected = ;
				_received = _obj.chooseDinner(diet, breakfast, lunch); break;
			}*/
			/*case 6:
			{
				string diet = ;
				string breakfast = ;
				string lunch = ;
				_expected = ;
				_received = _obj.chooseDinner(diet, breakfast, lunch); break;
			}*/
			/*case 7:
			{
				string diet = ;
				string breakfast = ;
				string lunch = ;
				_expected = ;
				_received = _obj.chooseDinner(diet, breakfast, lunch); break;
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
