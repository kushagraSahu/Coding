//Priority Queue
#include<iostream>
#include<stack>
using namespace std;
stack<int> S;
struct node{
    node *next;
    int data;
    int priority;
};
void inject(node* &head,int val){
    node *current_node=new node;
    current_node->data=val;
    current_node->next=head;
    head=current_node;
    //cout << "Added in the beginning " << val << endl;
}
void popfromQueue(node* &head){
    node* temp=head;
    head=temp->next;
    delete temp;
}
void pushintoQueue(node* &head,int value,int prio){
    node *current_node=new node;
    current_node->data=value;
    current_node->priority=prio;
    if(head==NULL){
          //  cout << "R0" << endl;
        head=current_node;
        current_node->next=NULL;
        //prev_node=current_node;
    }
    else{
        //cout << "R1" << endl;
        while(head!=NULL&&((current_node->priority)>(head->priority))){
            S.push(head->data);
            cout << "Top: " <<  S.top() << endl;
            popfromQueue(head);
            //cout << head->data << endl;
        }
        if(head!=NULL){
            current_node->next=head;
            head=current_node;
        }
        else{
            head=current_node;
            current_node->next=NULL;
        }
        while(!S.empty()){
            inject(head,S.top());
            S.pop();
        }
    }
}
void getfront(node *head){
    cout << "Front : " << head->data << endl;
}
void printQueue(node* head){
    while(head){
        cout << head->data;
        head=head->next;
    }
}
int main(){
    node *head=NULL;
    pushintoQueue(head,7,2);
    getfront(head);
    //printQueue(head);
    cout << "______________" << endl;
    pushintoQueue(head,6,3);
    getfront(head);
//   printQueue(head);
    cout << "______________" << endl;
    pushintoQueue(head,5,4);
    printQueue(head);
    getfront(head);
    cout << "______________" << endl;
    pushintoQueue(head,8,5);
    getfront(head);
    cout << "_______________" << endl;
    pushintoQueue(head,10,1);
    getfront(head);
    popfromQueue(head);
    popfromQueue(head);
    popfromQueue(head);
    getfront(head);
    return 0;
}
