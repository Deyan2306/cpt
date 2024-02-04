#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "Length of LIS: " << LIS(nums) << endl;
    return 0;
}
