#include<iostream>
using namespace std;
int sum_series(int arr[],int n){
    if(n==0){
        return 0;
    }
    return arr[n-1] + sum_series(arr,n-1);
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
    cout << "Sum of series : " << sum_series(arr,n);
    return 0;
}
