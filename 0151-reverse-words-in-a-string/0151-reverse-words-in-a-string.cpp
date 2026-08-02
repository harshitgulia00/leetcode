class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        vector<string> ans;
        string temp = "";
        while(i < s.length()){
            if(s[i] == ' '){
                i++;
                if(temp != ""){
                    ans.push_back(temp);
                }
                temp = "";
                continue;
            }else{
                temp += s[i];
                i++;
            }
        }
        if(temp != ""){
                    ans.push_back(temp);
                }
        s = "";
        for(int i = ans.size() - 1;i >= 0;i--){
            if(i == 0){
                s += ans[i];
            }else{
                s+= ans[i];
                s += " ";
            }
        }
        return s;
    }
};