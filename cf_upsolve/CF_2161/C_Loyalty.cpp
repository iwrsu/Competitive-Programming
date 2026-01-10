#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
#define cull const unsigned long long
using namespace std;
namespace FastIO
{
    const int BUF_SIZE=1<<20;
    char in_buf[BUF_SIZE],out_buf[BUF_SIZE];
    char* in_ptr=in_buf+BUF_SIZE;
    char* out_ptr=out_buf;
    char get_char()
    {
        if(in_ptr==in_buf+BUF_SIZE)
        {
            in_ptr=in_buf;
            fread(in_buf,1,BUF_SIZE,stdin);
        }
        return *in_ptr++;
    }
    void put_char(char c)
    {
        if(out_ptr==out_buf+BUF_SIZE)
        {
            fwrite(out_buf,1,BUF_SIZE,stdout);
            out_ptr=out_buf;
        }
        *out_ptr++=c;
    }
    struct Flusher
    {
        ~Flusher()
        {
            if(out_ptr!=out_buf)
            {
                fwrite(out_buf,1,out_ptr-out_buf,stdout);
            }
        }
    } flusher;
}
#define getchar FastIO::get_char
#define putchar FastIO::put_char
inline int read()
{
    int x=0;
    bool zf=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
        {
            zf=0;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return zf?x:-x;
}
void print(cll x)
{
    if(x==0)
    {
        putchar('0');
        return;
    }
    char buf[19];
    int len=0;
    ll y=x;
    if(y<0)
    {
        putchar('-');
        y=-y;
    }
    while(y)
    {
        buf[len++]=(y%10)+'0';
        y/=10;
    }
    while(len--)
    {
        putchar(buf[len]);
    }
}
inline void princh(cll x,const char ch)
{
    print(x);
    putchar(ch);
}
cint N=1e5;
ll sum;
int ans[N+1];
int n,x,now;
int a[N+1],lp,rp;
void solve()
{
    n=read();
    x=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
    }
    sort(a+1,a+n+1);
    sum=now=0;
    lp=1,rp=n;
    for(int i=1;i<=n;++i)
    {
        if(now+a[lp]<x)
        {
            now+=a[lp];
            ans[i]=a[lp++];
        }
        else
        {
            sum+=a[rp];
            now+=a[rp]-x;
            ans[i]=a[rp--];
        }
    }
    princh(sum,'\n');
    for(int i=1;i<=n;++i)princh(ans[i],' ');
    putchar('\n');
}
int main()
{
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}