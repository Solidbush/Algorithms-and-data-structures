#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int main() {
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> f(n + 3, vector<ll>(m + 3));
    f[2][2] = 1;
    ll start_i = 2, start_j = 2;
    while ((start_i < n + 1) || (start_j < m + 1)) {
        if (start_j == m + 1)
            start_i++;
        else
            start_j++;

        ll i = start_i;
        ll j = start_j;
        while ((i <= n + 1) && j >= 2) {
            f[i][j] = f[i + 1][j - 2] + f[i - 1][j - 2] + f[i - 2][j - 1] + f[i - 2][j + 1];
            i++;
            j--;
        }
    }
    cout << f[n + 1][m + 1];

    return 0;
}