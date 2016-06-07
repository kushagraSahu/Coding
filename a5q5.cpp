//sum of the two arrays and put the result in another array. e.g. if you are given [1,2,4] and [4,5,6] the output should be [5,8,0]. 
#include<iostream>
using namespace std;
static int factor1 = 1;
static int factor2 = 1;
int main(){
    int arr1[20],arr2[20],arr3[40];
    int i,j,k,len1,len2,len3,sum1,sum2,sum,num;
    cout << "Enter length for 1st array" << endl;
    cin >> len1;
    cout << "Enter 1st array " << ": ";
    for(i=0;i<len1;i++){
        cin >> arr1[i];
    }
    cout << "Enter length for 2nd array" << endl;
    cin >> len2;
    cout << "Enter 2nd array " << ": ";
    for(i=0;i<len2;i++){
        cin >> arr2[i];
    }
    sum1=0;
    for(i=len1-1;i>=0;i--){
        sum1 = sum1 + arr1[i]*factor1;
        factor1*=10;
    }
    sum2=0;
    for(i=len2-1;i>=0;i--){
        sum2 = sum2 + arr2[i]*factor2;
        factor2*=10;
    }
    sum = sum1 + sum2;
    for(j=0;sum!=0;j++){
        num = sum%10;
        arr3[j]=num;
        sum/=10;
    }
    len3=j;
    cout << "Final array : ";
    for(k=len3-1;k>=0;k--){
        cout << arr3[k] << " ";
    }
    return 0;
}
