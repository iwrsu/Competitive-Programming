#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n; cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        bool ok = true;
        for(int i=0;i<n;i++){
            long long need = 2LL * max(i, n - i - 1);
            if(a[i] <= need){ ok = false; break; }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
