#include <iostream>
#include <vector>

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

vector<int> kmp(string &pattern, string &text) {
    int pattern_size = pattern.size();
    int text_size = text.size();
    vector<int> ans;
    string temp_p = pattern + "#" + text;
    vector<int> p = pref_Fun(temp_p);
    for (int i = 0; i < text_size; i++)
        if (p[pattern_size + i + 1] == pattern_size)
            ans.push_back(i - pattern_size + 2);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);
    string query, text;
    cin >> query >> text;
    vector<int> res = kmp(query, text);

    cout << res.size() << endl;
    for (auto elem : res)
        cout << elem << " ";

    return 0;
}