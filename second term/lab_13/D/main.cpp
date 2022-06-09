#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefixFunction(string &str) {
    vector<int> pref(str.size(), 0);
    for (int i = 1; i < str.size(); i++) {
        int k = pref[i - 1];
        while (k > 0 && str[i] != str[k])
            k = pref[k - 1];
        if (str[i] == str[k])
            k++;
        pref[i] = k;
    }
    return pref;
}

int main() {
    string text;
    int alph;
    cin >> alph >> text;

    text += '#';
    int n = text.size();
    vector<int> p = prefixFunction(text);
    vector<vector<int> > ans(n, vector<int>(alph));

    for (int i = 0; i < n; i++)
        for (char j = 0; j < alph; j++) {
            char temp = (char) (j + 97);
            if (i > 0 && temp != text[i])
                ans[i][j] = ans[p[i - 1]][j];
            else
                ans[i][j] = i + (temp == text[i]);
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < alph; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}