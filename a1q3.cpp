//Prime
#include<iostream>
using namespace std;
int main(){
    int a,N;
    cout << "Enter the number N" << endl;
    cin >> N;
    for(a=2;a<=N/2;a++){
        if(N%a==0){
            cout << "Not a prime number!" << endl;
            break;
        }
    }
    if(a>N/2){
        cout << "A Prime number" << endl;
    }
    return 0;
}
