class Solution {
public:
    string removeStars(string s) {
        vector<char> stack;
        for(char ch : s){
            if(ch == '*'){
                if(!stack.empty()){
                    stack.pop_back();
                }
            }else{
                    stack.push_back(ch);
            }
        }
        s = "";
        for(char c : stack){
            s+=c;
        }
        return s;
    }
};