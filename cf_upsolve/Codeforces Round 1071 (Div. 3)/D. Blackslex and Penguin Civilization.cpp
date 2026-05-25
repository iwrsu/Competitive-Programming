#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using int64 = long long;

#define gcd(x,y) __gcd(x,y)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define rrep(i,a,b) for (int i = (a); i >= (b); i--)
#define pb push_back
#define ff first
#define ss second

// Input/output helpers for vectors
template<typename T>
istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) { for (auto &x : v) out << x << " "; return out; }

static const ll MOD = 1e9 + 7;
const ll INFLL = 4e18;

ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    int N = 1 << n;
    vector<int> ans;

    function<void(int)> build = [&](int k) {
        if (k == 0) {
            ans.push_back(0);
            return;
        }
        int half = 1 << (k - 1);

        build(k - 1);
        for (int i = 0; i < half; i++) {
            ans.push_back(ans[i] | half);
        }
    };

    build(n);

    reverse(ans.begin(), ans.end());

    for (int x : ans) cout << x << " ";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
