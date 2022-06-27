#include<bits/stdc++.h>
using namespace std;

int size = 0;

void max_heapify(int A[],int i,int n)
{
    int left_child = 2*i+1;
    int right_child = 2*i+2;

    int largest = i;
    if(left_child<n && A[left_child]>A[i])
        largest = left_child;

    if(right_child<n && A[right_child]>A[largest])
        largest = right_child;

    if(largest != i)
    {
        swap(A[i],A[largest]);
        max_heapify(A,largest,n);
    }
}

void build_max_heap(int A[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        max_heapify(A,i,n);
}

void heap_sort(int A[],int n)
{
    build_max_heap(A,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(A[0],A[i]);
        max_heapify(A,0,i);
    }
}


int main()
{
    cin>>size;
    int A[size];
    int print[size];
    for(int i=0;i<size;i++)
        cin>>A[i];

    heap_sort(A,size);

    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
    return 0;
}
