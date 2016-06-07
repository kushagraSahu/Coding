//Sorting of strings(by dictionary rule)
#include<iostream>
using namespace std;
int length(char str[]){
    int len;
    for(len=0;str[len]!=NULL;len++){
    }
    return len;
}
void sort_strings(char arr[][100],int len_arr[],int n){
    int i,j,k,smallest_index,len1,len2;
    int temp[100];
    for(i=0;i<n-1;i++){
        smallest_index=i;
        for(k=i+1;k<n;k++){
            len1 = len_arr[smallest_index];
            len2=len_arr[k];
            for(j=0;j<len1||j<len2;j++){
                if(int(arr[k][j])<int(arr[smallest_index][j])){
                    smallest_index=k;
                    break;
                }
                else if(int(arr[k][j])>int(arr[smallest_index][j])){
                    break;
                }
                else{
                    continue;
                }
            }
        }
        for(j=0;j<len_arr[i]||j<len_arr[smallest_index];j++){
            temp[j]=arr[i][j];
            arr[i][j]=arr[smallest_index][j];
            arr[smallest_index][j]=temp[j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;arr[i][j]!=NULL;j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    return ;
}
int main(){
    char arr[200][100];
    int len_arr[100];
    int i,j,k,n;
    cout << "Enter no. of strings" << endl;
    cin >> n;
    for(i=0,k=0;i<n+1;i++,k++){
        for(j=0;1;j++){
                cin.get(arr[i][j]);
                if(arr[i][j]=='\n'){
                    arr[i][j]=NULL;
                    break;
                }
        }
        len_arr[k]=j+1;
    }
    sort_strings(arr,len_arr,n+1);
    return 0;
}
