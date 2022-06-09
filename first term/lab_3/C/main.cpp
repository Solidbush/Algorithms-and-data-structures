#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sort(vector<string> & arr, int digit)
{
    vector<int> basket((unsigned int) 'z' + 1);

    for (int i = 0; i < arr.size(); i++)
    {
        string s = arr[i];
        basket[s[digit]]++;
    }
    int pos = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        int add_pos = basket[i];
        basket[i] = pos;
        pos += add_pos;
    }

    vector<string> int_to_char;
    int_to_char.resize(arr.size());

    for (int i = 0; i < arr.size(); i++ )
    {
        string s = arr[i];
        char d = s[digit];
        int_to_char[basket[d]++] = s;
    }
    arr = int_to_char;
}

void radix(vector<string> & a, int m, int k)
{
    for (int step = 1; step <= k; step++)
    {
        sort(a, m - step);
    }
}

using namespace std;

int main()
{
    ifstream fin;
    fin.open("radixsort.in");
    int n = 0;
    int m = 0;
    int k = 0;

    fin >> n >> m >> k;

    vector<string> a;
    a.resize(n);

    for (int i = 0; i < n; ++i)
    {
        fin >> a[i];
    }

    fin.close();
    radix(a, m, k);
    ofstream fout;
    fout.open("radixsort.out");

    for (int i = 0; i < a.size(); i++)
    {
        string s = a[i];
        fout << s << '\n';
    }
}