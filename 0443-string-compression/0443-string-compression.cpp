class Solution {
public:
    int compress(vector<char>& chars) {

        vector<char> ans;
        int count = 1;
        int n = chars.size();

        for(int i = 1; i <= n; i++) {

            if(i < n && chars[i] == chars[i - 1]) {
                count++;
            }
            else {

                ans.push_back(chars[i - 1]);

                if(count > 1) {
                    string freq = to_string(count);

                    for(char ch : freq)
                        ans.push_back(ch);
                }

                count = 1;
            }
        }

        chars = ans;
        return chars.size();
    }
};