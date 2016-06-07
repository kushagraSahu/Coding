#include"circularQueue.h"
int main(){
    int arr[100];
    circular_queue Q(3);
    int choice1,value;
    char choice2;
    while(true){
        cout << "Choose any of the functions :(1)Gethead||||(2)Dequeue||||(3)isEmpty" << endl << "(4)Enqueue||||(5)GetTail||||(6)isFull"<< endl;
        cin >> choice1;
        switch(choice1){
            case 1:
                Q.printhead(arr);
                break;
            case 2:
                Q.Dequeue(arr);
                break;
            case 3:
                if(Q.isCircQueueEmpty()){
                    cout << "Queue is empty!" << endl;
                }
                else{
                    cout << "Queue not empty!" << endl;
                }
                break;
            case 4:
                cout << "Enter value you want to Enqueue : ";
                cin >> value;
                Q.Enqueue(arr,value);
                break;
            case 5:
                Q.printtail(arr);
                break;
            case 6:
                Q.isFull();
                break;

        }
        cout << "Want to continue? y or n?: ";
        cin >> choice2;
        if(choice2=='y'){
            continue;
        }
        else if(choice2=='n'){
            cout << "Chao!" << endl;
            break;
        }
    }
    return 0;
}
