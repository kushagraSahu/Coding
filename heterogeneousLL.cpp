#include<iostream>
using namespace std;
static int count=0;
struct node1;
struct node2;
struct node1{
    node2 *next;
    int data;
};
struct node2{
    node1 *next;
    char data;
};
node1 *prev_node1;
node2 *prev_node2;
void pushInt_LL(node1 *&head){
    node1 *current_node=new node1;
    int value;
    cout << "Enter an integer!" << endl;
    cin >> value;
    if(isalpha(value)){
        cout << "You have to enter an integer,not character!" << endl;
        cin >> value;
    }
        current_node->next=NULL;
        current_node->data=value;
        if(!head){
            head=current_node;
        }
        else{
            prev_node2->next=current_node;
        }
        prev_node1=current_node;
}
void pushChar_LL(){
    node2 *current_node=new node2;
    char value;
    cout << "Enter a character!" << endl;
    cin >> value;
    if(isdigit(value)){
        cout << "You have to enter a character,not integer!" << endl;
        cin >> value;
    }
    current_node->next=NULL;
    current_node->data=value;
    prev_node1->next=current_node;
    prev_node2=current_node;
}
void printint(node1 *);
void printchar(node2 *);
void printchar();
void printint(node1 *temp1){
    if(!temp1){
        return;
    }
    else{
        cout << temp1->data << "->";
        printchar(temp1->next);
    }
}
void printchar(node2 *temp2){
    if(!temp2){
        return;
    }
    else{
        cout << temp2->data << "->";
        printint(temp2->next);
    }
}
int main(){
    node1 *head=NULL;
    char choice;
    while(1){
        if(count%2==0){
            pushInt_LL(head);
        }
        else{
            pushChar_LL();
        }
        count++;
        cout << "Do you want to continue? y/n?" << endl;
        cin >> choice;
        if(choice=='n'){
            break;
        }
    }
    printint(head);
    cout << "Null" << endl;
}
