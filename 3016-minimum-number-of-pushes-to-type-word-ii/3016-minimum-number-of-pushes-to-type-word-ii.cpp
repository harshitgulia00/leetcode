class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        vector<int> component;

        for (int x : freq) {
            if (x > 0)
                component.push_back(x);
        }

        sort(component.begin(), component.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < component.size(); i++) {
            ans += component[i] * ((i / 8) + 1);
        }

        return ans;
    }
};