// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  This problem statement contains images that may appear incorrectly or not appear at all in some plugins. In that case, use the standard view in the arena to see it correctly.

  "Petals Around the Rose" is a pretty well known logic game.  A person who knows the game rolls five dice and then says a number.  The other players must guess the rule used to obtain that number.  We will not ask you to play this game because it's a tricky one.  We will simply tell you that the rule is to sum the number of dots that are around the center dot of each die, like the petals around a rose. If a die has no dot in the center, it has no petals. The face of the die labeled with 1 dot has 0 petals, the face with 2 dots has 0 petals, the face with 3 dots has 2 petals, the face with 4 dots has 0 petals, the face with 5 dots has 4 petals and finally the face with 6 dots has 0 petals as can be seen in the picture.





  You are given a vector <int> dice containing the values of the five dice. Return the total number of petals in this configuration.


  DEFINITION
  Class:RosePetals
  Method:getScore
  Parameters:vector <int>
  Returns:int
  Method signature:int getScore(vector <int> dice)


  CONSTRAINTS
  -dice will contain exactly 5 elements.
  -Each element of dice will be between 1 and 6, inclusive.


  EXAMPLES

  0)
  {1, 2, 3, 2, 1}

  Returns: 2

  In this case we have 0 petals for 1 as there are no dots around the central dot, 0 petals for 2 as it has no central dot, 2 petals for 3, 0 petals for 2 and 0 petals for 1.

  1)
  {4, 4, 5, 6, 5}

  Returns: 8

  In this case we have 0 petals + 0 petals + 4 petals + 0 petals + 4 petals = 8 petals.

  2)
  {1, 2, 3, 3, 5}

  Returns: 8



  3)
  {3, 3, 3, 3, 3}

  Returns: 10



  4)
  {2, 2, 2, 2, 2}

  Returns: 0



*/
// END CUT HERE
#line 68 "RosePetals.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class RosePetals {
public:
  int getScore(vector <int> dice) {
    int ret = 0;
    const int arr[7] = {0, 0, 0, 2, 0, 4, 0}; // arr[0] = 0 is sentinel
    /*
    for (int i=1; i!=7; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;
    */
    for (int i=0; i!=dice.size(); ++i) {
      ret += arr[dice[i]];
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
      cout << "Testing RosePetals (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456061384;
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
      RosePetals _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int dice[] = {1, 2, 3, 2, 1};
	    _expected = 2;
	    _received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int dice[] = {4, 4, 5, 6, 5};
	    _expected = 8;
	    _received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int dice[] = {1, 2, 3, 3, 5};
	    _expected = 8;
	    _received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int dice[] = {3, 3, 3, 3, 3};
	    _expected = 10;
	    _received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
	  }
	case 4:
	  {
	    int dice[] = {2, 2, 2, 2, 2};
	    _expected = 0;
	    _received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
	  }
	  /*case 5:
	    {
	    int dice[] = ;
	    _expected = ;
	    _received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
	    }*/
	  /*case 6:
	    {
	    int dice[] = ;
	    _expected = ;
	    _received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
	    }*/
	  /*case 7:
	    {
	    int dice[] = ;
	    _expected = ;
	    _received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
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
