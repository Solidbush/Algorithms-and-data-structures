#include <iostream>
#include <vector>

using namespace std;

struct inch {
    vector<int> edges;
    int value;
};



void DFS(int &root, vector<vector<int>> &d, vector<inch> &graph) {
    d[root][0] = 0;
    d[root][1] = graph[root].value;

    for (auto &elem : graph[root].edges)
        DFS(elem, d, graph);

    for (int i = 0; i < graph[root].edges.size(); ++i) {
        d[root][1] += d[graph[root].edges[i]][0];
        d[root][0] += max(d[graph[root].edges[i]][0], d[graph[root].edges[i]][1]);
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("selectw.in", "r", stdin);
    freopen("selectw.out", "w", stdout);
    int root = 0;
    vector<vector<int>> d;
    vector<inch> graph;
    int count_nodes, vertex, num;
    cin >> count_nodes;
    graph.resize(count_nodes);
    d.resize(count_nodes, vector<int>(2));
    for (int i = 0; i < count_nodes; ++i) {
        cin >> vertex >> num;
        graph[i].value = num;
        if (vertex == 0)
            root = i;
        else
            graph[vertex - 1].edges.push_back(i);
    }
    DFS(root, d , graph);
    cout << max(d[root][0], d[root][1]);

    return 0;
}