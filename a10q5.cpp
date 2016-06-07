//Append the last n elements of a linked list to the front. e.g. 1 2 3 4 5 6  null and n = 2 would return 5 6 1 2 3  4  null
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
    cout << "null" << endl;
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
void append_last_n_elements(node* &head,int n,int len){
    node* temp=head;
    node *tail,*tailprev;
    int i;
    for(i=0;i<n;i++){
        tail=findKthElement(head,len-1);
        tailprev=findKthElement(head,len-2);
        tailprev->next=tail->next;
        tail->next=head;
        head=tail;
    }
    return;
}
int main(){
    node* head=NULL;
    createlist(head);
    int n,len=length_linkedlist(head);
    cout << "Enter n : ";
    cin >> n;
    append_last_n_elements(head,n,len);
    printList(head);
    return 0;
}
