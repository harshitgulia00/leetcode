class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        for(int i = 0; i < intervals.size()-1; i++){
            if(intervals[i][0] != intervals[i+1][0] && intervals[i][1] >= intervals[i+1][1]){
                intervals.erase(intervals.begin() + (i+1));

                if(i != 0){
                    i--;
                }else{
                    i = -1;
                }
            }else if(intervals[i][0] == intervals[i+1][0]){
                if(intervals[i][1] >= intervals[i+1][1]){
                    intervals.erase(intervals.begin() + (i+1));
                    if(i != 0){
                    i--;
                    }else{i = -1;}
                }else{
                    intervals.erase(intervals.begin() + (i));
                    if(i != 0){
                    i--;
                    }else{i = -1;}
                }

            }
            else{
                
            }
        }
    return intervals.size();
    }
};