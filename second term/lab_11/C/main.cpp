#include <iostream>
#include <vector>
#include <set>

#define ll long long
using namespace std;



void dijkstra_algo(vector<vector<pair<ll, ll>>> &graph, vector<ll> &shorted_dist) {
    set<pair<ll, ll>> queue;
    queue.insert({0, 0});

    while (!queue.empty()) {
        pair<ll, ll> temp_vert = *queue.begin();
        queue.erase(queue.begin());

        for (auto const &elem : graph[temp_vert.second])
            if (shorted_dist[temp_vert.second] + elem.first < shorted_dist[elem.second]) {
                queue.erase({shorted_dist[elem.second], elem.second});
                shorted_dist[elem.second] = shorted_dist[temp_vert.second] + elem.first;
                queue.emplace(pair<ll, ll>{shorted_dist[elem.second], elem.second});
            }
    }
}


int main() {
    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);
    ll n, m; cin >> n >> m;
    ll first_vert, second_vert, weight;
    vector<vector<pair<ll, ll>>> graph;
    graph.resize(n);
    vector<ll> shorted_dist;
    shorted_dist.resize(n, LONG_MAX);
    shorted_dist[0] = 0;

    for (auto i = 0; i < m; i++) {
        cin >> first_vert >> second_vert >> weight;
        graph[first_vert - 1].push_back({weight, second_vert - 1});
        graph[second_vert - 1].push_back({weight, first_vert - 1});
    }

    dijkstra_algo(graph, shorted_dist);

    for (auto const &elem : shorted_dist)
        cout << elem << ' ';

    return 0;
}