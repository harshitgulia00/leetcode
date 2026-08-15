class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool zero = false;
        int total = 0;
        for(int num : nums){
            zero = zero | num > 0;
            total = total ^ num;
        }
        if(total) return nums.size();
        if(zero != false) return nums.size() - 1;
        return 0;
    }
};