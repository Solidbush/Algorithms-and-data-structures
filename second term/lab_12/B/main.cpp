#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long






int main() {
    vector<ll> arr;
    ll INF = 100000000000;

    ll n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<ll> d(arr.size() + 1, INF), sequence_index(arr.size() + 1), prev_index(arr.size());
    ll length = 0;
    sequence_index[0] = prev_index[0] = -1;
    d[0] = -INF;

    for (auto i = 0; i < arr.size(); ++i) {
        ll j = upper_bound (d.begin(), d.end(), arr[i]) - d.begin();
        if (d[j - 1] < arr[i] && arr[i] < d[j]) {
            d[j] = arr[i];
            sequence_index[j] = i;
            prev_index[i] = sequence_index[j - 1];
            length = max(length, j);
        }
    }

    vector<ll> result;
    ll cur_prev = sequence_index[length];
    while (cur_prev != -1) {
        result.emplace_back(arr[cur_prev]);
        cur_prev = prev_index[cur_prev];
    }
    reverse(result.begin(), result.end());


    cout << result.size() << endl;
    for (auto const &elem : result)
        cout << elem << ' ';

    return 0;
}