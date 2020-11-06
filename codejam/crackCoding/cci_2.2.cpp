/*
taikt, 19.Aug.2017

Implement an algorithm to find the nth to last element of a singly linked list.

tìm thành phần thứ n tính từ cuối danh sách trong 1 danh sách liên kết đơn.

*/

#include <stdio.h>

class linked_list {
	struct Node {
		int data;
		Node* link;
	};

private:
	Node* head;

public:
	linked_list () {
		head = NULL;
	}

	void addNode(int data) {
		Node* tmp = new Node();
		tmp->data = data;
		tmp->link = NULL;

		if (head == NULL) {
			head = tmp;	
		} else {
			Node* tmp2 = head; 
			while (tmp2->link != NULL) {
				tmp2 = tmp2->link;
			}
			tmp2->link = tmp;
		}

	}

	void printList() {
		Node* tmp = head;
		while (tmp != NULL) {
			printf("%d ",tmp->data);
			tmp = tmp->link;
		}
		printf("\n");
	}

	void findNthElement1(int n) {
		Node* start = head;
		Node* end = head;
		for (int i=1; i<n; i++) {
			end = end->link;
		}
		while (end->link != NULL) {
			start = start->link;
			end = end->link;
		}
		printf("%d\n",start->data);

	}

	void findNthElement2(int n) {
		int cnt = 0;
		Node* tmp = head;
		while (tmp != NULL) {
			tmp = tmp->link;
			cnt++;
		}

		tmp = head;
		int i = 0;
		while (i<(cnt - n)) {
			tmp = tmp->link;
			i++;
		}

		printf("%d\n",tmp->data);
	} 

};


int main() {
	linked_list node;
	node.addNode(2);
	node.addNode(3);
	node.addNode(5);
	node.addNode(5);
	node.printList();
	node.findNthElement2(3);
	return 0;
}
