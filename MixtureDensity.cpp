// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A pharmacist is making a mixture of several ingredients. She needs to know the density of the resulting mixture. Density is defined as the mass of the mixture divided by its volume.

You're given a vector <string> ingredients, each element of which describes a single ingredient and is formatted "<Volume> ml of <Name>, weighing <Mass> g" (quotes for clarity). <Volume> and <Mass> are integers representing the volume in milliliters and mass in grams, respectively.  <Name> is the name of the ingredient.

Return the density of the resulting mixture in grams per milliliters.

DEFINITION
Class:MixtureDensity
Method:getDensity
Parameters:vector <string>
Returns:double
Method signature:double getDensity(vector <string> ingredients)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-ingredients will contain between 1 and 50 elements, inclusive.
-Each element of ingredients will contain between 23 and 50 characters, inclusive.
-Each element of ingredients will be formatted as described in the statement.
-Each <Volume> in ingredients will be an integer between 1 and 1000, inclusive, with no leading zeroes.
-Each <Mass> in ingredients will be an integer between 1 and 1000, inclusive, with no leading zeroes.
-Each <Name> in ingredients will contain only lowercase letters ('a'-'z') and spaces (' ').
-Each <Name> in ingredients will begin and end with a lowercase letter.


EXAMPLES

0)
{"200 ml of oil, weighing 180 g"}

Returns: 0.9

The density is mass/volume = 180g/200ml = 0.9g/ml, the answer is 0.9.

1)
{"100 ml of dichloromethane, weighing 130 g", "100 ml of sea water, weighing 103 g"}

Returns: 1.165

The volume of the resulting mixture is 200 ml and the mass is 233 g. Therefore, the density is 233g/200ml = 1.165g/ml.

2)
{"1000 ml of water, weighing 1000 g", "500 ml of orange juice concentrate, weighing 566 g"}

Returns: 1.044



3)
{"1000 ml of something   l i g h t, weighing 1 g"}

Returns: 0.0010



*/
// END CUT HERE
#line 65 "MixtureDensity.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class MixtureDensity {
public:
  double prs (string s) {
    double ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
  }

  double getDensity(vector <string> ingr) {
    double ret = 0.0;
    double v = 0.0;
    double m = 0.0;
    for (int i = 0; i != ingr.size(); ++i) {
      string vol, mass;
      string::iterator iter1;

      iter1 = find (ingr[i].begin(), ingr[i].end(), ' ');
      int temp1 = iter1 - ingr[i].begin(); // no of digits in vol
      vol = ingr[i].substr (0, temp1);

      string::reverse_iterator iter2;
      iter2 = find (ingr[i].rbegin(), ingr[i].rend(), ' ');
      iter2 = find (iter2 + 1, ingr[i].rend(), ' ');
      // now points to space before char of mass digits

      int temp4 = (iter2 - ingr[i].rbegin()); // num of digs in mass + 2
      int temp3 = ingr[i].size() - temp4;
      // temp3 is index of first digit of mass
      mass = ingr[i].substr (temp3, temp4 - 2);

      //      cout << "vol is = " << prs(vol) << " & mass = " << prs(mass) << " gms" << endl;      

      v += prs (vol);
      m += prs (mass);


    }
    ret = m / v;
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
		cout << "Testing MixtureDensity (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456479050;
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
		MixtureDensity _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string ingredients[] = {"200 ml of oil, weighing 180 g"};
				_expected = 0.9;
				_received = _obj.getDensity(vector <string>(ingredients, ingredients+sizeof(ingredients)/sizeof(string))); break;
			}
			case 1:
			{
				string ingredients[] = {"100 ml of dichloromethane, weighing 130 g", "100 ml of sea water, weighing 103 g"};
				_expected = 1.165;
				_received = _obj.getDensity(vector <string>(ingredients, ingredients+sizeof(ingredients)/sizeof(string))); break;
			}
			case 2:
			{
				string ingredients[] = {"1000 ml of water, weighing 1000 g", "500 ml of orange juice concentrate, weighing 566 g"};
				_expected = 1.044;
				_received = _obj.getDensity(vector <string>(ingredients, ingredients+sizeof(ingredients)/sizeof(string))); break;
			}
			case 3:
			{
				string ingredients[] = {"1000 ml of something   l i g h t, weighing 1 g"};
				_expected = 0.0010;
				_received = _obj.getDensity(vector <string>(ingredients, ingredients+sizeof(ingredients)/sizeof(string))); break;
			}
			/*case 4:
			{
				string ingredients[] = ;
				_expected = ;
				_received = _obj.getDensity(vector <string>(ingredients, ingredients+sizeof(ingredients)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string ingredients[] = ;
				_expected = ;
				_received = _obj.getDensity(vector <string>(ingredients, ingredients+sizeof(ingredients)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string ingredients[] = ;
				_expected = ;
				_received = _obj.getDensity(vector <string>(ingredients, ingredients+sizeof(ingredients)/sizeof(string))); break;
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
