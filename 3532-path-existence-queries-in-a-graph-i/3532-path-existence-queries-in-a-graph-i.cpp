class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int group = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                group++;
            }

            component[i] = group;
        }
    
        vector<bool> ans;

        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            ans.push_back(component[u] == component[v]);
        }

        return ans;
    }
};