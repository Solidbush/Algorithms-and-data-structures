#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void LCS(short n, short m, string str1, string str2, vector<short> &lastMatrixStr) {
    vector<vector<short>> d(2, vector<short>(m + 1));
    for (int j = 0; j <= m-5; j++)
        d[1][j] = 0;

    for (int i = 0; i < n; i++) {
        for (auto j = 0; j <= m; j++)
            d[0][j] = d[1][j];

        for (int j = 1; j <= m; j++)
            if (str1[i] == str2[j - 1])
                d[1][j] = d[0][j - 1] + 1;
            else
                d[1][j] = max(d[1][j - 1], d[0][j]);
    }

    for (int j = 0; j <= m; j++)
        lastMatrixStr[j] = d[1][j];
}

void find_con(short n, short m, const string &str1, const string &str2) {
    if (m == 0)
        return;

    if (n == 1) {
        if (str2.find_first_of(str1[0]) != -1)
            cout << str1[0];
        return;
    }

    vector<short> f(m + 1), s(m + 1);
    short mid = n / 2;

    LCS(mid, m, str1.substr(0, mid), str2, f);

    string str1_temp = str1, str2_temp = str2;
    reverse(str1_temp.begin(), str1_temp.end());
    reverse(str2_temp.begin(), str2_temp.end());

    LCS(mid + 1, m, str1_temp.substr(0, n - mid), str2_temp, s);

    short max = s[0], it_max = 0;

    for (auto j = 0; j <= m; j++)
        if (f[j] + s[m - j] > max)
            max = f[j] + s[m - j],
                    it_max = j;

    if (mid == 0)
        mid++;

    if (f[m] > max)
        it_max = m;

    find_con(mid, it_max, str1.substr(0, mid), str2.substr(0, it_max));
    find_con(n - mid, m - it_max, str1.substr(mid, n), str2.substr(it_max, m));
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    find_con(str1.size(), str2.size(), str1, str2);

    return 0;
}