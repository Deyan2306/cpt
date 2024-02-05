// Problem Statement: Given a set of positive integers and a target
// sum, determine whether there exists a subset of the given set with a sum equal to the target sum.

#include <iostream>
#include <vector>

bool isSubsetSum(const std::vector<int>& nums, int targetSum) {
    int n = nums.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(targetSum + 1, false));

    // Base case: subset with sum 0 is always possible
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            dp[i][j] = dp[i - 1][j]; // Exclude nums[i-1]

            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]]; // Include nums[i-1]
            }
        }
    }

    return dp[n][targetSum];
}

int main() {
    std::vector<int> nums = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;

    if (isSubsetSum(nums, targetSum)) {
        std::cout << "Subset with sum " << targetSum << " exists.\n";
    } else {
        std::cout << "No subset with sum " << targetSum << " exists.\n";
    }

    return 0;
}
