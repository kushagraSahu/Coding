//Alternate rectangles of Os and Xs.
#include<iostream>
using namespace std;
int main(){
    char mat[100][100];
    int m,N,i,j,k,count;
    cout << "Enter N" << endl;
    cin >> N;
    m=N;
    count = (N+1)/2;
    char key,key1,key2;
    cout << "What 2 alphabets should make up the alternate rectangles? : ";
    cin >> key1 >> key2;
    for(k=0;k<count;k++){
        if(k%2==0){
            key = key1;
        }
        else{
            key = key2;
        }
        i=j=k;
        for( ;i<m;i++){
            mat[i][j] = key;
        }
        i--;
        for( ;j<m;j++){
            mat[i][j] = key;
        }
        j--;
        for( ;i>=k;i--){//here we use k instead of 0 because every time our rectangle gets smaller, we don't want the new char to overwrite prev. one.
            mat[i][j] = key;
        }
        i=k;
        for( ;j>=k;j--){
            mat[i][j] = key;
        }
        m--;
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
