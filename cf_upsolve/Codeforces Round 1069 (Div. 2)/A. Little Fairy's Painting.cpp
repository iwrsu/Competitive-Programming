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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // distinct colors
        unordered_set<long long> st(a.begin(), a.end());
        long long d = st.size();

        long long ans = LLONG_MAX;
        for (long long x : st) {
            if (x >= d) {
                ans = min(ans, x);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

