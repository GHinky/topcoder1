// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  You are in a mountainous area which is represented by a vector <string> areaMap. The j-th character of the i-th element of the areaMap is a digit '0'-'9' representing the height of cell (i, j). You perform a walk in the area according to the following rules:

  You start from cell (0, 0).
  If you are in cell (i, j), you examine cells (i+1, j), (i, j-1), (i-1, j), (i, j+1) in this order. You go to the first of these cells you can enter. You can enter a cell if it is still on the map, you haven't been to it before and the difference between the heights of your current cell and the cell you want to enter is no bigger (in absolute value) than heightDifference.
  You end your walk if you can not make another move, i.e., if you can not enter any neighboring cell.

  You must return the number of cells that you visit while performing your walk. You visit cell (i, j) if and only if you enter cell (i, j) at some point during your walk (the starting cell (0, 0) also counts as entered, i.e., you definitely visit (0, 0)). Note that you will visit each cell at most once since you never enter the same cell twice.

  DEFINITION
  Class:MountainWalk
  Method:cellsVisited
  Parameters:vector <string>, int
  Returns:int
  Method signature:int cellsVisited(vector <string> areaMap, int heightDifference)


  CONSTRAINTS
  -areaMap will contain between 1 and 50 elements, inclusive.
  -All the elements of areaMap will contain the same number of characters.
  -Each element of areaMap will contain between 1 and 50 digits ('0' - '9'), inclusive.
  -heightDifference will be between 0 and 9, inclusive.


  EXAMPLES

  0)
  {"056",
  "135",
  "234"}
  1

  Returns: 5

  Your path goes (0, 0) --> (1, 0) --> (2, 0) --> (2, 1) --> (1, 1) and so you visit 5 cells.

  1)
  {"056",
  "195",
  "234"}
  1

  Returns: 8

  Now you can not enter the cell (1, 1) because of the cell difference so your path goes (0, 0) --> (1, 0) --> (2, 0) --> (2, 1) --> (2, 2) --> (1, 2) --> (0, 2) --> (0, 1).

  2)
  {"865",
  "123",
  "111"}
  3

  Returns: 9

  Your path is (0, 0) --> (0, 1) --> (0, 2) --> (1, 2) --> (2, 2) --> (2, 1) --> (2, 0) --> (1, 0) --> (1, 1).

  3)
  {"00009876543210",
  "00009876543210",
  "00009876543210",
  "00009876543210"}
  8

  Returns: 16



  4)
  {"0000",
  "0000",
  "0000",
  "0000",
  "9999",
  "8888",
  "7777",
  "6666",
  "5555",
  "4444",
  "3333",
  "2222",
  "1111",
  "0000"}
  3

  Returns: 16



  5)
  {"173642855131893831828253420",
  "126290035950506994475683704",
  "381277675415026563959463393",
  "019782700912864681764582260",
  "496448425114634806770407597",
  "049628433145840178727435051",
  "117194708226266248973780562",
  "398138380998246682323622510",
  "408178777661559971959512111"}
  8

  Returns: 135



  6)
  {"9"}
  0

  Returns: 1



