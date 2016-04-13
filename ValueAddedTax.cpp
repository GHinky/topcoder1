// BEGIN CUT HERE
/*
PROBLEM STATEMENT
In Russia, the Value Added Tax is 18% for almost all goods, with the exception of certain food items, which have a Value Added Tax of only 10%.
You are given a String product, the name of a product, and an int price, the price of the product before tax. You are also given a String[] food, each element of which is the name of a food product. If the given product is an element in food, it is a food item (and thus subject to 10% tax), and otherwise, it is a non-food item (and thus subject to 18% tax). Return the price of the product after tax has been added.

DEFINITION
Class:ValueAddedTax
Method:calculateFinalPrice
Parameters:string, int, vector <string>
Returns:double
Method signature:double calculateFinalPrice(string product, int price, vector <string> food)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-product will contain between 1 and 50 characters, inclusive.
-Each character in product will be a lowercase letter ('a'-'z').
-price will be between 1 and 1000, inclusive.
-food will contain between 1 and 50 elements, inclusive.
-Each element of food will contain between 1 and 50 characters, inclusive.
-Each character in each element of food will be a lowercase letter ('a'-'z').
-All elements of food will be distinct.


EXAMPLES

0)
"milk"
1
{"bread", "butter", "milk"}

Returns: 1.1



1)
"car"
100
{"bread", "butter", "milk"}

Returns: 118.0



2)
"abc"
57
{"a", "b", "c"}

Returns: 67.25999999999999



*/
// END CUT HERE
#line 61 "ValueAddedTax.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class ValueAddedTax {
public:
  double calculateFinalPrice(string product, int price, vector <string> food) {
    double ret = -69.0;
    VS::iterator i = find (food.begin(), food.end(), product);
    if (i != food.end())
      ret = price + 0.1 * price;
    else
      ret = price + 0.18 * price;
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
		cout << "Testing ValueAddedTax (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456330877;
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
		ValueAddedTax _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string product = "milk";
				int price = 1;
				string food[] = {"bread", "butter", "milk"};
				_expected = 1.1;
				_received = _obj.calculateFinalPrice(product, price, vector <string>(food, food+sizeof(food)/sizeof(string))); break;
			}
			case 1:
			{
				string product = "car";
				int price = 100;
				string food[] = {"bread", "butter", "milk"};
				_expected = 118.0;
				_received = _obj.calculateFinalPrice(product, price, vector <string>(food, food+sizeof(food)/sizeof(string))); break;
			}
			case 2:
			{
				string product = "abc";
				int price = 57;
				string food[] = {"a", "b", "c"};
				_expected = 67.25999999999999;
				_received = _obj.calculateFinalPrice(product, price, vector <string>(food, food+sizeof(food)/sizeof(string))); break;
			}
			/*case 3:
			{
				string product = ;
				int price = ;
				string food[] = ;
				_expected = ;
				_received = _obj.calculateFinalPrice(product, price, vector <string>(food, food+sizeof(food)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string product = ;
				int price = ;
				string food[] = ;
				_expected = ;
				_received = _obj.calculateFinalPrice(product, price, vector <string>(food, food+sizeof(food)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string product = ;
				int price = ;
				string food[] = ;
				_expected = ;
				_received = _obj.calculateFinalPrice(product, price, vector <string>(food, food+sizeof(food)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
