// BEGIN CUT HERE
/*
PROBLEM STATEMENT
 Southern China is suffering from a heavily snowy winter. The heavy snow even causes the closure of an important highway connecting southern and northern China. You've got several reports containing the start and end points of highway segments covered by heavy snow. Given those reports as two vector <int>s  startPoints and endPoints, you are to return the total length of highway segments covered by snow. Note that the reported segments may overlap.


DEFINITION
Class:SnowyWinter
Method:snowyHighwayLength
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int snowyHighwayLength(vector <int> startPoints, vector <int> endPoints)


CONSTRAINTS
-startPoints will contain between 1 and 50 elements, inclusive.
-endPoints will contain the same number of elements as startPoints.
-Each element of startPoints and endPoints will be between 0 and 10000, inclusive.
-The i-th element of startPoints will be smaller than the corresponding element in endPoints.


EXAMPLES

0)
{17,85,57}
{33,86,84}

Returns: 44

These segments don't overlap.

1)
{45,100,125,10,15,35,30,9}
{46,200,175,20,25,45,40,10}

Returns: 132

There are 3 segments covered by snow: 9-25, 30-46 and 100-200.

2)
{4387,711,2510,1001,4687,3400,5254,584,284,1423,3755,929,2154,5719,1326,2368,554}
{7890,5075,2600,6867,7860,9789,6422,5002,4180,7086,8615,9832,4169,7188,9975,8690,1423}

Returns: 9691

The snow covered segment is 284-9975.

3)
{4906,5601,5087,1020,4362,2657,6257,5509,5107,5315,277,6801,2136,2921,5233,5082,497,8250,3956,5720}
{4930,9130,9366,2322,4687,4848,8856,6302,5496,5438,829,9053,4233,4119,9781,8034,3956,9939,4908,5928}

Returns: 9510

There are 2 segments covered by snow: 277-4930 and 5082-9939.

4)
{51,807,943,4313,8319,3644,481,220,2161,448,465,1657,6290,22,6152,647,3185,4474,2168}
{1182,912,1832,7754,9557,7980,4144,3194,7129,5535,1172,2043,6437,7252,9508,4745,8313,8020,4017}

Returns: 9535

5)
{8786,7391,201,4414,5822,5872,157,1832,7487,7518,2267,1763,3984,3102,7627,4099,524,1543,1022,3060}
{9905,7957,3625,6475,9314,9332,4370,8068,8295,8177,7772,2668,7191,8480,9211,4802,2625,1924,9970,4180}

Returns: 9813

*/
// END CUT HERE
#line 71 "SnowyWinter.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class SnowyWinter {
public:
  int snowyHighwayLength(vector <int> startPoints, vector <int> endPoints) {
    int ret = 0;
    int roadend = endPoints[0];
    int roadstart = endPoints[0];
    for (int i = 0; i != endPoints.size(); ++i) {
      roadstart = min (roadstart, endPoints[i]);
      roadend = max (roadend, endPoints[i]);
    }
    
    
    vector<string> road;
    road.resize(roadend);
    for (int i = 0; i != roadstart; ++i) {
      road[i] = "_"; // 's' = snow, '_' = no snow
    }

    for (int i = 0; i != startPoints.size(); ++i) { // over reports
      for (int j = startPoints[i]; j != endPoints[i]; ++j) {
	road[j] = "s";
      }
    }
    
    for (int i = 0; i != roadend; ++i) {
      if (road[i] == "s")
	++ret;
      //      cout << road[i];
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
		cout << "Testing SnowyWinter (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456577216;
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
		SnowyWinter _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int startPoints[] = {17,85,57};
				int endPoints[] = {33,86,84};
				_expected = 44;
				_received = _obj.snowyHighwayLength(vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), vector <int>(endPoints, endPoints+sizeof(endPoints)/sizeof(int))); break;
			}
			case 1:
			{
				int startPoints[] = {45,100,125,10,15,35,30,9};
				int endPoints[] = {46,200,175,20,25,45,40,10};
				_expected = 132;
				_received = _obj.snowyHighwayLength(vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), vector <int>(endPoints, endPoints+sizeof(endPoints)/sizeof(int))); break;
			}
			case 2:
			{
				int startPoints[] = {4387,711,2510,1001,4687,3400,5254,584,284,1423,3755,929,2154,5719,1326,2368,554};
				int endPoints[] = {7890,5075,2600,6867,7860,9789,6422,5002,4180,7086,8615,9832,4169,7188,9975,8690,1423};
				_expected = 9691;
				_received = _obj.snowyHighwayLength(vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), vector <int>(endPoints, endPoints+sizeof(endPoints)/sizeof(int))); break;
			}
			case 3:
			{
				int startPoints[] = {4906,5601,5087,1020,4362,2657,6257,5509,5107,5315,277,6801,2136,2921,5233,5082,497,8250,3956,5720};
				int endPoints[] = {4930,9130,9366,2322,4687,4848,8856,6302,5496,5438,829,9053,4233,4119,9781,8034,3956,9939,4908,5928};
				_expected = 9510;
				_received = _obj.snowyHighwayLength(vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), vector <int>(endPoints, endPoints+sizeof(endPoints)/sizeof(int))); break;
			}
			case 4:
			{
				int startPoints[] = {51,807,943,4313,8319,3644,481,220,2161,448,465,1657,6290,22,6152,647,3185,4474,2168};
				int endPoints[] = {1182,912,1832,7754,9557,7980,4144,3194,7129,5535,1172,2043,6437,7252,9508,4745,8313,8020,4017};
				_expected = 9535;
				_received = _obj.snowyHighwayLength(vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), vector <int>(endPoints, endPoints+sizeof(endPoints)/sizeof(int))); break;
			}
			case 5:
			{
				int startPoints[] = {8786,7391,201,4414,5822,5872,157,1832,7487,7518,2267,1763,3984,3102,7627,4099,524,1543,1022,3060};
				int endPoints[] = {9905,7957,3625,6475,9314,9332,4370,8068,8295,8177,7772,2668,7191,8480,9211,4802,2625,1924,9970,4180};
				_expected = 9813;
				_received = _obj.snowyHighwayLength(vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), vector <int>(endPoints, endPoints+sizeof(endPoints)/sizeof(int))); break;
			}
			/*case 6:
			{
				int startPoints[] = ;
				int endPoints[] = ;
				_expected = ;
				_received = _obj.snowyHighwayLength(vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), vector <int>(endPoints, endPoints+sizeof(endPoints)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int startPoints[] = ;
				int endPoints[] = ;
				_expected = ;
				_received = _obj.snowyHighwayLength(vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), vector <int>(endPoints, endPoints+sizeof(endPoints)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int startPoints[] = ;
				int endPoints[] = ;
				_expected = ;
				_received = _obj.snowyHighwayLength(vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), vector <int>(endPoints, endPoints+sizeof(endPoints)/sizeof(int))); break;
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
