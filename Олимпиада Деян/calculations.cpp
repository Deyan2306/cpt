#include<bits/stdc++.h>

using namespace std;

int calculations(int n, int k, vector<int>& m, vector<int>& a) {
    vector<int> sequence(n + 1);

    for (int i = 1; i <= k; ++i) {
        sequence[i] = a[i];
    }

    for (int i = k + 1; i <= n; ++i) {
        sequence[i] = 0;
        for (int j = 1; j <= k; ++j) {
            sequence[i] += m[j] * sequence[i - j];
        }
        sequence[i] %= 2;
    }

    return sequence[n];
}

// May the source be with you :D
int main() {
    int T, k;
    cin >> T >> k;

    vector<int> m(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> m[i];
    }

    while (T--) {
        int n;
        vector<int> a(k + 1);

        cin >> n;
        for (int i = 1; i <= k; ++i) {
            cin >> a[i];
        }

        int result = calculations(n, k, m, a);
        cout << result << endl;
    }

    return 0;
}
//ez
