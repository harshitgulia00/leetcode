class Solution {
public:
    int minimumPushes(string word) {
        sort(word.begin(), word.end());

        vector<int> component;
        int count = 1;

        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1]) {
                count++;
            } else {
                component.push_back(count);
                count = 1;
            }
        }

        // Push the last frequency
        component.push_back(count);

        sort(component.begin(), component.end(), greater<int>());

        int minPush = 0;

        for (int i = 0; i < component.size(); i++) {
            minPush += component[i] * ((i / 8) + 1);
        }

        return minPush;
    }
};