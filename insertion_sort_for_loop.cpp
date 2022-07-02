#include <iostream>
using namespace std;

int arr[5] = {88,94342,14,354,5};

void insertion_sort()
{
   for(int i=1;i<5;i++)
      for(int j=0;j<4;j++)
      {
         if(arr[j]>arr[i])
         {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
         }
      }    
}

int main()
{
   insertion_sort();

   for(int i=0;i<5;i++)
      cout<<arr[i]<<" ";

   return 0;
}