#ifndef HEAP_H
#define HEAP_H
#include <Task.h>
#include <iostream>

using namespace std;

template <class T>
class Heap
{
private:
    T* heapElements;
    int Size;
    int currentSize;
public:
    Heap ()
    {
        heapElements = new T[10];
        Size = 10;
        currentSize = 0;
    };
    Heap (T* heapElements, int Size)
    {
        heapElements = heapElements;
        this->Size = Size;
        currentSize = Size;
    };
    void add(T elem)
    {
        if(currentSize == Size)
        {
            Size = (Size * 2) + 1;
            T *x = new T[Size];
            for(int i = 0; i < currentSize; i++)
                x[i] = heapElements[i];
            heapElements = x;
        }
        heapElements[currentSize] = elem;
        currentSize++;
        sortHeap(currentSize);
    };
    void Swap(T *x, T *y )
    {
        T z = *x;
        *x = *y;
        *y = z;
    };
    void heapify(int n,int i)
    {
        int l=2*i+1;
        int r=2*i+2;
        int Max=i;
        if(l<n&&heapElements[l]<heapElements[Max])
            Max=l;
        if(r<n&&heapElements[r]<heapElements[Max])
            Max=r;

        if(Max != i)
        {
            Swap(&heapElements[i],&heapElements[Max]);
            heapify(n,Max);
        }
    };
    void buildHeap(int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);
    };
    void sortHeap(int n)
    {

        buildHeap(n);
        for (int i = n-1; i >=0; i--)
        {
            Swap(&heapElements[0], &heapElements[i]);
            heapify(i, 0);
        }

    };
    Task removeRoot()
    {
        currentSize--;
        Swap(&heapElements[0],&heapElements[currentSize]);
        sortHeap(currentSize);
        return heapElements[currentSize];
    };
    Task Search (string taskName)
    {
        for(int i = 0; i < currentSize; i++)
            if(heapElements[i] == taskName)
                return heapElements[i];
        cout<<"there is no element has this item"<<endl;
    };
    T* heapSort()
    {
        return heapElements;
    };
    void print()
    {
        for(int i = 0; i < currentSize; i++)
        {
            cout<<heapElements[i]<<endl;
        }
    };
    int getCurrentSize()
    {
        return currentSize;
    };
};

#endif // HEAP_H
