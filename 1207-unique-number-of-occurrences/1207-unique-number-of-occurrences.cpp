class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> f;
        for(int & num : arr){
            f[num]++;
        }
        unordered_set<int> st;
        for(int num : arr){
            st.insert(f[num]);
        }

        return f.size() == st.size();
    }
};