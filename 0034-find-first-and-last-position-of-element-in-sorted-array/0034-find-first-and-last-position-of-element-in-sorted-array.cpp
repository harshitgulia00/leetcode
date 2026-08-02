class Solution {
public:

    int firstOcc(vector<int> &nums,int target,int st,int end){
        int answer = -1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                answer = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return answer;
    }

    int lastOcc(vector<int> &nums,int target,int st,int end){
        int answer = -1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                answer = mid;
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return answer;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return {-1,-1};
        }
        vector<int> ans;
        int occurence = -1;
        int st = 0;
        int end = nums.size() - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] == target){
                occurence = mid;
                break;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        if(occurence == -1){
            return {-1,-1};
        }else{
            
            ans.push_back(firstOcc(nums,target,0,occurence));
            ans.push_back(lastOcc(nums,target,occurence,nums.size() - 1));
        }
        return ans;
    }
};