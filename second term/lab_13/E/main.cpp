#include <iostream>
#include <vector>

using namespace std;

vector<int> pref_Fun(string str) {
    vector<int> pref(str.size(), 0);
    for (int i = 1; i < str.size(); ++i) {
        int k = pref[i - 1];
        while (k > 0 && str[i] != str[k])
            k = pref[k - 1];
        if (str[i] == str[k])
            k++;
        pref[i] = k;
    }
    return pref;
}

vector<int> kmp(string &pattern, string &text) {
    int pattern_size = pattern.size();
    int text_size = text.size();
    vector<int> answer;
    vector<int> p = pref_Fun(pattern + "#" + text);
    for (int i = 0; i < text_size; ++i)
        if (p[pattern_size + i + 1] == pattern_size)
            answer.emplace_back(i - pattern_size + 2);

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("search4.in", "r", stdin);
    freopen("search4.out", "w", stdout);
    int p_count; cin >> p_count;
    vector<string> patterns(p_count);

    for (int i = 0; i < p_count; ++i)
        cin >> patterns[i];

    string str; cin >> str;
    str += '#';
    vector<int> p = pref_Fun(str);

    for (auto &word : patterns) {
        vector<int> res = kmp(word, str);
        (res.empty()) ? cout << "NO\n" : cout << "YES\n";
    }

    return 0;
}