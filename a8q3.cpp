#include<iostream>
using namespace std;
bool check_sorted(int arr[],int n){
    if(n==0){
        return true;
    }
    if(arr[n]>=arr[n-1]){
        return check_sorted(arr,n-1);
    }
    else{
        return false;
    }
}
int main(){
    int arr[100];
    int i,n;
    cout << "Enter the length of series" << endl;
    cin >> n;
    cout << "Enter series" << endl;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    if(check_sorted(arr,n-1)){
        cout << "Series is sorted!";
    }
    else{
        cout << "Series is unsorted!";
    }
    return 0;
}
