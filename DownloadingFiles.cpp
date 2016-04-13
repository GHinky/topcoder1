// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You are downloading some files from the Internet, and you want to know how long it will take until they are completely downloaded.

For each download, you are given its current speed (in KB/s) and remaining time based on that speed (in seconds).  The sum of all the speeds is your total bandwidth, which remains constant and is utilized fully at all times during the downloads.  This means that when files finish downloading, the newly available bandwidth is distributed among the remaining files.  The way it's distributed does not affect the final answer.

For example, consider the following scenario where you are downloading two files.
1) Speed = 3 KB/s Remaining Time 57 seconds
2) Speed = 2 KB/s Remaining Time 22 seconds

After 22 seconds, the second file will finish downloading.  The first file still has 35 seconds remaining, but that time is based on the original speed.  The bandwidth freed up by the second file is now allocated to the first file, and its new speed is 3+2=5 KB/s.  The new remaining time is: Old_Remaining_Time * Old_Speed / New_Speed = 35*3/5 = 21 seconds.

So the actual remaining time for all the files is 21+22=43 seconds.

You will be given a vector <string> tasks, each element of which represents a single file being downloaded.  Each file is represented as two positive integers with no leading zeroes, separated by a single space.  The first integer is the current download speed in KB/s and the second integer is the remaining time in seconds based on the current speed.  Return a double representing the remaining time in seconds for all the downloads to finish.

DEFINITION
Class:DownloadingFiles
Method:actualTime
Parameters:vector <string>
Returns:double
Method signature:double actualTime(vector <string> tasks)


CONSTRAINTS
-tasks will contain between 1 and 50 elements, inclusive.
-Each element of tasks will be formatted "<speed> <time>" (quotes for clarity), where <speed> is an integer between 1 and 100, inclusive, with no leading zeroes, and <time> is an integer between 1 and 10000, inclusive, with no leading zeroes.


EXAMPLES

0)
{"3 57","2 22"}

Returns: 43.0

The example from above.

1)
{"3 1057","2 1022"}

Returns: 1043.0

This is the same as the first example but all the files will take 1000 seconds more to completely download.

2)
{"25 1000","5 5000","10 5000"}

Returns: 2500.0

In this case, when the first file finishes downloading, we will have 25 KB/s of newly available bandwidth.  We can share it between the remaining downloads however we want without affecting the final answer.  Suppose that 15 KB/s goes to the second file and 10 KB/s goes to the third file.  The new speeds and remaining times for those files will be:
20 KB/s and remaining time 2000 seconds
20 KB/s and remaining time 1000 secondsThose would take 1500 seconds to complete. So the answer is 1000 + 1500 = 2500.


3)
{"1 10","1 20","2 40"}

Returns: 27.5

For this example, suppose that all newly available bandwidth goes to the slowest task every time.  When the first download finishes (after 10 seconds), the second task doubles its speed to 2, and thus halves its remaining time from (20-10=10) to 5.  When the second download finishes, the third one doubles its speed, so its remaining time goes from (40-15=25) to 12.5.  The total time is 10+5+12.5=27.5.

4)
{"6 88","39 7057","63 2502","45 2285","28 8749","62 3636","1 5546","49 5741"}

Returns: 4414.542662116041

And here is a nice random example for you.

*/
// END CUT HERE
#line 74 "DownloadingFiles.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <sstream>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class DownloadingFiles {
public:
  static bool space (char c) {
    return isspace (c);
  }
  double prs (string s) {
    double ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
  }
  
  double actualTime(vector <string> tasks) {
    double ret = 0;
    vector<double> speeds, times, sizes;

    for (int i = 0; i != tasks.size(); ++i) {
      string::iterator iter;
      iter = find_if (tasks[i].begin(), tasks[i].end(), space);
      double speed = prs (string (tasks[i].begin(), iter));
      double time = prs (string (iter + 1, tasks[i].end()));
      double sz = speed * time;
      speeds.push_back (speed);
      times.push_back (time);
      sizes.push_back (sz);
    }
    double tot_sz = accumulate (sizes.begin(), sizes.end(), 0.0);
    double tot_bw = accumulate (speeds.begin(), speeds.end(), 0.0); // bandwidth
    ret = tot_sz / tot_bw;

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
		cout << "Testing DownloadingFiles (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456508309;
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
		DownloadingFiles _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string tasks[] = {"3 57","2 22"};
				_expected = 43.0;
				_received = _obj.actualTime(vector <string>(tasks, tasks+sizeof(tasks)/sizeof(string))); break;
			}
			case 1:
			{
				string tasks[] = {"3 1057","2 1022"};
				_expected = 1043.0;
				_received = _obj.actualTime(vector <string>(tasks, tasks+sizeof(tasks)/sizeof(string))); break;
			}
			case 2:
			{
				string tasks[] = {"25 1000","5 5000","10 5000"};
				_expected = 2500.0;
				_received = _obj.actualTime(vector <string>(tasks, tasks+sizeof(tasks)/sizeof(string))); break;
			}
			case 3:
			{
				string tasks[] = {"1 10","1 20","2 40"};
				_expected = 27.5;
				_received = _obj.actualTime(vector <string>(tasks, tasks+sizeof(tasks)/sizeof(string))); break;
			}
			case 4:
			{
				string tasks[] = {"6 88","39 7057","63 2502","45 2285","28 8749","62 3636","1 5546","49 5741"};
				_expected = 4414.542662116041;
				_received = _obj.actualTime(vector <string>(tasks, tasks+sizeof(tasks)/sizeof(string))); break;
			}
			/*case 5:
			{
				string tasks[] = ;
				_expected = ;
				_received = _obj.actualTime(vector <string>(tasks, tasks+sizeof(tasks)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string tasks[] = ;
				_expected = ;
				_received = _obj.actualTime(vector <string>(tasks, tasks+sizeof(tasks)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string tasks[] = ;
				_expected = ;
				_received = _obj.actualTime(vector <string>(tasks, tasks+sizeof(tasks)/sizeof(string))); break;
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
