#include <stdio.h>
int size;

void quicksort(int left,int right,int arr[])
{
	int i=left,j=right,pivot=arr[left];
	if(left>right)
	{
		return;
	}
	while(i!=j)
	{
		while(arr[j]>=pivot && i<j) /* >=的原因是因為若只剩兩個要比較時left會碰到right若只有>則不會碰到*/
		{
			j--;
		}
		while(arr[i]<=pivot && i<j) /* <=的原因是因為若只剩兩個要比較時left會碰到right若只有<則不會碰到*/
		{
			i++;
		}
		if(i<j) /*只有<的原因是因為若只剩下兩個要比較，上面兩行第一行已經讓i==j了，第二行不改變東西因此到這行時會變成i==j，跳出while迴圈*/
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	//兩個比較的case是在這邊換
	arr[left]=arr[i];//i==j
	arr[i]=pivot;
	quicksort(i+1,right,arr);
	quicksort(left,i-1,arr);
}

int main(void)
{
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(0,size-1,arr);
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
