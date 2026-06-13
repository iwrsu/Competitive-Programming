#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> dp(21, 0);

// Precompute everything once before main execution
void precompute() {
    dp[0] = 1;
    for(int i = 1; i <= 20; i++) {
        dp[i] = dp[i-1] * i;
    }
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    precompute(); 
    
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        // O(1) lookup
        cout << dp[n] << "\n";
    }
    return 0;
}