class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> cols;
        for(int i = 0;i < n;i++){
            vector<int> col;
            for(vector<int> row : grid){
                col.push_back(row[i]);
            }
            cols.push_back(col);
        }
        
        sort(cols.begin(),cols.end());
        sort(grid.begin(),grid.end());
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i] == cols[j]){
                    count++;
                }
            }
        }
        return count;
    }
};