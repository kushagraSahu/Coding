#include "BinaryTree1.h"
int main(){
    BinaryTree<int> T1,T2,T3,T4;
    T1.createBinaryTree(T1.root);
    T1.PrintLevelOrderBT(T1.root);
    cout << endl;
    cout << "PreOrder!" << endl;
    T1.PrintPreOrder(T1.root);
    cout << endl;
    cout << "InOrder!" << endl;
    T1.printInOrder(T1.root);
    cout << endl;
    cout << "PostOrder!" << endl;
    T1.PrintPostOrder(T1.root);
    cout << endl;
    cout << "Height of Binary Tree T1 : " << T1.FindHeightOfBinaryTree(T1.root) << endl;
    cout << "Width of Binary Tree T1 : " << T1.FindWidthOfBinaryTree(T1.root) << endl;
    if(T1.FindElementinBinaryTree(T1.root,7)){
        cout << "Depth of Node 7 in Tree T1: " << T1.FindDepthOfNode(T1.root,7) << endl;
    }
    else{
        cout << "Given element is not present in Binary Tree T1,So cant find depth!" << endl;
    }
    cout << "Largest Node in Binary Tree T1 : " << T1.FindLargestNode(T1.root)->data << endl;
    cout << "Printing at depth 2 in T1 using recursion" << endl;
    T1.PrintatDepthK(T1.root,2);
    cout << endl;
    cout << "Printing at depth 3 in T1 using Queues" << endl;
    T1.PrintatDepthK2(T1.root,0);
    cout << endl;
    cout << "Size of Binary Tree T1 : " << T1.sizeOfBinaryTree(T1.root) << endl;
    cout << "Creating Binary Tree T2 which is a mirror tree of T1!" << endl;
    T2.createMirrorTree(T2.root,T1.root);
    T2.PrintLevelOrderBT(T2.root);
    cout << endl;
    cout << "Node with Largest Sum Of Data Of Node and its Children: "<< T1.FindNodewithLargestSumOfDataOfNodeanditsChildren(T1.root)->data << endl;
    if(T1.isBinaryTreeComplete(T1.root)){
        cout << "Binary Tree T1 is complete!" << endl;
    }
    else{
        cout << "Binary Tree T1 is not complete" << endl;
    }
    cout << "Sum of all nodes in Binary Tree T1: " << T1.FindSumofallNodesOfTree(T1.root) << endl;
    if(T1.isBinaryTreeBalanced(T1.root)){
        cout << "Binary Tree is balanced!" << endl;
    }
    else{
        cout << "Binary Tree is NOT balanced!" << endl;
    }
    if(T1.areTwoTreesIdentical(T1.root,T2.root)){
        cout << "Binary Trees T1 and T2 are structurally identical" << endl;
    }
    else{
        cout << "Binary Trees T1 and T2 are NOT structurally identical" << endl;
    }
    cout << "Creating Binary Tree T3,mirror tree of T2(mirror tree of T1)" << endl;
    T3.createMirrorTree(T3.root,T2.root);
    T3.PrintLevelOrderBT(T3.root);
    cout << endl;
    if(T1.areTwoTreesIdentical(T1.root,T3.root)){
        cout << "Binary Trees T1 and T3 are structurally identical" << endl;
    }
    else{
        cout << "Binary Trees T1 and T3 are NOT structurally identical" << endl;
    }
    cout << "No. of Leaf nodes in Tree T1: " << T1.CountLeafNodesInBinaryTree(T1.root,0) << endl;

    if(T1.FindElementinBinaryTree(T1.root,5)){
        cout << "Element " << T1.FindElementinBinaryTree(T1.root,5)->data <<" is present!" << endl;
    }
    else{
        cout << "NOT Present" << endl;
    }
    int value;
    cout << "Enter data of node to find its next largest node in the Binary Tree T1" << endl;
    cin >> value;
    if(T1.FindNextLargestElement(T1.root,value,T1.FindLargestNode(T1.root)->data+1)){
        cout << "Next Largest node of given element: " << T1.FindNextLargestElement(T1.root,value,T1.FindLargestNode(T1.root)->data+1)->data << endl;
    }
    else{
        cout << "Given Element is the Largest in the tree itself,So no next largest node is available!" << endl;
    }
    T1.CreateSeperateLLforEachLevelOfTree(T1.root);
    cout << "Going to create Tree from PreOrder and InOrder Traversal!" << endl;
    T4.CreateTreeFromPreandInOrderTraversal(T4.root);
    T4.PrintLevelOrderBT(T4.root);
    cout << endl;
    cout << "Left view of Binary Tree T1!" << endl;
    T1.printLeftViewOfBinaryTree(T1.root);
    cout << endl;
    if(T1.FindDepthOfDeepestOddLevelLeafNode(T1.root)){
        cout << "Depth Of Deepest Odd Level Leaf Node in Tree T1: " << T1.FindDepthOfDeepestOddLevelLeafNode(T1.root) << endl;
    }
    else{
        cout << "There is no leaf node present at any odd level in Tree T1" << endl;
    }
    //To find LCA!
    stack<node<int> *> S1,S2;
    T1.getAncestorsInStack(T1.root,8,S1);//Getting ancestors of node1 in stack 1.
    T1.getAncestorsInStack(T1.root,5,S2);//Getting ancestors of node2 in stack 2.
    cout << "LCA of node 5&8 is node " << T1.getLCA(S1,S2)->data << endl;
    cout << "Are Leaf Node of Tree T1 are at the same level? ";
    if(T1.areAllLeafNodesonSameLevel(T1.root)){
        cout << "YES!" << endl;
    }
    else{
        cout << "NO!" << endl;
    }
    T1.printTreeinZigZagPattern(T1.root);
    cout << endl;
    return 0;
}
