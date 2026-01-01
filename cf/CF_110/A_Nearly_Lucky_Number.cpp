#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<utility>
#include<set>
#include<iterator>
#include<cstddef>
#include<vector>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for(size_t i=a;i<=b;++i)
#define FOR(tt,a,b) for(int tt=a;tt<=b;++tt)
#define rep(i,n) for(size_t i=0;i<n;++i)
#define ren(i,n) for(size_t i=n-1;i>=0;--i)
#define inp(i,n) for(int i=0;i<n;++i)
#define forn(i,a,b) for(int i=a;i>=b;--i)
#define forr(it,v) for(auto it=v.cbegin();it!=v.cend();++it)
#define forw(it,v) for(vector<int>::size_type i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
#define all(v) v.begin(),v.end()
#define b(v) v.begin()
#define bc(v) v.cbegin()
#define e(v) v.end()
#define ec(v) v.cend()
#define vsz vector<int>::size_type
#define mem(n,m) memset(n,m,sizeof(n))
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define gl(cin,s) getline(cin,s)
#define bitc(n) __builtin_popcountll(n)
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define SIZE 1000001

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldo;
typedef double db;

using std::equal_range;
using std::lower_bound;
using std::upper_bound;
using std::pair;
using std::string;
using std::getline;
using std::vector;
using std::cout;
using std::ios;
using std::set;
using std::max;
using std::min;
using std::iterator;
using std::cin;

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
//    int n;
//    cin>>n;
//    string s;
//    s=n;
//    s+=48;
//    int x=0;

//    for(auto i=0;i!=s.size();i++)
//    {
    // if((s[i]!=4)||(s[i]!=7)){
    //     cout<<"1";
    //     cout<<"NO";
    //     return 0;
    // }
//     cout<<s[i]<<"\n";
//    }
   
//    cout<<"YES";
    // string s;
    // cin>>s;
    // for(auto &i:s)
    // cout<<s[i]+48;

    ll m;
    cin>>m;
    int digitC=0;

    if(m<10) {cout<<"NO";
    return 0;}

    while(m)
    {
        if((m%10==4)||(m%10==7)) digitC++;
        m=m/10;
    }
    if(digitC==4||digitC==7) cout<<"YES";
    else cout<<"NO";

}