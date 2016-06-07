#include<iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node* InsertinBST_recursion(node *&root,int value){
    if(!root){
        root=new node;
        root->data=value;
        root->left=root->right=NULL;
        return root;
    }
    if(root->data > value){
        root->left=InsertinBST_recursion(root->left,value);
    }
    else{
        root->right=InsertinBST_recursion(root->right,value);
    }
    return root;
}
void InsertinBST(node *&root,int value){
    node* new_node= new node;
    new_node->data=value;
    new_node->left=new_node->right=NULL;
    if(!root){
        root=new_node;
        return;
    }
    node* prev=NULL, *temp=root;
    while(temp){
        prev=temp;
        if(temp->data < value){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    if(prev->data < value){
        prev->right=new_node;
    }
    else{
        prev->left=new_node;
    }
}
void createBinaryTree(node *&root){
        int ele;
        char choice;
        cout << "Enter data for root node!" << endl;
        cin >> ele;
        root=new node;
        root->data=ele;
        queue<node *> Q;
        Q.push(root);
        while(!Q.empty()){
            node *temp=Q.front();//node *temp = new node; temp = Q.front();
            Q.pop();
            cout << "Is there a left node  " << temp->data << " y/n ?" << endl;
            cin >> choice;
            if(choice=='y'||choice=='Y'){
                cout << "Enter data for left node : ";
                cin >> ele;
                temp->left=new node;
                temp->left->data=ele;
                temp->left->left=temp->left->right=NULL;
                Q.push(temp->left);
            }
            cout << "Is there a right node " << temp->data << " y/n ?" << endl;
            cin >> choice;
            if(choice=='y'||choice=='Y'){
                cout << "Enter data for right node : ";
                cin >> ele;
                temp->right=new node;
                temp->right->data=ele;
                temp->right->left=temp->right->right=NULL;
                Q.push(temp->right);
            }
        }
    }
node *FindMin(node *root){
    while(root->left){
        root=root->left;
    }
    return root;
}
node *FindMax(node *root){
    while(root->right){
        root=root->right;
    }
    return root;
}
node *FindElement(node *root,int data1){
    while(root){
        if(root->data < data1){
            root=root->right;
        }
        else if(root->data > data1){
            root=root->left;
        }
        else{
            return root;
        }
    }
    return NULL;
}
node * deletedata(node *root, int data){
    if(root->data < data){
        root->right=deletedata(root->right,data);
    }
    else if(root->data > data){
        root->left=deletedata(root->left,data);
    }
    else{
        if(!root->left&&!root->right){
            delete root;
            return NULL;
        }
        else if(root->left&&!root->right){
            node *temp=root->left;
            delete root;
            return temp;
        }
        else if(root->right&&!root->left){
            node *temp=root->right;
            delete root;
            return temp;
        }
        else{//Case:Both left and right subtree exists. Either find min in right subtree,swap the data with node and delete it OR do same with max in left.
            node *min=FindMin(root->right);
            root->data=min->data;//Swapping data
            root->right=deletedata(root->right,min->data);
            return root;
        }
    }
    return root;
}
node *FindNextLargestElement(node *root,int value,int next_largest){
    node *next_largest_node=NULL,*temp;
    if(root->data > value && root->data < next_largest){
        next_largest=root->data;
        next_largest_node=root;
    }
    if(root->data < value){
        temp=FindNextLargestElement(root->right,value,next_largest);
        if(temp){
            if(temp->data < next_largest){
                next_largest=temp->data;
                next_largest_node=temp;
            }
        }
    }
    if(root->data > value){
        temp=FindNextLargestElement(root->left,value,next_largest);
        if(temp){
            if(temp->data < next_largest){
                next_largest=temp->data;
                next_largest_node=temp;
            }
        }
    }
    cout << " " << next_largest << endl;
    return next_largest_node;
}
void printLevelOrderBST(node *root){
    if(!root){
        return;
    }
    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        node *temp=Q.front();
        Q.pop();
        if(!temp){
            if(!Q.empty()){
                cout << endl;
                Q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                Q.push(temp->left);
            }
            if(temp->right){
                Q.push(temp->right);
            }
        }
    }
    cout << endl;
}
node *FindInOrderSuccesorOfaNodeinBST(node *root,int value){//After finding node, InOrder successor is minimum in right subtree.
    node *temp=FindElement(root,value),*in_succ;
    if(temp){
        if(temp->right){
            in_succ=FindMin(temp->right);
        }
        if(!temp->left||!temp->right){
            in_succ=FindNextLargestElement(root,temp->data,FindMax(root)->data);
        }
        return in_succ;
    }
    else{
        InsertinBST(root,value);
        return FindInOrderSuccesorOfaNodeinBST(root,value);
        //printLevelOrderBST(root);
    }
}
node *FindInOrderSuccesorOfaNodeinBST_2(node *root,int value){//Geeks for Geeks Method.(Much Better! :( )
    node* temp=FindElement(root,value),*in_succ;
    if(temp){
        if(temp->right){
            in_succ=FindMin(temp->right);
            return in_succ;
        }
        if(!temp->right){
            while(root){
                if(root->data > value){
                    in_succ=root;//In order successor will be the next largest element in the tree.
                    root=root->left;
                }
                else if(root->data < value){
                    root=root->right;
                }
                else{
                    break;
                }
            }
        }
    return in_succ;
    }
}
bool isTreeBST(node *root){
    bool ans=true;
    if(root->left){
        if(root->data>=root->left->data){
            ans=isTreeBST(root->left);
        }
        else{
            return false;
        }
    }
    if(ans){
        if(root->right){
            if(root->data<root->right->data){
                ans=isTreeBST(root->right);
            }
            else{
                return false;
            }
        }
    }
    return ans;
}
void printElementsinRangeK1K2(node *root,int k1,int k2){
    if(!root){
        return;
    }
    if(root->data > k1){ // First finding in the left subtree.
        printElementsinRangeK1K2(root->left,k1,k2);
    }
    if(root->data>=k1 && root->data<=k2){
        cout << root->data << " ";
    }
    if(root->data < k2){  // Now finding in the right subtree.
        printElementsinRangeK1K2(root->right,k1,k2);
    }
}
void printPreOrder(node *root){
    if(!root){
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void CreateBSTfromGivenPreOrderTreaversal(node *&root){
    int arr[20],len,i;
    cout << "Enter size of tree" << endl;
    cin >> len;
    cout << "Enter PreOrder Traversal: ";
    for(i=0;i<len;i++){
        cin >> arr[i];
    }
    for(i=0;i<len;i++){
        InsertinBST(root,arr[i]);
    }
}
void createBalancedBST_usingSortedArray(node *&root,int len,int arr[]){
    int i,mid;
    mid=len/2;
    InsertinBST(root,arr[mid]);//Root of the BST!
    for(i=mid-1;i>=0;i--){//Filling the left subtree.
        InsertinBST(root,arr[i]);
    }
    for(i=mid+1;i<len;i++){//Filling the right subtree.
        InsertinBST(root,arr[i]);
    }
}
int sizeOfBinaryTree(node *root){
    int temp,size;
    if(!root){
        size=0;
    }
    else{
        size=1;
    }
    if(root->left){
        temp=sizeOfBinaryTree(root->left);
        size+=temp;
    }
    if(root->right){
        temp=sizeOfBinaryTree(root->right);
        size+=temp;
    }
    return size;
}
node *findLCAinBST(node *root,int value1,int value2){
    if(root->data>value1 && root->data>value2){
        findLCAinBST(root->left,value1,value2);
    }
    else if(root->data<value1 && root->data<value2){
        findLCAinBST(root->right,value1,value2);
    }
    else{
        return root;
    }
}
node * FindLargestSubTreeWhichIsBST(node *root,int size_max){
    int size_temp;
    node *size_max_node,temp2;
    if(isTreeBST(root)){
        size_max_node=root;
    }
    else{
        if(root->left){
            temp2=FindLargestSubTreeWhichIsBST(root->left,size_max);
            size_temp=sizeOfBinaryTree(temp2);
            if(size_temp>=size_max){
                size_max=size_temp;
                size_max_node=temp2;
            }
        }
        if(root->right){
            temp2=FindLargestSubTreeWhichIsBST(root->right,size_max);
            size_temp=sizeOfBinaryTree(temp2);//size of a sub-BST in binary tree of root->right.
            if(size_temp>=size_max){
                size_max=size_temp;
                size_max_node=temp2;
            }
        }
    }
    return size_max_node;
}

int main(){
    node *root=NULL,*root2=NULL,*root3=NULL,*root4=NULL,*root5=NULL;
    int value;
    cout << "Enter no. to be inserted in Binary Search Tree. Enter -1 to exit insertion" << endl;
    cin >> value;
    while(value!=-1){
        InsertinBST(root,value);
        cin >> value;
    }
    cout << "BST inserted is below." << endl;
    printLevelOrderBST(root);
    cout << "Preorder" << endl;
    printPreOrder(root);
    cout << endl;
    cout << "Minimum element in BST: " << FindMin(root)->data << endl;
    cout << "Maximum element in BST: " << FindMax(root)->data << endl;
    cout << "InOrder Successor of 8: " << FindInOrderSuccesorOfaNodeinBST(root,8)->data << endl;
    deletedata(root,8);
    cout << "Deleted data 8. New BST is below." << endl;
    printLevelOrderBST(root);
    cout << "Enter a Binary Tree" << endl;
    createBinaryTree(root2);
    printLevelOrderBST(root2);
    if(isTreeBST(root2)){
        cout << "This tree is BST!" << endl;
    }
    else{
        cout << "This tree is not BST!" << endl;
    }
    cout << "Elements in range 8&14 : ";
    printElementsinRangeK1K2(root,8,14);
    cout << endl;
    cout << "PreOrder" << endl;
    printPreOrder(root);
    cout << endl;
    cout << "Creating a BST from PreOrder Traversal" << endl;
    CreateBSTfromGivenPreOrderTreaversal(root3);
    printLevelOrderBST(root3);
    cout << endl;
    int i,len,arr[20];
    cout << "Enter length of sorted array!" << endl;
    cin >> len;
    cout << "Enter a sorted array!" << endl;
    for(i=0;i<len;i++){
        cin >> arr[i];
    }
    createBalancedBST_usingSortedArray(root4,len,arr);
    printLevelOrderBST(root4);
    cout << endl;
    cout << "LCA of 6 & 13: " << findLCAinBST(root3,6,13)->data << endl;
    createBinaryTree(root5);
    printLevelOrderBST(root5);
    cout << "Largest Subtree in BT which is a BST is below" << endl;
    printLevelOrderBST(FindLargestSubTreeWhichIsBST(root5,0));
    cout << endl;
}
