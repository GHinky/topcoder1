// BEGIN CUT HERE
/*
PROBLEM STATEMENT

You are going to stick the number of your room on the door. The shop near your house suggests wonderful sets of plastic digits. Each set contains exactly ten digits - one of each digit between 0 and 9, inclusive. Return the number of sets required to write your room number.  Note that 6 can be used as 9 and vice versa.



DEFINITION
Class:RoomNumber
Method:numberOfSets
Parameters:int
Returns:int
Method signature:int numberOfSets(int roomNumber)


CONSTRAINTS
-roomNumber will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
122

Returns: 2

Two sets are required because each set contains only one '2' digit.

1)
9999

Returns: 2

Each set contains one '6' digit and one '9' digit. '6' could be used as '9' and therefore two sets are enough. 

2)
12635

Returns: 1

3)
888888

Returns: 6

*/
// END CUT HERE
#line 50 "RoomNumber.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class RoomNumber {
public:
  int numberOfSets(int roomNumber) {
    int ret;
    double arr[10] = {0, 0, 0, 0 , 0, 0, 0, 0, 0 , 0}; // each digits requirement
    arr[9] = -70; // redundant as it is counted in 6 as well
    while (roomNumber != 0) {
      if (roomNumber % 10 == 6 || roomNumber % 10 == 9) {
	arr[6] += 0.5;
	//cout << "if" << endl;
      } else
	arr[roomNumber % 10] += 1;
      roomNumber /= 10;
    }
    //    cout << "arr[6] =" << arr[6] << endl;
    arr[6] = int (arr[6] + 0.5);
    ret = -69;
    for (int i = 0; i != 10; ++i) {
      //cout << "arr of i=" << i << " = "<< arr[i] << endl;
      ret = max (ret, int (arr[i]));
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
		cout << "Testing RoomNumber (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456323448;
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
		RoomNumber _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int roomNumber = 122;
				_expected = 2;
				_received = _obj.numberOfSets(roomNumber); break;
			}
			case 1:
			{
				int roomNumber = 9999;
				_expected = 2;
				_received = _obj.numberOfSets(roomNumber); break;
			}
			case 2:
			{
				int roomNumber = 12635;
				_expected = 1;
				_received = _obj.numberOfSets(roomNumber); break;
			}
			case 3:
			{
				int roomNumber = 888888;
				_expected = 6;
				_received = _obj.numberOfSets(roomNumber); break;
			}
			/*case 4:
			{
				int roomNumber = ;
				_expected = ;
				_received = _obj.numberOfSets(roomNumber); break;
			}*/
			/*case 5:
			{
				int roomNumber = ;
				_expected = ;
				_received = _obj.numberOfSets(roomNumber); break;
			}*/
			/*case 6:
			{
				int roomNumber = ;
				_expected = ;
				_received = _obj.numberOfSets(roomNumber); break;
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
