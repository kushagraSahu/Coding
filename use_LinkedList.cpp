#include "LinkedList.h"
int main(){
	LinkedList L1, L2;
	cout << "Enter LL1" << endl;
	L1.createLinkedList(L1.head);
	L1.printList(L1.head);
	cout << "reverseLL1" << endl;
	L1.reverseLL(L1.head);
	L1.printList(L1.head);
	cout << "middle of LL1:";
	cout << L1.findMiddleOfLL(L1.head)->data << endl;
	cout << "ZigZagLL" << endl;
	L1.ZigZagLL(L1.head);
    L1.printList(L1.head);
	cout << endl;
	cout << "Enter LL2" << endl;
	L2.createLinkedList(L2.head);
	L2.printList(L2.head);
	cout << endl;
	cout << "mergeLL1intoLL2atAltPos" << endl;
    L1.mergeLL1intoLL2atAltPos(L1.head, L2.head);
    L1.printList(L1.head);
    cout << endl;
    cout << "Quicksort to L1" << endl;
    L1.Quicksort(L1.head, 0, L1.length(L1.head)-1);
	L1.printList(L1.head);
    cout << endl;
 	cout << "Delete duplicates" << endl;
	L1.deleteDuplicatesFromSortedLL(L1.head);
	L1.printList(L1.head);
	cout << "Check Palindrome" << endl;
	cout << L1.is_Palindrome(L1.head) << endl;
	cout << "Seperate Odd Even" << endl;
	L1.seperateOddEvenElements(L1.head);
	L1.printList(L1.head);
	cout << "Append Last N" << endl;
	L1.appendLastNelementsToFront(L1.head, 4);
	L1.printList(L1.head);
	cout << "KReverse" << endl;
	L1.kReverse(L1.head, 4);
	L1.printList(L1.head);
	cout << endl;
	cout << "Heterogeneous LL" << endl;
	node1 *head = NULL;
	createHeterogeneousLL(head);
	printIntNode(head);
	LinkedList L3, L4, L5;
	cout << "Enter LL3" << endl;
	L3.createLinkedList(L3.head);
	L3.printList(L3.head);
	cout << "Enter LL4" << endl;
	L4.createLinkedList(L4.head);
	L4.printList(L4.head);
	cout << "mergeTwoSortedLL LL3,LL4 into LL5" << endl;
	L3.mergeTwoSortedLL(L3.head, L4.head, L5.head);
	L5.printList(L5.head);
	cout << "Random pointer cloning" << endl;
    randomNode *heado=NULL, *headc1=NULL, *headc2=NULL;
	cout << "Enter original LL" << endl;
    createNextLinksInRandomLL(heado);
    printNextPtrRandomList(heado);
    cout << endl;
    int arr[5] = {2,0,4,2,1};
    createRandomLinksinLL(heado, arr);
    printRandomPtrRandomList(heado);
    cloneRandomLL_1(heado, headc1);
    cout << "Cloned LL:" << endl;
    printNextPtrRandomList(headc1);
    printRandomPtrRandomList(headc1);
    cout << "Method2" << endl;
    cloneRandomLL_2(heado, headc2);
    printNextPtrRandomList(headc2);
    printRandomPtrRandomList(headc2);
    cout << "Cloned LL:" << endl;
    LinkedList L6;
    cout << "Enter LL6" << endl;
    L6.createLinkedList(L6.head);
    L6.printList(L6.head);
    cout << "deleteLastOccurrenceOfNode, key = 1" << endl;
    L6.deleteLastOccurrenceOfNode(L6.head, 1);
    L6.printList(L6.head);
    return 0;
}
