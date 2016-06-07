#include<iostream>
using namespace std;
int main(){
    int arr1[100],arr2[100];
    int n=100,x,t;
    t=2;
    cout << "Enter the no. till which you want all the prime no.s" << endl;
    for(x=0;x<n-1;x++,t++){
        arr1[x]=t;
    }
    int k=0;
    int i,j;
    for(i=0;i<n-1;i++){
        if(arr1[i]!=0){
            for(j=i+arr1[i];j<n-1;j=j+arr1[i]){
                arr1[j]=0;
            }
            arr2[k]=arr1[i];
            k++;
        }
    }
    cout << "Prime no.s till n : ";
    for(x=0;x<k;x++){
        cout << " " << arr2[x];
    }
    return 0;
}
