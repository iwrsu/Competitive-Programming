class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string s;
        for (int d : digits) s.push_back(d + '0');
        if (s.size() <= 18) {
            long long a = stoll(s);
            a++;
            s = to_string(a);
        } 
        else {
            int i = s.size() - 1;
            while (i >= 0 && s[i] == '9') {
                s[i] = '0';
                i--;
            }
            if (i >= 0) s[i]++;
            else s = "1" + s;
        }

        vector<int> ans;
        for (char c : s) ans.push_back(c - '0');
        return ans;
    }
};

