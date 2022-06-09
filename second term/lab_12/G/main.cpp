#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int main() {
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    ll space_count, gold_count;
    cin >> space_count >> gold_count;
    vector<vector<ll>> arr(gold_count + 1, vector<ll>(space_count + 1, 0));
    vector<ll> weight(gold_count + 1);

    weight[0] = 0;
    for (int i = 1; i <= gold_count; ++i)
        cin >> weight[i];

    for (int i = 0; i <= space_count; ++i)
        arr[0][i] = 0;

    for (int i = 0; i <= gold_count; ++i)
        arr[i][0] = 0;

    for (int i = 1; i <= gold_count; ++i)
        for (int j = 0; j <= space_count; ++j) {
            if (j >= weight[i])
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - weight[i]] + weight[i]);
            else
                arr[i][j] = arr[i - 1][j];
        }

    cout << arr[gold_count][space_count] << endl;

    return 0;
}