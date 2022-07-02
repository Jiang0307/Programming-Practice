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
		while(arr[j]>=pivot && i<j) /* >=����]�O�]���Y�u�Ѩ�ӭn�����left�|�I��right�Y�u��>�h���|�I��*/
		{
			j--;
		}
		while(arr[i]<=pivot && i<j) /* <=����]�O�]���Y�u�Ѩ�ӭn�����left�|�I��right�Y�u��<�h���|�I��*/
		{
			i++;
		}
		if(i<j) /*�u��<����]�O�]���Y�u�ѤU��ӭn����A�W�����Ĥ@��w�g��i==j�F�A�ĤG�椣���ܪF��]����o��ɷ|�ܦ�i==j�A���Xwhile�j��*/
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	//��Ӥ����case�O�b�o�䴫
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
