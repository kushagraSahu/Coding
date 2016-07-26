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

int findDiameterOfBT(node *root){
	int diameter, diameter_left_subtree, diameter_right_subtree;
	int diameter_through_root = findHeightOfBT(root->left) + findHeightOfBT(root->right) + 1;
	diameter = diameter_through_root;
	// Finding diameter of Left Subtree
	if(root->left){
		diameter_left_subtree = findDiameterOfBT(root->left);
		if(diameter_left_subtree > diameter){
			diameter = diameter_left_subtree;
		}
	}
	if(root->right){
		diameter_right_subtree = findDiameterOfBT(root->right);
		if(diameter_right_subtree > diameter){
			diameter = diameter_right_subtree;
		}
	}
	return diameter;
}

node *findLargesNodeInBT(node *root){
	node *max=root, *temp;
	if(root->left){
		temp = findLargesNodeInBT(root->left);
		if(temp->data > max->data){
			max = temp;
		}
	}
	if(root->right){
		temp = findLargesNodeInBT(root->right);
		if(temp->data > max->data){
			max=temp;
		}
	}
	return max;
}

void clearBT(node *&root){
	if(!root->left && !root->right){
		delete root;
		return;
	}
	if(root->left){
		clearBT(root->left);
	}
	if(root->right){
		clearBT(root->right);
	}
	return;
}

void printAtKDepthBFS(node *root, int k){
	int depth=0;
	queue<node *> Q;
	Q.push(root);
	Q.push(NULL);
	cout << "Nodes at Depth " << k << " : ";
	while(!Q.empty()){
		node *temp=Q.front();
		Q.pop();
		if(!temp){
			if(!Q.empty()){
				if(depth==k){
					break;
				}
				depth++;
				Q.push(NULL);
			}
		}
		else{
			if(depth==k){
				cout << temp->data << " ";
			}
			if(temp->left){
				Q.push(temp->left);
			}
			if(temp->right){
				Q.push(temp->right);
			}
		}
	}
	cout << endl;
	return;
}

void printAtKDepthDFS(node *root, int k){
	if(!k){
		cout << root->data << " ";
		return;
	}
	if(root->left){
		printAtKDepthDFS(root->left, k-1);
	}
	if(root->right){
		printAtKDepthDFS(root->right, k-1);
	}
	return;
}

int sizeOfTreeDFS(node *root){
	int size, temp;
	if(!root){
		size=0;
	}
	else{
		size=1;
	}
	if(root->left){
		temp=sizeOfTreeDFS(root->left);
		size+=temp;
	}
	if(root->right){
		temp=sizeOfTreeDFS(root->right);
		size+=temp;
	}
	return size;
}

//BFS
void createMirrorBT(node *root1, node *&root2){
	if(!root1){
		return;
	}
	root2 = new node;
	root2->data = root1->data;
	queue<node *> Q1, Q2;
	Q1.push(root1);
	Q2.push(root2);
	Q1.push(NULL);
	Q2.push(NULL);
	while(!Q1.empty()){
		node *temp1 = Q1.front();
		Q1.pop();
		node *temp2 = Q2.front();
		Q2.pop();
		if(temp1->left){
			temp2->right = new node;
			temp2->right->data = temp1->left->data;
			Q1.push(temp1);
			Q2.push(temp2);
		}
		if(temp1->right){
			temp2->left = new node;
			temp2->left->data = temp1->right->data;
			Q1.push(temp1);
			Q2.push(temp2);
		}
	}
	return;
}

//BFS
node *findNodewithLargestSumOfDataAndItsChildren(node *root){
	if(!root){
		return NULL;
	}
	int sum=0, sum_temp;
	node *max;
	queue<node *> Q;
	Q.push(root);
	while(!Q.empty()){
		node *temp=Q.front();
		Q.pop();
		sum_temp = temp->data;
		if(temp->left){
			sum_temp+=temp->left>data;
			Q.push(temp->left);
		}
		if(temp->right){
			sum_temp+=temp->right->data;
			Q.push(temp->right);
		}
		if(sum_temp>sum){
			sum=sum_temp;
			max=temp;
		}
	}
	return max;
}
