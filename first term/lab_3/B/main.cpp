#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    ifstream fin;
    fin.open("sort.in");
    int n;
    fin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        fin >> arr[i];
    }
    fin.close();
    heapSort(arr, n);
    ofstream fout;
    fout.open("sort.out");
    for (int i=0; i<n;i++)
    {
        fout << arr[i] << " ";
    }
    fout.close();
}