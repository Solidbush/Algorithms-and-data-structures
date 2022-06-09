#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_string(string &post_val, string &val, int pos){
    int i = pos;
    int j = 0;
    while ((i < post_val.size()) && (j < val.size())){
        if (post_val[i] == val[j]){
            i++;
            j++;
        }
        else
            return -1;
    }
    if (j == val.size())
        return pos;
    else
        return -1;
}


int main() {
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);
    string val;
    string post_val;
    vector<int> pos;
    cin >> val;
    cin >> post_val;
    for (int i = 0; i <= post_val.size(); i++){
        if ((find_string(post_val, val, i) + 1) >= 1){
            pos.push_back(i + 1);
        }
    }
    cout << pos.size() << endl;
    for (auto elem : pos)
        cout << elem << " ";
    return 0;
}