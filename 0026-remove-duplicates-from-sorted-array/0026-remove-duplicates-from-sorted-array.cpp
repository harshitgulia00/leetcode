class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev = nums[0];
        vector<int> helper = {prev};
        int ans = 1;
        for(int num : nums){
            if(prev != num){
                ans++;
                prev = num;
                helper.push_back(num);
            }
        }
        nums = helper;
        return ans;
    }
};