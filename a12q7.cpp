#include<iostream>
using namespace std;
static int count;
struct node{
    node* next;
    char data;
};
int string_length(char str[]){
    int len;
    for(len=0;str[len]!=NULL;len++){
    }
    return len;
}
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
void emptyStack(node* &head){
    while(head){
        pop(head);
    }
    head=NULL;
}
//bool isStackEmpty(node* &head){
//    if(head==NULL){
//        return true;
//    }
//    else{
//        return false;
//    }
//}
int main(){
    node *head=NULL;
    char str[100];
    cout << "Enter balanced parenthesis expression : ";
    cin.getline(str,100);
    int i,j,len;
    len=string_length(str);
    for(i=0;i<len;i++){
        j=i;
//        cout << j << endl;
        if(str[j]=='('){
            push_intostack(head,str[j]);
            cout << top(head) << endl;
            if(str[j+1]==top(head)){
                push_intostack(head,str[j+1]);
                cout << top(head) << endl;
            }
            else{
                cout << "Emptying yo!" << endl;
                emptyStack(head);
                continue;
                cout << top(head) << endl;
            }
//            cout << "Reached!" << endl;
            while(str[j]!=')'){
                j++;
            }
            cout << "Reached after while!" << endl;
            if(str[j]==')'){
                push_intostack(head,str[j]);
                cout << top(head) << endl;
            }
            else if(str[j]=='('){
                emptyStack(head);
                cout << top(head) << endl;
                continue;
            }
            cout << "Reached!" << endl;
            if(str[j+1]==top(head)){
                cout << "Found duplicate parenthesis at position " << i << "th & " << j+1 <<"th position in the string" << endl;
                break;
            }
            else{
                cout << "AA gaya main!" << endl;
                emptyStack(head);
//                cout << top(head) << endl;
            }
        }
    }
    if(i==len){
        cout << "Duplicate parenthesis not found!" << endl;
    }
    return 0;
}
