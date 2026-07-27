class Solution {
public:
    int getSum(int a, int b) {
        int carry = -1;
        int add = 0;
        while(carry != 0){
            add = (unsigned int)a^b;
            carry = (a & b) << 1;
            a = add;
            b = carry;
        }
    return add;
    }
};