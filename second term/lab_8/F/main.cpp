#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");

    int n, m;
    fin >> m >> n;
    vector <char> ans;
    Point start{}, finish{};
    vector<vector<int>> matrix(m + 2, vector<int> (n + 2));
    for(int i = 0; i < m + 2; i++) {
        matrix[i][0] = -1;
        matrix[i][n + 1] = -1;
    }
    for(int i = 0; i < n + 2; i++) {
        matrix[0][i] = -1;
        matrix[m + 1][i] = -1;
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char type;
            fin >> type;
            switch (type) {
                case '.':
                    matrix[i + 1][j + 1] = 0;
                    break;
                case '#':
                    matrix[i + 1][j + 1] = -1;
                    break;
                case 'S':
                    start.x = j + 1;
                    start.y = i + 1;
                    matrix[i + 1][j + 1] = 1;
                    break;
                case 'T':
                    finish.x = j + 1;
                    finish.y = i + 1;
                    matrix[i + 1][j + 1] = 0;
                    break;
            }
        }
    }
    fin.close();
    Point u{};
    queue <Point> q;
    q.push(start);
    while(!q.empty() && ((u.x != finish.x) || (u.y != finish.y))) {
        Point v = q.front();
        q.pop();
        if(!matrix[v.y][v.x - 1]) {
            matrix[v.y][v.x - 1] = matrix[v.y][v.x] + 1;
            u.x = v.x - 1;
            u.y = v.y;
            q.push(u);
        }
        if(!matrix[v.y - 1][v.x]) {
            matrix[v.y - 1][v.x] = matrix[v.y][v.x] + 1;
            u.x = v.x;
            u.y = v.y - 1;
            q.push(u);
        }
        if(!matrix[v.y + 1][v.x]) {
            matrix[v.y + 1][v.x] = matrix[v.y][v.x] + 1;
            u.x = v.x;
            u.y = v.y + 1;
            q.push(u);
        }
        if(!matrix[v.y][v.x + 1]) {
            matrix[v.y][v.x + 1] = matrix[v.y][v.x] + 1;
            u.x = v.x + 1;
            u.y = v.y;
            q.push(u);
        }
    }
    if(matrix[finish.y][finish.x] == 0) {
        fout << "-1" << endl;
    }
    else {
        int pos = matrix[finish.y][finish.x];
        while(finish.y != start.y || finish.x != start.x) {
            if(pos - 1 == matrix[finish.y + 1][finish.x]) {
                finish.y++;
                ans.push_back('U');
            } else if(pos - 1 == matrix[finish.y][finish.x + 1]) {
                finish.x++;
                ans.push_back('L');
            } else if(pos - 1 == matrix[finish.y - 1][finish.x]) {
                finish.y--;
                ans.push_back('D');
            } else if(pos - 1 == matrix[finish.y][finish.x - 1]) {
                finish.x--;
                ans.push_back('R');
            }
            pos--;
        }
        reverse(ans.begin(), ans.end());
        fout << ans.size();
        fout << endl;
        for(auto letter : ans)
            fout << letter;
        fout << endl;
    }
    fout.close();
    return 0;
}