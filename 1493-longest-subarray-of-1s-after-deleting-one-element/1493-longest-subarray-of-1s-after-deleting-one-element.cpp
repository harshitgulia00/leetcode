class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = i;
        int count = 0;
        int maxCount = INT_MIN;
        int k = 0;
        while(j < nums.size()){
            if(nums[j] == 1){
            }else{
                k++;
                while(k > 1){
                    if(nums[i] == 0){
                        k--;
                    }
                    i++;
                    
                }
            }
            maxCount = max(j - i,maxCount);
            j++;
        }
        return maxCount;
    }
};