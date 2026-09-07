class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas = 0;
        int tcost = 0;
        for(int val : gas){
            tgas += val;
        }
        for(int val : cost){
            tcost += val;
        }
        if(tgas < tcost) return -1;
        int start = 0;
        int currGas = 0;
        for(int i = 0;i < gas.size();i++){
            currGas += (gas[i] - cost[i]);
            if(currGas < 0){
                currGas = 0;
                start = i+1;
            }
        }
        return start;
    }
};