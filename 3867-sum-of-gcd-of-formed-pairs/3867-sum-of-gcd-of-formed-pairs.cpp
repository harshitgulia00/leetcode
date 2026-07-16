class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        vector<int> prefixGrid;
        for(int i = 0; i< nums.size();i++){
            mx = max(mx , nums[i]);
            prefixGrid.push_back(gcd(nums[i],mx));
        }
        sort(prefixGrid.begin(),prefixGrid.end());
        int i = 0;
        int j = prefixGrid.size() - 1;
        long long sum = 0;
        while(i < j){
            sum = sum + (gcd(prefixGrid[i],prefixGrid[j]));
            i++;
            j--;
        }
    return sum;
    }
};