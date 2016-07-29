#include<iostream>
#include<queue>
#include<stack>
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
	root->left = removeAllNodesLyingOnPathWithSumLessThanK_helper(root->left, sum, k);
	root->right = removeAllNodesLyingOnPathWithSumLessThanK_helper(root->right, sum, k);
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

bool printRootToTargetNodePath(node *root, node *targetNode){
	if(!root){
		return false;
	}
	if(root==targetNode){
		cout << root->data << " ";
		return true;
	}
	if(printRootToTargetNodePath(root->left, targetNode)){
		cout << root->data << " ";
		return true;
	}
	if(printRootToTargetNodePath(root->right,targetNode)){
		cout << root->data << " ";
		return true;
	}
	return false;
}

void findMaxSumPathInBT_helper(node *root, int sum, int *max_sum, node *&targetLeafNode){
	if(!root){
		return;
	}
	sum+=root->data;
	if(root->left){
		findMaxSumPathInBT_helper(root->left, sum, max_sum, targetLeafNode);
	}
	if(root->right){
		findMaxSumPathInBT_helper(root->right, sum, max_sum, targetLeafNode);
	}
	if(!root->left && !root->right){
		if(sum > *max_sum){
			*max_sum = sum;
			targetLeafNode = root;
		}
	}
}

void findMaxSumPathInBT(node *root){
	node *targetLeafNode=NULL;
	int max_sum = 0;
	findMaxSumPathInBT_helper(root, 0, &max_sum, targetLeafNode);
	cout << "Maximum Sum: " << max_sum << endl;
	cout << "MaxSumRootToLeafPath: ";
	printRootToTargetNodePath(root, targetLeafNode);
	cout << endl;
	return;
}

