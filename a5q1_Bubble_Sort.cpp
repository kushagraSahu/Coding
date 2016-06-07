#include<iostream>
using namespace std;
int main() {
    int arr[100],N,temp;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    for(int i=0; i<=N-2;i++) {
        for (int j=0;j<=N-2-i;j++) {
            if (arr[j]>arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
