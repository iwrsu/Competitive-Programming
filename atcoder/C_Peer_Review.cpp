#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll C3(ll x) {
    if (x < 3) return 0;
    return x*(x - 1)*(x - 2)/6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;

    unordered_map<int,int> mp;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        mp[a]++;
        mp[b]++;
    }

    for (int i=0; i<n; i++) {
        int id = i + 1;
        int conflicts=mp.count(id)?mp[id]:0;
        ll left=n-1-conflicts;
        cout << C3(left) << " ";
    }
}
