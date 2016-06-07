//Fibonacci
#include<iostream>
using namespace std;
int main(){
    int a,b,c,N;
    cout << "Enter N" << endl;
    cin >> N;
    a=0;
    b=1;
    int sum;
    cout << "0, 1";
    for(c=0;c<N;a=b,b=c){
        c = a+b;
        if(c<N){
            cout << ", " << c;
        }
        else{
            break;
        }
    }
    return 0;
}
