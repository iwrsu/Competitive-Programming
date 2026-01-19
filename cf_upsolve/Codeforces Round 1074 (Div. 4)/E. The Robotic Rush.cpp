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
	int n, m, k;
    if (!(cin >> n >> m >> k)) return;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    string s;
    cin >> s;
    sort(b.begin(), b.end());
    vector<int> gdCode(2 * k + 5, -1);
    int cur = 0;
    gdCode[k] = 0; 
    for (int i = 0; i < k; i++) {
        if (s[i] == 'L') cur--;
        else cur++;
        if (gdCode[cur + k] == -1) {
            gdCode[cur + k] = i + 1;
        }
    }
    vector<int> die(k + 2, 0);
    for (int i = 0; i < n; i++) {
        int p = a[i];
        int t_death = k + 1;
        auto it = lower_bound(b.begin(), b.end(), p);
        if (it != b.end()) {
            int dR = *it - p;
            if (dR <= k && gdCode[dR + k] != -1) {
                t_death = min(t_death, gdCode[dR + k]);
            }
        }
        if (it != b.begin()) {
            int dL = p - *prev(it);
            if (dL <= k && gdCode[-dL + k] != -1) {
                t_death = min(t_death, gdCode[-dL + k]);
            }
        }
        if (t_death <= k) {
            die[t_death]++;
        }
    }
    int current_alive = n;
    for (int i = 1; i <= k; i++) {
        current_alive -= die[i];
        cout << current_alive << (i == k ? "" : " ");
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
