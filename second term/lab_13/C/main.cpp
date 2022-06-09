#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> pref_Fun(string &text) {
    vector<int> pref(text.size(), 0);
    for (int i = 1; i < text.size(); i++) {
        int k = pref[i - 1];
        while (k > 0 && text[i] != text[k])
            k = pref[k - 1];
        if (text[i] == text[k])
            k++;
        pref[i] = k;
    }
    return pref;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    string text;
    cin >> text;
    vector<int> p = pref_Fun(text);
    for (auto &elem : p)
        cout << elem << " ";
    return 0;
}