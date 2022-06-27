#include <bits/stdc++.h>
using namespace std;

int median(int arr[],int n)
{
	if(n%2 == 0)
		return (arr[n/2-1] + arr[n/2]);
	else
		return (arr[n/2]);
}

int get_median(int a1[],int a2[],int n)
{
	if(n==0)
		return -1;
	
	if(n==1)
		return (a1[0]+a2[0])/2;
	if(n==2)
	{
		int max = a1[0];
		if(a2[0]>max)
			max = a2[0];
		int min = a1[1];
		if(a2[1]<min)
			min - a2[1];
		return (max+min)/2;
	}
	
	int m1 = median(a1,n);
	int m2 = median(a2,n);
	
	if(m1 == m2)
		return m1;
		
	if(m1 > m2)
	{
		if (n % 2 == 0)
        	return get_median(a2 + n/2 - 1, a1, n - n/2 + 1);
        	
        else
    		return get_median(a2 + n/2, a1, n - n/2);
	}
	
	else
	{
        if (n % 2 == 0)
            return get_median(a1 + n/2 - 1, a2, n - n/2 +1);
        
        else
        	return get_median(a1 + n/2, a2, n - n/2);
	}
	
	
}

int main() 
{
    int arr1[] = {1, 12, 15, 26, 38 };
    int arr2[] = {2, 13, 17, 30, 45};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int median = get_median(arr1,arr2,n1);
    cout<<median;
	return 0;
}