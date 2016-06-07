#include<iostream>
using namespace std;
/*ABCDEEDCBA
   ABCDDCBA
    ABCCBA
     ABBA
      AA*/
int main(){
    int a;
    int current_row = 1;
    int n, num_space, x, spaces_printed;
    cout << "Enter integer" << endl;
    cin >> n;
    while(current_row<=n){
        a=65;
        spaces_printed = 0;
        for(num_space = current_row-1;spaces_printed<num_space;spaces_printed++){
            cout << " ";
        }
        for(x=0;x<n-current_row+1;x++){
            cout << char(a);
            a++;
        }
        --a;
        for(x=n-current_row+1;x>0;x--){
            cout << char(a);
            a--;
        }
        cout << endl;
        current_row++;
    }
    return 0;
}
