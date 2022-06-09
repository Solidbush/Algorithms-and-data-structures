#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000000;

int main() {
    int n; cin >> n;

    if (n != 1) {
        vector<int> colors(n);
        vector<vector<int>> d(n, vector<int>(n, 0));

        for (auto &new_color : colors)
            cin >> new_color;

        for (int i = 0; i < n; ++i)
            d[i][i] = 1;

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < n - i; ++j) {
                if (colors[j] == colors[j + i])
                    d[j][j + i] = (d[j + 1][j + i] % MOD + d[j][j + i - 1] % MOD + 1) % MOD;
                else
                    d[j][j + i] = (d[j + 1][j + i] % MOD + d[j][j + i - 1] % MOD - d[j + 1][j + i - 1] % MOD) % MOD;
            }

        cout << (d[0][n - 1] + MOD) % MOD;
        exit(0);

    } else {
        cout << 0;
        exit(0);
    }
}