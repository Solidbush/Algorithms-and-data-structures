#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    int n;
    int m;
    bool flag = false;
    fin >> n >> m;
    int a, b;
    int **array = new int* [n]();
    for (int i = 0; i < n; i++)
        array[i] = new int [n]();
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        array[a - 1][b - 1] += 1;
    }
    fin.close();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (((i != j) && ((array[i][j] > 0) && (array[j][i] > 0))) || (array[i][j] > 1))
            {
                flag = true;
                break;
            }
        }
    if (flag == 1)
        fout << "YES" << endl;
    else
        fout << "NO" << endl;
    fout.close();
    for (int i = 0; i < n; i++)
        delete [] array[i];
    delete [] array;
    return 0;
}