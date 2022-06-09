#include <iostream>
#include <vector>

using namespace std;



void DFS(int root, vector<vector<int>> &graph, vector<vector<int>> &d) {
    d[root][0] = 0;
    d[root][1] = 1;

    for (auto &elem : graph[root])
        DFS(elem, graph, d);

    for (int i = 0; i < graph[root].size(); ++i) {
        d[root][1] += d[graph[root][i]][0];
        d[root][0] += max(d[graph[root][i]][0], d[graph[root][i]][1]);
    }
}


int main() {
    int root = 0;
    vector<vector<int>> graph, d;
    int count_nodes, vertex;
    cin >> count_nodes;
    graph.resize(count_nodes);
    d.resize(count_nodes, vector<int>(2));

    for (int i = 0; i < count_nodes; ++i) {
        cin >> vertex;
        if (vertex != 0)
            graph[vertex - 1].emplace_back(i);
        else
            root = i;
    }
    DFS(root, graph, d);

    cout << max(d[root][0], d[root][1]);

    return 0;
}