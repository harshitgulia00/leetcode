class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        bool flag = false;
        vector<int> list = {};
        for(int j = left;j <= right;j++){
            bool flag = true;
            int i =j;
            while(i != 0){
                int digit = i%10;
                if(digit == 0){
                    flag = false;
                    break;
                }
                if(j%digit == 0){
                    i = i/10;
                }else{
                    flag = false;
                    break;
                }
            }
        if(flag){
            list.push_back(j);
        }
        }
    return list;
    }
};