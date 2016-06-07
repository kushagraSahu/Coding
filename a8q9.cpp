#include<iostream>
using namespace std;
int finding_smallest_index(int arr[],int i,int j,int len){
    if(j==len){
        return i;
    }
    if(arr[j]<arr[i]){
        return finding_smallest_index(arr,j,j+1,len);
    }
    else{
        return finding_smallest_index(arr,i,j+1,len);
    }
}
void selection_sort(int arr[],int i,int len){
    if(i==len-1){
        return;
    }
    int smallest_index = i;
    smallest_index = finding_smallest_index(arr,i,i+1,len);
    int temp;
    temp=arr[i];
    arr[i]=arr[smallest_index];
    arr[smallest_index]=temp;
    return selection_sort(arr,i+1,len);
}
int main(){
    int arr[100],i,len;
    cout << "Enter length of array" << endl;
    cin >> len;
    cout << "Enter array : ";
    for(i=0;i<len;i++){
        cin >> arr[i];
    }
    selection_sort(arr,0,len);
    cout << "Selectively sorted array : ";
    for(i=0;i<len;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
