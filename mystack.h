#ifndef mystack_h
#define mystack_h
#include<iostream>
using namespace std;
struct node{
    node* next;
    int data;
};
void printStack(node *head){
    while(head){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "Null" << endl;
    return ;
}
void pushinStack(node* &head,int value){
    node *currentnode;
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
}
int gettop(node* &head){
    //cout << head->data << endl;
    return head->data;
}
void popfromStack(node* &head){
//    if(head==NULL){
//        cout << "Stack is empty!" << endl;
//    }
    node* temp=head;
    head=temp->next;
    delete temp;
//    cout << "New Top in stack after popping from stack into queue : ";
//    cout << head->data << endl;
}
#endif//mystack_h
//bool isStackEmpty(head){
//    if(head==NULL){
//        return true;
//    }
//    else{
//        return false;
//    }
//}

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
