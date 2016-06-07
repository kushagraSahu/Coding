#include<iostream>
using namespace std;
static int count=0;
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
node *findKthElement(node *head,int n){
    node *temp = head;
    while(temp && n){
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
void reverse_linkedlist_recursion(node* head,node* temp,int i,int len){
    int swapper;
    if(i>=len){
        return ;
    }
    else{
            reverse_linkedlist_recursion(head,temp->next,i+1,len-1);
            node* temp2 = findKthElement(head,len-1);
            swapper=temp->data;
            temp->data=temp2->data;
            temp2->data=swapper;
        }
}
int main(){
    node* head=NULL;
    createlist(head);
    int len=length_linkedlist(head);
    cout << "Reached";
    reverse_linkedlist_recursion(head,head,0,len);
    printList(head);
    return 0;
}
