#include <bits/stdc++.h>
using namespace std;

int lcs(int arr[], int num) {
    int maxval = 1;

    for (size_t index = 0; index < num; index++)
        maxval = max(maxval, arr[index]);   

    int dp[maxval + 1][2] = { 0 };

    int ans = 1;

    for (size_t index = 0; index < num; index++) {
        dp[arr[index]][0] = (1 + dp[arr[index] - 1][0]);

        if (arr[index] >= 2)
            dp[arr[index]][1] = max(1 + dp[arr[index] - 1][1], 2 + dp[arr[index] - 2][0]);
        else
            dp[arr[index]][1] = 1;

        ans = max(ans, dp[arr[index]][1]);
    }

    return ans;
}

// May the source be with you! :D
int main(void) {

    int n;
    cin >> n;

    int arr[n];
    for (size_t index = 0; index < n; index++)
        cin >> arr[index];

    cout << lcs(arr, n);

    return 0;
}