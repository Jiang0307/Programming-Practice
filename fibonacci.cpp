#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if(n==1 || n==0)
        return n;

    else
        return fibonacci(n-1) + fibonacci(n-2);
}


int main()
{
    int n;
    cin>>n;
    int ans = fibonacci(n);
    cout<<"fibonacci "<<n<<" = "<<ans<<endl;
    return 0;
}