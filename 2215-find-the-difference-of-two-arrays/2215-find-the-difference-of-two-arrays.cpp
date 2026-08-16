class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;
        vector<int> ans1;
        vector<int> ans2;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        //freq1 -> filling for nums1
        for(int num : nums1){
            freq1[num]++;
        }

        //freq2 -> filling for nums2
        for(int num : nums2){
            freq2[num]++;
        }
        //getting distincts of nums1
        for(int num : nums1){
            if(!ans1.empty() && ans1[ans1.size()-1] == num) continue;
            if(!freq2[num]){
                ans1.push_back(num);
            }
        }
        //getting distincts of nums2
        for(int num : nums2){
            if(!ans2.empty() && ans2[ans2.size()-1] == num) continue;
            if(!freq1[num]){
                ans2.push_back(num);
            }
        }
        return {ans1,ans2};
    }
};