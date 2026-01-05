#define INF 0x3f3f3f3f

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int cnt=0;
        int min=INF;
        for(auto &i: matrix)
        {
            for(auto &j: i)
            {
                ans+=abs(j);
                if(j<0)
                ++cnt;
                if(abs(j)<min) min=abs(j);
            }
        }
        return (cnt&1)?(ans-abs(min*2)):ans;
    }
};
