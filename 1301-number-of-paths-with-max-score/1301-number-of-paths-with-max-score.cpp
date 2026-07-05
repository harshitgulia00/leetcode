class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1000000007;
        int NEG = -1000000000;

        vector<vector<int>> score(n, vector<int>(n, NEG));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }

                int best = NEG;
                long long count = 0;

                // From below
                if (i + 1 < n) {
                    if (score[i + 1][j] > best) {
                        best = score[i + 1][j];
                        count = ways[i + 1][j];
                    } 
                    else if (score[i + 1][j] == best) {
                        count += ways[i + 1][j];
                    }
                }

                // From right
                if (j + 1 < n) {
                    if (score[i][j + 1] > best) {
                        best = score[i][j + 1];
                        count = ways[i][j + 1];
                    } 
                    else if (score[i][j + 1] == best) {
                        count += ways[i][j + 1];
                    }
                }

                // From diagonal bottom-right
                if (i + 1 < n && j + 1 < n) {
                    if (score[i + 1][j + 1] > best) {
                        best = score[i + 1][j + 1];
                        count = ways[i + 1][j + 1];
                    } 
                    else if (score[i + 1][j + 1] == best) {
                        count += ways[i + 1][j + 1];
                    }
                }

                if (best == NEG) {
                    continue;
                }

                score[i][j] = best;

                if (board[i][j] >= '0' && board[i][j] <= '9') {
                    score[i][j] += board[i][j] - '0';
                }

                ways[i][j] = count % MOD;
            }
        }

        if (ways[0][0] == 0) {
            return {0, 0};
        }

        return {score[0][0], ways[0][0]};
    }
};