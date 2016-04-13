// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  A skew symmetric matrix M satisfies MT = -M, where MT denotes the transpose of the matrix M and -M denotes the matrix obtained by multiplying each entry of M by -1. The transpose of a matrix M is obtained by replacing the element in the i'th row and j'th column of M with the element in the j'th row and i'th column of M. Note that this requires the diagonal elements of a skew-symmetric matrix to be equal to 0.
  Create a class SkewSymmetric which contains a method minChanges. The method will take a vector <string> M, each element of which is a single space separated list of integers. The j'th number in the i'th element of M represents the value at row i and column j of the matrix. The method should return the minimum number of values in M that must be changed such that the resulting matrix is skew symmetric.

  DEFINITION
  Class:SkewSymmetric
  Method:minChanges
  Parameters:vector <string>
  Returns:int
  Method signature:int minChanges(vector <string> M)


  CONSTRAINTS
  -M will contain between 2 and 10 elements, inclusive.
  -Each element of M will be a single space separated list of exactly n integers, where n is the number of elements in M.
  -Each element of M will contain between 1 and 50 characters, inclusive.
  -Each integer in M will be between -99 and 99 inclusive, with no extra leading zeros.
  -The integer zero will be represented as '0' (quotes for clarity) only, and not '-0' (quotes for clarity) in M.


  EXAMPLES

  0)
  {"1 2 8", "-2 1 0", "3 99 3"}

  Returns: 5

  One possible skew-symmetric matrix obtained by changing 5 elements in M is:

  0  2  -3
  -2  0 -99
  3 99   0

  Note that the diagonal elements must be 0.

  1)
  {"0 1 1 1 1 1", "-1 0 1 1 1 1", "-1 -1 0 1 1 1", 
  "-1 -1 -1 0 1 1", "-1 -1 -1 -1 0 1", "0 0 0 0 0 0"}

  Returns: 5



  2)
  {"0 0 0 0", "0 0 0 0", "0 0 0 0", "0 0 0 0"}

  Returns: 0



  3)
  {"1 0", "0 1"}

  Returns: 2



*/
// END CUT HERE
#line 63 "SkewSymmetric.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class SkewSymmetric {
public:
  
  int minChanges(vector <string> M) {
    int ret = 0;
    const int R = M.size();
    const int C = R;
    vector <vector<int> > M2;
    for (int i=0; i!=R; ++i) {
      string vin = M[i];
      stringstream sso;
      sso << vin;
      int dig;
      vector<int> temp;
      while (sso >> dig) {
	temp.push_back(dig);
      }
      M2.push_back(temp);
    }
    for (int i=0; i!=R; ++i) {
      for (int j=0; j!=C; ++j) {
	if ((M2[i][j] + M2[j][i]) != 0) {
	  if (i==j)
	    ret = ret + 2;
	  else
	    ret = ret + 1;
	  //	  cout << "ij = " << M2[i][j] << " & " << "ji = " << M2[j][i] << endl;
	}
      }
    }
    ret = ret/2;
    /*


    for (int i=0; i!=R; ++i) {
      for (int j=0; j!=C; ++j) {
	cout << M2[i][j] << "  ";
      }
      cout << endl;
    }
    
    */
/*   stringstream ss;
    string s = "1";
    ss << s;
    int temp;
    ss >> temp;
    cout << temp + 1 << " " << endl;
*/
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
      cout << "Testing SkewSymmetric (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456074068;
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
      SkewSymmetric _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string M[] = {"1 2 8", "-2 1 0", "3 99 3"};
	    _expected = 5;
	    _received = _obj.minChanges(vector <string>(M, M+sizeof(M)/sizeof(string))); break;
	  }
	case 1:
	  {
	    string M[] = {"0 1 1 1 1 1", "-1 0 1 1 1 1", "-1 -1 0 1 1 1", 
			  "-1 -1 -1 0 1 1", "-1 -1 -1 -1 0 1", "0 0 0 0 0 0"};
	    _expected = 5;
	    _received = _obj.minChanges(vector <string>(M, M+sizeof(M)/sizeof(string))); break;
	  }
	case 2:
	  {
	    string M[] = {"0 0 0 0", "0 0 0 0", "0 0 0 0", "0 0 0 0"};
	    _expected = 0;
	    _received = _obj.minChanges(vector <string>(M, M+sizeof(M)/sizeof(string))); break;
	  }
	case 3:
	  {
	    string M[] = {"1 0", "0 1"};
	    _expected = 2;
	    _received = _obj.minChanges(vector <string>(M, M+sizeof(M)/sizeof(string))); break;
	  }
	  /*case 4:
	    {
	    string M[] = ;
	    _expected = ;
	    _received = _obj.minChanges(vector <string>(M, M+sizeof(M)/sizeof(string))); break;
	    }*/
	  /*case 5:
	    {
	    string M[] = ;
	    _expected = ;
	    _received = _obj.minChanges(vector <string>(M, M+sizeof(M)/sizeof(string))); break;
	    }*/
	  /*case 6:
	    {
	    string M[] = ;
	    _expected = ;
	    _received = _obj.minChanges(vector <string>(M, M+sizeof(M)/sizeof(string))); break;
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
