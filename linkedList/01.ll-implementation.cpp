/*
 * 1. Linked list implementation
 *
 * Process: Implemented using classes.
 *
 * 		    Operations to be performed:
 * 		    - Insert
 * 		    - Delete
 * 		    - Search
 * 		    - Sort
 * 		    - Reverse
 */

#include <cstdlib>
#include <iostream>
using namespace std;

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

class LL {
    public:
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

            for (int i = 1; temp != nullptr && i < pos - 1; i++) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "pos out of bounds" << endl;
                delete newNode;
                return;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        void del(int val) {
            if (head == nullptr) {
                cout << "empty linked list" << endl;
                return;
            }
			
			// deleting head node
            if (head->data == val) {
                Node *temp = head;
                head = head->next;
                delete temp;
                return;
            }
			
	    // traversing to one node before node
            Node *temp = head;
            while (temp->next != nullptr && temp->next->data != val) {
                temp = temp->next;
            }
			
	    // deleting last node
            if (temp->next == nullptr) {
                cout << "node not found" << endl;
                return;
            }

            Node *nextNode = temp->next->next;					// stores next node

            delete temp->next;							// delete node after curr node
            temp->next = nextNode;						// update curr node's next pos
        }

        void replace(int val, int nval) {
            Node *temp = head;

            if (head == nullptr) {
                cout << "empty list" << endl;
                return;
            }

            while (temp != nullptr && temp->data != val) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "node not found" << endl;
                return;
            }

            temp->data = nval;
        }

        void reverse() {
            Node *curr = head;
            Node *prev = nullptr;
            Node *nextNode;

            if (head == nullptr) {
                cout << "empty list" << endl;
                return;
            }

            while (curr != nullptr) {
                nextNode = curr->next;						// think of flipping ptr of ll
                curr->next = prev;						// curr->next now points to prev [flipped arrow]
                prev = curr;							// curr nodes becomes previous
                curr = nextNode;						// curr moves to next node
            }

            head = prev;
        }
};

int main() {
    int c, v, nv, p;

    LL list;

    while (true) {
        cout << "operation to be performed on linked list" << endl;
        cout << "1. display  2. insert  3. insert at any position" << endl;
        cout << "4. delete  5. replace  6. reverse  7. exit" << endl;
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
                cout << "reversed linked list: ";
                list.reverse();
                list.display(); // Add display here to show reversed list
                cout << endl;
                break;

            case 7:
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
