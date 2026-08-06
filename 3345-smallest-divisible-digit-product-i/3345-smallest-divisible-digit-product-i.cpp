class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int product = 1;
            int number = n;
            while(number > 0){
                int digit = number % 10;
                product = product * digit;
                number = number / 10;
            }
            if(product % t == 0){
                return n;
            }else{
                ++n;
            }
        }
        return n;
    }
};