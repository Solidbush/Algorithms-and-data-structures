#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct ran {
    int place;
    string country;
    string name;
};

vector<ran> arr;
vector<ran> temp;

void copy_array(int left, int right)
{
    for (int i = left; i < right; i++)
    {
        arr[i] = temp[i];
    }
}

bool comp_run(int i, int j)
{
    return arr[i].country <= arr[j].country;
}


void merge(int left, int mid, int right)
{
    int i = left;
    int j = mid;

    for (int k = left; k < right; k++) {
        if (j == right || (i < mid && comp_run(i, j)))
        {
            temp[k] = arr[i];
            i++;
        }
        else {
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
    fin.open("race.in");
    string line;
    getline(fin, line);
    n = atoi(line.c_str());
    arr.resize(n);
    temp.resize(n);
    string temp_country;
    string temp_name;
    for (int i = 0; i < n; i++)
    {
        line.clear();
        temp_country.clear();
        temp_name.clear();
        fin >> temp_country >> temp_name;
        arr[i].country = temp_country;
        arr[i].name = temp_name;
        arr[i].place = i + 1;
    }
    fin.close();
    merge_sort(0, n);
    ofstream fout;
    fout.open("race.out");
    string country = "";
    for (int i = 0; i < n; i++)
    {
        if (country != arr[i].country)
        {
            country = arr[i].country;
            fout << "=== " << arr[i].country << " ===" << endl;
        }
        fout << arr[i].name << endl;
    }
    fout.close();
}