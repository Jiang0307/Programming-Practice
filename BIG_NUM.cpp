#include<bits/stdc++.h>
using namespace std;

string PLUS(string num1,string sign,string num2)
{
    int length1=num1.length();
    int length2=num2.length();
    string answer="";
    int carry,sum;
    
    if(length1<length2)
    {
        swap(length1,length2);
        swap(num1,num2);
    }
    int i=length1-1,j=length2-1;
    for(;j>=0;i--,j--)
    {
        sum = carry+(num1[i]-'0')+(num2[j]-'0');
        carry = sum/10;
        sum %= 10;
        string s = to_string(sum);
        answer = s + answer;
    }
    for(;i>=0;i--)
    {
        sum = carry+(num1[i]-'0');
        carry = sum/10;
        sum %= 10;
        string s = to_string(sum);
        answer = s + answer;
    }
    cout<<answer;
}
string MINUS(string num1,string sign,string num2)
{

}
string MULTIPLY(string num1,string sign,string num2)
{

}
string DIVIDE(string num1,string sign,string num2)
{

}


int main()
{
    string num1,num2,sign,ans;
    cin>>num1>>sign>>num2;
    if(sign=="+")
        ans=PLUS(num1,sign,num2);
    else if(sign=="-")
        ans=MINUS(num1,sign,num2);
    else if(sign=="*")
        ans=MULTIPLY(num1,sign,num2);
    else if(sign=="/")
        ans=DIVIDE(num1,sign,num2);
    return 0;
}