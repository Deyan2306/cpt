/* Problem Statement:
Given two strings, find the minimum number 
of operations (insertions, deletions, substitutions) required to convert one string into another.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int minDistance(const std::string& word1, const std::string& word2) {
    int m = word1.size();
    int n = word2.size();

    // Create a 2D DP table
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string word1 = "horse";
    std::string word2 = "ros";

    int distance = minDistance(word1, word2);
    std::cout << "Minimum Edit Distance: " << distance << std::endl;

    return 0;
}
