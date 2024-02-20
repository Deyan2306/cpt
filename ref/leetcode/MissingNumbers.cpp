#include <iostream>
#include <vector>
using namespace std;

// Elegant!!
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++)
            ans ^= i ^ nums[i];

        return ans;
    }
};

int main(void) { return 0; }

// ======
// Why does it work, tho? 
// XOR is true only when the two values differ.
// So to understand it, think that way -> it will always return 0 if the two elements are the same
// And at the end we are left with the only value, that has no duplicates
// ez 100 points on leet code
