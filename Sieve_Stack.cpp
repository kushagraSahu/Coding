#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> S;
    int arr1[100], arr2[20];
    int N,x,t=2;
    cout << "Enter the no." << endl;
    cin >> N;
    for(x=0;x<N-1;x++,t++){
        arr1[x]=t;
    }
    int i,j;
    for(i=0;i<N-1;i++){
        if(arr1[i]!=0){
            for(j=i+arr1[i];j<N-1;j=j+arr1[i]){
                arr1[j]=0;
            }
            if(N%arr1[i]==0){
                S.push(arr1[i]);
            }
        }
    }
    cout << "Prime factor(s) of N : ";
    while(!S.empty()){
        cout << S.top() << " ";
        S.pop();
    }
    return 0;
}

