// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You wish to buy a new car and would like to get the cheapest option available. However, you recognize that the initial purchase cost is only a part of what you will need to spend on the car and you want to factor tax and fuel costs into your decision. You will be given a vector <string> cars giving the specifications of various models of car and an int annualDistance containing the distance that you will drive each year. For the car that you choose, the purchase cost only has to be paid once, the tax cost specific to the model has to be paid once per year and the fuel cost should be calculated as FUEL PRICE * DISTANCE DRIVEN / FUEL EFFICIENCY, where the fuel efficiency is specific to the car. You should calculate which car model in cars has the lowest cost on aggregate after years amount of time and return a double containing this cost.
Each element of cars will be formatted "<PURCHASE COST> <TAX> <FUEL EFFICIENCY>" (quotes for clarity).

DEFINITION
Class:CarBuyer
Method:lowestCost
Parameters:vector <string>, int, int, int
Returns:double
Method signature:double lowestCost(vector <string> cars, int fuelPrice, int annualDistance, int years)


NOTES
-The return value must be accurate to within an absolute or relative tolerance of 1e-9.


CONSTRAINTS
-cars will contain between 1 and 50 elements, inclusive.
-Each element of cars will contain between 5 and 15 characters, inclusive.
-Each element of cars will be formatted "<PURCHASE COST> <TAX> <FUEL EFFICIENCY>".
-Each <PURCHASE COST> will be an integer, without leading zeros, between 1 and 100000, inclusive.
-Each <TAX> will be an integer, without leading zeros, between 1 and 1000, inclusive.
-Each <FUEL EFFICIENCY> will be an integer, without leading zeros, between 1 and 100, inclusive.
-fuelPrice will be between 1 and 100, inclusive.
-annualDistance will be between 1 and 100000, inclusive.
-years will be between 1 and 100, inclusive.


EXAMPLES

0)
{"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"}
2
5000
2

Returns: 10500.0

Here, fuel is cheap, you have a low annual mileage and you don't want to keep the car very long, so you go with the first model, which has the lowest purchase cost.

1)
{"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"}
8
25000
10

Returns: 45200.0

This is the same set of cars, but this time fuel is far more expensive and you're going to keep the car for longer and drive it further. Now the more fuel-efficient fourth model is the cheapest.

2)
{"8426 774 19","29709 325 31","30783 853 68","20796 781 3"
,"27726 4 81","20788 369 69","17554 359 34","12039 502 24"
,"6264 230 69","14151 420 65","25115 528 70","22234 719 55"
,"2050 926 40","18618 714 29","173 358 57"}
33
8673
64

Returns: 254122.44444444444



*/
// END CUT HERE
#line 69 "CarBuyer.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class CarBuyer {
public:
  double lowestCost(vector <string> cars, int fuelPrice, int annualDistance, int years) {
    double ret = 9999999999999.00;
    for (int c = 0; c != cars.size(); ++c) { // each car
      stringstream ss;
      int pp, tax, fe;
      int arr[3];
      string cin = cars[c];
      ss << cin;
      int temp3;
      int i = 0;
      while (ss >> temp3) {
	arr[i] = temp3;
	++i;
      }
      pp = arr[0];
      tax = arr[1];
      fe = arr[2];
      double temp2 = (fuelPrice * annualDistance * years);
      double temp = pp + tax * years + temp2 / fe;
      ret = min (ret, temp);
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
		cout << "Testing CarBuyer (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456292165;
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
		CarBuyer _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cars[] = {"10000 50 50 ","12000 500 10","15000 100 65","20000 20 80","25000 10 90"};
				int fuelPrice = 2;
				int annualDistance = 5000;
				int years = 2;
				_expected = 10500.0;
				_received = _obj.lowestCost(vector <string>(cars, cars+sizeof(cars)/sizeof(string)), fuelPrice, annualDistance, years); break;
			}
				case 1:
			{
				string cars[] = {"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"};
				int fuelPrice = 8;
				int annualDistance = 25000;
				int years = 10;
				_expected = 45200.0;
				_received = _obj.lowestCost(vector <string>(cars, cars+sizeof(cars)/sizeof(string)), fuelPrice, annualDistance, years); break;
			}
			case 2:
			{
				string cars[] = {"8426 774 19","29709 325 31","30783 853 68","20796 781 3"
				                ,"27726 4 81","20788 369 69","17554 359 34","12039 502 24"
				                ,"6264 230 69","14151 420 65","25115 528 70","22234 719 55"
				                ,"2050 926 40","18618 714 29","173 358 57"};
				int fuelPrice = 33;
				int annualDistance = 8673;
				int years = 64;
				_expected = 254122.44444444444;
				_received = _obj.lowestCost(vector <string>(cars, cars+sizeof(cars)/sizeof(string)), fuelPrice, annualDistance, years); break;
				}
			/*case 3:
			{
				string cars[] = ;
				int fuelPrice = ;
				int annualDistance = ;
				int years = ;
				_expected = ;
				_received = _obj.lowestCost(vector <string>(cars, cars+sizeof(cars)/sizeof(string)), fuelPrice, annualDistance, years); break;
			}*/
			/*case 4:
			{
				string cars[] = ;
				int fuelPrice = ;
				int annualDistance = ;
				int years = ;
				_expected = ;
				_received = _obj.lowestCost(vector <string>(cars, cars+sizeof(cars)/sizeof(string)), fuelPrice, annualDistance, years); break;
			}*/
			/*case 5:
			{
				string cars[] = ;
				int fuelPrice = ;
				int annualDistance = ;
				int years = ;
				_expected = ;
				_received = _obj.lowestCost(vector <string>(cars, cars+sizeof(cars)/sizeof(string)), fuelPrice, annualDistance, years); break;
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
