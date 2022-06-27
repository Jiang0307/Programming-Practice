#include <stdio.h>
int n;

void adjust(int arr[],int root)
{
	int child = root*2,rootkey = arr[root];
	int temp=rootkey;
	while(child<=n)
	{
		if(arr[child]<arr[child+1] && child<n)
		{
			child++;
		}
		if(rootkey>arr[child])
		{
			break;
		}
		else
		{
			arr[child/2]=arr[child];
			child*=2;
		}
	}
	arr[child/2]=temp;
}

int main(void)
{
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=n/2;i>0;i--)
	{
		adjust(arr,i);
	}

	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
