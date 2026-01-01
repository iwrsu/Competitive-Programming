#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define rep(i,a,b) for(auto i=a;i<b;++i)
#define ren(i,a,b) for(auto i=a;i>b;--i)
#define rei(i,a,b,x) for(auto i=a;i<b;i+=x)
#define opv(i,a,b,v) for(auto& i: v) cout<<i;
#define inv(i,a,b,v) v.reserve(n); for(auto i=a;i<b;i++) {ll x;cin>>x;v.pb(x);}
#define voit while(t--){solve();cout<<endl;}
#define all(v) v.begin(),v.end()
#define bv v.begin()
#define ev v.end()
#define mem(n,m) memset(n,m,sizeof(n))
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vi vector<int>
#define vll vector<long long>
#define bitc(n) __builtin_popcountll(n)
#define gcd(x,y) __gcd(x,y)
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define deb(x) cout << #x << "=" << x << endl
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define INF 0x3f3f3f3f
#define py cout<<"Yes"
#define pn cout<<"No"
#define dbg(x) cout << (#x) << " is " << (x) << endl
#define SIZE 1000001

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldo;
typedef double db;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>PBDS;

void solve()
{
   string s;
   cin>>s;
   int ans = 1;
   int tempans=1;
   rep(i,1,s.size()){
      if(s[i]==s[i-1]) ++tempans;
      else {
         ans = max(ans, tempans);
         tempans = 1;
      }
   }
   ans = max(ans, tempans);
   cout<<ans;
}

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t=1;
   // cin>>t;
   voit;
}