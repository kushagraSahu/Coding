//Implement kReverse(int k ) in a linklist i.e. you reverse first K elements then reverse next K elements and join the linked list and so on.
//For e.g: 3 4 5 2 6 1 9 10 NULL for kreverse(3) becomes 5 4 3 1 6 2 10 9 NULL
#include <iostream>
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
void kreverse(node* &head,int k,int len){//If we don't put the '&' before head in the argument, head(main) will still point to 1.
    int i,j;
    for(i=0;i<len;i+=k){
        j=i+k-1;
        while(j>=len){//For left out cases. for eg: for k=3,if only two elements are left in the sub array, j will exceed length.
            j--;
        }
        int m,n;
        for(m=i,n=j;m<=n;m++,n--){
            swapIthAndJthElement(head,m,n);
        }
    }
//    printList(head);
    return;
}
int main(){
    node* head=NULL;
    createlist(head);
    int k,len;
    cout << "Enter k : ";
    cin >> k;
    len=length_linkedlist(head);
    kreverse(head,k,len);
    printList(head);
    return 0;
}
