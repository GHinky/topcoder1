// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  You are the coordinator of a contest, and you have been presented with the final scores of all the contestants. It is now your job to determine the quality of the contest. To do this, you will compute the average score after eliminating the k highest scoring contestants and the k lowest scoring contestants. k is a non-negative integer (it can be 0), and you will choose a value for k that yields the maximum average score. Return a double representing this maximum average score. You are not allowed to eliminate all the scores.


  DEFINITION
  Class:ContestCoordinator
  Method:bestAverage
  Parameters:vector <int>
  Returns:double
  Method signature:double bestAverage(vector <int> scores)


  NOTES
  -The returned value must be accurate to 1e-9 relative or absolute.


  CONSTRAINTS
  -scores will contain between 1 and 50 elements, inclusive.
  -Each element of scores will be between 1 and 1000, inclusive.


  EXAMPLES

  0)
  {1}

  Returns: 1.0

  There's nothing to remove here.

  1)
  {1,2,3,4}

  Returns: 2.5

  Eliminating the first and the last score yields an average score of 2.5

  2)
  {1,1,999,999,1000,1000}

  Returns: 999.0

  Keep only the scores equal to 999.

  3)
  {1,13,8,6,7,9}

  Returns: 7.5

  4)
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

  Returns: 1.0

*/
// END CUT HERE
#line 60 "ContestCoordinator.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class ContestCoordinator {
public:
  double average1 (vector<int> v, int start, int end) {
    double ret = -69;
    int size = end - start;
    double sum = 0.0;
    while (start != end) {
      sum += v[start];
      ++start;
    }
    ret = sum / size;
    //    cout << "size is = " << size << endl;
    return ret;
  }
  double bestAverage(vector <int> scores) {
    sort (scores.begin(), scores.end());
    double ret = scores[0];
    int l = 0;
    int u = scores.size();
    while (((u - l) != 0) && ((u - l) != -1)) {
      double avg;
      avg = average1 (scores, l, u);
      if (avg > ret)
	ret = avg;
      ++l;
      --u;
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
      cout << "Testing ContestCoordinator (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1455728252;
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
      ContestCoordinator _obj;
      double _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int scores[] = {1};
	    _expected = 1.0;
	    _received = _obj.bestAverage(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int scores[] = {1,2,3,4};
	    _expected = 2.5;
	    _received = _obj.bestAverage(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int scores[] = {1,1,999,999,1000,1000};
	    _expected = 999.0;
	    _received = _obj.bestAverage(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int scores[] = {1,13,8,6,7,9};
	    _expected = 7.5;
	    _received = _obj.bestAverage(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
	  }
	case 4:
	  {
	    int scores[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	    _expected = 1.0;
	    _received = _obj.bestAverage(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
	  }
	  case 5:
	    {
	    int scores[] = {1, 4, 1, 1, 2, 10, 6, 4, 8, 6, 6, 3, 3, 9, 2, 2, 5, 3, 4, 9, 9, 10, 9, 4, 7, 7, 4, 10, 10, 9, 9, 6, 4, 5, 3, 10, 8, 9, 9, 9, 4, 5, 1};
	    _expected = 6.0;
	    _received = _obj.bestAverage(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
	    }
	  /*case 6:
	    {
	    int scores[] = ;
	    _expected = ;
	    _received = _obj.bestAverage(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
	    }*/
	  /*case 7:
	    {
	    int scores[] = ;
	    _expected = ;
	    _received = _obj.bestAverage(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
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
