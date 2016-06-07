//Output Restricted Queue
#include<iostream>
using namespace std;
struct node{
    node *next;
    node *prev;
    int data;
};
void push(node* &head,node* &tail,int value){
    node* current_node=new node;
    current_node->next=NULL;
    current_node->data=value;
    if(!head){
        head=current_node;
        current_node->prev=NULL;
    }
    else{
        tail->next=current_node;
        current_node->prev=tail;
    }
    tail=current_node;
    cout << "New Tail : " << tail->data << endl;
}
void inject(node* &head,int value){
    node* current_node=new node;
    current_node->data=value;
    current_node->next=head;
    head=current_node;
}
void pop(node *&head){
    node* temp=head;
    head=temp->next;
    delete temp;
}
void getfront(node *head){
    cout << head->data << endl;
}
void getTail(node *tail){
    cout << tail->data << endl;
}
bool isEmpty(node *head){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node* head=NULL;
    node* tail=NULL;
    int choice1,value;
    char choice2;
    while(1){
        cout << "Choose: (1)Push|||(2)Pop|||(3)GetFront" << endl;
        cout << "(4)Inject|||(5)GetTail" << endl;
        cin >> choice1;
        switch(choice1){
            case 1:
                cout << "Enter value : ";
                cin >> value;
                push(head,tail,value);
                break;
            case 2:
                pop(head);
                break;
            case 3:
                getfront(head);
                break;
            case 4:
                cin >> value;
                inject(head,value);
                break;
            case 5:
                getTail(tail);
                break;
        }
        cout << "Want to continue? Y/N? : ";
        cin >> choice2;
        if(choice2=='n'){
            break;
        }
    }
    return 0;
}

