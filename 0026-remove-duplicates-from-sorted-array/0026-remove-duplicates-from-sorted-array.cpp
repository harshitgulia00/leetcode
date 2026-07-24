class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 1;
        int prev = nums[0];
        for(int read = 0;read < nums.size();read++){
            if(prev != nums[read]){
                prev = nums[read];
                swap(nums[read],nums[write]);
                write++;
            }
        }
        return write;
    }
};