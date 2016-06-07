#include<iostream>
using namespace std;
static int count = 1;
int main(){
    int arr[50];
    int i,j,k,key,len;
    cout << "Enter length of the array" << endl;
    cin >> len;
    cout << "Enter array of length " << len << endl;
    for(i=0;i<len;i++){
        cin >> arr[i];
    }
    for(j=0;j<len;j++){
        key = arr[j];
        i=j-1;
        for(;i>=0 && arr[i]>key;i--){
            arr[i+1]=arr[i];
        }
        i++;
        arr[i]=key;
//        cout << "Customized array for iteration " << count << " : ";
//        for(k=0;k<len;k++){
//            cout << arr[k] << " ";
//        }
//        count++;
//        cout << endl;
    }
    cout << "Final Sorted array : ";
    for(k=0;k<len;k++){
            cout << arr[k] << " ";
    }
    return 0;
}
