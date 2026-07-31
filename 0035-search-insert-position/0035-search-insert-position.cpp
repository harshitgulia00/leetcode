class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        int mid;
        bool flag = false;
        while(st <= end){
            mid = st + (end - st) / 2;
            if(nums[mid] == target){
                flag = true;
                break;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        if(flag){
            return mid;
        }
        return st;
    }
};