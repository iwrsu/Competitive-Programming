#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const long long INF = numeric_limits<long long>::max() / 2;
const int INF_int = 1e9 + 7;
 
void solve(){
    int n; cin >> n;
    string s = "";
    for(int i = 0; i < n; ++i){
        string t; cin >> t;
        if (s + t <= t + s){
            s = s + t;
        } else {
            s = t + s;
        }
    }
    cout << s << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int t = 1; cin >> t;
    for(int test = 1; test <= t; ++test){
        solve();
    }
}
