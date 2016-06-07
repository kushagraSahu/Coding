//Queue using Doubly Linked List.
#include<iostream>
using namespace std;
struct node{
    node *next;
    node *prev;
    int data;
};
void push(node* &head,node* &tail,int value){
    node* current_node=new node;
    current_node->next=NULL;
    current_node->data=value;
    if(!head){
        head=current_node;
        current_node->prev=NULL;
    }
    else{
        tail->next=current_node;
        current_node->prev=tail;
    }
    tail=current_node;
    cout << "New Tail : " << tail->data << endl;
}
void pop(node* &head){
    node *temp=head;
    //cout << temp->next->data;
    head=temp->next;
   // cout << "New Head : " << head->data << endl;
    delete temp;
}
void getfront(node *head){
    if(head==NULL){
        cout << "Queue is empty!" << endl;
    }
    else{
        cout << "Head of Queue : " << head->data << endl;
    }
}
int main(){
    node* head=NULL;
    node* tail=NULL;
    int choice1,value;
    char choice2;
    while(1){
        cout << "Choose: (1)Push|||(2)Pop|||(3)GetFront" << endl;
        cin >> choice1;
        switch(choice1){
            case 1:
                cout << "Enter value : ";
                cin >> value;
                push(head,tail,value);
                break;
            case 2:
                pop(head);
                break;
            case 3:
                getfront(head);
                break;
        }
        cout << "Want to continue? Y/N? : ";
        cin >> choice2;
        if(choice2=='n'){
            break;
        }
    }
    return 0;
}
