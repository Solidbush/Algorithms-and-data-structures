#include <iostream>
#include <fstream>

using namespace std;

int binright(int arr[], int key, int n)
{
    int left = 0;
    int right = n;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (key < arr[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (arr[left - 1] == key)
        return left;
    else
        return -1;
}
int binleft(int arr[], int key, int n)
{
    int left = 0;
    int right = n;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (key > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    if (arr[left] == key)
        return left + 1;
    else
        return -1;
}
int main()
{
    int i, n, j, m;
    ifstream fin;
    fin.open("binsearch.in");
    fin >> n;
    int* arr = new int[n];
    for (i = 0; i < n; i++)
        fin >> arr[i];
    fin >> m;
    int* a = new int[m];
    for (i = 0; i < m; i++)
        fin >> a[i];
    ofstream fout("binsearch.out");
    for (i = 0; i < m; i++) {
        int c = binleft(arr, a[i], n);
        int d = binright(arr, a[i], n);
        fout << c << ' ' << d << '\n';
    }
    fout.close();
}