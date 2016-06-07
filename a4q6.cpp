//Pair of elements in array which sum to given integer X
#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int x,X,len;
    cout << "Enter length of array" << endl;
    cin >> len;
    cout << "Enter array" << endl;
    for(x=0;x<len;x++){
        cin >> arr[x];
    }
    cout << "Enter the integer X!" << endl;
    cin >> X;
    int i,j;
    cout << "Pairs which sum to X : ";
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(i==j){
                continue;
            }
            else{
                if(arr[i]+arr[j]==X){
                    cout << "(" << arr[i] << ", " << arr[j] << "), ";
                }
            }
        }
    }
    return 0;
}

