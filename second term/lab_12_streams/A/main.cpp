#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;


int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int flow;
    int maxFlow;
};

bool bfs(vector<vector<Edge>>& G, vector<int>& distances, int& s, int& t) {
    distances.assign(distances.size(), INF);
    queue<int> q;
    q.push(s);
    distances[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (Edge& e : G[v]) {
            if (distances[e.to] == INF && e.flow < e.maxFlow) {
                q.push(e.to);
                distances[e.to] = distances[v] + 1;
            }
        }
    }
    return distances[t] != INF;
}

int dfs(vector<vector<Edge>>& G, vector<int>& distances, int t, int flow, int v) {
    if (flow == 0)
        return 0;
    if (v == t)
        return flow;
    for (Edge& e : G[v]) {
        if (distances[e.to] != distances[v] + 1)
            continue;

        int result = dfs(G, distances, t, min(flow, e.maxFlow - e.flow), e.to);
        if (result > 0) {
            e.flow += result;
            for (Edge& w : G[e.to]) {
                if (w.to == v) {
                    w.flow -= result;
                    break;
                }
            }
            return result;
        }
    }
    return 0;
}
void fill_graph(vector<vector<Edge>> &G, int &m){
    int from, to, maxFlow;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> maxFlow;
        from--, to--;
        G[from].push_back({to, 0, maxFlow});
        G[to].push_back({from, maxFlow, maxFlow});
    }
}

int dinic(vector<vector<Edge>> &G, int s, int t) {
    vector<int> distances(G.size(), INF);

    int result = 0;

    while (bfs(G, distances, s, t))
        result += dfs(G, distances, t, INF, s);

    return result;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> G(n);

    fill_graph(G, m);
    cout << dinic(G, 0, n - 1) << endl;


    return 0;
}