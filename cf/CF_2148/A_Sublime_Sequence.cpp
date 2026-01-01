#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main()
{
    int tc;
    cin>>tc;

    for(int i=0;i<tc;i++){
        int x,n;
        cin>>x>>n;

        if(n%2==0) cout<<0;
        else cout<<x;

        cout<<endl;
    }
}
