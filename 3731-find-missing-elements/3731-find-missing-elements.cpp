class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bool present[101] = {false};

        int mn = INT_MAX, mx = INT_MIN;

        for (int x : nums) {
            present[x] = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }

        vector<int> ans;

        for (int x = mn; x <= mx; x++) {
            if (!present[x])
                ans.push_back(x);
        }

        return ans;
    }
};