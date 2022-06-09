#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {

public:
    int key;

    Node* left;
    Node* right;

    Node(int data) {
        key = data;
        left = NULL;
        right = NULL;
    }

};


class Tree {
    Node* root = NULL;

    Node* search(Node* node, int data) {

        if (node == NULL || node->key == data) {
            return node;
        }


        if (data < node->key) {
            return search(node->left, data);
        }
        else {
            return search(node->right, data);
        }

    }

    Node* insert(Node* node, int data) {

        if (node == NULL) {
            return new Node(data);
        }

        if (data < node->key) {
            node->left = insert(node->left, data);
        }
        else {
            node->right = insert(node->right, data);
        }

        return node;
    }

    Node* remove(Node* node, int data) {

        if (node == NULL) {
            return node;
        }

        if (node->key != data) {

            if (data < node->key) {
                node->left = remove(node->left, data);
            }
            else {
                node->right = remove(node->right, data);
            }

        }
        else {

            if (node->left != NULL && node->right != NULL) {
                Node* min = node->right;
                while (min->left != NULL) {
                    min = min->left;
                }

                node->key = min->key;
                node->right = remove(node->right, node->key);

            } else {

                if (node->left != NULL) {
                    node = node->left;
                }
                else {
                    node = node->right;
                }

            }

        }
        return node;
    }

    Node* next(Node* node, int data) {
        Node* temp = node;
        Node* maxterm = NULL;

        while (temp != NULL) {
            if (data >= temp->key) {
                temp = temp->right;
            }
            else {
                maxterm = temp;
                temp = temp->left;
            }
        }

        return maxterm;
    }

    Node* prev(Node* node, int data) {
        Node* temp = node;
        Node* minterm = NULL;

        while (temp != NULL) {
            if (data <= temp->key) {
                temp = temp->left;
            }
            else {
                minterm = temp;
                temp = temp->right;
            }
        }

        return minterm;
    }


public:

    bool exists(int data) {
        return (search(root, data) != NULL);
    }

    void insert(int data) {
        if(!exists(data)) {
            root = insert(root, data);
        }

    }

    void remove(int data) {
        if (exists(data)) {
            root = remove(root, data);
        }
    }

    int next(int data) {
        Node* t = next(root, data);
        if (t == NULL) {
            return NULL;
        }
        else {
            return t->key;
        }

    }


    int prev(int data) {
        Node* t = prev(root, data);
        if (t == nullptr) {
            return NULL;
        } else {
            return t->key;
        }
    }

};



int main() {
    ifstream fin;
    fin.open("bstsimple.in");
    ofstream fout;
    fout.open("bstsimple.out");
    Tree root;
    while (!fin.eof()) {
        string oper;
        int data;
        fin >> oper >> data;
        if (oper == "insert") {
            root.insert(data);
        }

        if (oper == "delete") {
            root.remove(data);
        }

        if (oper == "exists") {
            if (root.exists(data) == false) fout << "false\n";
            else fout << "true\n";
        }

        if (oper == "prev") {
            if (root.prev(data) == NULL) fout << "none\n";
            else fout << root.prev(data) << endl;
        }

        if (oper == "next") {
            if (root.next(data) == NULL) fout << "none\n";
            else fout << root.next( data) << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}