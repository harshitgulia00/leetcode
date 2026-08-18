class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        vector<int> vec1;
        vector<int> vec2;
        unordered_set<char> set1;
        unordered_set<char> set2;
        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;

        for(int i = 0;i < word1.length();i++){
            freq1[word1[i]]++;
            freq2[word2[i]]++;

            set1.insert(word1[i]);
            set2.insert(word2[i]);
        }

        if(set1 != set2) return false;
        
        for(auto [key,val] : freq1){
            vec1.push_back(val);
        }
        for(auto [key,val] : freq2){
            vec2.push_back(val);
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());

        int i = 0;
        while(i < vec1.size()){
            if(vec1[i] == vec2[i]){
                i++;
            }else{
                return false;
            }
        }
        return true;
    }
};