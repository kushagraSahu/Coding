#include<iostream>
using namespace std;
static int count = 0;
int main(){
    int mat[100][100];
    int i,j,M,N,k,key;
    cout << "Enter M and N" << endl;
    cin >> M >> N;
    cout << "Enter the matrix!" << endl;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            cin >> mat[i][j];
        }
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            key = mat[i][j];
            for(k=0;k<N;k++){
                if(mat[i][k]<=key){
                    continue;
                }
                else{
                    break;
                }
            }
            if(k!=N){
               // j=k-1;
                continue;
            }
            else{
                for(k=0;k<N;k++){
                    if(mat[k][j]>=key){
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if(k!=M){
                    continue;
                }
                else{
                    if(!count){
                        cout << "Saddle point(s) at position : ";
                    }
                    cout << "(" << i+1 << ", " << j+1 << ")";
                    count++;
                }
            }
        }
        if(!count){
            cout << "No Saddle points";
        }
    }
    return 0;
}
