class Solution {
public:
    double helper(double x,int n){
        if(n == 0) return 1;
        double temp= helper(x,n/2);
        temp = temp * temp;
        return (n%2 == 0) ? temp : temp * x;
    }
    double myPow(double x, int n) {
        long long exp = abs((long long)n);
        double result = helper(x,exp);
        return (n < 0) ? 1.0/result : result;
    }
};