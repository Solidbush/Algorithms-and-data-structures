#include <iostream>
#include <vector>
#include <map>

using namespace std;

static unsigned int COMPONENT = 0;

enum colors {
    white,
    grey,
    black
};

class Element {
public:
    int unsigned color = white, value, component;
    map<Element *, int> linked;
};

void DFSVisit(vector<Element> &graph, Element &el, map<int, vector<int>> &values) {
    if (el.color == white)
        el.color = grey;
    el.component = COMPONENT;

    for (auto &elem : el.linked)
        if (elem.first->color == white) {
            DFSVisit(graph, *elem.first, values);
        } else if (elem.first->color == grey && elem.first->value != el.value) {
            values[el.component].emplace_back(el.value + 1);
            values[el.component].emplace_back(elem.first->value + 1);
            elem.first->color = black;
            el.color = black;
            DFSVisit(graph, *elem.first, values);
        }
    el.color = black;
}

void DFS(vector<Element> &graph, map<int, vector<int>> &values) {
    for (auto &elem : graph)
        if (elem.color == white && values.empty()) {
            elem.component = ++COMPONENT;
            DFSVisit(graph, elem, values);
        }
}

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    unsigned int n, m, a, b;
    cin >> n >> m;
    vector<Element> graph(n);
    map<int, vector<int>> values;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1].value = a - 1;
        graph[b - 1].value = b - 1;
        graph[a - 1].linked[&graph[b - 1]] += 1;
    }

    DFS(graph, values);

    map<int, bool> used;
    for (auto &i : values) {
        if (i.second.size() >= 2) {
            cout << "YES" << endl;
            for (auto &j : i.second) {
                if (!used[j])
                    cout << j << " ";
                used[j] = true;
            }
            break;
        } else i.second.clear();
    }

    int flag = 0;
    for (auto const &i : values)
        if (i.second.empty())
            flag++;
    if (flag == values.size())
        cout << "NO";

    return 0;
}