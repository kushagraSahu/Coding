#ifndef LL_h
#define LL_h
#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node():next(NULL){}//constructor with 0 arguments
};
class LinkedList{
    public:
    node *head;
    LinkedList():head(NULL){}

    void createLinkedList(node *&head){
        node *currentnode, *prevnode;
        int value;
        cin >> value;
        while(value!=-1){
            currentnode = new node;
            currentnode->data = value;
            if (!head){
                head = currentnode;
            }
            else{
                prevnode->next = currentnode;
            }
            prevnode = currentnode;
            cin >> value;
        }
        return;
    }

    void printList(node *head){
        while(head){
            cout << head->data << "->";
            head = head->next;
        }
        cout << "X";
    }

    //0th element will return the head and not the 1st element
    node *findKthElement(node *head, int k){
        while(head && k){
            head = head->next;
            k--;
        }
        return head;
    }

    int length(node *head){
        int len;
        for(len=0;head!=NULL;head=head->next,len++){
        }
        return len;
    }

    bool is_Palindrome(node *head){
        int len = length(head);
        node *temp;
        int i;
        for(temp = head,i=0;i<len;temp=temp->next,i++,len--){
            if(temp->data!=findKthElement(head,len-1)->data){
                break;
            }
        }
        if(i>=len){
            return true;
        }
        else{
            return false;
        }
    }

    // j>i
    void swapIthAndJthElement(node *&head, int i, int j){
        // Defining elements.
        node *node_i, *node_j, *node_j_prev, *node_j_next, *node_i_prev, *node_i_next;
        node_i = findKthElement(head, i);
        node_j = findKthElement(head, j);
        node_i_prev = findKthElement(head, i-1);
        node_j_prev = findKthElement(head, j-1);
        node_i_next = node_i->next;
        node_j_next = node_j->next;
        // Swapping starts..
        if (i==0){
            head = node_j;
        }
        else{
            node_i_prev->next = node_j;
        }

        if (i==j-1){
            node_j->next = node_i;
        }
        else{
            node_j_prev->next = node_i;
            node_j->next = node_i_next;
        }
        node_i->next = node_j_next;
        return;
    }

    void seperateOddEvenElements(node *&head){
        node *temp1, *temp2;
        int len = length(head);
        for(int i=0;i<len;i++){
            temp1 = findKthElement(head, i);
            if(temp1->data%2==0){
                for(int j=i+1;j<len;j++){
                    temp2 = findKthElement(head, j);
                    if(temp2->data%2){
                        swapIthAndJthElement(head, i, j);
                        break;
                    }
                }
            }
        }
        return;
    }

    void deleteDuplicatesFromSortedLL(node *&head){
        node *temp=head,*temp2;
        while(temp->next->next!=NULL){
            temp2=temp->next;
            if(temp->data==temp2->data){
                temp->next=temp2->next;
                delete temp2;
            }
            temp=temp->next;
        }
        return;
    }

    void appendLastNelementsToFront(node *&head, int n){
        int len = length(head);
        if (n==len){
            return;
        }
        else{
            // First joining last element to head making it circular.
            node *temp = findKthElement(head, len-1);
            temp->next = head;
            // Now breaking the LL from position n from behind.
            temp = findKthElement(head, len-n-1);
            head = temp->next;
            temp->next = NULL;
        }
        return;
    }

    void kReverse(node *&head, int k){
        int i,j,m,n;
        int len = length(head);
        for(i=0;i<len;i+=k){
            j=i+k-1;
            while(j>=len){
                j--;
            }
            for(m=i,n=j;m<=n;m++,n--){
                swapIthAndJthElement(head,m,n);
            }
        }
        return;
    }

};

// Creating a Heterogenous Linked List: 1 a 2 b 3 c 4 d 5 g ...
struct node1;
struct node2;

struct node1 {
    int data;
    node2 *next;
};

struct node2 {
    char data;
    node1 *next;
};

node1 *prevnode1;
node2 *prevnode2;

void pushIntegerInLL(node1 *&head){
    node1 *currentnode = new node1;
    int value;
    cin >> value;
    if(isalpha(value)){
        cout << "Enter an Integer not a character" << endl;
        cin >> value;
    }
    currentnode->data = value;
    currentnode->next = NULL;
    if(head){
        prevnode2->next = currentnode;
    }
    else{
        head = currentnode;
    }
    prevnode1 = currentnode;
    return;
}

void pushCharacterInLL(){
    node2 *currentnode = new node2;
    char value;
    cin >> value;
    if(isdigit(value)){
        cout << "Enter a Character not an Integer" << endl;
        cin >> value;
    }
    currentnode->data = value;
    currentnode->next = NULL;
    prevnode1->next = currentnode;
    prevnode2 = currentnode;
}

void printIntNode(node1 *);
void printCharNode(node2 *);

void printCharNode();
void printIntNode(node1 *temp1){
    if(!temp1){
        return;
    }
    else{
        cout << temp1->data << "-->";
        printCharNode(temp1->next);
    }
}

void printCharNode(node2 *temp2){
    if(!temp2){
        return;
    }
    else{
        cout << temp2->data << "-->";
        printIntNode(temp2->next);
    }
}


void createHeterogeneousLL(node1 *&head){
    char choice;
    int count = 0;
    while(1){
        if(count%2==0){
            pushIntegerInLL(head);
        }
        else{
            pushCharacterInLL();
        }
        count++;
        cout << "Do you want to continue? y/n?" << endl;
        cin >> choice;
        if(choice=='n'){
            break;
        }
    }
}

#endif // LL_h



















