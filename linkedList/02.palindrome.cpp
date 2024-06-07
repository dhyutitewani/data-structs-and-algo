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

		void insert(int val) {
            Node *newNode = new Node(val);
            
			if (head == nullptr) {
                head = newNode;
            } else {
                Node *temp = head;
				while (temp->next != nullptr) {
                    temp = temp->next;
                }
                
				temp->next = newNode;
            }
        }

		bool isPalindrome() {
            if (head == nullptr) return true;

			stack<int> s;
			Node *temp = head;
            
			while (temp != nullptr) {
				s.push(temp->data);
                temp = temp->next;
            }

			temp = head;
			while (temp != nullptr) {
				if (temp->data != s.top()) return false;	
				s.pop();	
                temp = temp->next;
			}
			return true;
        }
};

int main() {
	LL ll;
	
	// linked list
	int l[] = {1, 2, 1};

	for (int i = 0; i < 3; i++) ll.insert(l[i]);			
	cout << ll.isPalindrome() << endl;
}
