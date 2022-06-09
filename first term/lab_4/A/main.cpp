#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct steck
{
    vector<int> s;
    int top = 0;

    explicit steck(int top)
    {
        s.resize(top + 1);
    }

    void push(int value)
    {
        top += 1;
        s[top] = value;
    }

    int pop(int t)
    {
        if (top > 0)
        {
            return s[t];
        }
    }
};

int main()
{
    int n = 0;
    int t = 0;
    string com;
    ifstream fin;
    fin.open("stack.in");
    ofstream fout;
    fout.open("stack.out");
    fin >> n;
    steck s(n);
    for (int i = 0; i <= n; i++)
    {
        com.clear();
        fin >> com;
        if (com == "+")
        {
            int data;
            fin >> data;
            s.push(data);
            t = s.top;
        }
        if (com == "-")
        {
            if (t > 0)
            {
                fout << s.pop(t) << '\n';
                t -= 1;
                s.top = t;
            }
        }
    }
    fin.close();
    fout.close();
}