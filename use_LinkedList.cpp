#include "LinkedList.h"
int main(){
	LinkedList L1, L2;
	L1.createLinkedList(L1.head);
	L1.printList(L1.head);
	cout << endl;
	L2.createLinkedList(L2.head);
	L2.printList(L2.head);
	cout << endl;
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
}
