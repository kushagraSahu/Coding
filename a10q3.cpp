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
void swapIthAndJthElement(node* &head,int i,int j){
    node *ith,*iprev,*inext,*jth,*jprev,*jnext;
    if(i==0) {
        iprev=NULL;
        ith=head;
    }
    else{
        iprev=findKthElement(head,i-1);
        ith=iprev->next;
    }
    inext=ith->next;
    jprev=findKthElement(head,j-1);
    jth=jprev->next;
    jnext=jth->next;
    //Till now I've just defined each node. Below I'm going to swap ith and jth node.
    if (i==0){
        head=jth;
    }
    else{
        iprev->next=jth;
    }
    ith->next=jnext;
    if(j==i+1){//When ith and jth node are next to each other.
        jth->next=ith;
    }
    else{
        jprev->next=ith;
        jth->next=inext;
    }
    return;
}
void seperate_odd_even(node* head,int len){
    node *temp1,*temp2;
    for(int i=0;i<len;i++){
        temp1=findKthElement(head,i);
        if((temp1->data%2)==0){
            for(int j=i+1;j<len;j++){
                temp2=findKthElement(head,j);
                if((temp2->data%2)){
                    swapIthAndJthElement(head,i,j);
                    break;
                }
            }
        }
    }
    return;
}
int main(){
    node* head=NULL;
    createlist(head);
    int len=length_linkedlist(head);
    seperate_odd_even(head,len);
    printList(head);
    return 0;
}
