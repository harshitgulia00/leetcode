class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i + 1] - nums[i] > 1){
                for(int j = 1;j < nums[i + 1] - nums[i];j++){
                    ans.push_back(nums[i] + j);
                }
            }
        }
        return ans;
    }
};