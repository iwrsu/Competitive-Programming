#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define i128 __int128
#define ld long double
#define fir first
#define sec second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define lowbit(x) (x&-x)
using namespace std;
namespace FastIO{
	const int Size=1<<21;
	char ibuf[Size],obuf[Size],*p1=ibuf,*p2=ibuf,*p3=obuf;
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,Size,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) (p3-obuf<Size?(*p3++=(x)):(fwrite(obuf,1,p3-obuf,stdout),p3=obuf,*p3++=(x)))
	inline void flush(){if(p3>obuf) fwrite(obuf,1,p3-obuf,stdout),p3=obuf;}
	template<class T>
	T read(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch&0xF),ch=getchar();
		x=(f?-x:x);return x;
	}template<class T>
	int reads(T*s){
		char ch=getchar();int len=0;
		while(ch==' '||ch=='\n'||ch=='\r') ch=getchar();
		while(ch!=' '&&ch!='\n'&&ch!=EOF&&ch!='\r') s[len++]=ch,ch=getchar();
		s[len]='\0';return len;
	}template<class T>
	T readd(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=x*10+(ch&0xF),ch=getchar();
		if(ch=='.'){ch=getchar();T d=1;while(isdigit(ch)) d*=0.1,x+=d*(ch&0xF),ch=getchar();}
		x=(f?-x:x);return x;
	}template<class T>
	void write(T x,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		char tmp[41];int cnt=0;
		while(x>9) tmp[cnt++]=x%10+'0',x/=10;tmp[cnt++]=x+'0';
		while(cnt) putchar(tmp[--cnt]);putchar(ch);
	}template<class T>
	void writes(T x,int l=0,int r=-1){
		if(~r){for(int i=l;i<=r;i++) putchar(x[i]);}
		else{for(int i=l;x[i];i++) putchar(x[i]);}
	}template<class T>
	void writed(T x,int p=6,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		T d=0.5;for(int i=0;i<p;i++) d*=0.1;x+=d;
		i128 g=(i128)(x);p?write(g,'.'):write(g,ch);
		if(p){T f=x-g;for(int i=0,d;i<p;i++) f*=10,d=(int)(f),putchar(d+'0'),f-=d;putchar(ch);}
	}
}
using namespace FastIO;
const int N=2e5+10;
int a[N],n,T;
void work(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	a[n+1]=0;
	ll ans=0;
	for(int i=2;i<=n;i+=2){
		int s=a[i-1]+a[i+1];
		if(s<=a[i]) continue;
		if(i<=n){
			int sub=min(a[i+1],s-a[i]);
			a[i+1]-=sub,s-=sub,ans+=sub;
		}
		if(s>a[i]){
			int sub=s-a[i];
			a[i-1]-=sub,ans+=sub;
		}
	}
	write(ans,'\n');
}
int main(){
	read(T);
	while(T--) work();
	flush();
	return 0;
}