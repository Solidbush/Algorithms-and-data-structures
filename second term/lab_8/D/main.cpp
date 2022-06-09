#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct Element {
    int component, vertex;
    vector<int> links;
    bool used = 0;
};

void DFS(int index, int c_num, vector<Element> &graph) {
    graph[index].used = true;
    graph[index].component = c_num;

    for (int i = 0; i < graph[index].links.size(); i++)
        if (!graph[graph[index].links[i]].used)
            DFS(graph[index].links[i], c_num, graph);

}

int main() {
    ifstream fin;
    fin.open("components.in");
    ofstream fout;
    fout.open("components.out");
    int n, m, start, end, c_num;
    c_num = 1;
    fin >> n >> m;
    vector<Element> graph(n);

    for (int i = 0; i < m; i++) {
        fin >> start >> end;
        graph[start - 1].vertex = start - 1;
        graph[end - 1].vertex = end - 1;
        graph[start - 1].links.push_back(end - 1);
        graph[end - 1].links.push_back(start - 1);

    }
    fin.close();
    for (int i = 0; i < n; i++)
        if (!graph[i].used)
            DFS(i, c_num++, graph);

    fout << c_num - 1 << "\n";
    for (int i = 0; i < n; i++)
        fout << graph[i].component << " ";
    fout.close();
    return 0;
}