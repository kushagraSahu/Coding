#include<iostream>
using namespace std;
bool binarysearch(int arr[],int start,int end,int a){
    int mid;
    mid = (start+end)/2;
    if(start<=end){
        if(a>arr[mid]){
                return binarysearch(arr,mid+1,end,a);
        }
        else if(a<arr[mid]){
                return binarysearch(arr,start,mid-1,a);
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}
int main()
{
    int a,n,j,arr[100];
    cout << "Enter the no. of elements in the sorted series" << endl;
    cin >> n;
    cout << "Enter the sorted series" << endl;
    for(j=0;j<n;j++){
        cin >> arr[j];
    }
    cout << "Enter the no. you want to find in the series" << endl;
    cin >> a;
    if(binarysearch(arr,0,n-1,a)){
        cout << "Present";
    }
    else{
        cout << "Not Present";
    }
    return 0 ;
}
