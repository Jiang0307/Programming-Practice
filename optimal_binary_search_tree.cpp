#include<bits/stdc++.h>
using namespace std;
#define SIZE 5

void optimal(double e[][SIZE+2] , double w[][SIZE+2] , int root[][SIZE+1] , double p[] , double q[] , int n)
{
   for(int i=1;i<=n+1;i++)
   {
      e[i][i-1] = q[i-1];
      w[i][i-1] = q[i-1];
   }

   for(int l=1;l<=n;l++)
   {
      for(int i=1;i<=n-l+1;i++)
      {
         int j=i+l-1;
         e[i][j] = 500;
         w[i][j] = w[i][j-1] + p[j] + q[j];

         for(int r=i;r<=j;r++)
         {
            double temp = e[i][r-1] + e[r+1][j] + w[i][j];
            if(temp < e[i][j])
            {
               e[i][j] = temp;
               root[i][j] = r;
            }
         }
      }
   }
}

/*
void construct_optimal_subtree(int i,int j,int r,string dir,int root[][SIZE])
{
   if(i<=j)
   {
      int t = root[i][j];
      cout<<t<<" is "<<dir<<" child of "<<r<<endl;
      construct_optimal_subtree(i,t-1,t,"left",root);
      construct_optimal_subtree(t+1,j,t,"right",root);
   }
}

void construct_optimal_binary_search_tree(int root[][SIZE+1])
{
   int r = root[1][SIZE];
   int n = SIZE+1;
   cout<<r<<" is the root"<<endl;
   construct_optimal_subtree(1,r-1,r,"left",root);
   construct_optimal_subtree(r+1,n,r,"right",root);  
}
*/

int main()
{
   int n=SIZE;
   double p[SIZE+1] = {0,0.08,0.15,0.05,0.1,0.12};
   double q[SIZE+1] = {0.04,0.1,0.08,0.1,0.06,0.12};
   /*
   for(int i=1;i<=SIZE;i++)
      cin>>p[i];
   */

   double e[SIZE+2][SIZE+2] = {0};
   double w[SIZE+2][SIZE+2] = {0};
   int root[SIZE+1][SIZE+1] = {0};

   optimal(e,w,root,p,q,n);

   cout<<"e : "<<endl;
   for(int i=1;i<SIZE+2;i++)
   {
      for(int j=0;j<SIZE+1;j++)
      {
         cout<<setw(5)<<e[i][j]<<" ";
      }
      cout<<endl;
   }

   cout<<"w : "<<endl;
   for(int i=1;i<SIZE+2;i++)
   {
      for(int j=0;j<SIZE+1;j++)
      {
         cout<<setw(5)<<w[i][j]<<" ";
      }
      cout<<endl;
   }

   cout<<"root : "<<endl;
   for(int i=1;i<=SIZE;i++)
   {
      for(int j=1;j<=SIZE;j++)
      {
         cout<<setw(5)<<root[i][j]<<" ";
      }
      cout<<endl;
   }

   //cout<<"tree : "<<endl;
   //construct_optimal_binary_search_tree(root);
   return 0;
}