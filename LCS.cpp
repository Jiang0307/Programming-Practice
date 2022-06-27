#include<bits/stdc++.h>
using namespace std;
#define SIZE 9

void LCS(int c[][SIZE+1],int b[][SIZE],string A,string B,int la,int lb)
{
   /*
   for(int i=1;i<=la;i++)
      c[i][0] = 0;

   for(int j=1;j<=lb;j++)
      c[0][j] = 0;
   */
   for(int i=1;i<=la;i++)
   {
      for(int j=1;j<=lb;j++)
      {
         if(A[i-1] == B[j-1])
         {
            c[i][j] = c[i-1][j-1]+1;
            b[i][j] = 0;
         }            
         else if(c[i][j-1] >= c[i-1][j] )
         {
            c[i][j] = c[i][j-1];
            b[i][j] = 1;
         }
            
         else
         {
            c[i][j] = c[i-1][j];
            b[i][j] = 2;
         }
      }
   }   
}

void print_LCS(int b[][SIZE],string a,int i,int j)
{
   if(i==0 || j==0)
      return;

   if(b[i][j] == 0)
   {
      print_LCS(b,a,i-1,j-1);
      cout<<a[i-1];
   }

   else if(b[i][j] == 1)
      print_LCS(b,a,i,j-1);

   else
      print_LCS(b,a,i-1,j);
}

int main()
{
   string A,B;
   cin>>A;
   cin>>B;
   int la = A.length();
   int lb = B.length();
   
   int c[SIZE+1][SIZE+1] = {0};
   int b[SIZE][SIZE];

   LCS(c,b,A,B,la,lb);

   cout<<"TABLE c : "<<endl;
   for(int i=0;i<=la;i++)
   {
      for(int j=0;j<=lb;j++)
      {
         cout<<c[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<"longest common subsequence : ";
   print_LCS(b,A,la,lb);
   return 0;
}