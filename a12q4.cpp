//Implement a queue using 2 stacks.
#include<iostream>
using namespace std;
struct node{
    node *next;
    int data;
};
void printstack(node* head){
    while(head){
        cout << head->data << " ";
        head=head->next;
    }
}
void push(node* &head){
    node *currentnode;
    int value;
    cin >> value;
    while(value!=-1){
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
        cin >> value;
    }
}
void push_intostack(node* &head,int value){
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
void push_into_newstack(node* &head,int value){
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
void top(node* &head){
    cout << head->data << endl;
    return;
}
void pop(node* &head){
    if(head==NULL){
        cout << "Stack is empty!" << endl;
    }
    node* temp=head;
    head=temp->next;
    delete temp;
}
int main(){
    node* head1=NULL;
    cout << "Enter queue till -1" << endl;
    push(head1);
    node *head2=NULL;
    int choice1,value;
    char choice2;
    while(true){
        cout << "Choose any of the functions :(1)Getfront||||(2)Pop||||(3)isEmpty||||(4)Push more!"<< endl;
        cin >> choice1;
        switch(choice1){
            case 1:
                if(head2==NULL){
                    while(head1){
                        push_into_newstack(head2,head1->data);
                        head1=head1->next;
                    }
                    top(head2);
                }
                else{
                    top(head2);
                }
                break;

            case 2:
                if(head2){
                    pop(head2);
                }
                else{
                    while(head1){
                        push_into_newstack(head2,head1->data);
                        head1=head1->next;
                    }
                    pop(head2);
                }
                break;
            case 3:
                if(head1==NULL&&head2==NULL){
                    cout << "Queue is empty" << endl;
                }
                else{
                    cout << "Queue not empty" << endl;
                }
                break;
            case 4:
                cout << "Enter value : ";
                cin >> value;
                if(head1){
                    push_intostack(head1,value);
                }
                else{
                    while(head2){
                        push_into_newstack(head1,head2->data);
                        head2=head2->next;
                    }
                    push_intostack(head1,value);
                }
                break;
            case 5:
                cout << "Stack1 : ";
                printstack(head1);
                cout << "Stack2 : ";
                printstack(head2);
        }
        cout << "Want to continue? y or n?: ";
        cin >> choice2;
        switch(choice2){
        case 'y':
            continue;
            break;
        }
        if(choice2=='n'){
            cout << "Chao!" << endl;
            break;
        }
    }
    return 0;
}
