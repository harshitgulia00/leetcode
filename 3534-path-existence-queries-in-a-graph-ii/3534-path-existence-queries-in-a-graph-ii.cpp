class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++) a.push_back({nums[i], i});
        sort(a.begin(), a.end());

        vector<int> pos(n), comp(n), nxt(n);
        int g = 0, r = 0;

        for (int i = 0; i < n; i++) {
            pos[a[i].second] = i;
            if (i && a[i].first - a[i - 1].first > maxDiff) g++;
            comp[i] = g;

            r = max(r, i);
            while (r + 1 < n && a[r + 1].first - a[i].first <= maxDiff) r++;
            nxt[i] = r;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]], v = pos[q[1]];

            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if (u > v) swap(u, v);

            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] < v) {
                    u = up[k][u];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + (u < v));
        }

        return ans;
    }
};