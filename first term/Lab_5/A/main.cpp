#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

class HashTable {
private:
    static const int hash_size = 50000;
    list<pair<int, int>> table[hash_size];

public:
    int hash_func(int key);
    void insert(int key, int value);
    void remove(int key);
    bool search(int key, int value);
};

int HashTable::hash_func(int key) {
    return abs(key % hash_size);
}

void HashTable::insert(int key, int value) {
    int hash_value = hash_func(key);
    auto& cell = table[hash_value];
    auto btr = begin(cell);
    bool KeyExists = false;
    for (; btr != end(cell); btr++)
    {
        if (btr->first == key)
        {
            KeyExists = true;
            btr->second = value;
            break;
        }
    }
    if (!KeyExists){
        cell.emplace_back(key, value);
    }
    return;
}

bool HashTable::search(int key, int value) {
    int hash_value = hash_func(key);
    auto& cell = table[hash_value];
    auto btr = begin(cell);
    bool ValueExists = false;
    for (; btr != end(cell); btr++)
    {
        if (btr->second == value)
        {
            ValueExists = true;
            btr->second = value;
            break;
        }
    }
    return ValueExists;
}

void HashTable::remove(int key) {
    int hash_value = hash_func(key);
    auto& cell = table[hash_value];
    auto btr = begin(cell);
    bool KeyExists = false;
    for (; btr != end(cell); btr++)
    {
        if (btr->first == key)
        {
            KeyExists = true;
            btr = cell.erase(btr);
            break;
        }
    }
    return;
}

int main() {
    HashTable HT;
    ifstream fin;
    fin.open("set.in");
    ofstream fout;
    fout.open("set.out");
    while (!fin.eof()) {
        string command;
        int value;
        fin >> command >> value;
        if (command == "insert") {
            HT.insert(value, value);
        }
        if (command == "delete")
            HT.remove(value);
        if (command == "exists") {
            if (HT.search(value, value) == 1)
                fout << "true\n";
            else
                fout << "false\n";
        }
    }
    fin.close();
    fout.close();
}