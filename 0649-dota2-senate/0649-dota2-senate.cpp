class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R;
        queue<int> D;
        for(int i = 0; i < senate.size();i++){
            if(senate[i] == 'R'){
                R.push(i);
            }else{
                D.push(i);
            }
        }
        while(!R.empty() && !D.empty()){
            if(R.front() > D.front()){
                R.pop();
                D.push(D.front() + senate.length());
                D.pop();
            }else{
                D.pop();
                R.push(R.front() + senate.length());
                R.pop();
            }
        }
        return (R.empty()) ? "Dire" : "Radiant";
    }
};