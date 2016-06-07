//Reverse a queue using stack.
#include"mystack.h"
void push(node* &front,node* &rear){
    node* current_node;
    int value;
    cin >> value;
    while(value!=-1){
        current_node=new node;
        current_node->data=value;
        current_node->next=NULL;
        if(front==NULL){
            front=current_node;
            rear=current_node;
        }
        else{
            rear->next=current_node;
            rear=current_node;
        }
        cin >> value;
    }
}
void printqueue(node* front){
    while(front!=NULL){
        cout << front->data << "->";
        front=front->next;
    }
    cout << "NULL" << endl;
}
void getfront(node* front){
    cout <<  front->data << endl;
}
void popfromqueue(node* &front){
    node* temp=front;
    front=temp->next;
    delete temp;
}
void from_StacktoQueue(node* &front2,node* &rear2,int value){
        node* current_node;
        current_node=new node;
        current_node->data=value;
        current_node->next=NULL;
        if(front2==NULL){
            front2=current_node;
            rear2=current_node;
        }
        else{
            rear2->next=current_node;
            rear2=current_node;
        }
        cout << "Reached!" << endl;
}
bool isQueueEmpty(node* &front){
    if(front==NULL){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node *head=NULL;
    node *front=NULL;
    node *rear=NULL;
    cout << "Push into the queue till the number -1: ";
    push(front,rear);
    cout << "Your queue : ";
    printqueue(front);
    while(front){
        pushinStack(head,front->data);
        popfromqueue(front);
    }
    cout << "Queue is now empty and elements have been transferred to Stack!" << endl;
    node *front2=NULL;
    node *rear2=NULL;
    while(head->next){
        from_StacktoQueue(front2,rear2,head->data);
//        getfront(rear2);
        cout << "::::::::::::" << endl;
        popfromStack(head);
    }
    from_StacktoQueue(front2,rear2,head->data);
    printqueue(front2);
    return 0;
}
