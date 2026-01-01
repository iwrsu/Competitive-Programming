#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define rrep(i,a,b) for (int i = (a); i >= (b); i--)
#define each(x,v) for (auto &x : v)
#define all(v) (v).begin(), (v).end()
#define mem(n,m) memset(n,m,sizeof(n))
#define lb lower_bound
#define ub upper_bound
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x) // zeros before first 1
#define gcd(x,y) __gcd(x,y)
#define ps(x,y) fixed<<setprecision(y)<<x
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define INF 0x3f3f3f3f
#define py cout<<"Yes"
#define pn cout<<"No"
#define SIZE 1000001

// Bit manipulation macros
#define GETBIT(n,i) (((n) >> (i)) & 1)
#define SETBIT(n,i) ((n) | (1 << (i)))
#define CLEARBIT(n,i) ((n) & ~(1 << (i)))
#define SETBITAT(n,v,i) (((n) & ~(1 << (i))) | ((v) << (i)))
#define TOGGLEBIT(n,i) ((n) ^ (1 << (i)))
#define LSB(x) ((x) & (-(x)))           // least significant set bit
#define MSB(x) (1 << (31 - __builtin_clz(x))) // most significant set bit
#define ISPOW2(x) ((x) && !((x) & ((x)-1))) // check if power of 2

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

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
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin>>n;
    vector<array<int,3>> v(n);
    rep(i,0,n){
        cin>>v[i][0]>>v[i][1];
        v[i][2] = i;
    }

    sort(all(v));

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vl ans(n);
    int room_cnt=0;

    for(auto [a,b,idx] : v){
        if(!pq.empty()&&pq.top().first<a){
            auto [dep,room] = pq.top();pq.pop();
            ans[idx] = room;
            pq.push({b,room});
        }
        else{
            ++room_cnt;
            ans[idx] = room_cnt;
            pq.push({b,room_cnt});
        }
    }
    cout<<room_cnt<<"\n";
    rep(i,0,n) cout<<ans[i]<<" ";

}

int32_t main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t=1;
//    cin>>t;
   while(t--){ solve(); cout<<"\n"; }
}