#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define rrep(i,a,b) for (int i = (a); i >= (b); i--)
#define pb push_back

// Input/output helpers for vectors
template<typename T>
istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) { for (auto &x : v) out << x << " "; return out; }

const ll MOD = 1e9 + 7;
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
    vector<ll> v(n);
    cin >> v;

    vector<ll> odd, even;
    for (ll x : v) {
        if (x & 1) odd.pb(x);
        else even.pb(x);
    }

    sort(all(odd));                 // small → large
    sort(all(even), greater<ll>()); // large → small

    int o = odd.size(), e = even.size();

    vector<ll> prefEven(e + 1, 0);
    for (int i = 0; i < e; i++)
        prefEven[i + 1] = prefEven[i] + even[i];

    int takeOdd = (o > 0 ? 1 : 0);
    int takeEven = 0;

    for (int k = 1; k <= n; k++) {
        if (k > 1) {
            if (takeEven < e) {
                takeEven++;
            } else if (takeOdd + 2 <= o && takeEven > 0) {
                takeOdd += 2;
                takeEven--;
            } else {
                takeOdd++;
            }
        }

        if (takeOdd <= o && (takeOdd & 1)) {
            ll bestOdd = odd[o - 1];
            ll sumEven = prefEven[min(takeEven, e)];
            cout << bestOdd + sumEven << " ";
        } else {
            cout << 0 << " ";
        }
    }
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
