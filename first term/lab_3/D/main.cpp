#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct heap_element{
    int value;
    int number;
};

void HeapifyUp(heap_element arr[], int count_arr)
{
    int last_index = count_arr;
    while (last_index != 0 && arr[last_index].value < arr[(last_index - 1)/2].value)
    {
        int parentIndex = (last_index - 1)/2;
        swap(arr[parentIndex], arr[last_index]);
        last_index = parentIndex;
    }
}

void push_in(heap_element arr[], int value, int number, int N)
{
    arr[N].value = value;
    arr[N].number = number;
}
void sift_down(heap_element arr[], int i, int N)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < N && arr[l].value < arr[i].value)
        smallest = l;

    if (r < N && arr[r].value < arr[smallest].value)
        smallest = r;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        sift_down(arr, smallest, N);
    }
}

void restart(heap_element arr[], int N)
{
    heap_element temp = arr[N-1];
    arr[0] = temp;
    arr[N - 1].value = 0;
    arr[N - 1].number = 0;
    sift_down(arr, 0, N - 1);

}

int find(heap_element arr[], int number_find, int N)
{
    for(int i = 0; i < N; i++)
        if (arr[i].number == number_find)
            return  i;
}

int main() {
    ifstream fin;
    fin.open("priorityqueue.in");
    ofstream fout;
    fout.open("priorityqueue.out");

    heap_element arr[1000000];
    int line_number = 0;
    int count_arr = 0;
    while (!fin.eof())
    {
        line_number++;
        string operation;
        fin >> operation;

        if (operation == "push")
        {
            int key;
            fin >> key;
            push_in(arr, key, line_number, count_arr);
            count_arr++;
            HeapifyUp(arr, count_arr - 1);
        }
        else if (operation == "extract-min")
        {
            if (count_arr <= 0)
                fout << "*" << endl;
            else
            {
                fout << arr[0].value << endl;
                restart(arr, count_arr);
                count_arr--;
            }
        }
        else if (operation == "decrease-key")
        {
            int number, new_value;
            fin >> number >> new_value;
            int found = find(arr, number, count_arr);
            push_in(arr, new_value, number, found);
            HeapifyUp(arr, found);
        }
    }
    fin.close();
    fout.close();
}