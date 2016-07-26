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
        cout << "X" << endl;
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

    node *findMiddleOfLL(node *head){
        node *temp1=head, *temp2=head;
        while(temp2 && temp2->next){
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        return temp1;
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

    //Rotate a Linked List.
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

    bool LoopInLL(node *head){
        node *temp1 = head;
        node *temp2 = head;
        while(temp1 && temp2){
            temp1=temp1->next;
            temp2=temp2->next->next;
            if(temp1==temp2){
                return true;
            }
        }
        return false;
    }

    void mergeLL1intoLL2atAltPos(node *&head1, node *head2){
        node *temp1=head1;
        node *temp2=head2;
        node *temp3, *temp4;
        while(temp1 && temp2){
            temp3=temp1->next;
            temp4=temp2->next;
            temp1->next=temp2;
            if(temp3){
                temp2->next=temp3;
            }
            temp1=temp3;
            temp2=temp4;
        }
        return;
    }

    //Creating partition for implementing Quicksort in LL.
    int partition(node *&head, int start, int end){
        node *pivot = findKthElement(head, end);
        int i=start;
        int j=end-1;
        while(i<j){
            //Finding index which has value > pivot.
            while(findKthElement(head, i)->data < pivot->data){
                i++;
            }
            //Finding index which has value < pivot.
            while(findKthElement(head, j)->data > pivot->data){
                j--;
            }
            if(i<j){
                swapIthAndJthElement(head, i, j);
            }
        }
        // After i and j pointers have crossed each other.
        swapIthAndJthElement(head, i, end);
        return i;
    }

    void Quicksort(node *&head, int start, int end){
        if(start>=end){
            return;
        }
        int pivot_index = partition(head, start, end);
        Quicksort(head, start, pivot_index-1);
        Quicksort(head, pivot_index+1, end);
    }

    void ZigZagLL(node *&head){
        int i;
        node *temp=head;
        for(i=0;temp->next->next;temp=temp->next,i++){
            if(i%2==0){
                if(temp->data > temp->next->data){
                    swapIthAndJthElement(head, i, i+1);
                }
                if(temp->next->data < temp->next->next->data){
                    swapIthAndJthElement(head, i+1, i+2);
                }
            }
            else{
                if(temp->next->data > temp->next->next->data){
                    swapIthAndJthElement(head, i+1, i+2);
                }
            }
        }
    }

    void pushInFinalLL(node *&head3,node *&refNode, node *&newNode){
        if(!head3){
            head3 = newNode;
        }
        else{
            refNode->next = newNode;
        }
        refNode = newNode;
    }

    void mergeTwoSortedLL(node *head1, node *head2, node *&head3){
        node *refNode = NULL;//Will keep record of last filled node in final LL.
        while(head1 && head2){
            if(head1->data < head2->data){
                pushInFinalLL(head3, refNode, head1);
                head1 = head1->next;
            }
            else{
                pushInFinalLL(head3, refNode, head2);
                head2 = head2->next;
            }
        }
        if(head1){
            while(head1){
                pushInFinalLL(head3, refNode, head1);
                head1 = head1->next;
            }
        }
        else{
            while(head2){
                pushInFinalLL(head3, refNode, head2);
                head2 = head2->next;
            }
        }
        return;
    }

    void deleteLastOccurrenceOfNode(node *&head, int key){
        node *temp=head, *prevnode, *targetnode;
        if(head->data == key){
            prevnode = NULL;
        }
        while(temp->next){
            if(temp->next->data == key){
                prevnode=temp;
                targetnode=temp->next;
            }
            temp=temp->next;
        }
        cout << endl;
        if(!prevnode){
            temp=head;
            head=temp->next;
            delete temp;
        }
        else{
            prevnode->next = targetnode->next;
            delete targetnode;
        }
    }

    void reverseLL(node *&head){
        node *prevnode=NULL, *next;
        while(head){
            next = head->next;
            head->next=prevnode;
            prevnode=head;
            if(next){
                head=next;
            }
            else{
                break;
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

struct randomNode{
    int data;
    randomNode *next;
    randomNode *random;
};

void createNextLinksInRandomLL(randomNode *&head){
    randomNode *currentnode, *prevnode;
    int value;
    cin >> value;
    while(value!=-1){
        currentnode = new randomNode;
        currentnode->data = value;
        currentnode->next = NULL;
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

int lengthOfRandomLL(randomNode *head){
    int len;
    for(len=0;head!=NULL;head=head->next,len++){
    }
    return len;
}

randomNode *findKthElementInRandomLL(randomNode *head, int k){
    while(head && k){
        head = head->next;
        k--;
    }
    return head;
}

void printNextPtrRandomList(randomNode *head){
    cout << "Next ptrs" << endl;
    while(head){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "X" << endl;
}

void printRandomPtrRandomList(randomNode *head){
    cout << "Random ptrs" << endl;
    while(head){
        cout << head->data << "->";
        cout << head->random->data << endl;
        head = head->next;
    }
    cout << "X" << endl;
}

void createRandomLinksinLL(randomNode *&head, int arr[]){
    for(int i=0;i<lengthOfRandomLL(head);i++){
        findKthElementInRandomLL(head, i)->random = findKthElementInRandomLL(head, arr[i]);
    }
    return;
}

//Function for both Method1.
//Cloning only next pointers of original LL
void cloneOnlyNextPtrsLL(randomNode *heado, randomNode *&headc){
    randomNode *currentnode, *prevnode;
    while(heado){
        currentnode = new randomNode;
        currentnode->data = heado->data;
        currentnode->next = NULL;
        if(!headc){
            headc = currentnode;
        }
        else{
            prevnode->next = currentnode;
        }
        prevnode = currentnode;
        heado = heado->next;
    }
    return;
}

//Function for Method1.
//Storing org next pointers of original LL before changing them.
void storeNextPtrsOfOriginalLL(randomNode *heado, randomNode *arr[]){
    for(int i=0;heado;heado=heado->next,i++){
        arr[i] = heado;
    }
    return;
}

//Function for Method1
void restoreOriginalLL_1(randomNode *&heado, randomNode *arr[]){
    randomNode *temp = heado;
    for(int i=1;arr[i];i++){
        temp->next = arr[i];
        temp=temp->next;
    }
    temp->next=NULL;
    return;
}

//Method 1 -> Space,Time Complexity->O(n) (GeeksForGeeks)
void cloneRandomLL_1(randomNode *heado, randomNode *&headc){
    cloneOnlyNextPtrsLL(heado, headc);
    randomNode *arr[20] = {NULL};
    storeNextPtrsOfOriginalLL(heado, arr);

    //Original LLnode->next = CorrespondingCloneLLnode
    randomNode *temp = headc;
    for(int i=0;arr[i];i++){
        cout << i << endl;
        arr[i]->next = temp;
        temp=temp->next;
    }

    //Setting random ptr of cloneLLnode to corresponding Original LLnode
    temp = headc;
    for(int i=0;arr[i];i++){
        temp->random = arr[i];
        temp=temp->next;
    }

    //Final step!
    temp = headc;
    while(temp){
        temp->random = temp->random->random->next;
        temp=temp->next;
    }
    //Current situation: heado->headc->clonedLL; Original LL is disturbed.
    restoreOriginalLL_1(heado, arr);
    return;
}

//Function for Method2
//void insertCopyNodeBtwOriginalLL(randomNode *heado){
//    randomNode *currentnode, *temp=heado;
//    while(temp){
//        currentnode = new randomNode;
//        currentnode->data = temp->data;
//        currentnode->next = temp->next;
//        temp->next = currentnode;
//        temp = temp->next->next;

//Function for Method2
void restoreBothLL(randomNode *heado, randomNode *headc){
    randomNode *temp1=heado, *temp2=headc;
    while(temp1 && temp2){
        temp1->next = temp1->next->next;
        if(temp2->next){
            temp2->next = temp2->next->next;
        }
        else{
            temp2->next=NULL;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return;
}

//Method2 -> Time Complexity->O(n), Space Complexity->O(1) since not storing addr in an array (Anushray Bhaiya, clicked right away!)
void cloneRandomLL_2(randomNode *heado, randomNode *&headc){
    randomNode *currentnode, *temp=heado;
    while(temp){
        currentnode = new randomNode;
        currentnode->data = temp->data;
        currentnode->next = temp->next;
        temp->next = currentnode;
        temp = temp->next->next;
    }
    if(!heado){
        cout << "BC" << endl;
    }
    randomNode *temp1=heado;
    printNextPtrRandomList(heado);
    headc = heado->next;
    while(temp1){
        cout << temp1->data << endl;
        temp1->next->random = temp1->random->next;
        temp1 = temp1->next->next;
    }
//    restoreBothLL(heado, headc);
    return;
}

struct stringNode{
    string data;
    stringNode *next;
};


#endif // LL_h



















