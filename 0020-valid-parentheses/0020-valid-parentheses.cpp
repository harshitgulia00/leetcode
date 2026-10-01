class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(int i = 0;i < s.length();i++){
            if(stack.empty()){
                stack.push_back(s[i]);
            }else{
                if(stack.back() == '(' && s[i] == ')'){
                    stack.pop_back();
                }else if(stack.back() == '[' && s[i] == ']'){
                    stack.pop_back();
                }else if(stack.back() == '{' && s[i] == '}'){
                    stack.pop_back();
                }else{
                    stack.push_back(s[i]);
                }
            }
        }
        return stack.empty();
    }
};