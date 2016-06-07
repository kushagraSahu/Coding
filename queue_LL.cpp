#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void push(node *&front,node *&rear,int value){
    node* current_node=new node;
    current_node->data=value;
    current_node->next=NULL;
    if(front==NULL){
        front=current_node;
        rear=current_node;
    }
    else{
        rear->next=current_node;
        rear=current_node;
    }
    return;
}
void pop(node *&head){
    node* temp=head;
    head=temp->next;
    delete temp;
    return;
}
void getfront(node *head){
    cout << head->data;
    return ;
}
bool isEmpty(node *head){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node*front=NULL;
    node*rear=NULL;
    if(isEmpty(front)){
        cout << "Queue is empty!" << endl;
    }
    else{
        cout << "Queue is NOT empty!" << endl;
    }
    int value;
    cout << "Enter value to be pushed in the queue" << endl;
    cin >> value;

    while(value!=-1){
        push(front,rear,value);
        cin >> value;
    }
    cout<<"Front : ";
    getfront(front);
    cout << endl;
    pop(front);
    cout << "Deleted front!" << endl;
    cout<<"New Front : ";
    getfront(front);
    cout << endl;
    pop(front);
    cout << "Deleted front!" << endl;
    if(isEmpty(front)){
        cout << "Queue is empty!" << endl;
    }
    else{
        cout << "Queue is NOT empty!" << endl;
    }
    cout << "Thanks!" << endl;
    return 0;
}
