#include <bits/stdc++.h>
using namespace std;

// May the source be with you! :D
int main(void) {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    vector<vector<int>> grid(N + 1, vector<int>(M + 1, 0));

    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;

        for (int dx = -K; dx <= K; ++dx) {
            for (int dy = -K; dy <= K; ++dy) {
                if (x + dx >= 1 && x + dx <= N && y + dy >= 1 && y + dy <= M) {
                    if (abs(dx) + abs(dy) <= K) {
                        grid[x + dx][y + dy] = 1;
                    }
                }
            }
        }

        int totalLamps = 0;
        for (int row = 1; row <= N; ++row) {
            for (int col = 1; col <= M; ++col) {
                totalLamps += grid[row][col];
            }
        }
        cout << totalLamps << endl;
    }

    return 0;
}
