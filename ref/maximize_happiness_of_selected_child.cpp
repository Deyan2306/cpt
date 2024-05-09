#include <bits/stdc++.h>
using namespace std;

// [1, 2, 3]
//  ^-- happiness of the first child
// [3, 2, 1] -- 3
// [3, 1, 0] -- 4


class Solution {
    public:
        long long maximumHappinessSum(vector<int> & happiness, int k) {
            ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); // housekeeping

            sort(begin(happiness), end(happiness), greater<int>());
            int i = 0; long long res = 0;

            while (k--) {
                happiness[i] = max(happiness[i] - i, 0);
                res += happiness[i++];
            }

            return res;
        }
};

int main(void) {

    return 0;
}