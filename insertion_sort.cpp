#include <bits/stdc++.h>
using namespace std;
int size;

void insertion_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
	{
		int index = i-1;
		int key = arr[i];
		while(index>=0 && arr[index]>key)
		{
			arr[index+1] = arr[index];
			index--;
		}
		arr[index+1]=key;
	}

}

int main()
{
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
		cin>>arr[i];
    insertion_sort(arr,size);
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	return 0;
}
