#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line;
    ifstream fin;
    fin.open("sortland.in");
    int n;
    int i = 0, j = 0;
    getline(fin, line);
    n = atoi(line.c_str());
    float *arr = new float[n];
    float *arr_sort = new float[n];
    while (!fin.eof())
    {
        line.clear();
        fin >> line;
        arr[i] = atof(line.c_str());
        arr_sort[i] = arr[i];
        i++;

    }
    fin.close();
    float temp;
    for (i = 1; i < n; i++)
    {
        temp = arr_sort[i];
        j = i - 1;
        while ((j >= 0) && (arr_sort[j] > temp))
        {
            arr_sort[j + 1] = arr_sort[j];
            j = j - 1;
        }
        arr_sort[j + 1] = temp;
    }
    int ans[3];
    for (i = 0; i < n; i++) {
        if (arr[i] == arr_sort[0]) {
            ans[0] = i + 1;
        }
        if (arr[i] == arr_sort[n / 2]) {
            ans[1] = i + 1;

        }
        if (arr[i] == arr_sort[n - 1]) {
            ans[2] = i + 1;
        }
    }
    cout << endl;
    ofstream fout;
    fout.open("sortland.out");
    for (i = 0; i < 3; i++) {
        fout << ans[i] << " ";
    }
    fout.close();
    cout << endl;
}