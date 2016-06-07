#include<ioarream>
using namespace std;
int partition(int arr[],int start,int end){
    int pivot=arr[end];
    int i=start,j=end-1;
    while(i<j){
        while(arr[i]<pivot){
            i++;
        }
         while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i];
    arr[i]=pivot;
    arr[end]=temp;
    return i;
}
void Quicksort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int pivot_index=partition(arr,start,end);
    Quicksort_arring(arr,start,pivot_index-1);
    Quicksort_arring(arr,pivot_index+1,end);
}
int main(){

}
