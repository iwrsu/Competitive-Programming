#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// check if we can place k teleports so that each friend
// is at least distance D away from every teleport
bool possible(const vector<ll> &a, ll n, ll k, ll x, ll D) {
    if (D == 0) return true; // always possible
    vector<pair<ll,ll>> segs;
    segs.reserve(n);

    for (ll v : a) {
        ll L = max(0LL, v - (D - 1));
        ll R = min(x,  v + (D - 1));
        if (L <= R) segs.emplace_back(L, R);
    }

    if (segs.empty()) return (x + 1) >= k;

    sort(segs.begin(), segs.end());
    vector<pair<ll,ll>> merged;
    merged.push_back(segs[0]);
    for (size_t i = 1; i < segs.size(); ++i) {
        if (segs[i].first <= merged.back().second + 1)
            merged.back().second = max(merged.back().second, segs[i].second);
        else
            merged.push_back(segs[i]);
    }

    ll forbidden = 0;
    for (auto &p : merged) {
        forbidden += (p.second - p.first + 1);
        if (forbidden > (x + 1 - k)) return false; // early stop
    }

    ll allowed = (x + 1) - forbidden;
    return allowed >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (ll &v : a) cin >> v;

        sort(a.begin(), a.end());
        // binary search for maximum D
        ll lo = 0, hi = x + 1;
        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if (possible(a, n, k, x, mid)) lo = mid;
            else hi = mid - 1;
        }

        ll D = lo;
        // reconstruct allowed positions
        vector<pair<ll,ll>> segs;
        for (ll v : a) {
            ll L = max(0LL, v - (D - 1));
            ll R = min(x,  v + (D - 1));
            if (L <= R) segs.emplace_back(L, R);
        }
        sort(segs.begin(), segs.end());
        vector<pair<ll,ll>> merged;
        if (!segs.empty()) {
            merged.push_back(segs[0]);
            for (size_t i = 1; i < segs.size(); ++i) {
                if (segs[i].first <= merged.back().second + 1)
                    merged.back().second = max(merged.back().second, segs[i].second);
                else
                    merged.push_back(segs[i]);
            }
        }

        vector<ll> result;
        ll cur = 0;
        for (auto &p : merged) {
            while (cur < p.first && (ll)result.size() < k) {
                result.push_back(cur);
                ++cur;
            }
            cur = p.second + 1;
            if ((ll)result.size() >= k) break;
        }
        while ((ll)result.size() < k && cur <= x) {
            result.push_back(cur);
            ++cur;
        }

        for (ll i = 0; i < k; ++i) {
            cout << result[i] << (i + 1 == k ? '\n' : ' ');
        }
    }
    return 0;
}
