
#include <iostream>

using namespace std;

class Node {
	friend class Snake;

	private:
		int xpos, ypos;
		Node *nextNode;
};

class Snake {
	private:
		Node *front, *rear;

	public:
		Snake() {
			front = new Node();
			rear = new Node();
			front = NULL;
			rear = NULL;
		}

		void enqueue(int x, int y) {
			Node* newNode = new Node();
			newNode->xpos = x;
			newNode->ypos = y;
			newNode->nextNode = NULL;

			if (rear == NULL) {
				rear = newNode;
				front = newNode;
			}
			else {
				rear->nextNode = newNode;
				rear = newNode;
			}
		}

		void dequeue(int& x, int& y) { 
			if (!(this->isEmpty())) {
				x = front->xpos;
				y = front->ypos;

				Node *temp = front;
				front = front->nextNode;

				delete temp;

				if(this->isEmpty())
					rear = NULL;
			}
			else cout << "Queue is Empty.\n";
		}

		void getFront(int& x, int& y) {
			if (!(this->isEmpty())) {
				x = front->xpos;
				y = front->ypos;
			}

			else cout << "Queue is empty.\n";
		}

		bool isEmpty() {
			return (front == NULL);
		}
};
