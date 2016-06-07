//Print in spiral form.
#include<iostream>
using namespace std;
int main(){
    int mat[10][10], out[100];
    int i,j,k,t,n,N;
    cout << "Enter N" << endl;
    cin >> N;
    cout << "Enter the matrix" << endl;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin >> mat[i][j];
        }
    }
    n=N;
    int T = N*N;
    int count = (N+1)/2;
    for(k=0,t=0;k<count;k++){
        i=j=k;
        for( ;j<n&&t<T;t++,j++){
            out[t]=mat[i][j];
        }
        j--;
        for(i=k+1;i<n&&t<T;t++,i++){
            out[t]=mat[i][j];
        }
        i--;
        for(j=n-2;j>=k&&t<T;t++,j--){//here we use k instead of 0 because every time our rectangle gets smaller, we don't want the new char to overwrite prev. one.
           out[t]=mat[i][j];
        }
        j++;
        for(i=n-2;i>k&&t<T;t++,i--){
            out[t]=mat[i][j];
        }
        n--;
    }
    for(i=0;i<T;i++){
        cout << out[i] << " ";
    }
    return 0;
}
