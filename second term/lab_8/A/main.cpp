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
    int a, b;
    fin >> n >> m;
    int **array = new int * [n]();
    for (int i = 0; i < n; i++)
        array[i] = new int [n]();
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        if (array[a-1][b-1] != 1)
            array[a-1][b-1] = 1;
    }
    fin.close();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fout << array[i][j] << " ";
        fout << endl;
    }
    fout.close();
    for (int i = 0; i < n; i++)
        delete [] array[i];
    delete [] array;
    return 0;
}