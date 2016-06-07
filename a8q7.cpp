#include<iostream>
using namespace std ;
float powof2(int k){
    if(k==0){
        return 1.0;
    }
    return 2*powof2(k-1) ;
}
float geometricsum(int n){
    if(n==0){//Base condition.
        return 1.0 ;
    }
    return 1/powof2(n) + geometricsum(n-1) ;
}
int main()
{
    int n ;
    cout << "Enter the power of k till which you want series:1+1/2+ 1/2^2+ 1/2^3+...+ 1/2^n" << endl ;
    cin >> n ;
   cout << "Last denominator term in the series : " <<  powof2(n) << endl ;
    cout << "The geometric sum : " << geometricsum(n)  ;
    return 0 ;
}

