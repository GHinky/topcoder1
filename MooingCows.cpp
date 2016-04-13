// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  The cows in Byterland are mooing loudly, annoying the residents very much.  Mrs. Darcy of the villa Pemberley is planning to resolve this problem by allowing only one cow to moo.  She will pick the cow whose mooing is the least offensive to all the other cows.

  The farmland in Pemberley is divided into n*m squares of grassland.  Each square is either empty or occupied by a single cow.  When a cow at (x,y) moos, the dissatisfaction of a cow at (i,j) is equal to the square of the distance between them: ((x-i)2 + (y-j)2).  The total dissatisfaction is the sum of the dissatisfaction of all the cows.

  Return the minimal total dissatisfaction that can be achieved by allowing only a single cow to moo.  The farmland will be given as a vector <string>, where '.' characters denote empty squares, and 'C' characters denote squares occupied by cows.

  DEFINITION
  Class:MooingCows
  Method:dissatisfaction
  Parameters:vector <string>
  Returns:int
  Method signature:int dissatisfaction(vector <string> farmland)


  CONSTRAINTS
  -farmland will contain between 1 and 50 elements, inclusive.
  -Each element of farmland will contain between 1 and 50 characters, inclusive.
  -Each element of farmland will contain the same number of characters.
  -Each character in farmland will be either uppercase 'C' or '.'.
  -farmland will contain at least one uppercase 'C'.


  EXAMPLES

  0)
  {"C..",
  ".C.",
  ".C."}

  Returns: 3


  If we set the uppermost cow to moo, the total dissatisfaction will be 2+5;
  If we set the middle cow to moo, the total dissatisfaction will be 2+1;
  If we set the bottommost cow to moo, the total dissatisfaction will be 1+5.

  Certainly we will choose the second plan.

  1)
  {"CCCC",
  "CCCC",
  "CCCC"}

  Returns: 26



  2)
  {"C"}

  Returns: 0

  3)
  {"CCC....",
  "C......",
  "....C.C",
  ".C.CC..",
  "C......"}

  Returns: 81



*/
// END CUT HERE
#line 70 "MooingCows.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MooingCows {
public:
  int calc_helper (int x, int y, int i, int j,const vector<string>& f) {//cow at (x,y) moos, return dissat(i,j)
    int ret;
    if (f[i][j] == '.') // if i,j is empty
      ret = 0;
    else
      ret = (x-i)*(x-i) + (y-j)*(y-j);
    return ret;
  }
  int calc_sum (int x,int y, int N, int M,const vector<string>& f) {//sum_dissat when (x,y) moos
    int ret = 0;
    if (f[x][y] == '.')
      ret += 1000000008; // if x,y is empty
    else {
      for (int i=0; i != N; ++i) {
	for (int j=0; j != M; ++j) {
	  int temp = calc_helper (x, y, i, j, f);
	  ret = ret + temp;
	}
      }
    }
    return ret;
  }
  int dissatisfaction(vector <string> farmland) {
    int ret = 1000000009;
    const int N = farmland.size();
    const int M = farmland[0].size();
    /*
    for (int i=0; i != N; ++i) {
      for (int j=0; j != M; ++j) {
	cout << farmland[i][j] << " ";
      }
      cout << endl;
    }
    */

    for (int i=0; i != N; ++i) {
      for (int j=0; j != M; ++j) {
	int sum = calc_sum (i, j, N, M, farmland);
	ret = min (ret, sum);
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
      cout << "Testing MooingCows (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456058953;
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
      MooingCows _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string farmland[] = {"C..",
				 ".C.",
				 ".C."};
	    _expected = 3;
	    _received = _obj.dissatisfaction(vector <string>(farmland, farmland+sizeof(farmland)/sizeof(string))); break;
	  }
	case 1:
	  {
	    string farmland[] = {"CCCC",
				 "CCCC",
				 "CCCC"};
	    _expected = 26;
	    _received = _obj.dissatisfaction(vector <string>(farmland, farmland+sizeof(farmland)/sizeof(string))); break;
	  }
	case 2:
	  {
	    string farmland[] = {"C"};
	    _expected = 0;
	    _received = _obj.dissatisfaction(vector <string>(farmland, farmland+sizeof(farmland)/sizeof(string))); break;
	  }
	case 3:
	  {
	    string farmland[] = {"CCC....",
				 "C......",
				 "....C.C",
				 ".C.CC..",
				 "C......"};
	    _expected = 81;
	    _received = _obj.dissatisfaction(vector <string>(farmland, farmland+sizeof(farmland)/sizeof(string))); break;
	  }
	  /*case 4:
	    {
	    string farmland[] = ;
	    _expected = ;
	    _received = _obj.dissatisfaction(vector <string>(farmland, farmland+sizeof(farmland)/sizeof(string))); break;
	    }*/
	  /*case 5:
	    {
	    string farmland[] = ;
	    _expected = ;
	    _received = _obj.dissatisfaction(vector <string>(farmland, farmland+sizeof(farmland)/sizeof(string))); break;
	    }*/
	  /*case 6:
	    {
	    string farmland[] = ;
	    _expected = ;
	    _received = _obj.dissatisfaction(vector <string>(farmland, farmland+sizeof(farmland)/sizeof(string))); break;
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
	  cout << "           Expected: " << _expected << endl;
	  cout << "           Received: " << _received << endl;
	}
    }
}

// END CUT HERE
