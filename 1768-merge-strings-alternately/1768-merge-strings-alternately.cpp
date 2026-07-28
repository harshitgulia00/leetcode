class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0;
        string ans;
        string rem;
        if(n < m){
            rem = word2.substr(min(n,m));
        }else if(m < n){
            rem = word1.substr(min(n,m));
        }else{
            rem = "";
        }
        for(int i = 0; i < min(n,m);i++){
            ans = ans + word1[i];
            ans = ans + word2[i];
        }
        return ans + rem;
    }
};