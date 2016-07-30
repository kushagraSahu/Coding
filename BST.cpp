#include<iostream>
#include<queue>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

bool isLeafNode(node *root){
	if(!root->left && !root->right){
		return true;
	}
	else{
		return false;
	}
}

//Recursion
node* insertInBST_1(node *&root, int value){
	if(!root){
		root=new node;
		root->data=value;
		root->left=root->right=NULL;
		return root;
	}
	if(root->data > value){
		root->left=insertInBST_1(root->left,value);
	}
	else{
		root->right=insertInBST_1(root->right,value);
	}
	return root;
}

//Method2
void insertInBST_2(node *&root, int value){
	node* new_node= new node;
	new_node->data=value;
	new_node->left=new_node->right=NULL;
	if(!root){
		root=new_node;
		return;
	}
	node* parent, *temp=root;
	while(temp){
		parent=temp;
		if(temp->data < value){
			temp=temp->right;
		}
		else{
			temp=temp->left;
		}
	}
	if(parent->data < value){
		parent->right=new_node;
	}
	else{
		parent->left=new_node;
	}
}

node *findMinNode(node *root){
	while(root->left){
		root=root->left;
	}
	return root;
}

node *findMaxNode(node *root){
	while(root->right){
		root=root->right;
	}
	return root;
}

node *findNodeInBST(node *root,int data1){
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

node *deleteNodeFromBST(node *root, int value){
	if(root->data > value){
		root->left = deleteNodeFromBST(root, value);
	}
	else if(root->data < value){
		root->right = deleteNodeFromBST(root, value);
	}
	else{
		if(!root->left && !root->right){
			delete root;
			return NULL;
		}
		else if(root->left && !root->right){
			node *temp = root->left;
			delete root;
			return temp;
		}
		else if(!root->left && root->right){
			node *temp = root->right;
			delete root;
			return temp;
		}
		else{
			node *min = findMinNode(root->right);
			root->data = min->data;
			root->right = deleteNodeFromBST(root->right, min->data);
			return root;
		}
	}
	return root;
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

node *findInorderSuccessorOfNode(node *root, int value){
	node *targetNode = findNodeInBST(root, value);
	node *inorder_successor=NULL;
	if(targetNode->right){
		return findMinNode(targetNode->right);
	}
	else{
		while(root){
			if(root->data > value){
				inorder_successor = root;
				root=root->left;
			}
			else if(root->data < value){
				root=root->right;
			}
			else{
				break;
			}
		}
		return inorder_successor;
	}
}

bool isTreeBST(node *root){
	bool temp = true;
	if(root->left){
		if(root->data >= root->left->data){
			temp = isTreeBST(root->left);
		}
		else{
			return false;
		}
	}
	if(temp){
		if(root->right){
			if(root->data < root->right->data){
				temp = isTreeBST(root->right);
			}
			else{
				return false;
			}
		}
	}
	return temp;
}

//Method1
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
//Method2 for finding LCA is also same but using a while loop.

void findKthSmallestElementInBST_helper(node *root, int *k, node *&targetNode){
	if(isLeafNode(root)){
		--*k;
		if(*k==0){
			targetNode = root;
		}
	}
	else{
		findKthSmallestElementInBST_helper(root->left, k, targetNode);
		--*k;
		if(*k==0){
			targetNode = root;
		}
		findKthSmallestElementInBST_helper(root->right, k, targetNode);
	}
	return;
}

node *findKthSmallestElementInBST(node *root, int k){
    int a = k;
    node *targetNode=NULL;
	findKthSmallestElementInBST_helper(root, &a, targetNode);
	return targetNode;
}

int main(){
	//All Functions-> DRY RUN.
	node *root=NULL;
	int value;
    cout << "Enter no. to be inserted in Binary Search Tree. Enter -1 to exit insertion" << endl;
    cin >> value;
    while(value!=-1){
        insertInBST_2(root,value);
        cin >> value;
    }
    cout << "BST inserted is below." << endl;
    printLevelOrderBST(root);
    cout << "Kth smallest element in BST: " << findKthSmallestElementInBST(root, 4)->data << endl;
}
