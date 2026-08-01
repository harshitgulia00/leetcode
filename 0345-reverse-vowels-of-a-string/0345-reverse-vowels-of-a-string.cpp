class Solution {
public:

    bool isValid(char vowel){
        vowel = (char)tolower(vowel);
        if(vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel =='o' || vowel == 'u'){
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            if(isValid(s[i]) && isValid(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            if(!isValid(s[i])){
                i++;
            }
            if(!isValid(s[j])){
                j--;
            }
        }
        return s;
    }
};