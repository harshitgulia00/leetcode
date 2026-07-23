class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 0;
        long long j = sqrt(c);
        bool flag = false;
        while(i <= j){
            if(i*i + j*j == c){
                flag = true;
                break;
            }
            else if(i*i + j*j > c){
                j--;
            }else{
                i++;
            }
        }
        return flag;
    }
};