#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;

int main()
{
    int n;
    ifstream fin;
    fin.open("antiqs.in");
    string line;
    getline(fin, line);
    n = atoi(line.c_str());
    arr.resize(n);
    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = i;
    }
    fin.close();
    for (int i = 0; i < n; i++)
    {
        swap(arr[i], arr[i / 2]);
    }
    ofstream fout;
    fout.open("antiqs.out");
    for (int i = 0; i < n; i++)
    {
        fout << arr[i] << " ";
    }
    fout.close();
}