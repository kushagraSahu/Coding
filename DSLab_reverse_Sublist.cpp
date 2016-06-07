#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
void createlist(node* &head){
    node *current_node,*prevnode;
    int value;
    cin>>value;
    while(value!=-1){
        current_node=new node;
        current_node->data=value;
        current_node->next=NULL;
        if(!head){
            head=current_node;
        }
        else{
            prevnode->next=current_node;
        }
        prevnode=current_node;
        cin>>value;
    }
    return;
}
void printlist(node* head){
    while(head){
        cout << head->data << "->";
        head=head->next;
    }
    cout << "Null" << endl;
    return;
}
node *findkthelement(node *head,int n){
    while(head&&n){
        head=head->next;
        n--;
    }
    return head;
}
void swapIthAndJthElement(node* &head,int i,int j){
    node *ith,*iprev,*inext,*jth,*jprev,*jnext;
    if(i==0){
        iprev=0;
        ith=head;
    }
    else{
        iprev=findkthelement(head,i-1);
        ith=iprev->next;
    }
    inext=ith->next;
    jprev=findkthelement(head,j-1);
    jth=jprev->next;
    jnext=jth->next;
    //Till now just defined these variables; Now swap these nodes!
    if(i==0){
        head=jth;
    }
    else{
        iprev->next=jth;
    }
    ith->next=jnext;
    if(j==i+1){
        jth->next=ith;
    }
    else{
        jprev->next=ith;
        jth->next=inext;
    }
    return;
}
void reverse_subLL(node* &head,int i,int j){
    while(i<j){
        swapIthAndJthElement(head,i,j);
        i++;
        j--;
    }
    return;
}
int main(){
    node *head=NULL;
    createlist(head);
    int i,j;
    cout << "Enter the start and end position of the sublist!" << endl;
    cin >> i >> j;
    reverse_subLL(head,i,j);
    printlist(head);
    return 0;
}
