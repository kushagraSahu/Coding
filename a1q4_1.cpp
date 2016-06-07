#include<iostream>
static int dec_row=1;
using namespace std;
int main(){
    int num_space,max_spaces,max_stars,num_stars,curr_row;
    int N,n;
    cout << "Enter N" << endl;
    cin >> N;
    n = (N+1)/2;
    curr_row = 1;
    while(curr_row<=N){
        num_space = 0;
        num_stars = 0;
        if(curr_row<n){
            max_spaces = n-curr_row;
            for(;num_space<max_spaces;num_space++){
                cout << " ";
            }
            if(n%2==0){
                max_stars = 2*(curr_row+2)-n-1;
            }
            else{
                max_stars = 2*(curr_row+2)-n;
            }
            while(num_stars<max_stars){
                cout << "*";
                num_stars++;
            }
        }
        if(curr_row>=n){
            max_spaces = curr_row-n;
            while(num_space<max_spaces){
                cout << " ";
                num_space++;
            }
            max_stars = N-2*dec_row+2;
            while(num_stars<max_stars){
                cout << "*";
                num_stars++;
            }
            dec_row++;
        }
        curr_row++;
        cout << endl;
    }
    return 0;
}
