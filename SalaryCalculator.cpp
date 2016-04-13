// BEGIN CUT HERE
/*
  PROBLEM STATEMENT
  At a certain company, a worker is paid an hourly rate of P1 dollars for the first 200 hours he works each month. He is paid an hourly rate of P2 dollars for the remaining hours. Return the minimum number of hours he must work this month to earn salary dollars.


  DEFINITION
  Class:SalaryCalculator
  Method:calcHours
  Parameters:int, int, int
  Returns:double
  Method signature:double calcHours(int P1, int P2, int salary)


  NOTES
  -Your return value must have an absolute or relative error less than 1e-9.


  CONSTRAINTS
  -P1 will be between 1 and 100, inclusive. 
  -P2 will be between 1 and 100, inclusive. 
  -salary will be between 1 and 1,000,000, inclusive. 


  EXAMPLES

  0)
  10
  15
  1000

  Returns: 100.0

  The worker is paid 10 dollars per hour for the first 200 hours, and 15 dollars per hour for any hours beyond that.  To earn 1000 dollars, he only needs to work 100 hours at 10 dollars per hour.

  1)
  10
  15
  3000

  Returns: 266.6666666666667

  The worker is paid 10 dollars per hour for the first 200 hours for a total of 2000 dollars.  To earn the extra 1000 dollars, he must work approximately 66.67 hours at 15 dollars per hour.

  2)
  100
  1
  1000000

  Returns: 980200.0

  The company does not like to pay for overtime work.

  3)
  17
  23
  973546

  Returns: 42380.260869565216

  4)
  82
  8
  12140

  Returns: 148.0487804878049



*/
// END CUT HERE
#line 73 "SalaryCalculator.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class SalaryCalculator {
public:
  double calcHours(int P1, int P2, int salary) {
    double ret = 0;
    //salary for first 200 hours
    double salary2 = salary;
    double sal200 = P1 * 200;
    if (salary2 <= sal200) {
      ret = salary2 / P1;
    } else {
      salary2 -= sal200;
      ret += 200.00;
      ret += salary2 / P2;
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
      cout << "Testing SalaryCalculator (250.0 points)" << endl << endl;
      for (int i = 0; i < 20; i++)
	{
	  ostringstream s; s << argv[0] << " " << i;
	  int exitCode = system(s.str().c_str());
	  if (exitCode)
	    cout << "#" << i << ": Runtime Error" << endl;
	}
      int T = time(NULL)-1456211287;
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
      SalaryCalculator _obj;
      double _expected, _received;
      time_t _start = clock();
      switch (_tc)
	{
	case 0:
	  {
	    int P1 = 10;
	    int P2 = 15;
	    int salary = 1000;
	    _expected = 100.0;
	    _received = _obj.calcHours(P1, P2, salary); break;
	  }
	case 1:
	  {
	    int P1 = 10;
	    int P2 = 15;
	    int salary = 3000;
	    _expected = 266.6666666666667;
	    _received = _obj.calcHours(P1, P2, salary); break;
	  }
	case 2:
	  {
	    int P1 = 100;
	    int P2 = 1;
	    int salary = 1000000;
	    _expected = 980200.0;
	    _received = _obj.calcHours(P1, P2, salary); break;
	  }
	case 3:
	  {
	    int P1 = 17;
	    int P2 = 23;
	    int salary = 973546;
	    _expected = 42380.260869565216;
	    _received = _obj.calcHours(P1, P2, salary); break;
	  }
	case 4:
	  {
	    int P1 = 82;
	    int P2 = 8;
	    int salary = 12140;
	    _expected = 148.0487804878049;
	    _received = _obj.calcHours(P1, P2, salary); break;
	  }
	  /*case 5:
	    {
	    int P1 = ;
	    int P2 = ;
	    int salary = ;
	    _expected = ;
	    _received = _obj.calcHours(P1, P2, salary); break;
	    }*/
	  /*case 6:
	    {
	    int P1 = ;
	    int P2 = ;
	    int salary = ;
	    _expected = ;
	    _received = _obj.calcHours(P1, P2, salary); break;
	    }*/
	  /*case 7:
	    {
	    int P1 = ;
	    int P2 = ;
	    int salary = ;
	    _expected = ;
	    _received = _obj.calcHours(P1, P2, salary); break;
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
