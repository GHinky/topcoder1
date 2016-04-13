// BEGIN CUT HERE
/*
PROBLEM STATEMENT
One approach to voting is to have voters assign a rank to each candidate. Candidate A is preferred to candidate B if there are more voters who rank A ahead of B than there are voters who rank B ahead of A. A Condorcet winner is a candidate which is preferred to all other candidates. There can be at most one Cordorcet winner in an election, but there might also be none.

You will be given a vector <string> votes. The jth character of the ith element of votes is a lowercase letter, indicating the ranking that voter i assigned to candidate j. Letters closer to 'a' indicate higher-ranked (preferred) candidates, while those closer to 'z' are lower-ranked (less preferred). Return the 0-based index of the Cordorcet winner, or -1 if there isn't one.

DEFINITION
Class:CondorcetVoting
Method:winner
Parameters:vector <string>
Returns:int
Method signature:int winner(vector <string> votes)


CONSTRAINTS
-votes will contain between 1 and 50 elements, inclusive.
-Each element of votes will contain between 1 and 50 characters, inclusive.
-Each element of votes will contain the same number of characters.
-Each element of votes will contain only lowercase letters ('a' - 'z').


EXAMPLES

0)
{"acbd",
 "bacd",
 "bdca"}

Returns: 0

Voters 0 and 2 ranked candidate 0 higher than candidate 1, while voter 1 ranked candidate 1 higher than candidate 0.  Therefore, candidate 0 is preferred to candidate 1.

All three voters ranked candidate 0 higher than candidate 2, so candidate 0 is preferred to candidate 2.

Finally, voters 0 and 1 ranked candidate 0 higher than candidate 3, while only voter 2 ranked candidate 3 higher than candidate 0.  Therefore, candidate 0 is preferred to candidate 3 as well.

1)
{"abc", 
 "bca", 
 "cab"}

Returns: -1

This is a classic example of a cyclic preference. Two voters prefer 0 to 1, two prefer 1 to 2, and two prefer 2 to 0. There is no Condorcet winner.

2)
{"cezdqcw"}

Returns: -1

Even with only one voter, there may be no Condorcet winner because of a simple tie.

3)
{"abcd", "abcd", "abcd", "abcd", "abcd", "abcd",
 "cbad", "cbad", "cbad", "cbad", "cbad",
 "dbca", "cbda", "cbda"}

Returns: 1

Candidate 1 is nobody's first choice, but still wins.

4)
{"abbcbbbaaccaaccbbacbbbaacbccbccacaaacaacaaacbccaac",
 "accbabcaacacbcccbbccbbcaccccccbbcbbcbaccbcbcacbcbc",
 "acacaaabccaaaccabbaaaacabaaabacacbaacbcccbccbcbacb",
 "acbcbabaabbcaababaacbabcacbaccabbaaacccbcabbbcacba",
 "cbbbacbbacccbbabbbcbaabaaaacaacbcbccbaaccbcaaccbcb",
 "cbacbbcbbcbcaaabccabcabbcbacaaabccabbcbacbbacbbaca",
 "cacaabccbbbaaacccacbbcacababbcaaabccbbacbbbccacbaa",
 "bccbbabaaaababcbabbbbcbcacbcbcbacccacacacacacacaab",
 "bccabcaabcabbccaaccbcabaaabbbcaabaaabbbbabbbaabaac",
 "accccbabaaaabcbacabbcbbacaacaaaacccbbbcacaccccaaac",
 "cccbcaababbaacaaabbbaabbccccacaacbacaacbbbaacccbbb",
 "bccccaccbcbbaaaaaaaaccbababcabaaccacbbabbbcabbaaca",
 "cbacacaabbccacaabbbbbbccabcbbaccacbcacacacbccbcbcc",
 "baabcabccaaaaccbaacaaccacccbcbbaaacacaccbcaacbbbba",
 "bccaaaabcbbcbbbbbcaabaacccbccbbcbabacaaccbccaababb",
 "cacbbbbcabbcbaabbccbaccbaacbbcbbbbcabababccabbbcab",
 "bccbcacbccaacacccccaacabacbacbbbcaabacacccbbbccaac",
 "aaaccbbbacacbaaaacacaabbaacccbcccbcabbccbcacabbacb",
 "bcabcbbacbacacbbaaccabcabcbbaabacacccbbbcabbbcaacb",
 "bacbbbbaccbaabbbbbcaccbbcbcabbbccbcacccbabbbcaaacc",
 "bababcacbacacacccccbbcacccbbcbccaccaacbbcacabcabba",
 "aaabaccbbcacaacbabccccabbbcbcccccccbaacbccbaacbbbc",
 "abacbaaaaaccacbbbaccbbbabaacbcbccacccabaaaacbaabbb",
 "cbbcacbaccabbbcaacbcbabbcabcbaccabcbbbcabcbcbaacca",
 "babbacaaacbbcbbbabbaabcbabcbbaacaacbbbaaaabbcabcca",
 "cbabaacabcccaabbbacccaccbacabbaacaaabcbcccbcbcccaa",
 "aabbbcbacabbcabcbcccbccaccbcacbaacabbbccaabaabcbba",
 "caccabcccabbaacbabbaaaccccccccaaccbcaccacaabacccba",
 "bbbcabcababaabacaccacabcbccacccbbbbcbbbaccabcabaab",
 "bbbcaababbbbababababcbbbbaaabbacaabcacbbccbcaaaaaa",
 "bcbacccaaaabbcbcabbbcababbcacaabbbbcbbacbaabcbaccb",
 "bbcaccaaccacbbaaccaaaabccbbacbcbacaacbacbccaaccbba",
 "abaaacbccbbabbcaccbaccccbaaacaccccababcbccccbabcca",
 "acccaccababababacbbaccbcabcaccbabaabacbaacaaacabca",
 "aaabababccabccbcbabcabcacbbcacbcbbbabcabacbcaacacb",
 "ccacbaabbcbaccaccbbabbabbabaacccabcaaccacacccbbcab",
 "bbaabcbabbbaacacabaabcbaaabacbccccaccaaaacbacabbbc",
 "abaaaccaacbbcacacbcbccbaaacbbcbacabbbccabbbccaaaac",
 "bbacbabbcacbbacccaccbcbcabbcbaacabbbbabbaaabaacacb",
 "cacbacbccbcbabacccacabcacacabbcabbccaacacbaaacaacb",
 "bacbbacbccccabcbabcbbcbacacaaabcbaccccaabaabbacbcb",
 "abcaaccccabccaaaaccbabccacbcaaaacaccaccccccaaaabaa",
 "bacabcbccbacccbaaaabcbbaabbabaabcabacccbcabacccbcc",
 "babaccbbcbcbacccabccbcccbaaaaacccabcbccbbbbcbabcbc",
 "cccbbaccbabbbbcbcbcbaaacbbcacbcaacacacccbcabccbcaa",
 "caacbcacbccaaaaacaaababbcccacbabaaabcaacaaababacba",
 "cccccaccabcaacababbacbcbabbcaacbacbabbbccbabcbabbb",
 "ccbcababcabcbcccaccccacabcbaaacaabccbbaabaccbaccab",
 "abbbcacaccabcbccbacabbbccaccaaaacccabbcbacbbccabcb",
 "bacabccabcbbcaacbcacabcbccacbcccbcbcaaaabbaabccabb"}

Returns: 12



5)
{"h", "e", "l", "l", "o"}

Returns: 0



*/
// END CUT HERE
#line 129 "CondorcetVoting.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
class CondorcetVoting {
public:
  int winner(vector <string> votes) {
    int ret = -1;
    const int C = votes[0].length(); // tot num of candidates
    const int V = votes.size();  // tot num of voters
    for (int i = 0; i != C; ++i) {
      bool undisputed = true;

      for (int j = 0; j != C; ++j) {
	int icounter = 0;
	int jcounter = 0;

	for (int k = 0; (k != V && i != j); ++k) {
	  if (votes[k][i] < votes[k][j]) // char is less => more preferred candidate
	    ++icounter;
	  if (votes[k][i] > votes[k][j])
	    ++jcounter;
	  if (votes[k][i] == votes[k][j]) {
	    ++icounter;
	    ++jcounter;
	  }
	}

	if ((icounter <= jcounter) && (icounter + jcounter > 0))
	  undisputed = false;
      }

      if (undisputed == true)
	ret = i;
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
		cout << "Testing CondorcetVoting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456413564;
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
		CondorcetVoting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string votes[] = {"acbd",
				                  "bacd",
				                  "bdca"};
				_expected = 0;
				_received = _obj.winner(vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			case 1:
			{
				string votes[] = {"abc", 
				                  "bca", 
				                  "cab"};
				_expected = -1;
				_received = _obj.winner(vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			case 2:
			{
				string votes[] = {"cezdqcw"};
				_expected = -1;
				_received = _obj.winner(vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			case 3:
			{
				string votes[] = {"abcd", "abcd", "abcd", "abcd", "abcd", "abcd",
				                  "cbad", "cbad", "cbad", "cbad", "cbad",
				                  "dbca", "cbda", "cbda"};
				_expected = 1;
				_received = _obj.winner(vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			case 4:
			{
				string votes[] = {"abbcbbbaaccaaccbbacbbbaacbccbccacaaacaacaaacbccaac",
				                  "accbabcaacacbcccbbccbbcaccccccbbcbbcbaccbcbcacbcbc",
				                  "acacaaabccaaaccabbaaaacabaaabacacbaacbcccbccbcbacb",
				                  "acbcbabaabbcaababaacbabcacbaccabbaaacccbcabbbcacba",
				                  "cbbbacbbacccbbabbbcbaabaaaacaacbcbccbaaccbcaaccbcb",
				                  "cbacbbcbbcbcaaabccabcabbcbacaaabccabbcbacbbacbbaca",
				                  "cacaabccbbbaaacccacbbcacababbcaaabccbbacbbbccacbaa",
				                  "bccbbabaaaababcbabbbbcbcacbcbcbacccacacacacacacaab",
				                  "bccabcaabcabbccaaccbcabaaabbbcaabaaabbbbabbbaabaac",
				                  "accccbabaaaabcbacabbcbbacaacaaaacccbbbcacaccccaaac",
				                  "cccbcaababbaacaaabbbaabbccccacaacbacaacbbbaacccbbb",
				                  "bccccaccbcbbaaaaaaaaccbababcabaaccacbbabbbcabbaaca",
				                  "cbacacaabbccacaabbbbbbccabcbbaccacbcacacacbccbcbcc",
				                  "baabcabccaaaaccbaacaaccacccbcbbaaacacaccbcaacbbbba",
				                  "bccaaaabcbbcbbbbbcaabaacccbccbbcbabacaaccbccaababb",
				                  "cacbbbbcabbcbaabbccbaccbaacbbcbbbbcabababccabbbcab",
				                  "bccbcacbccaacacccccaacabacbacbbbcaabacacccbbbccaac",
				                  "aaaccbbbacacbaaaacacaabbaacccbcccbcabbccbcacabbacb",
				                  "bcabcbbacbacacbbaaccabcabcbbaabacacccbbbcabbbcaacb",
				                  "bacbbbbaccbaabbbbbcaccbbcbcabbbccbcacccbabbbcaaacc",
				                  "bababcacbacacacccccbbcacccbbcbccaccaacbbcacabcabba",
				                  "aaabaccbbcacaacbabccccabbbcbcccccccbaacbccbaacbbbc",
				                  "abacbaaaaaccacbbbaccbbbabaacbcbccacccabaaaacbaabbb",
				                  "cbbcacbaccabbbcaacbcbabbcabcbaccabcbbbcabcbcbaacca",
				                  "babbacaaacbbcbbbabbaabcbabcbbaacaacbbbaaaabbcabcca",
				                  "cbabaacabcccaabbbacccaccbacabbaacaaabcbcccbcbcccaa",
				                  "aabbbcbacabbcabcbcccbccaccbcacbaacabbbccaabaabcbba",
				                  "caccabcccabbaacbabbaaaccccccccaaccbcaccacaabacccba",
				                  "bbbcabcababaabacaccacabcbccacccbbbbcbbbaccabcabaab",
				                  "bbbcaababbbbababababcbbbbaaabbacaabcacbbccbcaaaaaa",
				                  "bcbacccaaaabbcbcabbbcababbcacaabbbbcbbacbaabcbaccb",
				                  "bbcaccaaccacbbaaccaaaabccbbacbcbacaacbacbccaaccbba",
				                  "abaaacbccbbabbcaccbaccccbaaacaccccababcbccccbabcca",
				                  "acccaccababababacbbaccbcabcaccbabaabacbaacaaacabca",
				                  "aaabababccabccbcbabcabcacbbcacbcbbbabcabacbcaacacb",
				                  "ccacbaabbcbaccaccbbabbabbabaacccabcaaccacacccbbcab",
				                  "bbaabcbabbbaacacabaabcbaaabacbccccaccaaaacbacabbbc",
				                  "abaaaccaacbbcacacbcbccbaaacbbcbacabbbccabbbccaaaac",
				                  "bbacbabbcacbbacccaccbcbcabbcbaacabbbbabbaaabaacacb",
				                  "cacbacbccbcbabacccacabcacacabbcabbccaacacbaaacaacb",
				                  "bacbbacbccccabcbabcbbcbacacaaabcbaccccaabaabbacbcb",
				                  "abcaaccccabccaaaaccbabccacbcaaaacaccaccccccaaaabaa",
				                  "bacabcbccbacccbaaaabcbbaabbabaabcabacccbcabacccbcc",
				                  "babaccbbcbcbacccabccbcccbaaaaacccabcbccbbbbcbabcbc",
				                  "cccbbaccbabbbbcbcbcbaaacbbcacbcaacacacccbcabccbcaa",
				                  "caacbcacbccaaaaacaaababbcccacbabaaabcaacaaababacba",
				                  "cccccaccabcaacababbacbcbabbcaacbacbabbbccbabcbabbb",
				                  "ccbcababcabcbcccaccccacabcbaaacaabccbbaabaccbaccab",
				                  "abbbcacaccabcbccbacabbbccaccaaaacccabbcbacbbccabcb",
				                  "bacabccabcbbcaacbcacabcbccacbcccbcbcaaaabbaabccabb"};
				_expected = 12;
				_received = _obj.winner(vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			case 5:
			{
				string votes[] = {"h", "e", "l", "l", "o"};
				_expected = 0;
				_received = _obj.winner(vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}
			/*case 6:
			{
				string votes[] = ;
				_expected = ;
				_received = _obj.winner(vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string votes[] = ;
				_expected = ;
				_received = _obj.winner(vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string votes[] = ;
				_expected = ;
				_received = _obj.winner(vector <string>(votes, votes+sizeof(votes)/sizeof(string))); break;
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
