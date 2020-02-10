/* Write code to remove duplicates from an unsorted linked list. FOLLOW UP How would you solve this problem if a temporary buffer is not allowed?

xóa ký tự trùng nhau trong 1 danh sách liên kết chưa sắp xếp.

*/

#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <unordered_map>
using namespace std;

class linkedlist {
	struct Node {
		int data;
		Node * link;
	};
private:
	Node* head;

public:
	linkedlist() {
		head = NULL;
	}

	void createNode(int data) {
		Node* temp = new Node();
		temp->data = data;
		temp->link = NULL;

		if (head == NULL)
		{
			head = temp;
		} else {
			Node* tmp = head;
			while (tmp->link != NULL) {
				tmp = tmp->link;
			}
			tmp->link = temp;

		}

	}

	void printList() {
		Node* tmp = head;
		while (tmp != NULL) {
			printf("%d  ",tmp->data);
			tmp = tmp->link;
		}
		printf("\n");
	}

	void removeDuplicate1() { // O(n)
		Node* tmp = head;
		Node* pre = head;
		bitset<128> bits(0);

		while (tmp != NULL) {
			if (bits.test(tmp->data)) {
				pre->link = tmp->link;
				delete tmp;
				tmp = pre->link;
			}
			else {
				bits.set(tmp->data);
				pre = tmp;
				tmp = tmp->link;
			}
		}
	}

	void removeDuplicate2() {  // O(n)
		Node* tmp = head;
		bitset<128> bits(0);
		bits.set(tmp->data);

		while (tmp->link != NULL) {
			if (bits.test(tmp->link->data)) {
				Node* tmp2 = tmp->link;
				tmp->link = tmp->link->link;
				delete tmp2;
			}
			else {
				bits.set(tmp->data);
				tmp = tmp->link;
			}
		}
	}

	void removeDuplicate3() {  //use unordered_map, O(n)
		Node* tmp = head;
		unordered_map<int,bool> map;

		while (tmp->link != NULL) {
			if (map[tmp->link->data] == 1) {
				Node* tmp2 = tmp->link;
				tmp->link = tmp->link->link;
				delete tmp2;
			}
			else {
				map[tmp->data] = 1;;
				tmp = tmp->link;
			}
		}
	}

};


int main() {
	linkedlist ll;
	int a[]={2,3,4,3,5,4};


	for (int i=0; i< (sizeof(a)/sizeof(a[0])); i++) { 
		//printf("%d ",a[i]);
		ll.createNode(a[i]);
	}
	printf("before..\n");
	
	ll.printList();
	ll.removeDuplicate3();

	printf("after..\n");
	ll.printList();
	

	return 0;
}