#include <iostream>
#include <vector>

using namespace std;


const long long INF = LONG_LONG_MAX;

vector<long long> bellman_algo(const long long start, const long long n, vector<vector<pair<long long, long long>>> &graph, vector<bool> &used) {
    vector<long long> dist(n, INF);
    dist[start] = 0;
    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            for (auto k = 0; k < graph[j].size(); k++)
                if ((dist[j] < INF) && (dist[graph[j][k].second] > dist[j] + graph[j][k].first))
                    dist[graph[j][k].second] = dist[j] + graph[j][k].first;

    return dist;
}

void DFS(const long long id, vector<vector<pair<long long, long long>>> &graph, vector<bool> &used) {
    used[id] = true;
    for (auto const &elem : graph[id])
        if (!used[elem.second])
            DFS(elem.second, graph, used);
}

void check_res(const vector<long long> &dist, vector<vector<pair<long long, long long>>> &graph, vector<bool> &used) {
    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph[i].size(); j++)
            if ((dist[i] < INF) && (dist[graph[i][j].second] > dist[i] + graph[i][j].first) && !used[graph[i][j].second])
                DFS(graph[i][j].second, graph, used);
}


int main() {
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    long long n, m, start;
    cin >> n >> m >> start;
    vector<vector<pair<long long, long long>>> graph;
    vector<bool> used;
    long long first_vert, second_vert, weight;
    graph.resize(n);
    used.resize(n, false);

    for (int i = 0; i < m; i++) {
        cin >> first_vert >> second_vert >> weight;
        graph[first_vert - 1].push_back({weight, second_vert - 1});
    }

    vector<long long> shorted_dist = bellman_algo(start - 1, graph.size(), graph, used);

    check_res(shorted_dist, graph, used);

    for (int i = 0; i < graph.size(); i++)
        if (shorted_dist[i] == INF)
            cout << "*" << endl;
        else if (used[i] || shorted_dist[i] < -5e18)
            cout << "-" << endl;
        else
            cout << shorted_dist[i] << endl;

    return 0;
}