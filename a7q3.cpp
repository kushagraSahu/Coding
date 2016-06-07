#include<iostream>
using namespace std;
void wave_print(char mat[][100],int m,int n){
    int i,j,k;
    char temp;
    for(j=0;j<n;j++){
        if(j%2!=0){
            for(i=0,k=m-1;i<k;i++,k--){
                temp=mat[i][j];
                mat[i][j]=mat[k][j];
                mat[k][j]=temp;
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return ;
}
int main(){
    int mat[100][100];
    int M,N,i,j;
    cout << "Enter M and N" << endl;
    cin >> M >> N;
    cout << "Enter matrix" << endl;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            cin >> mat[i][j];
        }
    }
    wave_print(mat,M,N);
    return 0;
}
