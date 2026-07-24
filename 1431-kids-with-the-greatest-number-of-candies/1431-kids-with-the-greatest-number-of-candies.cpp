class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = INT_MIN;
        vector<bool> ans;
        for(int i = 0;i < candies.size();i++){
            maxCandies = max(maxCandies,candies[i]);
        }

        for(int i = 0; i < candies.size();i++){
            if(maxCandies <= candies[i] + extraCandies){
                ans.push_back(true);            
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};