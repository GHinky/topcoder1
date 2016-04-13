// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  You are thinking of using the following betting strategy: in the first round, you bet one dollar.  If you win the bet, you win the dollar and bet another dollar in the next round.  Otherwise you lose the dollar and bet two dollars in the second round (provided you still have at least two dollars in your account).  If you win, you get the two dollars and bet one dollar in the third round, otherwise you lose the two dollars and bet four dollars in the third round (provided you have at least that amount in your account) and so on.  In other words, whenever you lose a bet, you double the value of the bet for the next round.  Whenever you win, the bet for the next round will be one dollar.

  For example, if you start with 10 dollars, and you win the bet in the first round, lose the bet in the next two rounds and then win the bet in the fourth round, you will end up with 10+1-1-2+4 = 12 dollars.

  You will be given an int initSum giving the amount of money you initially have.  You will also be given a string outcome.  The ith character of outcome will be either 'W' (win) or 'L' (lose), denoting the outcome of the ith round.  Return the amount of money you will have after all the rounds are played.  If at some point you don't have enough money in your account to cover the value of the bet, you must stop and return the sum you have at that point.


  DEFINITION
  Class:BettingStrategy
  Method:finalSum
  Parameters:int, string
  Returns:int
  Method signature:int finalSum(int initSum, string outcome)


  CONSTRAINTS
  -initSum will be between 1 and 1000, inclusive.
  -outcome will contain between 1 and 50 characters, inclusive.
  -Each character of outcome will be either 'W' or 'L'.


  EXAMPLES

  0)
  12
  "WWWWWWWW"

  Returns: 20

  You are really lucky.  You win one dollar in each round, so you end up with 20 dollars.

  1)
  15
  "LLLWLLLL"

  Returns: 1

  After losing 7 dollars in the first three rounds, you have just enough money to cover your bet for the fourth round.  You win 8 dollars in this round, but lose another 15 in the last four, so your final sum will be one dollar.

  2)
  20
  "WLWLWLWL"

  Returns: 23

  You win one dollar in each odd numbered round and lose one dollar in the last round.

  3)
  925
  "WLLLLLWLLLLLLWWWWWLWLLWLLLLLLWL"

  Returns: 934

*/
// END CUT HERE
#line 60 "BettingStrategy.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class BettingStrategy {
public:
  int finalSum(int initSum, string outcome) {
    int ret = initSum;
    int bet = 1;
    for (int i = 0; (i != outcome.size() && bet <= ret); ++i) {
      if (outcome[i] == 'W') {
	ret += bet;
	bet = 1;
      } else {
	ret -= bet;
	bet *= 2;
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
      cout << "Testing BettingStrategy (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456226596;
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
      BettingStrategy _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int initSum = 12;
	    string outcome = "WWWWWWWW";
	    _expected = 20;
	    _received = _obj.finalSum(initSum, outcome); break;
	  }
	case 1:
	  {
	    int initSum = 15;
	    string outcome = "LLLWLLLL";
	    _expected = 1;
	    _received = _obj.finalSum(initSum, outcome); break;
	  }
	case 2:
	  {
	    int initSum = 20;
	    string outcome = "WLWLWLWL";
	    _expected = 23;
	    _received = _obj.finalSum(initSum, outcome); break;
	  }
	case 3:
	  {
	    int initSum = 925;
	    string outcome = "WLLLLLWLLLLLLWWWWWLWLLWLLLLLLWL";
	    _expected = 934;
	    _received = _obj.finalSum(initSum, outcome); break;
	  }
	  /*case 4:
	    {
	    int initSum = ;
	    string outcome = ;
	    _expected = ;
	    _received = _obj.finalSum(initSum, outcome); break;
	    }*/
	  /*case 5:
	    {
	    int initSum = ;
	    string outcome = ;
	    _expected = ;
	    _received = _obj.finalSum(initSum, outcome); break;
	    }*/
	  /*case 6:
	    {
	    int initSum = ;
	    string outcome = ;
	    _expected = ;
	    _received = _obj.finalSum(initSum, outcome); break;
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
