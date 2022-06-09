#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Number {
    int value, parent, sequence, index;
};



vector<int> find_path(vector<int> &path, int &id, vector<Number> &arr) {
    while (id != -1) {
        path.emplace_back(id);
        id = arr[id].parent;
    }

    return path;
}

void find_longest_sequence(vector<Number> &arr, int &id) {
    int ans = arr[0].sequence;
    for (auto const &elem : arr)
        if (elem.sequence > ans) {
            ans = elem.sequence;
            id = elem.index;
        }

    cout << ans << endl;
}

int main() {
    vector<Number> arr;
    int id = 0;
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr[i] = {x, -1, 1, i};
    }

    for (int i = 0; i < arr.size(); ++i)
        for (int j = 0; j < i; ++j)
            if (arr[j].value < arr[i].value)
                if (1 + arr[j].sequence > arr[i].sequence) {
                    arr[i].sequence = 1 + arr[j].sequence;
                    arr[i].parent = j;
                }

    find_longest_sequence(arr, id);

    vector<int> path;
    find_path(path, id, arr);

    reverse(path.begin(), path.end());
    for (auto const &index : path)
        cout << arr[index].value << ' ';

    return 0;
}