class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size(),0);
        //prefix - filling
        for(int i = 0;i < nums.size();i++){
            if(i == 0){
                prefix.push_back(nums[0]);
            }else{
                prefix.push_back(prefix[i-1] + nums[i]);
            }
        }
        //suffix - filling
        for(int i = nums.size()-1;i >= 0;i--){
            if(i == nums.size() - 1){
                suffix[i] = nums[i];
            }else{
                suffix[i] = suffix[i+1] + nums[i];
            }
        }
        for(int i = 0;i < nums.size();i++){
            if(prefix[i] == suffix[i]){
                return i;
            }
        }
        return -1;
    }
};