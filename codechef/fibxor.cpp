#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, long long n) {
    if (n % 3 == 0) return a;
    if (n % 3 == 1) return b;
    return a ^ b;
}


int main() {
	// your code goes here
	int tc;
	cin>>tc;
	while(tc--){
	    long long a,b,n;
	    cin>>a>>b>>n;
	    // vector<int> dp(n+1,-1);
	    cout<<f(a,b,n)<<'\n';
	}

}
