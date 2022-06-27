#include <bits/stdc++.h>
using namespace std;
int size=0;

int partition(int A[],int left,int right)
{
    int x = A[right];
    int i = left-1;
    int t=0;
    for(int j=left;j<right;j++)
    {
        if(A[j] < x )
        {
            i++;
            t++;
            swap(A[i],A[j]);
        }
    }
    t++;
    swap(A[i+1],A[right]);
    cout<<"t = "<<t<<endl;
    return i+1;
}

void quicksort(int A[],int left,int right)
{
    if(left<right)
    {
        int pivot=partition(A,left,right);
        quicksort(A,left,pivot-1);
        quicksort(A,pivot+1,right);
    }
}

int main()
{
    cin>>size;
    int A[size];
    for(int i=0;i<size;i++)
        cin>>A[i];
    quicksort(A,0,size-1);
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
	return 0;
}
