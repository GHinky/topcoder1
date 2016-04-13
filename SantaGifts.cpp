// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Santa Claus has come with a bag full of presents this year.  A group of N kids stand in line, anxious to get their gifts.  Santa Claus takes a present from his bag and gives it to the kid who is currently first in line.  That kid then goes to the end of the line, unless he already has 4 gifts, in which case, he goes home.  This process continues as long as there are presents in the bag and kids in the line.


  You are given a vector <string> gifts containing the presents in Santa's bag, in the order they are given away.  Return a vector <string> containing exactly N elements, where the k-th element is a single space separated list of presents received by the k-th kid, in the order he received them.  Kid 0 is the first kid in the initial lineup, kid 1 is the second kid, etc.


  DEFINITION
  Class:SantaGifts
  Method:distribute
  Parameters:vector <string>, int
  Returns:vector <string>
  Method signature:vector <string> distribute(vector <string> gifts, int N)


  CONSTRAINTS
  -gifts will contain between 1 and 50 elements, inclusive.
  -Each element of gifts will contain between 1 and 10 lowercase letters ('a'-'z'), inclusive.
  -N will be between 1 and 50, inclusive.


  EXAMPLES

  0)
  {"ball","plane","robot","puzzle"}
  3

  Returns: {"ball puzzle", "plane", "robot" }

  The first kid gets a ball, the second one a plane, and the third one a robot.  Then the first kid reaches the front of the line again and gets the last gift.

  1)
  {"ball","plane","robot","puzzle","bike"}
  1

  Returns: {"ball plane robot puzzle" }

  There is only one kid, so he will take the first four presents.

  2)
  {"ball","ball","plane","plane"}
  2

  Returns: {"ball plane", "ball plane" }

  In this case Santa Claus is fair and gives a ball and a plane to both kids.

  3)
  {"ball","plane","robot"}
  5

  Returns: {"ball", "plane", "robot", "", "" }

  Unfortunately, not all the kids will get gifts.

*/
// END CUT HERE
#line 61 "SantaGifts.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class SantaGifts {
public:
  vector <string> distribute(vector <string> gifts, int N) {
    vector<string> ret;
    ret.resize(N);
    const int S = gifts.size();
    for (int i = N; i < S; ++i) { // add a space to each of the second received or greater gifts
      // i != S does not work for the case of N > S when it leads to infinite loop
      gifts[i] = " " + gifts[i];
    }
    for (int i = 0; (i != 4*N && i != S); ++i) { //iterate gifts till each one has 4 gifts or till S
      //      cout << "i=" << i << endl;
      ret[i%N] += gifts[i];
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
      cout << "Testing SantaGifts (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456217864;
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
      SantaGifts _obj;
      vector <string> _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string gifts[] = {"ball","plane","robot","puzzle"};
	    int N = 3;
	    string __expected[] = {"ball puzzle", "plane", "robot" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.distribute(vector <string>(gifts, gifts+sizeof(gifts)/sizeof(string)), N); break;
	  }
	case 1:
	  {
	    string gifts[] = {"ball","plane","robot","puzzle","bike"};
	    int N = 1;
	    string __expected[] = {"ball plane robot puzzle" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.distribute(vector <string>(gifts, gifts+sizeof(gifts)/sizeof(string)), N); break;
	  }
	case 2:
	  {
	    string gifts[] = {"ball","ball","plane","plane"};
	    int N = 2;
	    string __expected[] = {"ball plane", "ball plane" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.distribute(vector <string>(gifts, gifts+sizeof(gifts)/sizeof(string)), N); break;
	  }
	case 3:
	  {
	    string gifts[] = {"ball","plane","robot"};
	    int N = 5;
	    string __expected[] = {"ball", "plane", "robot", "", "" };
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.distribute(vector <string>(gifts, gifts+sizeof(gifts)/sizeof(string)), N); break;
	  }
	  /*case 4:
	    {
	    string gifts[] = ;
	    int N = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.distribute(vector <string>(gifts, gifts+sizeof(gifts)/sizeof(string)), N); break;
	    }*/
	  /*case 5:
	    {
	    string gifts[] = ;
	    int N = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.distribute(vector <string>(gifts, gifts+sizeof(gifts)/sizeof(string)), N); break;
	    }*/
	  /*case 6:
	    {
	    string gifts[] = ;
	    int N = ;
	    string __expected[] = ;
	    _expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
	    _received = _obj.distribute(vector <string>(gifts, gifts+sizeof(gifts)/sizeof(string)), N); break;
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
