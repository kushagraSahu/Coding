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
		cout << "Is there a Left Node for " << temp->data <<  "? " << "Y/N?: ";
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
		cout << "Is there a Right Node for " << temp->data <<  "? " << "Y/N?: ";

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
	cout << endl;
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
			sum_temp+=temp->left->data;
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

int sumOfAllNodesInBT(node *root){
	int sum = root->data;
	if(root->left){
		sum+=sumOfAllNodesInBT(root->left);
	}
	if(root->right){
		sum+=sumOfAllNodesInBT(root->right);
	}
	return sum;
}

int countLeafNodesInBT(node *root){
	int leaf_count=0;
	if(!root->left && !root->right){
		leaf_count+=1;
	}
	if(root->left){
		leaf_count+=countLeafNodesInBT(root->left);
	}
	if(root->right){
		leaf_count+=countLeafNodesInBT(root->right);
	}
	return leaf_count;
}

//DFS
node *findNextLargestNodeInBT(node *root, int value, int nextLargestValue){
	node *nextLargestNode = NULL, *temp;
	if(root->data > value && root->data < nextLargestValue){
		nextLargestNode = root;
		nextLargestValue = root->data;
	}
	if(root->left){
		temp = findNextLargestNodeInBT(root->left, value, nextLargestValue);
		if(temp){
			if(temp->data > value && temp->data < nextLargestValue){
				nextLargestNode = temp;
				nextLargestValue = temp->data;
			}
		}
	}
	if(root->right){
		temp = findNextLargestNodeInBT(root->right, value, nextLargestValue);
		if(temp){
			if(temp->data > value && temp->data < nextLargestValue){
				nextLargestNode = temp;
				nextLargestValue = temp->data;
			}
		}
	}
	return nextLargestNode;
}

//BFS
node* FindElementinBinaryTree(node *root,int value){
	node *temp=NULL;
	if(!root){
		return temp;
	}
	queue<node *> Q;
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

//DFS
void convertBTintoSumTree(node *&root){
	int original_left_data, original_right_data, sum=0;
	if(root->left){
		original_left_data = root->left->data;
		convertBTintoSumTree(root->left);
		sum+=original_left_data + root->left->data;
	}
	if(root->right){
		original_right_data = root->right->data;
		convertBTintoSumTree(root->right);
		sum+=original_right_data + root->right->data;
	}
	root->data = sum;
	return;
}

bool checkChildrenSumPropertyInBT(node *root){
	int right_child_data=0, left_child_data=0;
	if(!root->right && !root->left){
		return true;
	}
	if(root->left){
		if(checkChildrenSumPropertyInBT(root->left)){
			left_child_data = root->left->data;
		}
		else{
			return false;
		}
	}
	if(root->right){
		if(checkChildrenSumPropertyInBT(root->right)){
			right_child_data = root->right->data;
		}
		else{
			return false;
		}
	}
	if(root->data == left_child_data + right_child_data){
		return true;
	}
	else{
		return false;
	}
}

bool areTwoSubtreesStructuralMirrorImages(node *root1, node *root2){
	if(!root1 && !root2){
		return true;
	}
	else if(root1 && !root2){
		return false;
	}
	else if(!root1 && root2){
		return false;
	}
	else if(root1 && root2){
		if(areTwoSubtreesStructuralMirrorImages(root1->left, root2->right)){
			return areTwoSubtreesStructuralMirrorImages(root1->right, root2->left);
		}
		else{
			return false;
		}
	}
}

bool isBTFoldable(node *root){
	if(!root){
		return true;
	}
	else{
		return areTwoSubtreesStructuralMirrorImages(root->left, root->right);
	}
}

bool areTwoTreesIdentical(node *root1, node *root2){
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

//Helper for Method1
node *removeAllNodesLyingOnPathWithSumLessThanK_helper(node *root, int sum, int k){
	if(!root){
		return NULL;
	}
	sum+=root->data;
	root->left = removeAllNodesLyingOnPathWithSumLessThanK(root->left, sum, k);
	root->right = removeAllNodesLyingOnPathWithSumLessThanK(root->right, sum, k);
	if(!root->left && !root->right && sum < k){
		delete root;
		return NULL;
	}
	return root;
}	

//Method1
node *removeAllNodesLyingOnPathWithSumLessThanK_1(node *root, int k){
	return removeAllNodesLyingOnPathWithSumLessThanK_helper(root, 0, k);
}

//Geeks For Geeks Method (clever!)
node *removeAllNodesLyingOnPathWithSumLessThanK_2(node *root, int sum){
	if(!root){
		return NULL;
	}
	root->left = removeAllNodesLyingOnPathWithSumLessThanK_2(root->left, sum - root->data);
	root->right = removeAllNodesLyingOnPathWithSumLessThanK_2(root->right, sum - root->data);
	if(!root->left && !root->right && root->data < sum){
		delete root;
		return NULL;
	}
	return root;
}

int main(){
	node *root = NULL;
	createBinaryTree(root);
	cout << "Original BT:" << endl;
	printLevelOrderBT(root);
	if(checkChildrenSumPropertyInBT(root)){
		cout << "Children Sum Property satisfied!" << endl;
	}
	else{
		cout << "Children Sum Property NOT satisfied!" << endl;
	}
	convertBTintoSumTree(root);
	cout << "Sum Tree:" << endl;
	printLevelOrderBT(root);
	node *root1 = NULL;
	createBinaryTree(root1);
	printLevelOrderBT(root1);
	if(isBTFoldable(root1)){
		cout << "BT is foldable" << endl;
	}
	else{
		cout << "BT is NOT foldable" << endl;
	}
	return 0;
}
