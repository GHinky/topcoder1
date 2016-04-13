#include <bits/stdc++.h>
 
using namespace std;
 
#define dbg(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {
    cerr << str << " : " << t << endl;
}
template <class T, class... S> void dbs(string str, T t, S... s) {
    int idx = str.find(',');
    cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
