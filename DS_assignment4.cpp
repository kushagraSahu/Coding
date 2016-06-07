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
        cin >> value;//    printList(head);
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
node * insert_linkedlist(node* head,int value){
    node* currentnode = new node;
    currentnode->data=value;
    node* temp=head;
        if(!temp){
            head=currentnode;
            head->next=NULL;
        }
        else{
            while(temp->next){
                temp=temp->next;
            }
            currentnode->next=NULL;
            temp->next=currentnode;
        }
        return head;
}
void intersection_2sortedLL(node* head,node* head1,node* head2){
    node* temp;
    for( ;head1!=NULL;head1=head1->next){
        for(temp=head2;temp!=NULL;temp=temp->next){
            if(head1->data==temp->data){
                if (!head)
                {
                    head=insert_linkedlist(head,head1->data);
                }
                else
                    insert_linkedlist(head,head1->data);
            }
        }
    }
    printList(head);
    return;
}
int main(){
    node* head=NULL;
    node* head1=NULL;
    node* head2=NULL;
    createlist(head1);
    createlist(head2);
    intersection_2sortedLL(head,head1,head2);

    return 0;
}
