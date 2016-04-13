// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  In the English language, the plural form of a noun is created according to many difficult rules, but for the most part, a noun can be transformed into its plural form using four simple rules. These rules are: 
  If the word ends in 's', 'z', 'x', 'ch' or 'sh', add 'es' to the end of the word;
  If the word ends in 'ay', 'ey', 'iy', 'oy' or 'uy', add 's' to the end of the word;
  If the word ends in 'y', but doesn't satisfy the previous rule, replace the trailing 'y' with 'ies';
  In all other cases, just add 's' to the end of the word.
  You will be given a vector <string> nouns. Transform each element of nouns into its plural form using the rules above and return the resulting vector <string>. 
  DEFINITION
  Class:NounReform
  Method:makePlural
  Parameters:vector <string>
  Returns:vector <string>
  Method signature:vector <string> makePlural(vector <string> nouns)


  CONSTRAINTS
  -nouns will contain between 1 and 50 elements, inclusive. 
  -Each element of nouns will contain between 1 and 20 characters, inclusive. 
  -Each element of nouns will consist of only lower-case letters ('a'-'z'). 


  EXAMPLES

  0)
  {"box", "church", "elephant", "stereo"}

  Returns: {"boxes", "churches", "elephants", "stereos" }

  1)
  {"tray", "key", "enemy", "baby"}

  Returns: {"trays", "keys", "enemies", "babies" }

  2)
  {"a", "s", "oy", "y", "yy"}

  Returns: {"as", "ses", "oys", "ies", "yies" }

*/
// END CUT HERE
#line 60 "NounReform.cpp"
#include <string>
#include <vector>
#include <set>

using namespace std;
class NounReform {
public:
  vector <string> makePlural(vector <string> nouns) {
    vector<string> res;
    vector<string>::size_type i;
    set<string> rule1, rule2, rule3;

    rule1.insert("s");
    rule1.insert("z");
    rule1.insert("x");
    rule1.insert("x");
    rule1.insert("ch");
    rule1.insert("sh");

    rule2.insert("ay");
    rule2.insert("ey");
    rule2.insert("iy");
    rule2.insert("oy");
    rule2.insert("uy");

    rule3.insert("y");
    
    for (i = 0; i != nouns.size(); ++i) {
      string in = nouns[i];
      string last1, last2;
      if (in.size() > 0) last1 = in[in.size() - 1];
      if (in.size() > 1) last2 = in[in.size() - 2] + last1;
      if (rule1.count(last1) || rule1.count(last2)) {
	in = in + "es";
      } else if (rule2.count(last2)) {
	in = in + "s";
      } else if (rule3.count(last1)) {
	in = in.substr(0, in.size()-1) + "ies";
      } else
	in = in + "s";
      res.push_back(in);
    }
    return res;
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
	cout << "Testing NounReform (250.0 points)" << endl << endl;
	for (int i = 0; i < 20; i++)
	  {
	    ostringstream s; s << argv[0] << " " << i;
	    int exitCode = system(s.str().c_str());
	    if (exitCode)
	      cout << "#" << i << ": Runtime Error" << endl;
	  }
	int T = time(NULL)-1454944907;
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
	NounReform _obj;
	vector <string> _expected, _received;
	time_t _start = clock();
	switch (_tc)
	  {
	  case 0:
	    {
	      string nouns[] = {"box", "church", "elephant", "stereo"};
	      string __expected[] = {"boxes", "churches", "elephants", "stereos" };
	      _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	      _received = _obj.makePlural(vector <string>(nouns, nouns+sizeof(nouns)/sizeof(string))); break;
	    }
	  case 1:
	    {
	      string nouns[] = {"tray", "key", "enemy", "baby"};
	      string __expected[] = {"trays", "keys", "enemies", "babies" };
	      _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	      _received = _obj.makePlural(vector <string>(nouns, nouns+sizeof(nouns)/sizeof(string))); break;
	    }
	  case 2:
	    {
	      string nouns[] = {"a", "s", "oy", "y", "yy"};
	      string __expected[] = {"as", "ses", "oys", "ies", "yies" };
	      _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	      _received = _obj.makePlural(vector <string>(nouns, nouns+sizeof(nouns)/sizeof(string))); break;
	    }
	    /*case 3:
	      {
	      string nouns[] = ;
	      string __expected[] = ;
	      _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	      _received = _obj.makePlural(vector <string>(nouns, nouns+sizeof(nouns)/sizeof(string))); break;
	      }*/
	    /*case 4:
	      {
	      string nouns[] = ;
	      string __expected[] = ;
	      _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	      _received = _obj.makePlural(vector <string>(nouns, nouns+sizeof(nouns)/sizeof(string))); break;
	      }*/
	    /*case 5:
	      {
	      string nouns[] = ;
	      string __expected[] = ;
	      _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	      _received = _obj.makePlural(vector <string>(nouns, nouns+sizeof(nouns)/sizeof(string))); break;
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


