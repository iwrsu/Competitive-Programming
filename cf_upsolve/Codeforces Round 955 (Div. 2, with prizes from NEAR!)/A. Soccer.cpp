/**
 *    author:  Adham211 (;;)
 *     date: 5/12/2025
**/
#include <bits/stdc++.h>
#define  ll  long long
#define  el '\n'
#define cin(v) for(auto& i : v) cin >> i;
#define all(vc) ((vc).begin()), ((vc).end())
#define rall(vc) ((vc).rbegin()), ((vc).rend())
#define code_it ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
#define  pq1  priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>
using namespace std;
void Ana_eh_elly_khalani_mazakrsh_wana_3andy_sanateen()
{
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;
    if(x2 == y2)
    {
        cout << "NO" << el;
        return;
    }
    if(y - x <=0 && y2 - x2 >0)
    {
        cout << "NO" << el;
        return;
    }
    else if(y - x  >= 0 && y2 - x2 <0)
    {
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
}
int32_t main()
{
    code_it;
    //freopen(".in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) 
    {
          Ana_eh_elly_khalani_mazakrsh_wana_3andy_sanateen();
    }
    return 0;
}
