#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cfloat>
#include <fstream>
#define edge pair<double, double>

using namespace std;

class Vertex {
public:
    int id;
    double x, y;
    bool used = false;
    vector<double> distances;
    inline Vertex() = default;

    inline Vertex(const double &x_, const double &y_, const int &id_) : x(x_), y(y_), id(id_) {};
};

inline double setDist(const edge &a, const edge &b) {
    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

void prim_algo(vector<Vertex> &graph, vector<double> &min_dist, vector<double> &included, double &weight) {
    ofstream fout;
    fout.open("spantree.out");
    min_dist[0] = 0;
    for (int i = 0; i < graph.size(); ++i) {
        Vertex *cur = nullptr;
        for (auto &elem : graph)
            if (!elem.used && (cur == nullptr || min_dist[elem.id] < min_dist[cur->id]))
                cur = &elem;
        cur->used = true;
        if (included[cur->id] != -1)
            weight += graph[cur->id].distances[included[cur->id]];

        for (auto &elem : graph)
            if (cur->distances[elem.id] < min_dist[elem.id]) {
                min_dist[elem.id] = cur->distances[elem.id];
                included[elem.id] = cur->id;
            }
    }
    fout << setprecision(10) << weight;
    fout.close();
}

inline void set_distances(vector<Vertex> &graph) {
    for (auto &elem : graph)
        for (auto &second_elem : graph)
            elem.distances.push_back(setDist(edge(elem.x, elem.y), edge(second_elem.x, second_elem.y)));
}

int main() {
    ifstream fin;
    fin.open("spantree.in");
    int count;
    fin >> count;
    double x_, y_, weight = 0;
    vector<Vertex> graph(count);
    vector<double> min_dist(count, FLT_MAX), included(count, -1);

    for (int i = 0; i < count; ++i) {
        fin >> x_ >> y_;
        graph[i] = Vertex(x_, y_, i);
    }
    fin.close();

    set_distances(graph);
    prim_algo(graph, min_dist, included, weight);

    return 0;
}