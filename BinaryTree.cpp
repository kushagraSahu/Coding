#include<iostream>
#include<queue>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

void createBinaryTree(node *&root){
	int value;
	char choice;
	cout << "Enter data for root: ";
	cin >> value;
	root = new node;
	root->data = value;
	root->left = NULL;
	root->right = NULL;
	queue <node *> Q;
	Q.push(root);
	while(!Q.empty()){
		node *temp = Q.front();
		Q.pop();
		cout << "Is there a Left Node? Y/N?: ";
		cin >> choice;
		if(choice == 'y' || choice == 'Y'){
			cout << "Enter data for left node: ";
			cin >> value;
			temp->left = new node;
			temp->left->left = NULL;
			temp->left->right = NULL;
			temp->left->data = value;
			Q.push(temp->left);
		}
		cout << "Is there a right Node? Y/N?: ";
		cin >> choice;
		if(choice == 'y' || choice == 'Y'){
			cout << "Enter data for right node: ";
			cin >> value;
			temp->right = new node;
			temp->right->left = NULL;
			temp->right->right = NULL;
			temp->right->data = value;
			Q.push(temp->right);
		}
	}
	return;
}

void printLevelOrderBT(node *root){
	if(!root){
		return;
	}
	queue <node *> Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty()){
		node *temp = Q.front();
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
	return;
}

void printPreOrder(node *root){
	if(!root){
		return;
	}
	cout << root->data << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void printInOrder(node *root){
	if(!root){
		return;
	}
	printPreOrder(root->left);
	cout << root->data << " ";
	printPreOrder(root->right);
}

void printPostOrder(node *root){
	if(!root){
		return;
	}
	printPreOrder(root->left);
	printPreOrder(root->right);
	cout << root->data << " ";
}

int findHeightOfBT(node *root){
	int height=-1;
	int return_height;
	if(root->left){
		return_height=findHeightOfBT(root->left);
		if(return_height>height){
			height=return_height;
		}
	}
	if(root->right){
		return_height=findHeightOfBT(root->right);
		if(return_height>height){
			height=return_height;
		}
	}
	return height+1;
}

int findDepthOfNodeBFS(node *root, int key){
	int depth=0;
	queue<node *> Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty()){
		node *temp=Q.front();
		Q.pop();
		if(!temp){
			if(!Q.empty()){
				depth++;
				Q.push(NULL);
			}
		}
		else{
			if(temp->data==key){
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

int findWidthOfTree(node *root){
    if(!root){
        return 0;
    }
    int width=1, width_temp=0;
    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
    	node *temp = Q.front();
    	Q.pop();
    	if(!temp){
    		if(!Q.empty()){
    			if(width_temp>width){
    				width=width_temp;
    			}
    			width_temp=0;
    			Q.push(NULL);
    		}
    		else{
    			if(temp->left){
    				temp+=1;
    				Q.push(temp->left);
    			}
    			if(temp->right){
    				temp+=1;
    				Q.push(temp->right);
    			}
    		}
    	}
    }
    return width;
}


























