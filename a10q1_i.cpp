#include<iostream>
using namespace std;
static int count=0;
struct node{
    node *next;
    int data;
};
void createlist(node* &head){
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
void findKthElement(node *head,int n){
    node *temp = head;
    while(temp && n){
        temp=temp->next;
        n--;
    }
    cout << temp->data;
}
int length_linkedlist(node *head){
    int len;
    node* temp1=head;
    for(len=0;temp1!=NULL;temp1=temp1->next,len++){
    }
    return len;
}
int main(){
    node* head=NULL;
    createlist(head);
    int N,len;
    len=length_linkedlist(head);
    cout << len << endl;
    cout << "Enter position from the back" << endl;
    cin >> N;
    findKthElement(head,len-N);
    return 0;
}
