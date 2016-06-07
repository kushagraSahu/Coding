#include<iostream>
using namespace std;
int factor_10(int num,int fact){
    if(num==0){
        return fact/10;
    }
    else{
        return factor_10(num/10,fact*10);
    }
}
int rev_integer(int num,int factor,int sum){
    if(num==0){
        return sum;
    }
    else{
        int rem = num%10;
        sum = sum + rem*factor;
        return rev_integer(num/10,factor/10,sum);
    }
}
int main(){
    int num,factor;
    cout << "Enter number" << endl;
    cin >> num;
    factor = factor_10(num,1);
    cout << "Reverse of the number : " << rev_integer(num,factor,0);
    return 0;
}
