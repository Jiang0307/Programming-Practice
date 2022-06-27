#include <iostream>
using namespace std;

void cutting_rod(int p[],int r[],int s[],int n)
{
   r[0] = 0;
   for(int j=1;j<=8;j++)
   {
      int max = -2147483648;
      for(int i=1;i<=j;i++)
      {
         if((p[i] + r[j-i]) > max)
         {
            max = (p[i] + r[j-i]);
            s[j] = i;
         }
      }
      r[j] = max;
   }
}

void print(int s[],int n)
{
   while(n>0)
   {
      cout<<s[n]<<" ";
      n -= s[n];
   }

}

int main()
{
   int p[9] = {0,1,5,8,9,10,17,17,20};
   int r[9];
   int s[9];

   cutting_rod(p,r,s,8);


   for(int i=0;i<9;i++)
      cout<<r[i]<<" ";

   cout<<endl;
   print(s,8);
   return 0;
}