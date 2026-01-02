#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        // Compute |a1|
        long long target = llabs(a[0]);

        // Create array of absolute values
        vector<long long> b(n);
        for (int i = 0; i < n; i++) b[i] = llabs(a[i]);

        sort(b.begin(), b.end());

        // Find position (1-based) of |a1|
        int pos = lower_bound(b.begin(), b.end(), target) - b.begin() + 1;

        // Threshold
        int thresh = n / 2 + 1;

        if (pos <= thresh) cout << "YES\n";
        else cout << "NO\n";
    }
}
