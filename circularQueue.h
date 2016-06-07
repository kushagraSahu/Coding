#ifndef circularqueue_h
#define circularqueue_h
#include<iostream>
using namespace std;
class circular_queue{
    int head;
    int tail;
    int length;
public:
    circular_queue(int le): head(-1),tail(-1),length(le){
    }
    void Enqueue(int arr[],int value){
        if(head==-1){
            head=0;
            tail=0;
            arr[tail]=value;
        }
        else if(((head==0)&&(tail==length-1))||tail+1==head){
            cout << "Queue is full. OVERFLOW!" << endl;
        }
        else if(tail==length-1){
            tail=0;
            arr[tail]=value;
        }
        else{
            tail++;
            arr[tail]=value;
        }
    }
    void Dequeue(int arr[]){
        if(head==-1){
            cout << "Queue is empty. UNDERFLOW!" << endl;
        }
        if(head==length-1){
            head=0;
        }
        else{
            head++;
        }
    }
    void printhead(const int arr[]) const{
        cout << "Head of queue : " << arr[head] << endl;
    }
    void printtail(const int arr[]) const{
         cout << "Tail of queue : " << arr[tail] << endl;
    }
    bool isCircQueueEmpty() const{
        if(head==tail){
            return true;
        }
        else{
            return false;
        }
    }
    void isFull();
    ~circular_queue(){}
};
void circular_queue::isFull(){
    if((head==tail+1)||((head==0)&&(tail=length-1))){
            cout << "Queue is Full!" << endl;
        }
        else{
            cout << "Queue is not full" << endl;
        }
        return;
}
#endif // circularqueue_h
