#define radit using
#define sangat namespace
#define ganteng std
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cctype>
#include<iomanip>
#include<map>
#include<set>
radit sangat ganteng;
#define FOR(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define REP(a,b) FOR(a,1,b)
#define REPD(a,b) FORD(a,b,0)
#define FORV(a,b) for(int (a)=0;(a)<(b).size();(a)++)
#define FORVD(a,b) for(int (a)=(b).size()-1;(a)>=0;(a)--)
#define FORL(a,b,c) for(LL (a)=(b);(a)<=(c);(a)++)
#define FORLD(a,b,c) for(LL (a)=(b);(a)>=(c);(a)--)
#define np next_permutation
#define pp prev_permutation
#define lb lower_bound
#define ub upper_bound
#define AL(a) a.begin(),a.end()
#define SORT(a) sort(a.begin(),a.end())
#define REV(a) reverse(a.begin(),a.end())
#define SOAR(a,n) sort(a,a+n)
#define REAR(a,n) reverse(a,a+n)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define INF 1000000000
#define INFL 1000000000000000LL
#define mo 1000000007
#define pi acos(-1)
#define DEBUG(a) printf("%d\n", a)
#define nw printf("\n");
#define out(a) printf("%d", a);
#define outl(a) printf("%lld", a);
#define spc printf(" ")
#define out2(a,b) out(a);spc;out(b)
#define outl2(a,b) outl(a);spc;outl(b)
#define outvec(a,b) out(b[0]); FOR(a,1,b.size()-1) {spc;out(b[a])}; nw
#define pf push_front
#define ppf pop_front
#define priority_queue pque
#define PQUEUP(ty,a) pque<ty,vector<ty>,greater<ty> > a
#define fi first
#define se second
#define UNIQ(a) (a).resize(unique(AL(a))-(a).begin())
#define ASAL puts("RADIT SANGAT GANTENG")
#define dummy char spa[5]; gets(spa)
#define FLUS fflush_unlocked(stdout)
#define RESET(a,b) memset(a,b,sizeof a)
#define endclock printf("%.3lf\n", (clock()-now) / (double)CLOCKS_PER_SEC)
#define CT clock_t now=clock()
#define init0(i,a,b,angka) FOR(i,0,b-1) a[i]=angka
#define init(i,a,b,angka) FOR(i,1,b) a[i]=angka
int arahx4[]={0,-1,0,1};
int arahy4[]={-1,0,1,0};
 
int arahx8[]={0,-1,-1,-1,0,1,1,1};
int arahy8[]={-1,-1,0,1,1,1,0,-1};

template <typename t>
t getnum()
{
	t res=0;
	char c;
	t mult=1;
	while(1)
	{
		c=getchar();
		if(c==' ' || c=='\n') continue;
		else break;
	}
	if(c=='-') mult*=-1;
	else res+=c-'0';
	while(1)
	{
		c=getchar();
		if(c>='0' && c<='9') 
		{
			res*=10;
			res+=c-'0';
		}
		else break;
	}
	return res*mult;
}
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<pii,pii> ppi;
typedef vector<int> vi;
typedef queue<int> qi;
typedef map<int,int> mii;
typedef map<LL,LL> mll;
typedef map<int,bool> mib;
typedef map<LL,int> mli;
typedef map<LL,bool> mlb;
#define in(a) (a)=getnum<int>()
#define in2(a,b) in(a);in(b)
#define in3(a,b,c) in2(a,b);in(c)
#define inl(a) (a)=getnum<LL>()
#define inl2(a,b) inl(a);inl(b)
#define inl3(a,b,c) inl2(a,b);inl(c)
#define ins(a) cin>>a;
//raditya1710 template designed for ubuntu 12.04 24 December 2012 00:41 ver 2.0.0
int ar[5];
int main()
{
	RESET(ar,0);
	int tc;
	in(tc);
	int b;
	FOR(i,1,tc) 
	{
		in(b);
		ar[b]++;
	} 
	int total=0;
	total+=ar[4];
	int tmp=min(ar[1],ar[3]);
	total+=tmp;
	ar[1]-=tmp;
	ar[3]-=tmp;
	total+=ar[2]/2;
	ar[2]%=2;
	if(ar[1])
	{
		int sem=0;
		if(ar[2]) sem+=2;
		sem+=ar[1];
		total+=sem/4;
		sem%=4;
		if(sem) total++;
	}
	else if(ar[3])
	{
		if(ar[2]) total++;
		total+=ar[3];
	}
	else if(ar[2]) total++;
	out(total);nw;
	return 0;
}
