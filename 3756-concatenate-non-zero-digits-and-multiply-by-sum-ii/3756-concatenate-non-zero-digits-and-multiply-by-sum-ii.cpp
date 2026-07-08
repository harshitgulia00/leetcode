class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        int n = s.size();

        vector<int> nonZeroCount(n + 1, 0);
        vector<long long> prefixSum(n + 1, 0);
        vector<long long> prefixNumber(n + 1, 0);
        vector<long long> power10(n + 1, 1);

        for (int i = 0; i < n; i++) {
            nonZeroCount[i + 1] = nonZeroCount[i];
            prefixSum[i + 1] = prefixSum[i];
            prefixNumber[i + 1] = prefixNumber[i];
            power10[i + 1] = (power10[i] * 10) % MOD;

            int digit = s[i] - '0';

            if (digit != 0) {
                nonZeroCount[i + 1]++;

                prefixSum[i + 1] += digit;

                prefixNumber[i + 1] =
                    (prefixNumber[i] * 10 + digit) % MOD;
            }
        }

        vector<int> result;
        result.reserve(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            int before = nonZeroCount[left];
            int till = nonZeroCount[right + 1];
            int digitsInRange = till - before;

            long long sum = prefixSum[right + 1] - prefixSum[left];

            long long number = prefixNumber[right + 1]
                - (prefixNumber[left] * power10[digitsInRange]) % MOD;

            if (number < 0) {
                number += MOD;
            }

            result.push_back((number * sum) % MOD);
        }

        return result;
    }
};