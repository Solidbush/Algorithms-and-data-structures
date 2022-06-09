#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Element {
public:
    int value, component = 0;
    vector<Element *> linked;
    bool used = false;
};

void dfs1(Element &el, vector<int> &rightOrder) {
    el.used = true;

    for (auto &elem : el.linked)
        if (!elem->used)
            dfs1(*elem, rightOrder);

    rightOrder.emplace_back(el.value);
}

void dfs2(Element &el, int comp, vector<Element> &invertedGraph) {
    el.component = comp;

    for (auto &elem : el.linked)
        if (elem->component == 0)
            dfs2(*elem, comp, invertedGraph);
}

int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    int n, m, a, b;
    cin >> n >> m;
    vector<Element> graph(n), invertedGraph(n);
    vector<int> rightOrder;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1].value = a - 1;
        graph[b - 1].value = b - 1;
        graph[a - 1].linked.push_back(&graph[b - 1]);
        invertedGraph[a - 1].value = a - 1;
        invertedGraph[b - 1].value = b - 1;
        invertedGraph[b - 1].linked.push_back(&invertedGraph[a - 1]);
    }

    for (auto &elem : graph)
        if (!elem.used)
            dfs1(elem, rightOrder);

    int comp = 0;
    for (int i = rightOrder.size() - 1; i >= 0; --i) {
        int index = rightOrder[i];
        if (invertedGraph[index].component == 0)
            dfs2(invertedGraph[index], ++comp, invertedGraph);
    }

    cout << comp << endl;
    for (auto &elem : invertedGraph)
        cout << elem.component << ' ';

    return 0;
}