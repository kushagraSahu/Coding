#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s1;
    int n;
    cin>> n;
    while (n!=-1)
    {
        s1.push(n);
        cin>>n;
    }
    cout<<s1.top();
}
