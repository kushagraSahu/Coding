#include<iostream>
using namespace std;
struct node{
    node* next;
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
node *findKthElement(node *head,int n){
    node *temp=head;
    while(temp&&n){
        temp=temp->next;
        n--;
    }
    return temp;
}
int length_linkedlist(node *head){
    int len;
    node* temp1=head;
    for(len=0;temp1!=0;temp1=temp1->next,len++){
    }
    return len;
}
void delete_duplicates_from_sortedLL(node* head){
    node *temp=head,*temp2;
    while(temp->next!=NULL){
        temp2=temp->next;
        if(temp->data==temp2->data){
            temp->next=temp2->next;
            delete temp2;
        }
        temp=temp->next;
    }
}
int main(){
    node* head=NULL;
    createlist(head);
    delete_duplicates_from_sortedLL(head);
    printList(head);
    return 0;
}
