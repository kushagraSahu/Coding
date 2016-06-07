#include "Generic_Tree.h"
int main(){
    GenericTree<int> T1,T2;
    T1.createGenericTree(T1.root);
    T1.printLevelOrderGenericTree(T1.root);
    cout << endl;
    cout << "Height of the Generic Tree: " << T1.FindHeightofGenericTree(T1.root);
    cout << endl;
    cout << "Largest node in the Generic Tree: " << T1.FindLargestNode(T1.root)->data << endl;
    T1.FindLargestNode(T1.root);
    cout << endl;
    T1.PrintatDepthK(T1.root,2);
    cout << endl;
    cout << "Using recursion!" << endl;
    cout << "At depth 1 : ";
    T1.PrintatDepthK2(T1.root,1);//Recursion.
    cout << endl;
    T1.SizeOfTree(T1.root);
    cout << "Size of Generic Tree: " << T1.size << endl;
    T1.FindDiameterOfGenericTree(T1.root);
    cout << "PreOrder!"<<endl;
    T1.printPreorderGenericTree(T1.root);
    cout << endl;
    cout << "Post Order!"<<endl;
    T1.PrintPostOrder(T1.root);
    cout << "InOrder!" << endl;
    T1.PrintInOrder(T1.root);
    cout << endl;
    cout << "Mirror tree of T1!" << endl;
    T2.createMirrorTree(T2.root,T1.root);
    T2.printLevelOrderGenericTree(T2.root);
    cout << endl;
    cout << "Node with Largest Sum Of Data Of Node and its Children : "<< T1.FindNodewithLargestSumOfDataOfNodeanditsChildren(T1.root)->data << endl;
    return 0;
}
