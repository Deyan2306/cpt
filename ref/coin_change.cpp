#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX - 1);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return (dp[amount] == INT_MAX - 1) ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = coinChange(coins, amount);

    if (result == -1) {
        cout << "It is not possible to make up the amount." << endl;
    } else {
        cout << "Minimum number of coins needed: " << result << endl;
    }

    return 0;
}
