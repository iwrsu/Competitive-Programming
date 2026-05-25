#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using int64 = long long;

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
	int n,m,k;
	cin>>n>>m>>k;
	int i=0,j=0;
	vector<int> a(n);
	vector<int> b(m);
	cin>>a;
	cin>>b;
	sort(all(a));
	sort(all(b));
	int ans=0;
	while(i<n&&j<m)
	{
		if(abs(a[i]-b[j])<=k)
		{
			++ans;
			++i;
			++j;
		}
		else if(b[j]<a[i]) ++j;
		else ++i;
	}
	cout<<ans;
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
