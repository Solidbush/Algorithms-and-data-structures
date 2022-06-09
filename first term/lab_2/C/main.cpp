#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> temp;
long long count_in = 0;

void copy_array(int left, int right)
{
    for (int i = left; i < right; i++)
    {
        arr[i] = temp[i];
    }
}

void merge(int left, int mid, int right)
{
    int i = left;
    int j = mid;

    for (int k = left; k < right; k++) {
        if (j == right || (i < mid && arr[i] <= arr[j]))
        {
            temp[k] = arr[i];
            i++;
        }
        else {
            count_in += mid - i;
            temp[k] = arr[j];
            j++;
        }
    }

    copy_array(left, right);
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
    ifstream fin;
    fin.open("inversions.in");
    string line;
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
    fout.open("inversions.out");
    fout << count_in << endl;
    fout.close();
}