//Triplets which add upto integer X
#include<iostream>
using namespace std;
int main(){
    int arr[50];
    int i,j,k,X,len;
    cout << "Enter length of the array" << endl;
    cin >> len;
    cout << "Enter array of length " << len << endl;
    for(i=0;i<len;i++){
        cin >> arr[i];
    }
    cout << "Enter the integer X" << endl;
    cin >> X;
    cout << "Triplets which sum to X : ";
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(i==j){
                continue;
            }
            else{
                for(k=0;k<len;k++){
                    if(k==i || k==j){
                        continue;
                    }
                    else{
                        if(arr[i]+arr[j]+arr[k]==X){
                            cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << "), ";
                        }
                    }
                }
            }
        }
    }
    return 0;
}
