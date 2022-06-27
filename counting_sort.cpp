#include <bits/stdc++.h>
using namespace std;

void counting_sort(int n,int k,int a[],int b[],int c[])
{
   for(int i=0;i<n;i++)
      c[a[i]] = c[a[i]] + 1;

   for(int i=1;i<=k;i++)
      c[i] = c[i-1] + c[i];

   for(int i=n-1;i>=0;i--)
   {
      b[c[a[i]]-1] = a[i];
      c[a[i]]--;
   }

}

int main()
{
   int n,k;
   cin>>n>>k;
   int A[n];
   int B[n];
   int C[k+1] = {0};
   
   for(int i=0;i<n;i++)
      cin>>A[i];

   counting_sort(n,k,A,B,C);

   for(int i=0;i<n;i++)
      cout<<B[i]<<" ";
  
}