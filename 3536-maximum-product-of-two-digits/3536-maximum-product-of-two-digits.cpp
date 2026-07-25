class Solution {
public:
    int maxProduct(int n) {
        int max1 = INT_MIN;
        int m = n;
        while(n > 0){
            int digit = n%10;
            n = n / 10;
            max1 = max(max1,digit); 
        }
        int count = 0;
        n = m;
        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            if(digit == max1){
                count++;
            }
        }
        if(count > 1){
            return pow(max1,2);
        }
        int max2 = INT_MIN;
        n = m;
        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            if(digit != max1){
                max2 = max(max2 , digit);
            }
        }
        return max1 * max2;
    }
};