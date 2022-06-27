#include <bits/stdc++.h>
#define INFINITY 2147483647
using namespace std;

void merge(vector<int> &array,int front,int mid,int end)
{
   int left_index = 0;
   int right_index = 0;
   vector<int> left(array.begin()+front , array.begin()+mid+1);
   vector<int> right(array.begin()+mid+1, array.begin()+end+1);
   left.insert(left.end(),INFINITY);
   right.insert(right.end(),INFINITY);

   for(int i=front;i<=end;i++)
   {
      if(left[left_index] <= right[right_index])
      {
         array[i] = left[left_index];
         left_index++;
      }
      else
      {
         array[i] = right[right_index];
         right_index++;
      }
   }
}

void merge_sort(vector<int> &array ,int front,int end)
{
   int mid = (front+end) / 2;
   if(front<end)
   {
      merge_sort(array,front,mid);
      merge_sort(array,mid+1,end);
      merge(array,front,mid,end);
   }
}

int main()
{
   vector<int> array;
   int size;
   cin>>size;
   for(int i=0;i<size;i++)
   {
      int temp;
      cin>>temp;
      array.push_back(temp);
   }

   merge_sort(array,0,array.size()-1);

   for(int i=0;i<size;i++)
      cout<<array[i]<<" ";

   return 0;
}
