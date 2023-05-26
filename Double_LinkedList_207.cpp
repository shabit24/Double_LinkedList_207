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
	bool search(int rollNo, Node** previous, Node** current);
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
	while (current->next != NULL && current->next->noMhs < nim)
	{
		previous = current; 
		current = current->next;
	}

	if (current->next != NULL && nim == current->next->noMhs) {
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
		cout << "\nRecord in ascending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;

		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is Empty" << endl;
	}
	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;

		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;

	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter roll number of student whose record you want to secach: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}


int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from list" << endl;
			cout << "3. View all records on ascending order of roll numbers" << endl;
			cout << "4. View all records on descending order of roll numbers" << endl;
			cout << "5. Search for a record inthe list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice(1-6): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
				obj.searchData();
				break;
			case '6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}



		}
		catch (exception& e) {
			cout << "Check for the values entered" << endl;
		}

	}
}