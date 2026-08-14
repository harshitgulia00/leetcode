class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> prefix(gain.size()+1,0);
        int highest = INT_MIN;
        for(int i = 1;i <= gain.size();i++){
            prefix[i] = prefix[i-1] + gain[i-1];
            highest = max(prefix[i],highest);
        }
        return (highest < 0) ? 0 : highest;
    }
};