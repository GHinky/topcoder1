// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Pig Latin is a simple way of encoding words. We have invented a competitor 
  called "Vowel Latin". It just changes the order of the 
  letters in a word by moving all the vowels to the end, keeping them in the
  same order as they appeared in the original word. 

  Vowels are defined to be the letters 'a', 'e', 'i', 'o', and 'u' (in either uppercase or
  lowercase). The reordering of the letters in a word does not change their case.
  So the Vowel Latin version of "AmplifierX" would be "mplfrXAiie" 

  Create a class VowelLatin that contains a method translate that is given a string
  word and that returns the Vowel Latin version of word.



  DEFINITION
  Class:VowelLatin
  Method:translate
  Parameters:string
  Returns:string
  Method signature:string translate(string word)


  CONSTRAINTS
  -word contains between 1 and 50 characters, inclusive.
  -Each character in word is a letter ('A'-'Z', 'a'-'z').


  EXAMPLES

  0)
  "XYz"

  Returns: "XYz"



  The word contains no vowels so it is unchanged by translating to Vowel Latin.



  1)
  "application"

  Returns: "pplctnaiaio"



  The 5 vowels in this word are all moved to the end of the word.

  2)
  "qwcvb"

  Returns: "qwcvb"

  3)
  "aeioOa"

  Returns: "aeioOa"

*/
// END CUT HERE
#line 66 "VowelLatin.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class VowelLatin {
public:
  static bool vowel (char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }

  string translate (string word) {
    string ret;
    string non_vowel_part;
    string vowel_part;
    for (int i = 0; i != word.size(); ++i) {
      if (vowel (word[i])) {
	vowel_part.push_back(word[i]);
      } else {
	non_vowel_part.push_back(word[i]);
      }
    }
    ret = non_vowel_part + vowel_part;
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
      cout << "Testing VowelLatin (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456224830;
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
      VowelLatin _obj;
      string _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string word = "XYz";
	    _expected = "XYz";
	    _received = _obj.translate(word); break;
	  }
	case 1:
	  {
	    string word = "application";
	    _expected = "pplctnaiaio";
	    _received = _obj.translate(word); break;
	  }
	case 2:
	  {
	    string word = "qwcvb";
	    _expected = "qwcvb";
	    _received = _obj.translate(word); break;
	  }
	case 3:
	  {
	    string word = "aeioOa";
	    _expected = "aeioOa";
	    _received = _obj.translate(word); break;
	  }
	  /*case 4:
	    {
	    string word = ;
	    _expected = ;
	    _received = _obj.translate(word); break;
	    }*/
	  /*case 5:
	    {
	    string word = ;
	    _expected = ;
	    _received = _obj.translate(word); break;
	    }*/
	  /*case 6:
	    {
	    string word = ;
	    _expected = ;
	    _received = _obj.translate(word); break;
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
