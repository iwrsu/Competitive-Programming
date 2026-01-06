#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        bool ok=true;
        int ans=0;

        for(int i=0;i<n-1;i++){
            if(s[i]!='<' and s[i+1]!='>'){
                ans=-1;
                ok=false;
                break;
            }
        }
        if(ok){
            int c1=0,c2=0;
            for(int i=0;i<n;i++){
                if(s[i]=='<')c1++;
                if(s[i]=='>')c2++;
            }
            ans=n-min(c1,c2);
        }
        cout<<ans<<endl;
    }

    return 0;
}
