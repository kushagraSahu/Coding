#ifndef Binary_tree_aft_generic_h
#define Binary_tree_aft_generic_h
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
class node{
    public:
    int sum;
    T data;
    node *left;
    node *right;
    node *parent;
    node():left(NULL),right(NULL),parent(NULL),sum(0){}//Constructor with 0 arguments.
};
template<typename T>
struct node_LL{
    T data_LL;
    node_LL *next;
};
template<typename T>
class BinaryTree{
    public:
    node<T> *root;
    BinaryTree():root(NULL){}
    void createBinaryTree(node<T> *&root){
        T ele;
        char choice;
        cout << "Enter data for root node!" << endl;
        cin >> ele;
        root=new node<T>;
        root->data=ele;
        queue<node<T> *> Q;
        Q.push(root);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            cout << "Is there a left node  " << temp->data << " y/n ?" << endl;
            cin >> choice;
            if(choice=='y'||choice=='Y'){
                cout << "Enter data for left node : ";
                cin >> ele;
                temp->left=new node<T>;
                temp->left->data=ele;
                Q.push(temp->left);
            }
            cout << "Is there a right node " << temp->data << " y/n ?" << endl;
            cin >> choice;
            if(choice=='y'||choice=='Y'){
                cout << "Enter data for right node : ";
                cin >> ele;
                temp->right=new node<T>;
                temp->right->data=ele;
                Q.push(temp->right);
            }
        }
    }
    void PrintLevelOrderBT(node<T> *root){
        if(!root){
            return;
        }
        queue<node<T> *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    cout << endl;
                    Q.push(NULL);
                }
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left){
                    Q.push(temp->left);
                }
                if(temp->right){
                    Q.push(temp->right);
                }
            }
        }
    }
    void PrintPreOrder(node<T> *root){
        if(!root){
                return;
            }
            cout << root->data << " ";
            PrintPreOrder(root->left);
            PrintPreOrder(root->right);
    }
    void printInOrder(node<T> *root){
        if(!root){
            return;
        }
        printInOrder(root->left);
        cout<<root->data<<" ";
        printInOrder(root->right);
    }
    void PrintPostOrder(node<T> *root){
        if(!root){
            return;
        }
        PrintPostOrder(root->left);
        PrintPostOrder(root->right);
        cout<<root->data<< " ";
    }
    int FindHeightOfBinaryTree(node<T> *root){
        int height=-1;
        int temp;
        if(root->left){
            temp=FindHeightOfBinaryTree(root->left);
            if(temp>height){
                height=temp;
            }
        }
        if(root->right){
            temp=FindHeightOfBinaryTree(root->right);
            if(temp>height){
                height=temp;
            }
        }
        return height+1;
    }
    int FindDepthOfNode(node<T> *root,int value){
        int depth=0;
        queue<node<T> *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    depth++;
                    Q.push(NULL);
                }
            }
            else{
                if(temp->data==value){
                    break;
                }
                if(temp->left){
                    Q.push(temp->left);
                }
                if(temp->right){
                    Q.push(temp->right);
                }
            }
        }
        return depth;
    }
    int FindWidthOfBinaryTree(node<T> *root){
        int width,h,count=0;
        if(!root){
            return 0;
        }
        width=1;
        queue<node<T> *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    if(count>width){
                        width=count;
                    }
                    Q.push(NULL);
                    count=0;
                }
            }
            else{
                if(temp->left){
                    count+=1;
                    Q.push(temp->left);
                }
                if(temp->right){
                    count+=1;
                    Q.push(temp->right);
                }
            }
        }
        return width;
    }
    int FindDiameterofBinaryTree(node<T> *root){
        int maxi,height_left=FindHeightOfBinaryTree(root->left);
        int height_right=FindHeightOfBinaryTree(root->right);
        maxi=height_left+height_right+1;//Diameter through the node;
        int diameter_left=FindDiameterofBinaryTree(root->left);//Diameter in the left subtree.
        if(diameter_left>maxi){
            maxi=diameter_left;
        }
        int diameter_right=FindDiameterofBinaryTree(root->right);//Diameter in the right subtree;
        if(diameter_right>maxi){
            maxi=diameter_right;
        }
        return maxi;
    }
    node<T> *FindLargestNode(node<T> *root){
        node<T> *max,*temp;
        max=root;
        if(root->left){
            temp=FindLargestNode(root->left);
            if(temp->data>max->data){
                max=temp;
            }
        }
        if(root->right){
            temp=FindLargestNode(root->right);
            if(temp->data>max->data){
                max=temp;
            }
        }
        return max;
    }
    void clearBinaryTree(node<T> *root){
        if(!root){
            return;
        }
        if(root->left){
            clearBinaryTree(root->left);
        }
        if(root->right){
            clearBinaryTree(root->right);
        }
        delete root;
        return;
    }
    void PrintatDepthK(node<T> *root,int k){//Using recursion.
        if(!k){
            cout << root->data << " ";
        }
        if(root->left){
            PrintatDepthK(root->left,k-1);
        }
        if(root->right){
            PrintatDepthK(root->right,k-1);
        }
    }
    void PrintatDepthK2(node<T> *root,int k){//Using Queues.
        if(!root){
            return;
        }
        if(!k){
            cout <<"Node(s) at depth "<< k << ": " << root->data << endl;
            return;
        }
        int i,count=1;//this will keep count of depth after each level.
        queue<node<T> *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    if(count==k){
                        break;
                    }
                    else{
                        count++;
                    }
                    Q.push(NULL);
                }
            }
            else{
                    if(temp->left){
                        Q.push(temp->left);
                    }
                    if(temp->right){
                        Q.push(temp->right);
                    }
                }
            }
        cout << "Nodes at depth "<<k<<endl;
        while(!Q.empty()){
            cout<<Q.front()->data<<" ";
            Q.pop();
        }
    }
    int sizeOfBinaryTree(node<T> *root){
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
    void createMirrorTree(node<T> *&root1,node<T> *root2){
        if(!root2){
            return;
        }
        root1=new node<T>;
        root1->data=root2->data;
        queue<node<T> *> Q1;//New Tree
        queue<node<T> *> Q2;
        Q1.push(root1);
        Q2.push(root2);
        while(!Q1.empty()){
            node<T> *temp1=Q1.front();
            Q1.pop();
            node<T> *temp2=Q2.front();
            Q2.pop();
            if(temp2->right){
                temp1->left=new node<T>;
                temp1->left->data=temp2->right->data;
                Q1.push(temp1->left);
                Q2.push(temp2->right);
            }
            if(temp2->left){
                temp1->right=new node<T>;
                temp1->right->data=temp2->left->data;
                Q1.push(temp1->right);
                Q2.push(temp2->left);
            }
        }
    }
    node<T> *FindNodewithLargestSumOfDataOfNodeanditsChildren(node<T> *root){
        node<T> *max=root,*temp;
        root->sum=root->data;
        if(root->left){
            root->sum+=root->left->data;
        }
        if(root->right){
            root->sum+=root->right->data;
        }
        if(root->left){
            temp=FindNodewithLargestSumOfDataOfNodeanditsChildren(root->left);
            if(temp->sum>max->sum){
                max=temp;
            }
        }
        if(root->right){
            temp=FindNodewithLargestSumOfDataOfNodeanditsChildren(root->right);
            if(temp->sum>max->sum){
                max=temp;
            }
        }
        return max;
    }
    bool isBinaryTreeComplete(node<T> *root){//Galat Hain.
        if(!root->left){
            if(root->right){
                return false;
            }
            else{
                return true;
            }
        }
        if(root->left){
            return isBinaryTreeComplete(root->left);
            if(root->right){
                return isBinaryTreeComplete(root->right);
            }
            else{
                return true;
            }
        }
    }
    int FindSumofallNodesOfTree(node<T> *root){
        int sum_nodes=root->data;
        if(root->left){
            sum_nodes+=FindSumofallNodesOfTree(root->left);
        }
        if(root->right){
            sum_nodes+=FindSumofallNodesOfTree(root->right);
        }
        return sum_nodes;
    }
    bool isBinaryTreeBalanced(node<T> *root){
        if(!root->left&&!root->right){//If root's left and right child are empty, it's still balanced!
            return true;
        }
        if(root->left){
            return isBinaryTreeBalanced(root->left);
        }
        if(root->right){
            return isBinaryTreeBalanced(root->right);
        }

        if((FindHeightOfBinaryTree(root->left)-FindHeightOfBinaryTree(root->right))<=1){
            return true;
        }
        else{
            return false;
        }
    }
    //bool isTreeFoldable()
    bool areTwoTreesIdentical(node<T> *root1,node<T> *root2){
        if(root1->data!=root2->data){
            return false;
        }
        if(root1->left){
            if(root2->left){
                return areTwoTreesIdentical(root1->left,root2->left);
            }
            else{
                return false;
            }
        }
        if(root1->right){
            if(root2->right){
                return areTwoTreesIdentical(root1->right,root2->right);
            }
            else{
                return false;
            }
        }
        return true;
    }
    int CountLeafNodesInBinaryTree(node<T> *root,int count){
        if(!root->left&&!root->right){
            count++;
        }
        if(root->left){
            count=CountLeafNodesInBinaryTree(root->left,count);
        }
        if(root->right){
            count=CountLeafNodesInBinaryTree(root->right,count);
        }
        return count;
    }
    node<T>* FindNextLargestElement(node<T> *root,int value,int next_largest){
        node<T> *next_largest_node=NULL,*temp;
        if(root->data>value&&root->data<next_largest){
            next_largest=root->data;
            next_largest_node=root;
        }
        if(root->left){
            temp=FindNextLargestElement(root->left,value,next_largest);
            if(temp){
                if(temp->data<next_largest){
                    next_largest=temp->data;
                    next_largest_node=temp;
                }
            }
        }
        if(root->right){
            temp=FindNextLargestElement(root->right,value,next_largest);
            if(temp){
                if(temp->data<next_largest){
                    next_largest=temp->data;
                    next_largest_node=temp;
                }
            }
        }
        return next_largest_node;
    }
    node<T>* FindElementinBinaryTree(node<T> *root,int value){
        node<T> *temp=NULL;
        if(!root){
            return temp;
        }
        queue<node<T> *> Q;
        Q.push(root);
        while(!Q.empty()){
            temp=Q.front();
            Q.pop();
            if(temp->data==value){
                return temp;
                break;
            }
            else{
                if(temp->left){
                    Q.push(temp->left);
                }
                if(temp->right){
                    Q.push(temp->right);
                }
            }
        }
        if(Q.empty()){
            return NULL;
        }
    }
    void createLL(node_LL<T> *&head,node<T> *arr[],int l){
        node_LL<T> *current_node;
        node_LL<T> *prevnode;
        int i;
        for(i=0;i<l;i++){
            current_node=new node_LL<T>;
            current_node->next=NULL;
            current_node->data_LL=arr[i]->data;
            if(!head){
                head=current_node;
                prevnode=current_node;
            }
            else{
                prevnode->next=current_node;
                prevnode=current_node;
            }
        }
    }
    void printlist(node_LL<T> *head){
        while(head){
            cout << head->data_LL << "->";
            head=head->next;
        }
        cout << "NULL" << endl;
    }
    void CreateSeperateLLforEachLevelOfTree(node<T> *root){
        if(!root){
            return;
        }
        queue<node<T> *> Q;
        node<T> *arr[100];
        Q.push(root);
        Q.push(NULL);
        int i,count=0;
        for(i=0;!Q.empty();i++){
            node<T> *temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    node_LL<T> *head=NULL;
                    createLL(head,arr,i);
                    cout << "Linked List for Level " << count << " : ";
                    printlist(head);
                    arr[0]=NULL;
                    i=-1;
                    count++;
                    Q.push(NULL);
                }
            }
            else{
                arr[i]=temp;
                if(temp->left){
                    Q.push(temp->left);
                }
                if(temp->right){
                    Q.push(temp->right);
                }
            }
        }
        node_LL<T> *head=NULL;
        createLL(head,arr,i-1);
        cout << "Linked List for Level " << count << " : ";
        printlist(head);
    }
    int FindCountinArray(T arr[],T value){
        int i;
        for(i=0;arr[i]!=value;i++){
        }
        return i;
    }
    void CreateTreeFromPreandInOrderTraversal(node<T> *&root){//This has a bug.**************
        int pre_index,count,pivot_preorder,root_inorder,len,i;
        T preorder[100],inorder[100];
        cout << "Enter size of Tree: ";
        cin >> len;
        cout << "Enter PreOrder Traversal: ";
        for(i=0;i<len;i++){
            cin >> preorder[i];
        }
        cout << "Enter InOrder Traversal: ";
        for(i=0;i<len;i++){
            cin>>inorder[i];
        }
        //First we will find the root_pivot to set up the root,left and the right subtree.
        root=new node<T>;
        root->data=preorder[0];
        count=FindCountinArray(inorder,root->data);
        root_inorder=count;
        pivot_preorder=count;
        queue<node<T> *> Q;
        root->left=new node<T>;
        root->left->data=preorder[1];
        root->left->parent=root;
        Q.push(root->left);
        root->right=new node<T>;
        root->right->data=preorder[count+1];
        root->right->parent=root;
        Q.push(root->right);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            pre_index=FindCountinArray(preorder,temp->data);//Here we find the index of root_node in preorder array.
            count=FindCountinArray(inorder,temp->data);
            if(count>root_inorder){
                count=count-root_inorder-1;//count for the right subtree of root node of the whole tree.
            }
            //cout << "root_inorder: " << root_inorder << endl;
            if(pre_index+1<pivot_preorder){
                if(pre_index+1<=pivot_preorder){
                    temp->left=new node<T>;
                    temp->left->data=preorder[pre_index+1];
                    Q.push(temp->left);
                }
                if(pre_index<=count){
                    if(pre_index+count+1<=pivot_preorder){
                        temp->right=new node<T>;
                        temp->right->data=preorder[pre_index+count+1];
                        Q.push(temp->right);
                    }
                }
            }
            if(pre_index>pivot_preorder){
                if(pre_index+1<len&&pre_index+1!=len-1){
                    temp->left=new node<T>;
                    temp->left->data=preorder[pre_index+1];
                    cout << preorder[pre_index] << "->left: " << preorder[pre_index+1] << " " << count << endl;
                    Q.push(temp->left);
                }
                if(count){//as count is 0, both pre_index+1 & pre_index+count+1 is same,so same element is assigned as both left and right child of temp.
                    if((pre_index+count+1)<len){
                        temp->right=new node<T>;
                        temp->right->data=preorder[pre_index+count+1];
                        cout << temp->data << "->right: " << preorder[pre_index+count+1] << endl;
                        Q.push(temp->right);
                    }
                }
            }
        }
    }
    void printLeftViewOfBinaryTree(node<T> *root){
        if(!root){
            return;
        }
        int count=1;
        queue<node<T> *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    cout << endl;
                    count=1;
                    Q.push(NULL);
                }
            }
            else{
                if(count==1){
                    cout << temp->data;
                }
                if(temp->left){
                    Q.push(temp->left);
                }
                if(temp->right){
                    Q.push(temp->right);
                }
                count++;
            }
        }
    }
    int FindDepthOfDeepestOddLevelLeafNode(node<T> *root){
        int depth=1,depth_leaf=0;
        queue<node<T> *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    depth++;
                    Q.push(NULL);
                }
            }
            else{
                if(depth%2&&(!temp->left&&!temp->right)){
                    depth_leaf=depth;
                }
                else{
                    if(temp->left){
                        Q.push(temp->left);
                    }
                    if(temp->right){
                        Q.push(temp->right);
                    }
                }
            }
        }
        return depth_leaf;
    }
    bool getAncestorsInStack(node<T> *root,T value,stack<node<T> *> &S){//We're storing in stack because our main aim is to find the LCA.
        if(!root){
            return false;
        }
        if(root->data==value){
            return true;
        }
        bool temp=getAncestorsInStack(root->left,value,S);
        if(temp){
            S.push(root);
            return true;
        }
        temp=getAncestorsInStack(root->right,value,S);
        if(temp){
            S.push(root);
            return true;
        }
        return temp;//here we're returning temp since now we have checked both left and right subtrees.
    }
    node<T>* getLCA(stack<node<T> *> S1,stack<node<T> *> S2){//We have stored ancestors of value1&value2 in Stack S1&S2 respectively from main function.
        node<T> *LCA;
        while((!S1.empty()&&!S2.empty())&&S1.top()==S2.top()){
            LCA=S1.top();
            S1.pop();
            S2.pop();
        }
        return LCA;
    }
    bool areAllLeafNodesonSameLevel(node<T> *root){
        int depth=0,depth1=0,depth2;
        bool ans;
        queue<node<T> *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    depth++;
                    Q.push(NULL);
                }
            }
            else{
                if(temp->left){
                    Q.push(temp->left);
                }
                if(temp->right){
                    Q.push(temp->right);
                }
                if(!temp->left&&!temp->right){
                    if(!depth1){
                        depth1=depth;
                    }
                    else{
                        depth2=depth;
                        if(depth1==depth2){
                            ans=true;
                        }
                        else{
                            return false;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
    void printTreeinZigZagPattern(node<T> *root){
        int count=1;
        queue<node<T> *> Q;
        stack<node<T> *> S;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    count++;
                    cout << endl;
                    Q.push(NULL);
                }
            }
            else{
                if(count%2!=0){
                    cout << temp->data << " ";
                }
                else{
                    cout << S.top()->data <<" ";
                    S.pop();
                }
                if(temp->left){
                    Q.push(temp->left);
                    if(count%2){
                        S.push(temp->left);
                    }
                }
                if(temp->right){
                    Q.push(temp->right);
                    if(count%2){
                        S.push(temp->right);
                    }
                }
            }
        }
    }
};
#endif // Binary_tree_aft_generic_h
