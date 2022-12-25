#include <vector>
#include <chrono>
#include <iostream>
using namespace std;
void heapify(vector<int>arr, int n, int root)
{
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;


    if (l < n && arr[l] > arr[largest])
        largest = l;


    if (r < n && arr[r] > arr[largest])
        largest = r;


    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(vector<int>arr, int n)
{
      int n;
    cin >> n;
   int* arr = new arr[n];  
    for (int i = 0; i<n; n++){
        int b;
        b = rand();
        arr[i] = b;
    }
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
     for (int i = 0; i<l;i++){
    cout << arr[i] << endl;
}

int main()
{
  
    heapSort();
    
}

