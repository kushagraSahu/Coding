#include<iostream>
using namespace std;
int main() {
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i =0; i < n-1; i++) {
        int smallest_index = i;
        for(int j = i+1; j <= n-1; j++) {
            if (arr[smallest_index] > arr[j]) {
                smallest_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallest_index];
        arr[smallest_index] = temp;
         //Printing After each cycle
//        for(int i = 0; i < n; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl<<endl;
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

