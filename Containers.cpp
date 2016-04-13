// BEGIN CUT HERE
/*
PROBLEM STATEMENT
There are several empty containers lined up in a row, and you want to put packages into them. You start with the first container and the first package. Do the following until all the packages are inside containers:


If the current package cannot fit into the current container, skip to step 3. Otherwise, go to the next step.
Put the current package into the current container. Grab the next  package, and go back to step 1.
Put the current container aside (you will not put any more packages into that container). Move on to the next container in line, and go back to step 1.


You are given a vector <int> containers, the i-th element of which is the capacity of the i-th container in line, and a vector <int> packages, the i-th element of which is the size of the i-th package. The constraints will guarantee that you will be able to put all the packages into containers using the above procedure. Return the sum of the wasted space in all the containers. The wasted space in a container is its capacity minus the total size of its contents.

DEFINITION
Class:Containers
Method:wastedSpace
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int wastedSpace(vector <int> containers, vector <int> packages)


NOTES
-A set of packages fits into a container if the total size of all the packages in the set does not exceed the capacity of the container.
-You must use the containers and the packages in the order that they are given. You may not reorder them.


CONSTRAINTS
-containers will contain between 1 and 50 elements, inclusive.
-Each element of containers will be between 1 and 1000, inclusive.
-packages will contain between 1 and 50 elements, inclusive.
-Each element of packages will be between 1 and 1000, inclusive.
-It will be possible to put all the packages inside containers using the method described in the statement.


EXAMPLES

0)
{ 5, 5, 5 }
{ 5, 5, 5 }

Returns: 0

Here, we've got 3 packages of size 5 and 3 containers of size 5, so no space will be wasted.

1)
{ 5, 6, 7 }
{ 5, 5, 5 }

Returns: 3

All the packages are of size 5. We will put the first package into the container of size 5, the second package into the container of size 6 and the third into the container of size 7. The overall wasted space will be equal to (5 - 5) + (6 - 5) + (7 - 5) = 3.

2)
{ 2, 3, 5 }
{ 3 }

Returns: 7

Here, we've got only one package of size 3. First, we'll try to put it into the container of size 2, but it won't fit, so we'll put it into the second container, leaving the third untouched. The overall wasted space will be 2 + (3 - 3) + 5 = 7.

3)
{ 3, 4, 5, 6 }
{ 3, 3, 3, 3, 3 }

Returns: 3



*/
// END CUT HERE
#line 72 "Containers.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class Containers {
public:
  int wastedSpace(vector <int> containers, vector <int> packages) {
    int ret = 0;
    int c = 0, p = 0;

    while (p != packages.size()) {
      if (packages[p] > containers[c]) {
	ret += containers[c];
	++c;
      }
      else {
	int diff = containers[c] - packages[p];
	containers[c] = diff;
	++p;
      }
    }

    while (c != containers.size()) {
      ret += containers[c];
      ++c;
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
		cout << "Testing Containers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456407990;
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
		Containers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int containers[] = { 5, 5, 5 };
				int packages[] = { 5, 5, 5 };
				_expected = 0;
				_received = _obj.wastedSpace(vector <int>(containers, containers+sizeof(containers)/sizeof(int)), vector <int>(packages, packages+sizeof(packages)/sizeof(int))); break;
			}
			case 1:
			{
				int containers[] = { 5, 6, 7 };
				int packages[] = { 5, 5, 5 };
				_expected = 3;
				_received = _obj.wastedSpace(vector <int>(containers, containers+sizeof(containers)/sizeof(int)), vector <int>(packages, packages+sizeof(packages)/sizeof(int))); break;
			}
			case 2:
			{
				int containers[] = { 2, 3, 5 };
				int packages[] = { 3 };
				_expected = 7;
				_received = _obj.wastedSpace(vector <int>(containers, containers+sizeof(containers)/sizeof(int)), vector <int>(packages, packages+sizeof(packages)/sizeof(int))); break;
			}
			case 3:
			{
				int containers[] = { 3, 4, 5, 6 };
				int packages[] = { 3, 3, 3, 3, 3 };
				_expected = 3;
				_received = _obj.wastedSpace(vector <int>(containers, containers+sizeof(containers)/sizeof(int)), vector <int>(packages, packages+sizeof(packages)/sizeof(int))); break;
			}
			/*case 4:
			{
				int containers[] = ;
				int packages[] = ;
				_expected = ;
				_received = _obj.wastedSpace(vector <int>(containers, containers+sizeof(containers)/sizeof(int)), vector <int>(packages, packages+sizeof(packages)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int containers[] = ;
				int packages[] = ;
				_expected = ;
				_received = _obj.wastedSpace(vector <int>(containers, containers+sizeof(containers)/sizeof(int)), vector <int>(packages, packages+sizeof(packages)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int containers[] = ;
				int packages[] = ;
				_expected = ;
				_received = _obj.wastedSpace(vector <int>(containers, containers+sizeof(containers)/sizeof(int)), vector <int>(packages, packages+sizeof(packages)/sizeof(int))); break;
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
