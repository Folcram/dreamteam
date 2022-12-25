#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

int main()
{
   
        int n;
        cin >> n;
        int* array = new int[n];

        for (int i = 0; i < n; i++)
        {
            array[i] = rand();
        }
        for (int k = 1; k < n; k++)
        {
            int temp = array[k];
            int j = k - 1;
            while (j >= 0 && temp <= array[j])
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            cout << array[i] << endl;
        }
   }






