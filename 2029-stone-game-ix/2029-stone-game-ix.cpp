class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If count of 0-rem stones is even,
        // Alice can win iff both 1 and 2 exist.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // If count of 0-rem stones is odd,
        // one side must have at least 2 more stones than the other.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};