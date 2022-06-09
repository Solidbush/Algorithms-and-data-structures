#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct queue
{
    vector<int> q;
    int l = 0;
    int r = 0;

    explicit queue(int size)
    {
        q.resize(size + 1);
    }

    void push(int value)
    {
        q[r++] = value;
    }

    int pop()
    {
        return q[l++];
    }
};

int main()
{
    ifstream fin;
    fin.open("queue.in");
    ofstream fout;
    fout.open("queue.out");

    int m = 0;
    string line;
    fin >> m;
    queue q(m);
    string com;
    int data;

    for (int i = 0; i < m; ++i)
    {
        fin >> com;

        if (com == "+")
        {
            int data;
            fin >> data;
            q.push(data);
        }
        else if (com == "-")
        {
            fout << q.pop() << '\n';
        }
    }
    fin.close();
    fout.close();
}