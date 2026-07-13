#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> ans;

        // Step 1: Start with a base template of sequential options
        // Loop through all possible lengths of sequential numbers (from 2 digits to 9 digits)
        for (int length = 2; length <= 9; ++length) {
            
            // Loop through starting digits that can fit a number of this length
            for (int startDigit = 1; startDigit <= 10 - length; ++startDigit) {
                int num = 0;
                int currentDigit = startDigit;

                // Construct the sequential number mathematically
                for (int i = 0; i < length; ++i) {
                    num = (num * 10) + currentDigit;
                    currentDigit++;
                }

                // Step 2: Validate if the generated number falls within the range
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};
