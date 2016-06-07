//Given an array, reverse it without using a new array!
#include<iostream>
using namespace std;
int main(){
    int arr[20];
    int x,len;
    cout << "Enter length of array" << endl;
    cin >> len;
    cout << "Enter array" << endl;
    for(x=0;x<len;x++){
        cin >> arr[x];
    }
    int temp,i,j;
    for(i=0,j=len-1;i<j;i++,j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
     for(x=0;x<len;x++){
        cout << arr[x] << " ";
    }
    return 0;
}
