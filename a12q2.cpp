//Parenthesis balanced or not?
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
void push_intostack(node* &head,char value){
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
    return;
}
char top(node* &head){
    return head->data;
}
void pop(node* &head){
    if(head==NULL){
        cout << "Stack is empty!" << endl;
    }
    node* temp=head;
    head=temp->next;
    delete temp;
}
bool isStackEmpty(node* &head){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node* head=NULL;
    char str[100];
    cin.getline(str,100);
    for(int i=0;str[i]!=NULL;i++){
        if(str[i]=='{'||str[i]=='['||str[i]=='('){
            push_intostack(head,str[i]);
            cout << top(head) << endl;
           }
        else if(str[i]==')'&&top(head)=='('){
            pop(head);
        }
        else if(str[i]=='}'&&top(head)=='{'){
            pop(head);
        }
        else if(str[i]==']'&&top(head)=='['){
            pop(head);
        }
    }
    if(isStackEmpty(head)){
        cout << "Parenthesis balanced!" << endl;
    }
    else{
        cout << "Parenthesis not balanced!" << endl;
    }
    return 0;
}
