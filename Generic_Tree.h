#ifndef Generic_Tree_h
#define Generic_Tree_h
#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class node{
    public:
    T data;
    int sum;
    node **children;
    node *parent;
    int child_count;
    node():children(0),parent(0),child_count(0),sum(0){}
    node(const T &ele):children(0),parent(0),child_count(0),sum(0),data(ele){}
};
template<typename T>
class GenericTree{
    public:
    int size;
    int diameter;
    node<T> *root;
    GenericTree():root(0),size(1),diameter(1){}
    void createGenericTree(node<T> *&root){
        T ele;
        int i;
        cout << "Data for root node:";
        cin>>ele;
        queue<node<T>*> Q;
        root=new node<T>(ele);
        Q.push(root);
        while(!Q.empty()){
            node<T> *temp=Q.front();
            Q.pop();
            cout << "Enter child_count of node" << temp->data << endl;
            cin >> temp->child_count;
            temp->children=new node<T> *[temp->child_count];
            for(i=0;i<temp->child_count;i++){
                cout << "Enter data for child" << endl;
                cin >> ele;
                temp->children[i]=new node<T>(ele);
                temp->children[i]->parent=temp;
                Q.push(temp->children[i]);
            }
        }
    }
    void printPreorderGenericTree(node<T> *root){
        if(!root){
            return;
        }
        cout << root->data << " ";
        int i;
        for(i=0;i<root->child_count/2;i++){
            printPreorderGenericTree(root->children[i]);
        }
        for(;i<root->child_count;i++){
            printPreorderGenericTree(root->children[i]);
        }
    }
    void PrintPostOrder(node<T> *root){
        if(!root){
            return;
        }
        int i;
        for(i=0;i<(root->child_count)/2;i++){
            PrintPostOrder(root->children[i]);
        }
        for(;i<root->child_count;i++){
            PrintPostOrder(root->children[i]);
        }
        cout << root->data << " ";
    }
    void PrintInOrder(node<T> *root){
        if(!root){
            return;
        }
        int i;
        for(i=0;i<(root->child_count)/2;i++){
            PrintInOrder(root->children[i]);
        }
        cout << root->data << " ";
        for(;i<root->child_count;i++){
            PrintPostOrder(root->children[i]);
        }
    }
    void printLevelOrderGenericTree(node<T> *root){
        if(!root){
            return;
        }
        else{
            int i;
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
                    cout << temp->data<<" ";
                    for(i=0;i<temp->child_count;i++){
                        Q.push(temp->children[i]);
                    }
                }

            }
        }
    }
    int FindHeightofGenericTree(node<T> *root){
        if(root==NULL||root->child_count==0){
            return 0;
        }
        int i,temp,height=-1;
        for(i=0;i<root->child_count;i++){
            temp=FindHeightofGenericTree(root->children[i]);
            if(height<temp){
                height=temp;
            }
        }
        return height+1;
    }
    node<T>* FindLargestNode(node<T> *root){
        if(!root){
            return NULL;
        }
        node<T> *max=root,*temp;
        int i;
        for(i=0;i<root->child_count;i++){
            temp=FindLargestNode(root->children[i]);
            if(temp->data>max->data){//Comparing the largest among the children and parent
                max=temp;
            }
        }
        return max;
    }
    void clearGenericTree(node<T> *&root){
        if(!root){
            return;
        }
        int i;
        for(i=0;i<root->child_count;i++){
            clearGenericTree(root->children[i]);
        }
        delete root;
        return;
    }
    int PrintatDepthK(node<T> *root,int k){
        if(!root){
            return 0;
        }
        int i,count=1;
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
                for(i=0;i<temp->child_count;i++){
                    Q.push(temp->children[i]);
                }
            }
        }
        cout << "Nodes at depth " << k << endl;
        while(!Q.empty()){
            cout<<Q.front()->data<<" ";
            Q.pop();
        }
    }
    void PrintatDepthK2(node<T> *root,int k){//Using Recursion.(Bhaiya)
        if(k==0){
            cout<<root->data<<" ";
        }
        int i;
        for(i=0;i<root->child_count;i++){
            PrintatDepthK2(root->children[i],k-1);
        }
    }
    void SizeOfTree(node<T> *root){
        if(!root){
            return;
        }
        size+=root->child_count;
        int i;
        for(i=0;i<root->child_count;i++){
            SizeOfTree(root->children[i]);
        }
    }
    void FindDiameterOfGenericTree(node<T> *root){//width
       if(!root){
            return;
       }
       int count=0,i;
       queue<node<T> *> Q;
       Q.push(root);
       Q.push(NULL);
       diameter=1;
       int h=FindHeightofGenericTree(root);
       while(h--){
            node<T> *temp=Q.front();
            Q.pop();
            if(temp==NULL){
                if(!Q.empty()){
                    if(count>diameter){
                        diameter=count;
                    }
                    count=0;
                    Q.push(NULL);
                }
            }
            else{
                count+=temp->child_count;
                for(i=0;i<temp->child_count;i++){
                    Q.push(root->children[i]);
                }
            }
       }
       cout << "Diameter : " << diameter << endl;
    }
    void createMirrorTree(node<T> *&root1,node<T> *root2){
        root1=new node<T>(root2->data);
        queue<node<T> *> Q1;
        queue<node<T> *> Q2;
        Q1.push(root1);
        Q2.push(root2);
        while(!Q1.empty()){
            node<T> *temp1=Q1.front();
            Q1.pop();
            node<T> *temp2=Q2.front();
            Q2.pop();
            int i,j;
            temp1->child_count=temp2->child_count;
            temp1->children=new node<T>*[temp1->child_count];
            for(i=0,j=temp2->child_count-1;i<temp1->child_count;i++,j--){
                temp1->children[i] = new node<T>(temp2->children[j]->data);
                temp1->children[i]->parent=temp1;
                Q1.push(temp1->children[i]);
                Q2.push(temp2->children[j]);
            }
        }
    }
    node<T> *FindNodewithLargestSumOfDataOfNodeanditsChildren(node<T> *root){
        node<T> *max,*temp;
        max=root;
        root->sum=root->data;
        int i;
        for(i=0;i<root->child_count;i++){
            root->sum+=root->children[i]->data;
        }
        for(i=0;i<root->child_count;i++){
            temp=FindNodewithLargestSumOfDataOfNodeanditsChildren(root->children[i]);
            if((temp->sum)>(max->sum)){
                max=temp;
            }
        }
        return max;
    }
};
#endif // Generic_Tree_h
