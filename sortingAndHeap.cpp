#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] < a[i])
                swap(a[i], a[j]);
        }
    }
}
void selectionSort(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        int idx = i, j = i + 1;
        while (j < a.size())
        {
            if (a[j] < a[idx])
            {
                idx = j;
            }
            j++;
        }
        if (idx != i)
        {
            swap(a[i], a[idx]);
        }
    }
}
void insertionSort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int j = i - 1;
        int value = a[i];
        while (j >= 0 && value < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = value;
    }
}
void Merge(int low, int mid, int high, vector<int> &a)
{
    int size = high - low + 1;
    int store[size];
    int idx = 0, i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            store[idx++] = a[i++];
        else
            store[idx++] = a[j++];
    }
    while (i <= mid)
        store[idx++] = a[i++];
    while (j <= high)
        store[idx++] = a[j++];

    idx = 0;
    i = low;

    while (i <= high)
    {
        a[i++] = store[idx++];
    }
}
void mergeSort(vector<int> &a, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) >> 1;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    Merge(low, mid, high, a);
}
int partition(int low, int high, vector<int> &a)
{
    int pivot = a[high];
    int i = low - 1;
    int j = low;
    while (j < high)
    {
        if (a[j] < pivot)
        {
            swap(a[++i], a[j]);
        }
        j++;
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}
void quickSort(int low, int high, vector<int> &a)
{
    if (low >= high)
        return;
    int i = partition(low, high, a);
    quickSort(low, i - 1, a);
    quickSort(i + 1, high, a);
}
void heapify(int i, int n, vector<int> &a)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(largest, n, a);
    }
}
void builtHeap(vector<int> &a)
{
    int n = a.size();
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(i, n, a);
    }
}
void heapSort(vector<int> &a)
{
    builtHeap(a);
    int i = a.size() - 1;
    while (i > 0)
    {
        swap(a[i], a[0]);
        i--;
        heapify(0, i + 1, a);
    }
}

class Heap
{
    vector<int> v;

public:
    void insert(int value)
    {
        v.push_back(value);
        int i = v.size() - 1;
        while (i > 0)
        {
            int parent = i / 2;
            if (v[parent] < v[i])
            {
                swap(v[i], v[parent]);
                i = parent;
            }
            else
                break;
        }
    }

    void erase();

    void display()
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
void Heap::erase()
{
    if (v.size() == 0)
    {
        cout << "No elemet is to be deleted.\n";
        return;
    }
    v[0] = v.back();
    v.pop_back();
    int i = 0, n = v.size();
    while (i < n)
    {
        int largest = 2 * i + 1;
        int right = largest + 1;
        if (right < n && v[right] > v[largest])
            largest = right;
        if (v[largest] > v[i])
        {
            swap(v[largest], v[i]);
            i = largest;
        }
        else
            break;
    }
}
int main()
{
    Heap h;
    int i = 5;
    while (i--)
    {
        int val;
        cin >> val;
        h.insert(val);
        h.display();
    }
    h.erase();
    h.display();
    return 0;
}