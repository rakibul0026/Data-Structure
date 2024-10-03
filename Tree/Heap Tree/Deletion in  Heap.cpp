#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;      
    int total_size; 

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }
        arr[size] = value;
        int index = size;
        size++;

        
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << value << " is inserted into the heap\n";
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
 /*Largest will store of the element which is the greater between 
        parent,left child and Right child */
      
        if (left < size && arr[left] > arr[largest])
            largest = left;

       
        if (right < size && arr[right] > arr[largest])
            largest = right;

       
        if (largest != index)
        {
            swap(arr[index], arr[largest]);

           
            Heapify(largest);
        }
    }

   
    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap Underflow\n";
            return;
        }
        cout << arr[0] << " deleted from the heap\n";

      
        arr[0] = arr[size - 1];
        size--;

       
        Heapify(0);
    }
};

int main()
{
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.insert(12);

  
    H1.print();

   
    H1.deleteRoot();
    cout<<"After the delete opration\n";
    H1.print();

    return 0;
}
