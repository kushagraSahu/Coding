//Concatenate two linked list.
#include<iostream>
using namespace std;
struct node{
    node *next;
    int data;
};
void createlist(node* &head){
    head = NULL;
    node *currentnode,*prevnode;
    int value;
    cin >> value;
    while(value!=-1){
        currentnode=new node;
        currentnode->next=NULL;
        currentnode->data=value;
        if(head==NULL){
            head=currentnode;
        }
        else{
            prevnode->next=currentnode;
        }
        prevnode=currentnode;
        cin >> value;
    }
    return;
}
void concatenate(node *head1,node *head2){
    while(head1->next!=NULL){
        head1=head1->next;
    }
    head1->next=head2;
    return;
}
void printList(node *head){
    while(head){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "Null" << endl;
    return ;
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    cout << "Enter linked list1" << endl;
    createlist(head1);
    cout << "Enter linked list2" << endl;
    createlist(head2);
    concatenate(head1,head2);
    cout << "Concatenated Linked list" << endl;
    printList(head1);
    return 0;
}
