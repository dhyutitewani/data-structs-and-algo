/*
 *	2. Move last element to the first
 */

#include <bits/stdc++.h>
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

		void rotate() {
			Node *temp = head;

			while (temp->next->next != nullptr) {
				temp = temp->next;
			}

			temp->next->next = head;
			head = temp->next;
			temp->next = nullptr;
		}
};

int main() {
	LL ll;
	int a[] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++) {
		ll.insert(a[i]);
	}
	
	ll.rotate();
	ll.display();
}
