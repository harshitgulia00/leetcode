class Solution {
public:
    long long LIMIT = 1000000LL + 5;

    // Safely calculates combinations nCr capped at LIMIT
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r; // Optimize calculations
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - r + i) / i;
            if (res > LIMIT) return LIMIT;
        }
        return res;
    }

    // Correctly computes multinomial coefficient capped at LIMIT
    long long countWays(const vector<int>& freq) {
        int total = 0;
        long long ways = 1;
        
        for (int f : freq) {
            if (f == 0) continue;
            total += f;
            ways *= nCr(total, f);
            if (ways > LIMIT) return LIMIT;
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            if (cnt[i] % 2) mid = (char)('a' + i);
        }

        // Quick check: If total combinations initially is less than k, return ""
        if (countWays(half) < k) return "";

        string left = "";
        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {
            bool found = false;
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back((char)('a' + ch));
                    found = true;
                    break;
                }

                k -= ways;
                half[ch]++; // Backtrack
            }
            if (!found) return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid) return left + string(1, mid) + right;
        return left + right;
    }
};
