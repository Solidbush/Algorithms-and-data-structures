#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct El {
    int vertex;
    int distance = 0;
    string color = "white";
    vector<int> links;
};

void DFS_Short_Way(vector<El> &graph, El &element) {
    element.color = "grey";
    element.distance = 0;
    queue<int> set_of_vertex;
    set_of_vertex.push(element.vertex);
    while (!set_of_vertex.empty()) {
        int u = set_of_vertex.front();
        for (int i = 0; i < graph[u].links.size(); i++) {
            if (graph[graph[u].links[i]].color == "white") {
                graph[graph[u].links[i]].color = "grey";
                graph[graph[u].links[i]].distance = graph[u].distance + 1;
                set_of_vertex.push(graph[graph[u].links[i]].vertex);
            }
        }
        graph[u].color = "black";
        set_of_vertex.pop();
    }
}

int main() {
    ifstream fin;
    fin.open("pathbge1.in");
    ofstream fout;
    fout.open("pathbge1.out");
    int n, m, start, end;
    fin >> n >> m;
    vector<El> graph(n);

    for (int i = 0; i < m; i++) {
        fin >> start >> end;
        graph[start - 1].vertex = start - 1;
        graph[end - 1].vertex = end - 1;
        graph[start - 1].links.push_back(end - 1);
        graph[end - 1].links.push_back(start - 1);
    }
    fin.close();
    DFS_Short_Way(graph, graph[0]);

    for (int i = 0; i < n; i++)
        fout << graph[i].distance << " ";
    fout.close();
    return 0;
}