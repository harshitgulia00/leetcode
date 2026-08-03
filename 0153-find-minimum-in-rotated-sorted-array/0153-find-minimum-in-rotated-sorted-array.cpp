class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[end]) {
                // Minimum is in the right half
                st = mid + 1;
            } else {
                // Minimum is at mid or in the left half
                end = mid;
            }
        }

        return nums[st];
    }
};