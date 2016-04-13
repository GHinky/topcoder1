// why is 3rd iteration temp = 2410000 instead of expected 24 ??
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
int main() {
  string s1 = "10000 50 24";
  stringstream ss;
  int i = 0;
    ss << s1;
    int temp;
    while (ss>>temp){
    cout << temp << endl;
    ++i;
  }
  return 0;
}
