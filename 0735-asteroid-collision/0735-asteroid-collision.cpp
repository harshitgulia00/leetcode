class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for(int a : asteroids){

            if(ans.empty()){
                ans.push_back(a);
                continue;
            }

            if(ans.back() > 0 && a < 0){

                while(!ans.empty() &&
                      ans.back() > 0 &&
                      abs(ans.back()) < abs(a)){
                    ans.pop_back();
                }

                if(!ans.empty() &&
                   ans.back() > 0 &&
                   abs(ans.back()) == abs(a)){
                    ans.pop_back();
                }
                else if(ans.empty() || ans.back() < 0){
                    ans.push_back(a);
                }
            }
            else{
                ans.push_back(a);
            }
        }

        return ans;
    }
};