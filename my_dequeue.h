#ifndef my_dequeue_h
#define my_dequeue_h
#include<iostream>
#include<stack>
using namespace std;
struct node{
    node* next;
    int priority;
    int data;
};
class dequeue{
    node* head;
    node* tail;
public:
    dequeue() : head(NULL),tail(NULL){
    }
    void push(stack<int> S,int value,int pri){
        node* current_node=new node;
        current_node->data=value;
        current_node->priority=pri;
        if(!head){
            head=current_node;
        }
        else{
            node *temp=head;
            while(current_node->priority>(temp->priority)){
                S.push(temp->data);
                cout << S.top();
                pop();
                temp=temp->next;
            }
            head=current_node;
            current_node->next=temp;
            //current_node->next=head;
            cout << "R" << endl;
            while(!S.empty()){
                cout << "R1" << endl;
                inject(S.top());
                S.pop();
                cout << "Fro" << getfront() << endl;
            }
        }
    }
    void inject(int value){
        node* current_node=new node;
        current_node->data=value;
        current_node->next=head;
        head=current_node;
    }
    void pop(){
        node* temp=head;
        head=temp->next;
        delete temp;
    }
    int getfront() const{
        return head->data;
    }
    int getTail() const{
        return tail->data;
    }
    bool isEmpty() const{
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    ~dequeue(){}
};
#endif // my_dequeue_h
