class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1000000007;
        int n = s.size();

        // nzPos[k] = original string index of kth non-zero digit
        // digits[k] = kth non-zero digit
        vector<int> nzPos;
        vector<int> digits;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                nzPos.push_back(i);
                digits.push_back(s[i] - '0');
            }
        }

        int m = digits.size();

        // pow10[i] = 10^i % MOD
        vector<long long> pow10(m + 1, 1);

        // prefixNum[i] = number made using first i non-zero digits
        // prefixSum[i] = sum of first i non-zero digits
        vector<long long> prefixNum(m + 1, 0);
        vector<long long> prefixSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pow10[i + 1] = (pow10[i] * 10) % MOD;
            prefixNum[i + 1] = (prefixNum[i] * 10 + digits[i]) % MOD;
            prefixSum[i + 1] = prefixSum[i] + digits[i];
        }

        vector<int> answer;

        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            // first non-zero digit whose position >= left
            int start = lower_bound(nzPos.begin(), nzPos.end(), left) - nzPos.begin();

            // first non-zero digit whose position > right
            int end = upper_bound(nzPos.begin(), nzPos.end(), right) - nzPos.begin();

            // No non-zero digit inside this query
            if (start == end) {
                answer.push_back(0);
                continue;
            }

            int length = end - start;

            // Extract compressed number from prefix values
            long long number = prefixNum[end] - (prefixNum[start] * pow10[length]) % MOD;

            if (number < 0) {
                number += MOD;
            }

            long long sum = prefixSum[end] - prefixSum[start];

            answer.push_back((number * sum) % MOD);
        }

        return answer;
    }
};