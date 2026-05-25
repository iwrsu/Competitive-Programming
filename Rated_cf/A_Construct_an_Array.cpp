#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define rrep(i,a,b) for (int i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x) // zeros before first 1
#define gcd(x,y) __gcd(x,y)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define INF 0x3f3f3f3f
#define py cout<<"Yes"
#define pn cout<<"No"
// Bit manipulation macros
#define GETBIT(n,i) (((n) >> (i)) & 1)
#define SETBIT(n,i) ((n) | (1 << (i)))
#define CLEARBIT(n,i) ((n) & ~(1 << (i)))
#define SETBITAT(n,v,i) (((n) & ~(1 << (i))) | ((v) << (i)))
#define TOGGLEBIT(n,i) ((n) ^ (1 << (i)))
#define LSB(x) ((x) & (-(x)))           // least significant set bit
#define MSB(x) (1 << (31 - __builtin_clz(x))) // most significant set bit
#define ISPOW2(x) ((x) && !((x) & ((x)-1))) // check if power of 2

using pii = pair<int,int>;
using vi = vector<int>;
using vpi = vector<pii>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Debug macro (prints only locally)
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
#define dbg(x)
#endif

// Input/output helpers for vectors
template<typename T>
istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) { for (auto &x : v) out << x << " "; return out; }

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T, typename U> using safe_map = unordered_map<T, U, custom_hash>;
template <typename T> using safe_set = unordered_set<T, custom_hash>;

void solve()
{
    int n;
    cin>>n;
    rrep(i,2*n,n+1) cout<<i<<" ";
}

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t=1;
   cin>>t;
   while(t--){ solve(); cout<<"\n"; }
}