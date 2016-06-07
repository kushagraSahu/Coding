//Finding non-duplicate out of 2N+1 numbers out of which N are duplicate.
#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int len;
    cout << "Enter total number of no.s to be checked" << endl;
    cin >> len;
    cout << "Enter the series!" << endl;
    int x;
    for(x=0;x<len;x++){
        cin >> arr[x];
    }
    int i, j;
    for(i=0;i<len;i++){
        for(j=0;j<len+1;j++){
            if(i==j){
                continue;
            }
            else{
                if(arr[i]==arr[j]){
                    break;
                }
                if(j==len){
                    cout << "Non duplicate no. : " << arr[i];
                }
            }
        }
    }
    return 0;
}
