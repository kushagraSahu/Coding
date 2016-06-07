#include<iostream>
using namespace std;
struct node{
    node *next;
    char data;
};
void createlist(node* &head){
    node *currentnode,*prevnode;
    char value;
    cin >> value;
    while(value!='$'){
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
bool check_palindrome(node* head,int i,int len){
    node* temp;
    for(temp=head;i<len;temp=temp->next,i++,len--){
        if(temp->data!=findKthElement(head,len-1)->data){
            break;
        }
    }
    if(i>=len){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node* head=NULL;
    createlist(head);
    int len=length_linkedlist(head);
    if(check_palindrome(head,0,len)){
        cout << "Its a palindrome";
    }
    else{
        cout << "Its not a palindrome";
    }
    cout << endl;
}