//BFS
void printLeftViewOfBT(node *root){
	if(!root){
		return;
	}
	int count=1;
	queue<node *> Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty()){
		node *temp=Q.front();
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

void printDLL(node *head){
	while(head){
		cout << head->data << "-->";
		head=head->right;
	}
	cout << "X" << endl;
}

void printReverseDLL(node *head){
	while(head->right){
		head=head->right;
	}
	while(head){
		cout << head->data << "-->";
		head=head->left;
	}
	cout << "X" << endl;
}

//treating 'right' ptr as 'next' & 'left' as 'prev' ptr;
void connectLeavesOfBTasDLL_helper(node *root, node *&head, node *&prevnode){
	if(!root->left && !root->right){
		if(!head){
			head = root;
		}
		else{
			prevnode->right = root;
			root->left = prevnode;
		}
		prevnode = root;
	}
	else{
		if(root->left){
			connectLeavesOfBTasDLL_helper(root->left, head, prevnode);
		}
		if(root->right){
			connectLeavesOfBTasDLL_helper(root->right, head, prevnode);
		}
		return;
	}
}

void connectLeavesOfBTasDLL(node *root, node *&head){
	node *prevnode = NULL;
	connectLeavesOfBTasDLL_helper(root, head, prevnode);
	return;
}

void findDeepestLeftLeafNode_helper(node *root, int *max_depth, int depth_of_node, node *&targetLeafNode){
	if(!root){
		return;
	}
	node *temp;
	int depth_of_leaf_node;
	if(root->left){
		temp = root->left;
		//Checking if leaf node is the left leaf node or not.
		if(!temp->left && !temp->right){
			//Here, depth_of_node represents depth of parent of leaf node, so incrementing it by 1 for the depth of leaf node.
			depth_of_leaf_node = depth_of_node + 1;
			if(depth_of_leaf_node > *max_depth){
				*max_depth = depth_of_node;
				targetLeafNode = temp;
			}
		}
	}
	if(root->left){
		findDeepestLeftLeafNode_helper(root->left, max_depth, depth_of_node+1, targetLeafNode);
	}
	if(root->right){
		findDeepestLeftLeafNode_helper(root->right, max_depth, depth_of_node+1, targetLeafNode);
	}
	return;
}

node *findDeepestLeftLeafNode(node *root){
	int depth_of_node = 0, max_depth=0;
	node *targetLeafNode=NULL;
	findDeepestLeftLeafNode_helper(root, &max_depth, depth_of_node, targetLeafNode);
	return targetLeafNode;
}

bool getAncestorsinStack(node *root,int value, stack<node *> &S){
	if(root->data == value){
		S.push(root);
		return true;
	}
	if(root->left){
		if(getAncestorsinStack(root->left, value, S)){
			S.push(root);
			return true;
		}
		else{
			false;
		}
	}
	if(root->right){
		if(getAncestorsinStack(root->right, value, S)){
			S.push(root);
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}

node *findLCA(node *root, int value1, int value2){
	stack<node *> S1;
	stack<node *> S2;
	getAncestorsinStack(root, value1, S1);
	getAncestorsinStack(root, value2, S2);
	node *temp;
	while(!S1.empty() && !S2.empty()){
		if(S1.top() == S2.top()){
			temp = S1.top();
			S1.pop();
			S2.pop();
		}
		else{
			break;
		}
	}
	return temp;
}

//Using Stack to print even levels in reverse.(Method 1)
void printTreeinZigZagPattern(node *root){
	int count=1;
	queue<node *> Q;
	stack<node *> S;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty()){
		node *temp=Q.front();
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

int findDepthOfDeepestOddLevelLeafNode(node *root){
	int depth=1,depth_leaf=0;
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

bool isBT1SubTreeOfBT2(node *root1, node *root2){
	if(!root1){
		return false;
	}
	if(!root2){
		return false;
	}
	if(areTwoTreesIdentical(root1, root2)){
		return true;
	}
	if(isBT1SubTreeOfBT2(root1->left, root2)){
		return true;
	}
	else{
		return isBT1SubTreeOfBT2(root1->right, root2);
	}
}

int search_index_inorder(int inorder_list[], int data, int start, int end){
	int index=start;
	while(index<=end){
		if(inorder_list[index]==data){
			return index;
		}
		index++;
	}
}

node *createBTfromInAndPreOrder(node *root, int inorder_list[], int preorder_list[], int start, int end){
	if(start>end){
		return NULL;
	}
	static int preindex=0;
	root = new node;
	root->data = preorder_list[preindex];
	preindex++;
	root->left=root->right=NULL;
	if(start==end){
		return root;
	}
	int index_inorder = search_index_inorder(inorder_list, root->data, start, end);
	//Left of root in inorder lies in Left subtree.
	root->left=createBTfromInAndPreOrder(root->left, inorder_list, preorder_list, start, index_inorder-1);
	//Right of root in inorder lies in Right subtree.
	root->right=createBTfromInAndPreOrder(root->right, inorder_list, preorder_list, index_inorder+1, end);
	return root;
}


//Initially sending arguments (arr, 0, len-1)
node *createSpecialTreeFromInorder(int inorder_list[], int start, int end){
	if(start > end){
		return NULL;
	}
	int root_index, maxi=0;
	for(int index=start;index<=end;index++){
		if(inorder_list[index]>maxi){
			maxi=inorder_list[index];
			root_index = index;
		}
	}
	node* root = new node;
	root->data = inorder_list[root_index];
	root->left=root->right=NULL;
	if(start==end){
		return root;
	}
	root->left = createSpecialTreeFromInorder(inorder_list, start, root_index-1);
	root->right = createSpecialTreeFromInorder(inorder_list, root_index+1, end);
	return root;
}

int length(int arr[]){
	int i;
	for(i=0;arr[i];i++){
		i++;
	}
	return i;
}

node *createSpecialTreeFromPreOrder(int preorder_list[], char preorder_property[]){
	static int index_preorder = 0;
	int length_list = length(preorder_list);
	if(index_preorder == length_list){
		return NULL;
	}
	node *root = new node;
	root->data = preorder_list[index_preorder];
	if(preorder_property[index_preorder] == 'L'){
		return root;
	}
	else{
		root->left = createSpecialTreeFromPreOrder(preorder_list, preorder_property);
		root->right = createSpecialTreeFromPreOrder(preorder_list, preorder_property);
	}
	return root;
}

//Doubt
node *createBTfromPreAndPostOrder(int preorder_list[], int postorder_list[], int start, int end, int *index_preorder){
	if(start>end){
		return NULL;
	}
	node *root=new node;
	root->data = preorder_list[*index_preorder];
	++*index_preorder;//Not Working if *index_preorder++ .
	cout << "index_pre: " << root->data << endl;
	cout << preorder_list[*index_preorder] << endl;
	if(start==end){
		return root;
	}

	int index_postorder;
	for(index_postorder=start;index_postorder<=end;index_postorder++){
		if(postorder_list[index_postorder] == preorder_list[*index_preorder]){
			break;
		}
	}
	if(index_postorder<=end){
		root->left = createBTfromPreAndPostOrder(preorder_list, postorder_list, start, index_postorder, index_preorder);
		root->right = createBTfromPreAndPostOrder(preorder_list, postorder_list, index_postorder+1, end-1, index_preorder);
	}
	return root;
}

int main(){
	node *root;
	int index_preorder = 0;
	int inorder_list[] = {1, 5, 10, 40, 30, 15, 28, 20};
	int preorder_list[] = {1,2,4,8,9,5,3,6,7};
	int postorder_list[] = {8,9,4,5,2,6,7,3,1};
	root = createBTfromPreAndPostOrder(preorder_list, postorder_list, 0, length(preorder_list)-1, &index_preorder);
	printLevelOrderBT(root);
	root = createSpecialTreeFromInorder(inorder_list, 0, 7);
	printLevelOrderBT(root);
	root=NULL;
	createBinaryTree(root);
	cout << "Original BT:" << endl;
	printLevelOrderBT(root);
	cout << "DeepestLeftLeafNode: " << findDeepestLeftLeafNode(root)->data << endl;

	findMaxSumPathInBT(root);
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
	cout << "To find LCA: " << endl;
	int value1, value2;
	cout << "Enter data of node 1: ";
	cin >> value1;
	cout << "Enter data of node 2: ";
	cin >> value2;
	//Right now doing it with data values of node.
	cout << "LCA of " << value1 << " & " << value2 << " : " << findLCA(root, value1, value2)->data << endl;


	//Warning! Keep below section of code at the bottom of main() always since it messes up right and left pointers, destroying its BT structure!
	node *head = NULL;
	connectLeavesOfBTasDLL(root, head);
	cout << "Double Linked List of Leaf nodes: " << endl;
	cout << "While traversing through next pointer: ";
	printDLL(head);
	cout << "While traversing through prev pointer: ";
	printReverseDLL(head);

	return 0;
}

