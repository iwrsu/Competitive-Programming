#include<bits/stdc++.h>
using namespace std;
long long n,b[10000009],a[10000009],t,l,k;
void solve(){
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	l=1;
	for (int i=1; i<=n; i++){
		k=i-a[i]+a[i-1];
		if (k == 0){
			b[i]=l++;
		}
		else b[i]=b[k];
	}
	for (int i=1; i<=n; i++){
		cout << b[i] << ' ';
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--){
		solve();
	}
}