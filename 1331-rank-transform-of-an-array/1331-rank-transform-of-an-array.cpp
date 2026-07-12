class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;

        sort(copy.begin(), copy.end());

        unordered_map<int, int> rank;
        int currentRank = 1;

        for (int i = 0; i < copy.size(); i++) {
            if (rank.find(copy[i]) == rank.end()) {
                rank[copy[i]] = currentRank;
                currentRank++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(rank[arr[i]]);
        }

        return ans;
    }
};