#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> temp;

void copy_arr(int left, int right)
{
    for (int i = left; i < right; ++i)
    {
        arr[i] = temp[i];
    }
}

void merge(int left, int mid, int right)
{
    int i = left;
    int j = mid;
    for (int k = left; k < right; ++k) {
        if (j == right || (i < mid && arr[i] <= arr[j])) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
    }
    copy_arr(left, right);
}

void merge_sort(int left, int right)
{
    if (right <= left + 1)
    {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid, right);
    merge(left, mid, right);
}

int main()
{
    int n;
    string line;
    ifstream fin;
    fin.open("sort.in");
    getline(fin, line);
    n = atoi(line.c_str());
    arr.resize(n);
    temp.resize(n);
    for (int i = 0; i < n; i++)
    {
        line.clear();
        fin >> line;
        arr[i] = atoi(line.c_str());
    }
    fin.close();
    merge_sort(0, n);
    ofstream fout;
    fout.open("sort.out");
    for (int i = 0; i < arr.size(); i++)
    {
        fout << arr[i] << " ";
    }
    fout.close();
}