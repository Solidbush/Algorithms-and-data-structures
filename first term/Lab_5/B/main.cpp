#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

class HashTable {
private:
    static const int hash_size = 2;
    list<pair<string, string>> table[hash_size];

public:
    int hash_func(string key);
    void insert(string key, string value);
    void remove(string key);
    string search(string key);
};

int HashTable::hash_func(string key) {
    return key.length() % hash_size;
}

void HashTable::insert(string key, string value) {
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
        cell.emplace_front(key, value);
    }
    return;
}

string HashTable::search(string key) {
    int hash_value = hash_func(key);
    auto& cell = table[hash_value];
    auto btr = begin(cell);
    bool KeyExists = false;
    for (; btr != end(cell); btr++)
    {
        if (btr->first == key)
        {
            KeyExists = true;
            return btr->second;
        }
    }
    if (!KeyExists)
    {
        return "none";
    }
}

void HashTable::remove(string key) {
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    HashTable HT;
    ifstream fin;
    fin.open("map.in");
    ofstream fout;
    fout.open("map.out");
    while (!fin.eof()) {
        string command;
        fin >> command;
        if (command == "put") {
            string value;
            string key;
            fin >> key >> value;
            HT.insert(key, value);
        }
        if (command == "delete") {
            string key;
            fin >> key;
            HT.remove(key);
        }
        if (command == "get") {
            string key;
            fin >> key;
            if (HT.search(key) != "none")
                fout << HT.search(key) << "\n";
            else
                fout << "none\n";
        }
    }
}