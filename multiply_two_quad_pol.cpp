#include<iostream>
using namespace std;
struct node{
    node *next;
    int data;
};
void createlist(node* &head){
    head=NULL;
    node *currentnode, *prevnode;
    int value;
    cin >> value;
    while(value!=-1){
        currentnode = new node;
        currentnode->data = value;
        currentnode->next = NULL;
        if(head==NULL){
            head=currentnode;
        }
        else{
            prevnode->next=currentnode;
        }
        prevnode = currentnode;
        cin >> value;
    }
    return ;
}
void printList(node *head){
    while(head){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "Null" << endl;
    return ;
}
void multiply_list(node *head1,node *head2,node* &head){
    int arr[5]={0},i,j,k,sum;
    for( i=2;head1!=NULL&&i>=0;i--,head1=head1->next){
        node *temp;
        for(temp=head2,j=2;temp!=NULL&&j>=0;j--,temp=temp->next){
            k = i+j;
            sum = head1->data*temp->data;
            arr[k]=sum+arr[k];
        }
    }
    node* prev;
    for(int i=4;i>=0;i--){
        node *current = new node;
        current->data = arr[i];
        current->next = NULL;
        if(head==NULL){
            head = current;
            prev = current;
        }
        else{
            prev->next = current;
            prev = current;
        }
    }

}
int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    cout << "Enter 1st list" << endl;
    createlist(head1);
    printList(head1);
    cout << "Enter 2nd list" << endl;
    createlist(head2);
    printList(head2);
    node* head3=NULL;
    multiply_list(head1,head2,head3);
    cout << "Final list" << endl;
    printList(head3);
    return 0;
}
