#include<iostream>
using namespace std;
void convert(int n)
{
    if(n == 0)
    return;

    int val= n%2;

    convert(n/2);
    cout<<val;
}
int main()
{
    int num;
    cin>>num;
     
     convert(num);
}