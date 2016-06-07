#ifndef mystack_h
#define mystack_h
#include<iostream>
using namespace std;
struct node{
    node* next;
    char data;
};
void printList(node *head){
    while(head){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "Null" << endl;
    return ;
}
void push(node* &head){
    node *currentnode;
    char value;
    cin >> value;
    while(value!='$'){
        currentnode=new node;
        currentnode->data=value;
        currentnode->next=NULL;
        if(head==NULL){
            head=currentnode;
        }
        else{
            currentnode->next=head;
            head=currentnode;
        }
        cin >> value;
    }
}
node *top(node* &head){
    //cout << head->data << endl;
    return head;
}
void pop(node* &head){
    if(head==NULL){
        cout << "Stack is empty!" << endl;
    }
    node* temp=head;
    head=temp->next;
    delete temp;
    cout << "New Top : ";
    cout << head->data << endl;
}
#endif
//int main(){
//    node* head=NULL;
//    cout << "Start pushing elements into stack till $ : ";
//    push(head);
//    printList(head);
//    char ch;
//    while(1){
//        cout << "Do you want to poop" << endl;
//        cin >> ch;
//        if(ch=='y'){
//            pop(head);
//        }
//        else{
//            break;
//        }
//    }
//    printList(head);
//    return 0;
//}
