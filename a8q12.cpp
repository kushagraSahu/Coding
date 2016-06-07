/*A child is running up a staircase with n steps, and can hop either 1
step, 2 steps or 3 steps at a time. Implement a method to count how
many possible ways the child can run up to the stairs. */
#include<iostream>
using namespace std;
static int count=0;
void count_ways_upstairs(int n,int i){
    if(i==n-1){
        count++;
        return;
    }
    if(i==n-2){
        count+=2;
        return;
    }
    if(i==n-3){
        count+=3;
        return;
    }
    count_ways_upstairs(n,i+1);
    count_ways_upstairs(n,i+2);
    count_ways_upstairs(n,i+3);
}
int main(){
    int n;
    cout << "Enter no. of stairs : ";
    cin >> n;
    count_ways_upstairs(n,0);
    cout << "No. of ways child can climb n stairs by taking either 1,2 or 3 step : " << count;
    return 0;
}
