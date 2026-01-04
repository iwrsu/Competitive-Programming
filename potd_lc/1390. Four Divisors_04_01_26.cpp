class Solution {
public:

    int factors(int n) {
    vector<int> divisors;
    
    // Note that this loop runs till square root
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            
            // If divisors are equal, print only one
            if (n / i == i) {
                divisors.push_back(i) ;
            }
            // Otherwise print both 
            else {
                divisors.push_back(i) ;
                divisors.push_back(n/i) ;
            }
        }
        if(divisors.size()>4) return 0;
    }

    if(divisors.size()<4) return 0;
    
    return (accumulate(divisors.begin(),divisors.end(),0));
}
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        ans+=factors(nums[i]);
        return ans;
    }
};
