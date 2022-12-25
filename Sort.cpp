#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

void InsertionSort(){
  int n;
        cin >> n;
        int* arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            array[i] = rand();
        }
        for (int k = 1; k < n; k++)
        {
            int temp = arr[k];
            int j = k - 1;
            while (j >= 0 && temp <= array[j])
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }

}

int main()
{
   InsertionSort();     
}






