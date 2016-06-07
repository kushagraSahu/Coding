//Copy Contents of one stack into another
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> S1,S_medium,S2;
    int value;
    cout << "Enter Stack1 till -1" << endl;
    cin >> value;
    while(value!=-1){
        S1.push(value);
        cin >> value;
    }
    while(!S1.empty()){
        S_medium.push(S1.top());
        S1.pop();
    }
    while(!S_medium.empty()){
        S2.push(S_medium.top());
        S_medium.pop();
    }
    cout << "Stack2 : ";
    while(!S2.empty()){
        cout << S2.top() << " ";
        S2.pop();
    }
    return 0;
}
