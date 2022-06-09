#include <fstream>
#include <vector>

using namespace std;

struct vertex
{
    int left;
    int key;
    int right;
};

void pass_bst(vector<vertex> &bst, vector<int> &key, int vert)
{
    if (vert != -1)
    {
        pass_bst(bst, key, bst[vert].left);

        key.push_back(bst[vert].key);

        pass_bst(bst, key, bst[vert].right);
    }
}

bool orderd_bst(vector<int> &key)
{
    for(int i = 1; i < key.size(); i++)
    {
        if (key[i - 1] >= key[i])
        {
            return false;
        }
    }

    return true;
}

bool bst_is(vector<vertex> &bst)
{
    vector<int> key;

    pass_bst(bst, key, 0);

    return orderd_bst(key);
}

int main()
{
    ifstream fin;
    fin.open("check.in");

    int n;
    fin >> n;

    vector<vertex> bst;
    bst.resize(n);

    for(int i = 0; i < n; i++)
    {
        fin >> bst[i].key;
        fin >> bst[i].left;
        fin >> bst[i].right;

        bst[i].left--;
        bst[i].right--;
    }
    fin.close();

    ofstream fout;
    fout.open("check.out");

    if ((n == 0) ||  (bst_is(bst)))
    {
        fout << "YES";
    }
    else
    {
        fout << "NO";
    }
    fout.close();
    return 0;
}