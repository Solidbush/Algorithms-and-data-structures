#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    int n;
    bool flag = true;
    fin >> n;
    int **array = new int* [n]();
    for (int i = 0; i < n; i++)
        array[i] = new int [n]();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fin >> array[i][j];
    }
    fin.close();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if ((i == j) && (array[i][j] != 0))
            {
                flag = false;
                break;
            }
            if ((array[i][j] != array[j][i]) || ((i == j) && (array[i][j] == 1)))
            {
                flag = false;
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