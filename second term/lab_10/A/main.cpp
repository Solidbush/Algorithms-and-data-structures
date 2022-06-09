#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" ,stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>edge;
    edge.resize(n, vector<int>(0));
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(const auto& string: edge){
        cout << string.size() << " ";
    }
    return 0;
}