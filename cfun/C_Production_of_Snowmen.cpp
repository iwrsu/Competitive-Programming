#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 1. Global Arrays: No more dynamic memory allocation inside the test cases.
// Size is 10005 because max N is 5000, and we double it to 10000.
const int N = 10005;
ll a[N], b[N], c[N];

// 2. Fast I/O: Reads characters directly from the buffer.
inline ll read() {
    ll s = 0, k = 1;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-') k = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return s * k;
}

// Helper function to double the arrays
void init(ll arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i + n] = arr[i];
    }
}

void solve() {
    // Using the fast read function instead of cin
    ll n = read();
    
    for (int i = 0; i < n; i++) a[i] = read();
    for (int i = 0; i < n; i++) b[i] = read();
    for (int i = 0; i < n; i++) c[i] = read();
    
    // Double the arrays to simulate the cyclic behavior
    init(a, n);
    init(b, n);
    init(c, n);
    
    ll val_a = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int x = 0; x < n; x++) {
            // 3. No Modulo: We just use a[i + x] because the array is doubled!
            if (a[i + x] >= b[x]) {
                ok = false;
                break;
            }
        }
        if (ok) ++val_a;
    }
    
    ll val_k = 0;
    for (int k = 0; k < n; k++) {
        bool ok = true;
        for (int x = 0; x < n; x++) {
            // No Modulo: c[k + x] works perfectly here too.
            if (c[k + x] <= b[x]) {
                ok = false;
                break;
            }
        }
        if (ok) ++val_k;
    }
    
    // Output the answer
    ll ans = val_a * val_k * n;
    printf("%lld\n", ans);
}

int main() {
    // Reading number of test cases
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}