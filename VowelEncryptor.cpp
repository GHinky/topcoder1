// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  You are given a vector <string> text, each element of which contains a single word.  Encrypt the text by removing 
  all vowels ('a', 'e', 'i', 'o', 'u') from every word that contains at least one non-vowel.  If a word consists only of vowels, leave it as is.  Return the result as a vector <string>, where the ith element is the encrypted version of the ith element in text.


  DEFINITION
  Class:VowelEncryptor
  Method:encrypt
  Parameters:vector <string>
  Returns:vector <string>
  Method signature:vector <string> encrypt(vector <string> text)


  CONSTRAINTS
  -text will contain between 1 and 50 elements, inclusive.
  -Each element of text will contain between 1 and 20 lowercase letters ('a'-'z'), inclusive.


  EXAMPLES

  0)
  {"hello", "world"}

  Returns: {"hll", "wrld" }



  1)
  {"a", "b", "c"}

  Returns: {"a", "b", "c" }



  2)
  {"he", "who", "is", "greedy", "is", "disgraced"}

  Returns: {"h", "wh", "s", "grdy", "s", "dsgrcd" }



*/
// END CUT HERE
#line 48 "VowelEncryptor.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class VowelEncryptor {
public:
  static bool vowel (char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }
  vector <string> encrypt(vector <string> text) {
    vector<string> ret;
    for (int i = 0; i != text.size(); ++i) {
      string tin = text[i];
      string::iterator new_end;
      new_end = remove_if (tin.begin(), tin.end(), vowel);
      if (new_end == tin.begin())
	ret.push_back(text[i]);
      else
	ret.push_back(string(tin.begin(), new_end));
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
      cout << "Testing VowelEncryptor (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456216528;
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
      VowelEncryptor _obj;
      vector <string> _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string text[] = {"hello", "world"};
	    string __expected[] = {"hll", "wrld" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.encrypt(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
	  }
	case 1:
	  {
	    string text[] = {"a", "b", "c"};
	    string __expected[] = {"a", "b", "c" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.encrypt(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
	  }
	case 2:
	  {
	    string text[] = {"he", "who", "is", "greedy", "is", "disgraced"};
	    string __expected[] = {"h", "wh", "s", "grdy", "s", "dsgrcd" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.encrypt(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
	  }
	  /*case 3:
	    {
	    string text[] = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.encrypt(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
	    }*/
	  /*case 4:
	    {
	    string text[] = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.encrypt(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
	    }*/
	  /*case 5:
	    {
	    string text[] = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.encrypt(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
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
	  cout << "           Expected: {";
	  for (unsigned i = 0; i < _expected.size(); i++)
	    {
	      if (i) cout << ",";
	      cout << " \"" << _expected[i] << "\"";
	    }
	  cout << " }" << endl;
	  cout << "           Received: {";
	  for (unsigned i = 0; i < _received.size(); i++)
	    {
	      if (i) cout << ",";
	      cout << " \"" << _received[i] << "\"";
	    }
	  cout << " }" << endl;
	}
    }
}

// END CUT HERE
