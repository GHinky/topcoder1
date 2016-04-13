// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You are sitting in front of a mirror and looking at the image of a clock located behind you. You want to know what time it is. The clock is a traditional clock with a 12-hour board (without numbers written on it), a minute and an hour hand (the hour hand is shorter, so that you can distuniguish them). You are given a string time denoting the time as it is seen in the mirror. The time will be formatted as "HH:MM" (quotes for clarity), where HH is the two digit hour and MM is the two digit minute. The hour will be between 00 and 11, inclusive, where 00 represents 12 o' clock. Return a string in the same format denoting the actual time. See examples for further clarification.

DEFINITION
Class:MirroredClock
Method:whatTimeIsIt
Parameters:string
Returns:string
Method signature:string whatTimeIsIt(string time)


CONSTRAINTS
-time will be formatted as "HH:MM" (quotes for clarity), where HH is a two digit integer between 00 and 11, inclusive, and MM is a two digit integer between 00 and 59, inclusive.


EXAMPLES

0)
"10:00"

Returns: "02:00"



1)
"01:15"

Returns: "10:45"



2)
"03:40"

Returns: "08:20"



3)
"00:00"

Returns: "00:00"

Although it doesn't happen often, sometimes we can see the actual time right in the mirror.

4)
"11:53"

Returns: "00:07"



*/
// END CUT HERE
#line 58 "MirroredClock.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class MirroredClock {
public:
  string rprs (int i) {
    string ret;
    stringstream ss;
    ss << i;
    ss >> ret;
    if (ret.length() != 2)
      ret = "0" + ret;
    return ret;
  }
  int prs (string s) {
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
  }
  string whatTimeIsIt(string time) {
    string ret;
    string min;
    string hr;
    int h = prs (time.substr(0, 2));
    int m = prs (time.substr(3, 2));
    int dh6 = abs (h - 6);
    int dm30 = abs (m - 30);
    if (h < 6)
      h = h + 2*dh6 - 1;
    else
      h = h - 2*dh6 - 1;
    if (m < 30)
      m = m + 2 * dm30;
    else
      m = m - 2 * dm30;
    if (m == 0 || m == 60) {
      ++h;
      m = 0;
    }
    h = (h == 12)? 0 : h;
    //    cout << "m = " << rprs(m) << " & h = " << rprs(h) << endl;
    ret = rprs(h) + ":" + rprs(m);
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
		cout << "Testing MirroredClock (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456397600;
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
		MirroredClock _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string time = "10:00";
				_expected = "02:00";
				_received = _obj.whatTimeIsIt(time); break;
			}
			case 1:
			{
				string time = "01:15";
				_expected = "10:45";
				_received = _obj.whatTimeIsIt(time); break;
			}
			case 2:
			{
				string time = "03:40";
				_expected = "08:20";
				_received = _obj.whatTimeIsIt(time); break;
			}
			case 3:
			{
				string time = "00:00";
				_expected = "00:00";
				_received = _obj.whatTimeIsIt(time); break;
			}
			case 4:
			{
				string time = "11:53";
				_expected = "00:07";
				_received = _obj.whatTimeIsIt(time); break;
			}
			/*case 5:
			{
				string time = ;
				_expected = ;
				_received = _obj.whatTimeIsIt(time); break;
			}*/
			/*case 6:
			{
				string time = ;
				_expected = ;
				_received = _obj.whatTimeIsIt(time); break;
			}*/
			/*case 7:
			{
				string time = ;
				_expected = ;
				_received = _obj.whatTimeIsIt(time); break;
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
