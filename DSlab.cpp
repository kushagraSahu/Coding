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
    while(head!=NULL){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "Null" << endl;
    return ;
}
node *findKthElement(node *head,int n){
    node *temp = head;
    while(temp && n){
        temp=temp->next;
        n--;
    }
    return temp;
}
void insertion_at_kth(node* head,int k){
    node* temp2 = findKthElement(head,k);
    node* temp1 = head;
    while(temp1->next!=temp2){
        temp1=temp1->next;
    }
    node *currentnode = new node;
    currentnode->next = NULL;
    int value;
    cout << "Enter value to be inserted at position" << endl;
    cin >> value;
    currentnode->data=value;
    currentnode->next=temp2;
    temp1->next=currentnode;
    return;
}
void deletion_from_kth(node* head,int k){
    node* temp1 = head;
    node* temp2 = findKthElement(head,k);
    while(temp1->next!=temp2){
        temp1=temp1->next;
    }
    temp1->next=temp2->next;
    delete temp2;
}
int main(){
    node* head=NULL;
    createlist(head);
    int k;
    cout << "Enter position to insert" << endl;
    cin >> k;
    insertion_at_kth(head,k);
    printList(head);
    int n;
    cout << "Enter position of node to delete" << endl;
    cin >> n;
    deletion_from_kth(head,n);
    printList(head);
    return 0;
}
