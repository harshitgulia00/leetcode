class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        long long sum = 0;
        long long i = 1;
        while(n > 0){
            int digit = n % 10;
            sum = sum + digit;
            if(digit == 0){
                n = n/10;
                continue;
            }else{
                ans = (digit * i) + ans;
                i = i * 10;
            }
            n = n/10;
        } 
    return ans * sum;  
    }
};