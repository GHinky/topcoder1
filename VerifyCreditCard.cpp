// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You are developing an application for online transactions and you want to accept several credit cards. Card numbers, however, are usually long, so it's easy to make mistakes when typing them in. You want to create a method that will verify the numbers entered by users.

You know that the Luhn formula applies for all the acceptable card numbers.
The Luhn formula works as follows.

First, separate the individual digits of the credit card number.  For example:

21378 becomes
2 1 3 7 8

If there is an even number of digits, multiply each digit in an odd position by 2. Otherwise, multiply each digit in an even position by 2. Positions are 1-indexed, so the first digit is at position 1. The example number above contains an odd number of digits, so we multiply each digit in an even position by 2:

2 1 3 7 8 becomes
2 2 3 14 8

Note that the even positions refer to the original number so they don't change even when a 2-digit number appears.

Finally, take the sum of all the digits (for 2-digit numbers insert both the digits separately into the sum):

2+2+3+1+4+8 = 20

If the sum is a multiple of 10, the number is valid. Otherwise, it is invalid.

Given a string cardNumber containing the credit card number, return "VALID" if the card number is valid, or "INVALID" if it is invalid (all quotes for clarity).


DEFINITION
Class:VerifyCreditCard
Method:checkDigits
Parameters:string
Returns:string
Method signature:string checkDigits(string cardNumber)


CONSTRAINTS
-cardNumber will contain between 1 and 50 characters, inclusive.
-Each character in cardNumber will be a digit ('0'-'9').


EXAMPLES

0)
"21378"

Returns: "VALID"

This number has 5 digits, which is an odd number, so we multiply the digits in even positions by 2 to get:

2 2 3 14 8

The sum of the digits is 20, which is a multiple of 10, meaning it's a valid number.

1)
"31378"

Returns: "INVALID"

When we apply the Luhn formula here, the sum of the digits is 21, so the number is invalid.


2)
"11111101"

Returns: "VALID"

We multiply the digits in odd positions by 2 to get:

2 1 2 1 2 1 0 1

The sum of the digits is 10, so it's a valid card.


3)
"50005"

Returns: "VALID"

All the digits in even positions are 0 so multiplying by 2 doesn't change the number. The sum of the digits is 10, so it's a valid card.

4)
"542987223412"

Returns: "INVALID"



*/
// END CUT HERE
#line 93 "VerifyCreditCard.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <numeric>
#include <climits>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class VerifyCreditCard {
public:
  int prs (string s) {
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
  }
  int prs (char c) {
    int ret;
    stringstream ss;
    ss << c;
    ss >> ret;
    return ret;
  }

  int sum_of_digits (int i) {
    int ret = 0;
    while (i != 0) {
      ret += i % 10;
      i /= 10;
    }
    return ret;
  }

  VI digits (int i) {
    VI ret;
    while (i != 0) {
      ret.push_back (i % 10);
      i /= 10;
    }
    reverse (ret.begin(), ret.end());
    return ret;
  }

  VI digits (string s) {
    VI ret;
    for (int i = 0; i != s.size(); ++i) {
      int temp = prs(s[i]);
      ret.push_back(temp);
    }
    return ret;
  }

  string checkDigits(string cardNumber) {
    //    cout << "card number = " << cardNumber << endl;
    const int Sz = cardNumber.size();
    string ret;
    VI digs = digits (cardNumber);
    //    cout << "card number = " << cardNumber << endl;

    /*    for (int j = 0; j != digs.size(); ++j) {
      cout << "digs[" << j << "] = " << digs[j] << endl;
      }*/

    int start = (Sz % 2 == 0)? 0 : 1;
    for (int j = start; j != digs.size(); j = j + 2) {
      digs[j] = sum_of_digits (digs[j] * 2);
    }

    /*    for (int j = 0; j != digs.size(); ++j) {
      cout << "digs2[" << j << "] = " << digs[j] << endl;
      }*/

    int luhn = accumulate (digs.begin(), digs.end(), 0);
    //    cout << "luhn : " << luhn << endl;
    ret = (luhn % 10 == 0)? "VALID" : "INVALID";
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
		cout << "Testing VerifyCreditCard (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456594378;
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
		VerifyCreditCard _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cardNumber = "21378";
				_expected = "VALID";
				_received = _obj.checkDigits(cardNumber); break;
			}
			case 1:
			{
				string cardNumber = "31378";
				_expected = "INVALID";
				_received = _obj.checkDigits(cardNumber); break;
			}
			case 2:
			{
				string cardNumber = "11111101";
				_expected = "VALID";
				_received = _obj.checkDigits(cardNumber); break;
			}
			case 3:
			{
				string cardNumber = "50005";
				_expected = "VALID";
				_received = _obj.checkDigits(cardNumber); break;
			}
			case 4:
			{
				string cardNumber = "542987223412";
				_expected = "INVALID";
				_received = _obj.checkDigits(cardNumber); break;
			}
			case 5:
			{
				string cardNumber = "72570633544";
				_expected = "VALID";
				_received = _obj.checkDigits(cardNumber); break;
			}
			case 6:
			{
				string cardNumber = "70227645677166800029";
				_expected = "VALID";
				_received = _obj.checkDigits(cardNumber); break;
			}
			/*case 7:
			{
				string cardNumber = ;
				_expected = ;
				_received = _obj.checkDigits(cardNumber); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
