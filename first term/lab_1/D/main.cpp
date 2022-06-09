#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string line;
    ifstream fin;
    fin.open("smallsort.in");
    int n;
    int i = 0, j = 0;
    string str;
    getline(fin, line);
    n = atoi(line.c_str());
    int temp;
    int *arr = new int[n];
    while (!fin.eof())
    {
        str = "";
        fin >> str;
        arr[i] = atoi(str.c_str());
        i++;
    }
    cout << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    fin.close();
    ofstream fout;
    fout.open("smallsort.out");
    for (i = 0; i < n; i++) {
        fout << arr[i] << " ";
    }
    fout.close();
    cout << endl;
}