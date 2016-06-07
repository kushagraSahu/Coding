//GCD(by Euclidean Algorithm)
#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout << "Enter the two numbers!" << endl;
    cin >> a >> b;
    int maxi,mini;
    if(a>b){
        maxi=a;
        mini=b;
    }
    else{
        maxi=b;
        mini=a;
    }
    c = maxi%mini;
    for(;c>=0;maxi=mini,mini=c){
        c = maxi%mini;
        if(c==0){
            cout << "GCD of a & b : " << mini << endl;
            break;
        }
    }
    return 0;
}
