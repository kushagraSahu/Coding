//Reverse a stack using a stack.
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
void push_into_newstack(node* &head2,char value){
    node *currentnode;
    currentnode=new node;
    currentnode->data=value;
    currentnode->next=NULL;
    if(head2==NULL){
        head2=currentnode;
    }
    else{
        currentnode->next=head2;
        head2=currentnode;
    }
    return;
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
void top(node* &head){
    cout << head->data << endl;
    return;
}
void pop(node* &head){
    if(head==NULL){
        cout << "Stack is empty!" << endl;
    }
    node* temp=head;
    head=temp->next;
    delete temp;
    cout << "New Top : ";
    top(head);
}
int main(){
    node* head1=NULL;
    cout << "Start pushing elements into stack1 till $ : ";
    push(head1);
    printList(head1);
    node* head2=NULL;
    char val;
    while(head1!=NULL){
        val=head1->data;
        push_into_newstack(head2, val);
        head1=head1->next;
    }
    delete head1;
    cout << "Reversed stack : ";
    printList(head2);
    printList(head1);
    return 0;
}
