// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  Three girls are shopping at a supermarket.  The supermarket is having a sale: "Spend $50 or more in a single transaction and get $10 off."  The girls realize that if they combine their purchases, they might be able to pay less than if they each pay separately.  For example, if they are buying a total of $46, $62 and $9 worth of goods, respectively, they can combine the $46 and $9 totals and make two purchase transactions ($55 and $62) to get $20 off.

  You will be given a vector <int> goods, each element of which is the total cost of the goods purchased by one of the girls.  Return the minimal total cost required to purchase all the goods.  The girls are willing to combine their purchases as described above, but no girl is willing to split up her goods across multiple transactions.

  DEFINITION
  Class:SupermarketDiscount
  Method:minAmount
  Parameters:vector <int>
  Returns:int
  Method signature:int minAmount(vector <int> goods)


  CONSTRAINTS
  -goods will contain exactly 3 elements. 
  -Each element of goods will be between 1 and 99, inclusive.


  EXAMPLES

  0)
  {46, 62, 9}

  Returns: 97

  The example from the problem statement. 

  1)
  {50, 62, 93}

  Returns: 175

  The best decision is to pay separately. 

  2)
  {5, 31, 15}

  Returns: 41

  The only way to get the discount is to combine all three purchases into one transaction.


  3)
  {5, 3, 15}

  Returns: 23

  The girls have no chance of getting the discount.

*/
// END CUT HERE
#line 55 "SupermarketDiscount.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class SupermarketDiscount {
public:
  int minAmount(vector <int> goods) {
    int ret = 0;
    ret = goods[0] + goods[1] + goods[2];
    int discount = 0;

    for (int i = 0; i != goods.size(); ++i) {
      if (goods[i] >= 50) {
	discount += 10;
	goods[i] = -69;
      }
    }
    int othersum = 0;
    for (int i = 0; i != goods.size(); ++i) {
      if (goods[i] != -69) {
	othersum += goods[i];
      }
    }
    if (othersum >= 50)
      discount += 10;
    ret -= discount;
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
      cout << "Testing SupermarketDiscount (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456221960;
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
      SupermarketDiscount _obj;
      int _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int goods[] = {46, 62, 9};
	    _expected = 97;
	    _received = _obj.minAmount(vector <int>(goods, goods+sizeof(goods)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int goods[] = {50, 62, 93};
	    _expected = 175;
	    _received = _obj.minAmount(vector <int>(goods, goods+sizeof(goods)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int goods[] = {5, 31, 15};
	    _expected = 41;
	    _received = _obj.minAmount(vector <int>(goods, goods+sizeof(goods)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int goods[] = {5, 3, 15};
	    _expected = 23;
	    _received = _obj.minAmount(vector <int>(goods, goods+sizeof(goods)/sizeof(int))); break;
	  }
	  /*case 4:
	    {
	    int goods[] = ;
	    _expected = ;
	    _received = _obj.minAmount(vector <int>(goods, goods+sizeof(goods)/sizeof(int))); break;
	    }*/
	  /*case 5:
	    {
	    int goods[] = ;
	    _expected = ;
	    _received = _obj.minAmount(vector <int>(goods, goods+sizeof(goods)/sizeof(int))); break;
	    }*/
	  /*case 6:
	    {
	    int goods[] = ;
	    _expected = ;
	    _received = _obj.minAmount(vector <int>(goods, goods+sizeof(goods)/sizeof(int))); break;
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
