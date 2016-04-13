// BEGIN CUT HERE
/*
  PROBLEM STATEMENT

  You have a device that measures temperature once a minute. Sadly, the temperature sensor of your device is not 100% reliable,
  and sometimes it reports wildly inaccurate values. 



  You don't have the resources to buy a new device so you decide to fix the problem by writing software for your device that will throw away invalid measurements.
  We consider a measurement invalid if:



  the value is less than -273, or
  each value that was measured within 2 minutes before and after this one differs from this value by more than 2



  In other words, when deciding whether a measurement is valid, you usually consider the previous two, and the next two measurements.



  You are given a vector <int> measuredValues that contains temperatures measured in the last few minutes. 
  The temperatures are given in chronological order, i.e., the i-th value is the temperature measured i minutes after the device was started.
  Write a method that computes the average of the valid measurements. If no measurement is valid, return -300.0.


  DEFINITION
  Class:MeasuringTemperature
  Method:averageTemperature
  Parameters:vector <int>
  Returns:double
  Method signature:double averageTemperature(vector <int> measuredValues)


  NOTES
  -The returned value must be accurate to within a relative or absolute error of 1E-9.
  -The lowest possible temperature (in degrees Celsius) is -273.15.
  -It may seem weird that only integer temperatures are used in the input. This is only done to avoid rounding errors.


  CONSTRAINTS
  -measuredValues contains between 2 and 50 elements, inclusive.
  -Each element of measuredValues will be between -1000 and 1000, inclusive.


  EXAMPLES

  0)
  {9, 11, 12, 13, 15}

  Returns: 12.0

  All measurements are valid. During this period of time it was getting warmer. The average temperature is (9+11+12+13+15)/5 = 12.

  1)
  {0, 0, 0, 2, 997, -1, 0}

  Returns: 0.16666666666666666

  The fifth measurement is clearly invalid. The average of the valid ones is slightly positive.

  2)
  {0, 0, 0, 2, -4, -1, 0}

  Returns: 0.16666666666666666

  This time, the fifth measurement is only slightly off, but still we consider it to be invalid.

  3)
  {0, 0, 0, 2, -3, -1, 0}

  Returns: -0.2857142857142857

  All the measurements are valid.

  4)
  {1,2,3,100,100,1,2}

  Returns: 29.857142857142858

  Again, all these measurements are valid. (Sadly, the sensor malfunctioned twice in a row. Our approach can't deal with this situation.)

  5)
  {1,2,3,4,5,6,7,10}

  Returns: 4.0

  The last measurement is invalid. (The measurements made within 2 minutes from the last measurement gave results 6 and 7, and neither of these values is close enough to 10.)

  6)
  {-35, -34, -34, -34, -35, 72, -34, 52, -36, -35, -36, 52, -36, -35, 981, -33}

  Returns: -34.75

  It's freezing cold and the sensor is malfunctioning quite often, but luckily we can identify all the wrong measurements (72, 52, 52, and 981) as invalid.

  7)
  {-273, -273, -274, -273}

  Returns: -273.0

  The third measurement gives a temperature lower than -273, and thus is considered to be invalid.

  8)
  {10, 20, 30, 40}

  Returns: -300.0

  No valid measurements here.

*/
// END CUT HERE
#line 116 "MeasuringTemperature.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class MeasuringTemperature {
public:
  double averageTemperature(vector <int> measuredValues) {
    double ret = -69.0;
    typedef vector<int>::size_type vs;
    vs size = measuredValues.size();

    int mv[size+4];
    for (int i=2; i!=size+2; ++i) {
      mv[i] = measuredValues[i-2];
    }

    //sentinels
    mv[size+2] = mv[size-1];
    mv[size+3] = mv[size];
    mv[0] = mv[3];
    mv[1] = mv[4];

    /*    //print mv
    cout << endl;
    for (int i=0; i != size+4; ++i) {
      cout << mv[i] << " ";
    }
    */

    int invalid_count = 0;
    double running_sum = 0;
    for (int i=2, im=1, imm=0, ip=3, ipp=4; i != size+2; ++i,++im,++imm,++ip,++ipp) {
      int diff1 = abs (mv[i] - mv[imm]);
      int diff2 = abs (mv[i] - mv[im]);
      int diff3 = abs (mv[i] - mv[ip]);
      int diff4 = abs (mv[i] - mv[ipp]);
      int temp1 = min (diff1, diff2);
      int temp2 = min (diff3, diff4);
      int diff = min (temp1, temp2);
      //      cout << "\n***********\n" << diff1 << " " << diff2 << " "
      // << diff3 << " " << diff4 << " " << "\n*************\n";
      if (diff > 2 || mv[i] < -273) {
	++invalid_count;
      } else {
	running_sum += mv[i];
      }
    }
    //    cout << "\ninvalid count =" << invalid_count << endl;
    if (invalid_count == size)
      ret = -300.0;
    else
      ret = running_sum / (size - invalid_count);

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
      cout << "Testing MeasuringTemperature (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1455733054;
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
      MeasuringTemperature _obj;
      double _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int measuredValues[] = {9, 11, 12, 13, 15};
	    _expected = 12.0;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	  }
	case 1:
	  {
	    int measuredValues[] = {0, 0, 0, 2, 997, -1, 0};
	    _expected = 0.16666666666666666;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	  }
	case 2:
	  {
	    int measuredValues[] = {0, 0, 0, 2, -4, -1, 0};
	    _expected = 0.16666666666666666;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	  }
	case 3:
	  {
	    int measuredValues[] = {0, 0, 0, 2, -3, -1, 0};
	    _expected = -0.2857142857142857;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	  }
	case 4:
	  {
	    int measuredValues[] = {1,2,3,100,100,1,2};
	    _expected = 29.857142857142858;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	  }
	case 5:
	  {
	    int measuredValues[] = {1,2,3,4,5,6,7,10};
	    _expected = 4.0;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	  }
	case 6:
	  {
	    int measuredValues[] = {-35, -34, -34, -34, -35, 72, -34, 52, -36, -35, -36, 52, -36, -35, 981, -33};
	    _expected = -34.75;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	  }
	case 7:
	  {
	    int measuredValues[] = {-273, -273, -274, -273};
	    _expected = -273.0;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	  }
	case 8:
	  {
	    int measuredValues[] = {10, 20, 30, 40};
	    _expected = -300.0;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	  }
	  case 9:
	    {
	      int measuredValues[] = {10, 13};
	      _expected = -300.0;
	      _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	    }
	  case 10:
	    {
	    int measuredValues[] = {-13, 12, -14, 11, -15, 10, -16, 9, -17, 8, -18, 7, 6, -19, 5, -400, -400, 4, -390, -300, -270, 3, -12, 3, 2};
	    _expected = -1.0;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
	    }
	  /*case 11:
	    {
	    int measuredValues[] = ;
	    _expected = ;
	    _received = _obj.averageTemperature(vector <int>(measuredValues, measuredValues+sizeof(measuredValues)/sizeof(int))); break;
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
