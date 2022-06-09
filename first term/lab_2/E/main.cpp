#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> arr;

void search(int left, int right, int k)
{
    int i = left;
    int j = right;
    int mid = arr[(left + right) / 2];
    while (i <= j)
    {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;
        if (i <= j)
            swap(arr[i++], arr[j--]);
    }
    if ((left < j) && (k <= j))
        search(left, j, k);
    if ((i < right) && (k >= i))
        search(i, right, k);
}


int main()
{
    ifstream fin;
    fin.open("kth.in");
    int n, k;
    fin >> n >> k;
    int A, B, C, a_1, a_2;
    fin >> A >> B >> C >> a_1 >> a_2;
    fin.close();
    arr.resize(n);
    arr[0] = a_1;
    arr[1] = a_2;
    for (int i = 2; i < n; i++)
    {
        arr[i] = (A * arr[i - 2] + B * arr[i - 1] + C);
    }
    search(0, arr.size() - 1, k - 1);
    ofstream fout;
    fout.open("kth.out");
    fout << arr[k - 1];
    fout.close();
}