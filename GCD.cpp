#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,r;
    cin>>a>>b;
    r = a%b;
    d = b;

    while(r>0)
    {
        c = d;
        d = r;
        r = c%d;
    }
    cout<<d<<endl;
}