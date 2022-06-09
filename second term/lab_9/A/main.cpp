#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum colors {
    white,
    grey,
    black
};

class Element {
public:
    int color = white, value;
    vector<Element *> linked;
};

void DFSVisit(vector<Element> &graph, Element &el, vector<int> &values) {
    el.color = grey;

    for (auto &elem : el.linked)
        if (elem->color == grey) {
            cout << -1; exit(0);
        } else if (elem->color == white)
            DFSVisit(graph, *elem, values);

    values.emplace_back(el.value + 1);
    el.color = black;
}

void DFS(vector<Element> &graph, vector<int> &values) {
    for (auto &elem : graph)
        if (elem.color == white)
            DFSVisit(graph, elem, values);
}

int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    int n, m, a, b;
    cin >> n >> m;
    vector<Element> graph(n);
    vector<int> values;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1].value = a - 1;
        graph[b - 1].value = b - 1;
        graph[a - 1].linked.emplace_back(&graph[b - 1]);
    }

    DFS(graph, values);

    for (int i = values.size() - 1; i >= 0; --i)
        cout << values[i] << " ";

    return 0;
}