//Split two linked list.
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
node *findKthElement(node *head,int n){
    node *temp = head;
    while(temp && n){
        temp=temp->next;
        n--;
    }
    return temp;
}
void printList(node *head){
    while(head!=NULL){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "Null" << endl;
    return ;
}
void split(node *head2,node *head){
    node* head1=head;
    int N;
    cout << "From which position you want to split" << endl;
    cin >> N;
    head2=findKthElement(head,N);
    while(head->next!=head2){
        head=head->next;
    }
    cout << head2->data << endl;
    head->next=NULL;
    cout << "Split Linked list 1 : " << endl;
    printList(head1);
    cout << "Split Linked list 2 : " << endl;
    printList(head2);
    return;
}
int main(){
    node* head=NULL;
    node* head2=NULL;
    cout << "Enter linked list" << endl;
    createlist(head);
    split(head2,head);
    return 0;
}
