#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main() {
    ifstream fin;
    fin.open("isheap.in");
    int n;
    bool a = true;
    fin >> n;

    vector<int> arr;
    arr.resize(n+1);
    for (int i=1; i <= n; i++)
    {
        fin >> arr[i];
    }
    fin.close();
    for (int i = 1; i <= n; i++)
    {
        if (2 * i <= n)
            if (arr[i] > arr[2 * i])
                a = false;
        if (2 * i + 1 <= n)
            if (arr[i] > arr[2 * i + 1])
                a = false;
    }
    ofstream fout;
    fout.open("isheap.out");
    if (a)
        fout << "YES\n";
    else
        fout << "NO\n";

}