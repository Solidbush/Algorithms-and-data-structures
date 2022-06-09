#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
enum colors {
    white, grey, black
};

class Element {
public:
    int color = white, value;
    vector<Element *> linked, linkedOut;
    bool isWin = false;
};

void DFSVisit(vector<Element> &graph, Element &el, vector<int> &topSorted) {
    el.color = grey;

    for (auto &elem : el.linked) {
        if (elem->linkedOut.empty())
            elem->isWin = false;

        if (elem->color == white)
            DFSVisit(graph, *elem, topSorted);
    }

    topSorted.emplace_back(el.value);
    el.color = black;
}

int main() {
    ifstream fin;
    fin.open("game.in");
    int n, m, a, b, start;
    fin >> n >> m >> start;
    vector<Element> graph(n);
    vector<int> topSorted;

    for (int i = 0; i < m; ++i) {
        fin >> a >> b;
        graph[a - 1].value = a - 1;
        graph[b - 1].value = b - 1;
        graph[a - 1].linked.emplace_back(&graph[b - 1]);
        graph[a - 1].linkedOut.emplace_back(&graph[b - 1]);
    }
    fin.close();
    ofstream fout;
    fout.open("game.out");
    DFSVisit(graph, graph[start - 1], topSorted);

    for (auto &index : topSorted)
        for (auto &elem : graph[index].linked)
            if (!graph[index].isWin)
                !elem->isWin ? graph[index].isWin = true : graph[index].isWin = false;

    if(graph[start - 1].isWin == true)
        fout << "First player wins";
    else
        fout << "Second player wins";

    fout.close();
    return 0;
}