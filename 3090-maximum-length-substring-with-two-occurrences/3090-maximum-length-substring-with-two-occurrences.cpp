class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0;
        int j = 0;
        int maxLen = INT_MIN;
        unordered_map<char,int> freq;
        while(j < s.length()){
            freq[s[j]]++;
            while(freq[s[j]] > 2){
                freq[s[i]]--;
                i++;
            }
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};