*/
// END CUT HERE
#line 118 "MountainWalk.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class MountainWalk {
public:
  int prs (char c) {
    int ret;
    if (isdigit (c)) {
      stringstream ss;
      ss << c;
      ss >> ret;
      return ret;
    }
    else if (c == '*')
      ret = -69;

    return ret;
  }
  
  bool ispoint (int i, int j, int H, int W) { // point is inside H * W
    bool ret = true;
    if (i < 0 || i >= H+2 || j < 0 || j >= W+2)
      ret = false;
    return ret;
  }
  
  int cellsVisited(vector <string> areaMap, int hd) {
    int ret = 0;
    // sentinel boundary '*'

    //    VS a = areaMap;
    VS am;
    const int H = areaMap.size();
    const int W = areaMap[0].length();
    
    am.push_back (string (W + 2, '*'));
    for (int i = 0; i != H; ++i) {
      string topush = "*" + areaMap[i] + "*";
      am.push_back (topush);
    }
    am.push_back (string (W + 2, '*'));

    cout << "--------area Map----------" << endl;
    for (int i = 0; i != am.size(); ++i) {
      cout << am[i] << endl;
    }
    cout << "--------------------------" << endl;

    int i = 1, j = 1;
    int mem = prs(am[i][j]);

    while ( ispoint(i, j, H, W)
	    && (am[i][j] != '*')
	    && (abs ((prs(am[i][j]) - mem)) <= hd)) {
      //      cout << "inside while";
      ++ret;
      // * = already visited
      int i1, i2, i3, i4;
      i1 = prs(am[i+1][j]); // down
      i2 = prs(am[i][j-1]); // left
      i3 = prs(am[i-1][j]); // up
      i4 = prs(am[i][j+1]); // right
      
      if ((i1 != -69) && (abs(i1 - mem) <= hd)) {
	mem = i1;
	am[i][j] = '*';
	++i;
      }
      else if ((i2 != -69) && (abs(i2 - mem) <= hd)) {
	mem = i2;
	am[i][j] = '*';
	--j;
      }
      else if ((i3 != -69) && (abs(i3 - mem) <= hd)) {
	mem = i3;
	am[i][j] = '*';
	--i;
      }
      else if ((i4 != -69) && (abs(i4 - mem) <= hd)) {
	mem = i4;
	am[i][j] = '*';
	++j;
      }
      else
	break;
      //cout << "visiting ( " << i-1 << " , " << j-1 << " )" << endl;
    }
    
    cout << endl;
    cout << "----------finally map -------------" << endl;
    for (int i = 0; i != am.size(); ++i) {
      cout << am[i] << endl;
    }
    cout << endl;

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
      cout << "Testing MountainWalk (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456581701;
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
      MountainWalk _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    string areaMap[] = {"056",
				"135",
				"234"};
	    int heightDifference = 1;
	    _expected = 5;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
	  }
	case 1:
	  {
	    string areaMap[] = {"056",
				"195",
				"234"};
	    int heightDifference = 1;
	    _expected = 8;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
	  }
	case 2:
	  {
	    string areaMap[] = {"865",
				"123",
				"111"};
	    int heightDifference = 3;
	    _expected = 9;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
	  }
	case 3:
	  {
	    string areaMap[] = {"00009876543210",
				"00009876543210",
				"00009876543210",
				"00009876543210"};
	    int heightDifference = 8;
	    _expected = 16;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
	  }
	case 4:
	  {
	    string areaMap[] = {"0000",
				"0000",
				"0000",
				"0000",
				"9999",
				"8888",
				"7777",
				"6666",
				"5555",
				"4444",
				"3333",
				"2222",
				"1111",
				"0000"};
	    int heightDifference = 3;
	    _expected = 16;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
	  }
	case 5:
	  {
	    string areaMap[] = {"173642855131893831828253420",
				"126290035950506994475683704",
				"381277675415026563959463393",
				"019782700912864681764582260",
				"496448425114634806770407597",
				"049628433145840178727435051",
				"117194708226266248973780562",
				"398138380998246682323622510",
				"408178777661559971959512111"};
	    int heightDifference = 8;
	    _expected = 135;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
	  }
	case 6:
	  {
	    string areaMap[] = {"9"};
	    int heightDifference = 0;
	    _expected = 1;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
	  }
	  /*case 7:
	    {
	    string areaMap[] = ;
	    int heightDifference = ;
	    _expected = ;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
	    }*/
	  /*case 8:
	    {
	    string areaMap[] = ;
	    int heightDifference = ;
	    _expected = ;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
	    }*/
	  /*case 9:
	    {
	    string areaMap[] = ;
	    int heightDifference = ;
	    _expected = ;
	    _received = _obj.cellsVisited(vector <string>(areaMap, areaMap+sizeof(areaMap)/sizeof(string)), heightDifference); break;
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
