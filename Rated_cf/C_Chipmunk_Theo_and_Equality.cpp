#include<bits/stdc++.h>
using namespace std;
long long a[100000],d[100000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T;
	long long n,i,j,ans,flag,c,x;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			a[i]--;
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			for(j=29;j>-1;j--)
			{
				if(a[i]>>j&1)break;
			}
			d[i]=j;
			ans+=d[i]+1;
			for(j=d[i];j>-1;j--)
			{
				if(a[i]>>j&1^1)ans++;
			}
		}
		for(j=0;j<=30;j++)
		{
			flag=0;
			c=-1;
			for(i=0;i<n;i++)
			{
				if(j>d[i])
				{
					flag=1;
					break;
				}
				x=a[i]>>(d[i]-j)&1;
				if(c==-1)c=x;
				if(c!=x)
				{
					flag=1;
					break;
				}
			}
			if(flag)break;
			if(c==0)ans-=n*2;
			else ans-=n;
		}
		c=0;
		flag=0;
		for(i=0;i<n;i++)
		{
			if(j<=d[i])c--;
			else
			{
				if(d[i]!=-1)flag=1;
				c++;
			}
		}
		if(flag==0&&c<0)ans+=c;
		cout<<ans<<'\n';
	}
	return 0;
}