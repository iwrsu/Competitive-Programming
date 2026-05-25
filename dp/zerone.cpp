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

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res;
}



int maxpro(vector<int> &wt,vector<int> &profit, int W, int n,vector<vector<int>> dp)
{
    if(W==0||n==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(wt[n-1]<=W) return dp[n][W] = max(profit[n-1]+maxpro(wt,profit,W-wt[n-1],n-1,dp),maxpro(wt,profit,W,n-1,dp));
    else return dp[n][W]=maxpro(wt,profit,W,n-1,dp);
}

void solve()
{
    int n;
    cin>>n;
    int W;
    cin>>W;
    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
    vector<int> wt(n);
    vector<int> profit(n);
    cin>>wt;
    cin>>profit;
    cout<<maxpro(wt,profit,W,n,dp);
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