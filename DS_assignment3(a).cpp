//k1 and k2 values between which we want to delete elements of linked list.
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
void printList(node *head){
    while(head){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "Null" << endl;
    return ;
}
void delete_between_k1andk2(node* &head,int k1,int k2){
    node* temp;
    node* temp2;
    for(temp=head;temp->data!=k1;temp=temp->next){
    }
    for(temp2=temp->next;temp2->data!=k2;temp2=temp2->next){
    }
    temp->next=temp2;
    printList(head);
    return;
}
int main(){
    node* head=NULL;
    createlist(head);
    int k1,k2;
    cout << "Enter k1 and k2 between which you want to delete elements of linked list : ";
    cin >> k1 >> k2;
    delete_between_k1andk2(head,k1,k2);
    return 0;
}
