#include "LinkedList.h"
int main(){
	LinkedList L1;
	L1.createLinkedList(L1.head);
	L1.printList(L1.head);
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
