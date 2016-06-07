//Shift the 0s at the end keeping the order of natural no.s intact.
#include<iostream>
using namespace std;
static int count = 1;
int main(){
    int arr[50];
    int i,j,k,temp,len;
    cout << "Enter length of the array" << endl;
    cin >> len;
    cout << "Enter array of length " << len << endl;
    for(i=0;i<len;i++){
        cin >> arr[i];
    }
    for(i=0;i<len;i++){
        if(arr[i]==0){
            j=i+1;
            for(;j<len;j++){
                if(arr[j]!=0){
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                    break;
                }
            }
            cout << "Customized array after finding 0 in iteration " << count << " : ";
            for(k=0;k<len;k++){
                cout << arr[k] << " ";
            }
            count++;
            cout << endl;
        }
    }
    cout << "Final array : ";
    for(k=0;k<len;k++){
        cout << arr[k] << " ";
    }
    return 0;
}
