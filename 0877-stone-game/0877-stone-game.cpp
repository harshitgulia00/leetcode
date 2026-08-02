class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int left, int right, vector<int>& piles) {
        if (left == right)
            return piles[left];

        if (dp[left][right] != INT_MIN)
            return dp[left][right];

        int takeLeft = piles[left] - dfs(left + 1, right, piles);
        int takeRight = piles[right] - dfs(left, right - 1, piles);

        return dp[left][right] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, INT_MIN));

        return dfs(0, n - 1, piles) > 0;
    }
};