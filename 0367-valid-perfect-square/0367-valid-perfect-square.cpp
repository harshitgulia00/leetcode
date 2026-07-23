class Solution {
public:
    bool isPerfectSquare(int num) {
        int sqr = sqrt(num);
        if(sqr * sqr == num){
            return true;
        }
        return false;
    }
};