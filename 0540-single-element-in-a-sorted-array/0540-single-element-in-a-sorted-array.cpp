class Solution { 
public: 
    int singleNonDuplicate(vector<int>& nums) { 
        // Handle single-element array edge case
        if (nums.size() == 1) return nums[0];
        
        int st = 0; 
        int end = nums.size() - 1; 

        while (st <= end) { 
            int mid = st + (end - st) / 2; 

            // Check boundary conditions safely
            if (mid == 0 && nums[0] != nums[1]) return nums[0]; 
            if (mid == nums.size() - 1 && nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1]; 
            if (mid > 0 && mid < nums.size() - 1 && nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) return nums[mid]; 

            // Coordinate pairs logic
            if (mid % 2 == 0) { 
                if (nums[mid + 1] == nums[mid]) { 
                    st = mid + 2; 
                } else { 
                    end = mid - 2; 
                } 
            } else { 
                if (nums[mid] == nums[mid - 1]) { 
                    st = mid + 1; 
                } else { 
                    end = mid - 1; 
                } 
            } 
        } 
        return -1; 
    } 
};
