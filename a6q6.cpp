#include<iostream>
using namespace std;
int main(){
    int initial_mat[100][100],final_mat[100][100];
    int N,i,j,k,t;
    cout << "Enter N(of NxN matrix)" << endl;
    cin >> N;
    cout << "Enter the matrix" << endl;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin >> initial_mat[i][j];
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            final_mat[i][j]=1;
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(initial_mat[i][j]==1){
                for(t=0,k=j;t<N;t++){
                    if(initial_mat[t][k]==0){
                        final_mat[i][j]=0;
                        break;
                    }
                }
                if(t==N){
                    for(t=i,k=0;k<N;k++){
                        if(initial_mat[t][k]==0){
                            final_mat[i][j]=0;
                            break;
                        }
                    }
                }
            }
            else{
                final_mat[i][j]=0;
            }
        }
    }
    cout << "___Final matrix___" << endl;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cout << final_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
