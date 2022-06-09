#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("turtle.in");
    int h, w;
    fin >> h >> w;
    string line;

    int **arr = new int* [h];
    for (int i = 0; i < h; i++)
        arr[i] = new int [w];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            line.clear();
            fin >> line;
            arr[i][j] = atoi(line.c_str());
        }
    }
    fin.close();
    for (int i = h - 1; i >= 0; i--) {
        for (int j = 0; j < w; j++) {
            if ((i + 1 >= h) && (j - 1 >= 0))
                arr[i][j] += arr[i][j - 1];
            if ((i + 1 < h) && (j - 1 < 0))
                arr[i][j] += arr[i + 1][j];
            if ((i + 1 < h) && (j - 1 >= 0)) {
                if (arr[i + 1][j] > arr[i][j - 1])
                    arr[i][j] += arr[i + 1][j];
                else
                    arr[i][j] += arr[i][j - 1];
            }
        }
    }
    ofstream fout;
    fout.open("turtle.out");
    fout << arr[0][w - 1];
    fout.close();

}