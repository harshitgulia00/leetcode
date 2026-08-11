class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u'){
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int count = 0;
        for(int i = 0;i < k;i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        if(s.length() == k){
            return count;
        }
        int maxCount = count;
        int i = 1;
        int j = k;
        while(j < s.length()){
            if(isVowel(s[i-1])){
                count--;
            }
            if(isVowel(s[j])){
                count++;
            }
            i++;
            j++;
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};