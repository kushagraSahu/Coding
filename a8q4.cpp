#include<iostream>
using namespace std;
static int count = 0;
int zeroes_count(int num, int temp){
    if(temp==0){
        count++;
    }
    if(num!=0){
        temp = num%10;
        return zeroes_count(num/10,temp);
    }
    return count;
}
int main(){
    int num,temp;
    cout << "Enter the number" << endl;
    cin >> num;
    cout << "No. of zeroes in the number : " << zeroes_count(num,num);
    return 0;
}
