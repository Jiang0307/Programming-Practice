#include<bits/stdc++.h>
using namespace std;
#define SIZE 6

void matrix_chain_multiplication(int p[],int m[][SIZE],int s[][SIZE],int n)
{
   for(int i=1;i<n;i++)
      m[i][i] = 0;
   
   for(int l=2;l<=n;l++)
   {
      for(int i=1;i<=n-l+1;i++)
      {
         int j=i+l-1;
         int min = INT_MAX;
         for(int k=i;k<j;k++)
         {
            int temp = (m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
            if(temp < min)
            {
               min = temp;
               s[i][j] = k;
            }
         }
         m[i][j] = min;
      }
   }
}

int main()
{
   int n=SIZE;
   int m[SIZE][SIZE] = {0};
   int s[SIZE][SIZE] = {0};
   int p[n];
   for(int i=0;i<n;i++)
      cin>>p[i];

   matrix_chain_multiplication(p,m,s,n-1);
   cout<<"TABLE m : "<<endl;
   for(int i=1;i<n;i++)
   {
      for(int j=1;j<n;j++)
      {
         cout<<setw(6)<<m[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<"TABLE s : "<<endl;
   for(int i=1;i<n-1;i++)
   {
      for(int j=2;j<n;j++)
      {
         cout<<setw(6)<<s[i][j]<<" ";
      }
      cout<<endl;
   }
   
   return 0;
}