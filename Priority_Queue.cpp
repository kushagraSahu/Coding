#include"my_dequeue.h"
int main(){
    dequeue Q;
    stack<int> S;
    Q.push(S,5,4);
    cout << Q.getfront() << endl;
    Q.push(S,10,1);
    cout << Q.getfront() << endl;
    //cout << Q.getTail() << endl;
    Q.push(S,7,3);
    cout << Q.getfront() << endl;
   // cout << Q.getTail() << endl;
    Q.push(S,6,3);
    cout << Q.getfront() << endl;
  //  cout << Q.getTail() << endl;
    Q.push(S,9,2);
    cout << Q.getfront() << endl;
   // cout << Q.getTail() << endl;
    Q.push(S,8,2);
    cout << Q.getfront() << endl;
   // cout << Q.getTail() << endl;

   // cout << Q.getTail() << endl;
    return 0;
}
