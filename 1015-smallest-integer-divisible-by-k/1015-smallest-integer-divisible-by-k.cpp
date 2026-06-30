class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) { return -1; }
        if(k == 1){return 1;}
        int n = 1;
        int count = 0;
        while(count <= k){
            count++;
            if(n % k == 0){
                return count;
            }else{
                n = ((n * 10) + 1)%k;
            }
        }
    return -1;
    }
};