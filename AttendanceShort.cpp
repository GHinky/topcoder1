// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The students at your university have lately picked up the annoying habit of missing classes. To fix this problem your board has decided to only allow students with 75% or higher attendance to sit for the exams. Given a vector <string> names containing the students' names and a vector <string> attendance containing their attendance records, return the list of students who have less than 75% attendance.

The ith student's name is given as the ith element of names and his attendance record as the ith element of attendance. The attendance record corresponding to each student is specified as a string of 'A's, 'P's and 'M's. An 'A' indicates the students was absent for a class, whereas a 'P' means he was present and a 'M' means he was absent but he submitted a doctor's note for that class. If a student was absent for a class but submitted a doctor's note then that class is not counted when calculating his attendance percentage. Return a vector <string> containing the names of all the students who do not meet the attendance requirements. The names in the returned vector <string> should be in the same relative order as names.

DEFINITION
Class:AttendanceShort
Method:shortList
Parameters:vector <string>, vector <string>
Returns:vector <string>
Method signature:vector <string> shortList(vector <string> names, vector <string> attendance)


CONSTRAINTS
-names will contain between 0 and 50 elements, inclusive.   
-attendance will contain the same number of elements as names.
-Each element of names will contain between 1 and 50 characters, inclusive.
-Each element of attendance will contain between 1 and 50 characters, inclusive.
-Each element of names will contain only letters ('A' - 'Z' and 'a' - 'z').
-Each element of attendance will contain only 'A', 'P' and 'M' characters.
-Each element of attendance will contain at least one 'A' or 'P' character.


EXAMPLES

0)
{"Justin"}
{"PAAPP"}

Returns: {"Justin" }

Justin has attended 3 of his 5 classes which gives him 3/5 * 100 = 60% attendance. Since this is lower than 75% his name should be returned.

1)
{"Justin","Chris"}
{"PAAPP","PPPPA"}

Returns: {"Justin" }

Chris has attended 4 out of his 5 classes and thus has 80% attendance. Justin has 60% so only Justin's name should be returned.

2)
{"Sunny"}
{"PPPAM"}

Returns: { }

Sunny's attendance is effectively calculated from "PPPA" as classes which have a doctor's note are ignored. This results in a 75% attendance and so his name is not included in the returned list.

3)
{"Mansi", "Arjun", "Nikhil", "Taneja"}
{"PPPPMPPAPP", "AAMAAPP", "PPPPAAP", "PPPAAAMPP"}

Returns: {"Arjun", "Nikhil", "Taneja" }



4)
{}
{}

Returns: { }

Take care of the empty case.

*/
// END CUT HERE
#line 71 "AttendanceShort.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class AttendanceShort {
public:
  VI at_calc (const VS& a) {
    VI ret;
    // 1 => unsatisfactory attendance ie < 75%
    //  0 => proper attendance ie > 75%
    for (int i = 0; i != a.size(); ++i) { // each student
      int acc = 0;
      int count = 0;
      for (int j = 0; j != a[i].length(); ++j) { // each class
	if (a[i][j] == 'P') {
	  ++count;
	  ++acc;
	}
	if (a[i][j] == 'A') {
	  ++count;
	}
      }
      double temp = acc * 100 / count;
      int topush = 0;
      if (temp < 75)
	topush = 1;
      ret.push_back (topush);
    }
    return ret;
  }
  vector <string> shortList(vector <string> names, vector <string> attendance) {
    VS ret;
    VI att = at_calc (attendance);
    for (int i = 0; i != att.size(); ++i) {
      if (att[i] == 1) {
	ret.push_back(names[i]);
      }
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
		cout << "Testing AttendanceShort (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456324686;
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
		AttendanceShort _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string names[] = {"Justin"};
				string attendance[] = {"PAAPP"};
				string __expected[] = {"Justin" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.shortList(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string))); break;
			}
			case 1:
			{
				string names[] = {"Justin","Chris"};
				string attendance[] = {"PAAPP","PPPPA"};
				string __expected[] = {"Justin" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.shortList(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string))); break;
			}
			case 2:
			{
				string names[] = {"Sunny"};
				string attendance[] = {"PPPAM"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.shortList(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string))); break;
			}
			case 3:
			{
				string names[] = {"Mansi", "Arjun", "Nikhil", "Taneja"};
				string attendance[] = {"PPPPMPPAPP", "AAMAAPP", "PPPPAAP", "PPPAAAMPP"};
				string __expected[] = {"Arjun", "Nikhil", "Taneja" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.shortList(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string))); break;
			}
			case 4:
			{
				string names[] = {};
				string attendance[] = {};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.shortList(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string))); break;
			}
			/*case 5:
			{
				string names[] = ;
				string attendance[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.shortList(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string names[] = ;
				string attendance[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.shortList(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string names[] = ;
				string attendance[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.shortList(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
