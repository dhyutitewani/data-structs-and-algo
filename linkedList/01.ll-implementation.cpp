/*
 * 1. Linked list implementation
 *
 * Process: Implemented using classes.
 *
 * 		    Operations to be performed:
 * 		    - Insertion
 * 		    - Deletion
 * 		    - Searching
 * 		    - Sorting
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

class LL {
	public:
		class Node {
			public:
				int data;
				Node *next;
	
				Node() {
					data = 0;
					next = nullptr;
				}
	
				Node(int val) {
					data = val;
					next = nullptr;
				}
		};
		
		Node *head;

		LL() {
			head = nullptr;
		}

		void display() {
			Node *temp = head;
			
			if (head == nullptr) {
				cout << "empty list" << endl;
				return;
			}

			while (temp != nullptr) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			
			cout << endl;
		}

		void insert(int val) {
			Node *temp = head;
			Node *newNode = new Node(val);

			if (head == nullptr) {
				head = newNode;
			} 
			else {
				while (temp->next != nullptr) {
					temp = temp->next;
				}

				temp->next = newNode;
			}	
		}
		
		void insertAtPos(int val, int pos) {
			Node *temp = head;
			Node *newNode = new Node(val);
			
			if (pos <= 0) {
				cout << "invalid pos" << endl;

				delete newNode;
				return;
			}
			
			if (pos == 1) {
				newNode->next = head;
				head = newNode;

				return;
			}
			
			if (temp == nullptr) {
				cout << "pos out of bounds" << endl;

				delete newNode;
				return;
			}

			int i = 0;
			while (i < pos - 1 && temp->next != nullptr) {
				temp = temp->next;
				i++;
			}
			
			temp->next = newNode;
			newNode->next = temp->next->next;
		}

		void del(int val) {
			if (head == nullptr) {
				cout << "empty linked list" << endl;
				return;
			}
		
			// deleting the head node
			if (head->data == val) {
				Node *temp = head;

				head = head->next;
				delete temp;
				
				return;
			}
			
			Node *temp = head;
			
			// traversing to one node before node
			while (temp->next != nullptr && temp->next->data != val) {	
				temp = temp->next;					
			}
			
			// deleting the last node
			if (temp->next == nullptr) {

				if (temp->data != val) {
					cout << "node not found" << endl; 
				}

				delete temp;
				return;
			}
			
			Node *nextNode = temp->next->next;			// store next node
			
			delete temp->next;					// delete node after curr node
			temp->next = nextNode;					// update curr node's next pos
		}	

		void replace(int val, int nval) {
			Node *temp = head;

			if (head == nullptr) {
				cout << "empty list" << endl;
				return;
			}
	
			if (head->data == val) {
				head->data = nval;
				return;
			}

			while (temp->next != nullptr && temp->next->data != val) {
				temp = temp->next;
			}
		
			temp->next->data = nval;
		}
};

int main() {
	int c, v, nv, p;
	
	LL list;

	while (true) {
		cout << "operation to be performed on linked list" << endl;
		cout << "1. display  2. insert  3. insert at any position" << endl;
		cout << "4. delete  5. replace  6. exit" << endl;
		cin >> c;	
		cout << endl;

		switch(c) {
			case 1:
				list.display();

				cout << endl;
				break;

			case 2:
			   	cout << "enter val: ";
                		cin >> v;
               
			   	list.insert(v);

				cout << endl;
                		break;

			case 3:
				cout << "enter val: ";
				cin >> v;

				cout << "enter position: ";
				cin >> p;

				list.insertAtPos(v, p);

				cout << endl;
				break;

			case 4:
				cout << "enter val to be deleted: ";
				cin >> v;

				list.del(v);

				cout << endl;
				break;

			case 5:
                cout << "enter curr val: ";
				cin >> v;

				cout << "enter new val: ";
				cin >> nv;
				
				list.replace(v, nv);

			   	cout << endl;
                break;

			case 6:
				exit(0);
				break;

			default:
				cout << "invalid" << endl;
				cout << endl;
				break;
		}
	}

	return 0;
}
