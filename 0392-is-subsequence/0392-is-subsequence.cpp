class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        if(s.length() > t.length()){
            return false;
        }
        if(s.length() == 0){
            return true;
        }
        if(t.length() == 0){
            return false;
        }
        bool ans = false;
        while(i < s.length()){
            if(s[i] == t[j]){
                j++;
                i++;
                ans = true;
            }else{
                if(j < t.length()){
                    j++;
                }else{
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};