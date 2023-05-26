#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;

};


class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node* previous, Node* current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void hapus();
	void searchData();

};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}


void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\Enter the name of student: ";
	cin >> nm;
	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim;
	newNode->name = nm;
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;
		if (START != NULL)
			START->prev = newNode;
		newNode->prev = NULL;
		START = newNode;
		return;
	}
	/*inserting a node betweent two node*/

	Node* current = START;
	Node* previous = NULL;
	while (current->next != NULL && current->next->noMhs < nim);
	{
		previous = current; 
		current = current->next;
	}

	if (current->next != NULL && nim == current->next->noMhs); {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
 }
	newNode->next = current->next;
	newNode->prev = current;
	if (current->next != NULL)
		current->next->prev = newNode;
	current->next = newNode;

}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START;
	*current = START;
	while (*current != NULL && rollNo!=(*current)->noMhs) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current!=NULL);

}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;
}
bool DoubleLinkedList::listEmpty() {
	return (START == NULL);

}
void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nlist is empty" << endl;
	else {
		cout << "\nRecord in ascnding order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;

		}
	}
}