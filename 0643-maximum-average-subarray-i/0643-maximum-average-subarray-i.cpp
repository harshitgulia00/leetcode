class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0;i < k;i++){
            sum = sum + nums[i];
        }
        double maxSum = sum;
        double avg = (double)sum / k;
        if(nums.size() <= k){
            return avg;
        }
        int i = 1;
        int j = k;
        while(j < nums.size()){
            sum += nums[j];
            sum -= nums[i-1];
            i++;
            j++;
            maxSum = max(maxSum,sum);
        }
        avg = maxSum / k;
        return avg;
    }
};