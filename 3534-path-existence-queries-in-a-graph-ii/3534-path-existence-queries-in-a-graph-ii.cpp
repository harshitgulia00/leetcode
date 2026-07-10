class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<pair<int, int>> values;

        for (int i = 0; i < n; i++) {
            values.push_back({nums[i], i});
        }

        sort(values.begin(), values.end());

        vector<int> position(n);
        vector<int> component(n);

        int group = 0;
        component[0] = 0;

        for (int i = 0; i < n; i++) {
            position[values[i].second] = i;

            if (i > 0 && values[i].first - values[i - 1].first > maxDiff) {
                group++;
            }

            component[i] = group;
        }

        vector<int> next(n);
        int right = 0;

        for (int i = 0; i < n; i++) {
            if (right < i) {
                right = i;
            }

            while (right + 1 < n &&
                   values[right + 1].first - values[i].first <= maxDiff) {
                right++;
            }

            next[i] = right;
        }

        int LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> jump(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            jump[0][i] = next[i];
        }

        for (int level = 1; level < LOG; level++) {
            for (int i = 0; i < n; i++) {
                jump[level][i] = jump[level - 1][jump[level - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int u = position[queries[i][0]];
            int v = position[queries[i][1]];

            if (component[u] != component[v]) {
                ans.push_back(-1);
                continue;
            }

            if (u > v) {
                swap(u, v);
            }

            int current = u;
            int steps = 0;

            for (int level = LOG - 1; level >= 0; level--) {
                if (jump[level][current] < v) {
                    current = jump[level][current];
                    steps += (1 << level);
                }
            }

            if (current < v) {
                steps++;
            }

            ans.push_back(steps);
        }

        return ans;
    }
};