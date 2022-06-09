#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;

struct Node
{
    int key;
    int children[2];

    Node(int key, int left, int right) : key(key)
    {
        children[0] = left;
        children[1] = right;
    }
};

int height_of_tree(vector<Node*> & tree)
{
    if (tree.empty())
    {
        return 0;
    }

    int max_distance = 0;
    queue<pair<Node*, int>> queue;
    queue.push(make_pair(tree[0], 1));

    while (!queue.empty())
    {
        Node* Next_node = queue.front().first;
        int long_to_top = queue.front().second;
        max_distance = max(long_to_top, max_distance);
        for (auto child : Next_node->children)
        {
            if (child != -1)
            {
                queue.push(make_pair(tree[child], long_to_top + 1));
            }
        }
        queue.pop();
    }

    return max_distance;
}

int main()
{
    ifstream input;
    input.open("height.in");

    int n;
    input >> n;
    vector<Node*> nodes;

    for (int i = 0; i < n; i++)
    {
        int key;
        int left, right;
        input >> key >> left >> right;
        nodes.push_back(new Node(key, left-1, right-1));
    }
    ofstream output;
    output.open("height.out");
    output << height_of_tree(nodes);

    return 0;
}