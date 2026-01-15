using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define rrep(i,a,b) for (int i = (a); i >= (b); i--)
#define pb push_back

// Input/output helpers for vectors
template<typename T>
istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) { for (auto &x : v) out << x << " "; return out; }

const ll MOD = 1e9 + 7;
const ll INFLL = 4e18;


class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(all(hBars));
        sort(all(vBars));

        int hmax=1,vmax=1,hcur=1,vcur=1;
        int n1=hBars.size();
        int m1=vBars.size();
        for(int i=1;i<n1;i++)
        {
            if(hBars[i]==hBars[i-1]+1) 
            {
                ++hcur;
            }
            else {
                hcur=1;}
            hmax=max(hcur,hmax);

        }
        for(int i=1;i<m1;i++)
        {
            if(vBars[i]==vBars[i-1]+1) 
            {
                ++vcur;
            }
            else {
                vcur=1;}
            vmax=max(vcur,vmax);
        }
        return (min(hmax,vmax)+1)*(min(hmax,vmax)+1);
    }
};
