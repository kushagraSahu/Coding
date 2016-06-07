/*Write a program to count all the possible paths from top left to
bottom right of a MXN matrix with the constraints that from each cell you
can either move only to right or down*/
#include<iostream>
using namespace std;
static int count=0;
void count_possible_paths(int i,int j,int m,int n){
    if(i==m-1||j==n-1){
        count++;
        return;
    }
    count_possible_paths(i+1,j,m,n);
    count_possible_paths(i,j+1,m,n);
}
int main(){
    int i,j,m,n;
    cout << "Enter M and N of matrix MxN" << endl;
    cin >> m >> n;
    count_possible_paths(0,0,m,n);
    cout << "Total no. of paths : " << count;
    return 0;
}
