#include<iostream>
using namespace std;
int main(){
    int x, n;
    cout << "Enter the integer!" << endl;
    cin >> x;
    if(x==0){
        cout << "00000000" << endl;
    }
    for(n=128;n>0;n=n/2){
        if(x>=n){
            cout << "1";
            x = x%n;
        }
        else{
            cout << "0";
        }
    }
    return 0;
}
