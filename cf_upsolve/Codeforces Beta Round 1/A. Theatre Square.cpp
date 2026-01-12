#include<bits/stdc++.h>
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
    // CURSOR
    unsigned long long m=0,n=0,a=0;
scanf("%d%d%d",&n,&m,&a);
if(n%a)n=n/a+1;else n=n/a;
if(m%a)m=m/a+1;else m=m/a;
printf("%llu",m*n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
