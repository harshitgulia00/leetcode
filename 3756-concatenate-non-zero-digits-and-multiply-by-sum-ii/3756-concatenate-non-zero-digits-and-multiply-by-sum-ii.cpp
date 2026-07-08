class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        int n = s.size();

        vector<int> digits;
        vector<int> count(n + 1, 0);

        for (int i = 0; i < n; i++) {
            count[i + 1] = count[i];

            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                count[i + 1]++;
            }
        }

        int m = digits.size();

        vector<long long> power10(m + 1, 1);
        vector<long long> prefixNumber(m + 1, 0);
        vector<long long> prefixSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            power10[i + 1] = (power10[i] * 10) % MOD;

            prefixNumber[i + 1] =
                (prefixNumber[i] * 10 + digits[i]) % MOD;

            prefixSum[i + 1] = prefixSum[i] + digits[i];
        }

        vector<int> result;

        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            int start = count[left];
            int end = count[right + 1];

            int length = end - start;

            long long number =
                prefixNumber[end] -
                (prefixNumber[start] * power10[length]) % MOD;

            if (number < 0) {
                number += MOD;
            }

            long long sum = prefixSum[end] - prefixSum[start];

            result.push_back((number * sum) % MOD);
        }

        return result;
    }
};