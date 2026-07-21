class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";
        int m = t.size();

        vector<int> leftZero(m), rightZero(m);

        for (int i = 1; i < m - 1;) {
            if (t[i] == '0') {
                int j = i;
                while (j < m - 1 && t[j] == '0') j++;
                for (int k = i; k < j; k++)
                    leftZero[k] = i, rightZero[k] = j - 1;
                i = j;
            } else {
                i++;
            }
        }

        int ans = ones;

        for (int i = 1; i < m - 1;) {
            if (t[i] == '1') {
                int j = i;
                while (j < m - 1 && t[j] == '1') j++;

                if (t[i - 1] == '0' && t[j] == '0') {
                    int lost = j - i;

                    int L = leftZero[i - 1];
                    int R = rightZero[j];

                    int gain = R - L + 1;

                    ans = max(ans, ones - lost + gain);
                }

                i = j;
            } else {
                i++;
            }
        }

        return ans;
    }
};