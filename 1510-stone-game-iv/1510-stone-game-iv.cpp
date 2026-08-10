class Solution {
public:
    vector<int> dp;

    bool dfs(int n) {
        if (n == 0)
            return false;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++) {
            int square = i * i;

            // If opponent loses, current player wins
            if (!dfs(n - square)) {
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);

        return dfs(n);
    }
};