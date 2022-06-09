#include <iostream>
#include <stack>
#include <vector>

using namespace std;

enum colors { white, grey, black };

class Element {
public:
    int value, color = white;
    vector<Element *> linked;
};

bool DFS(vector<Element> &graph, Element &el, stack<int> &order) {
    el.color = grey;

    for (auto &elem : el.linked) {
        if (elem->color == white)
            if (!DFS(graph, *elem, order))
                return false;

        if (elem->color == grey)
            return false;
    }

    order.push(el.value);
    el.color = black;
    return true;
}

int main() {
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;
    vector<Element> graph(n);
    stack<int> sort;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1].value = a - 1;
        graph[b - 1].value = b - 1;
        graph[a - 1].linked.emplace_back(&graph[b - 1]);
    }

    for (auto &elem : graph)
        if (elem.color == white)
            DFS(graph, elem, sort);

    bool isHamiltonian = true;

    while (sort.size() > 1 && isHamiltonian) {
        a = sort.top();
        sort.pop();
        isHamiltonian = false;

        for (auto &index : graph[a].linked)
            if (index->value == sort.top())
                isHamiltonian = true;
    }

    if (isHamiltonian == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}