#include<iostream>
using namespace std;
int main()
{
    int arr1[100] , arr2[100], arr3[100] ;
    int i,j,k,n;
    cout << "Enter no.of elements in both series each" << endl ;
    cin >>  n;
    cout << "Enter 1st series" << endl ;
    for(i=0;i<n;i++ ){
        cin >> arr1[i] ;
    }
    cout << "Enter 2nd series" << endl ;
    for(j=0;j<n;j++){
        cin >> arr2[j];
    }
    for(i=0,j=0,k=0 ;(i<n && j<n) ; k++){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i] ;
            i++ ;
        }
        else{
            arr3[k] = arr2[j] ;
            j++;
        }
    }
    if(i==n){
        for(  ;j<n;j++,k++){
            arr3[k] = arr2[j] ;
        }
    }
    else{
        for(  ;i<n ;i++,k++){
            arr3[k] = arr1[i];
        }
    }
    cout << "Combination of both the series(sorted) : ";
    for(k=0;k<2*n;k++){
        cout << arr3[k] << " ";
    }
    cout << endl << "Median is/are " << arr3[n-1] <<'\t' << "and " << arr3[n];
    return 0 ;
}

