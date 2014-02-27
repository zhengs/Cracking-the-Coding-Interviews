#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	Node* next;
	int a;
	Node() {
		this->next = 0;
		this->a = 0;
	}
};

Node* removeDup(Node* h) {
	// 2.1
	Node* now = h;
	std::map<int, int> m;
	m[now->a] = 1;
	Node* prev = now;
	now = now->next;
	while(now != 0) {
		if(m.find(now->a) == m.end()) {
			m[now->a] = 1;
			prev = now;
			now = now->next;
		} else {
			Node* toDelete = now;
			prev->next = now->next;
			delete toDelete;
			now = prev->next;
		}
	}
	return h;
}

Node* removeDupNoBuffer(Node* h) {
	Node* now1 = h;
	while(now1 != 0) {
		Node* now2 = now1->next;
		Node* prev = now1;
		while(now2 != 0) {
			std::cout<< now2->a << endl;
			if(now2->a == now1->a) {
				prev->next = now2->next;
				// delete now2;
				now2 = prev->next;
			} else{
				prev = now2;
				now2 = now2->next;
			}
		}
		now1 = now1->next;
	}
	return h;
}

void print(Node* h) {
	while(h!=0) {
		std::cout << h->a << " ";
		h = h->next;
	}
	std::cout << std::endl;
}

Node* findK(Node* h, int k){
	int i = k - 1; 
	Node* now = h;
	while(now != 0 && i > 0){
		now = now->next;
		i--;
	}
	if(now == 0) return 0; 
	Node* p = h;
	while(now->next != 0) {
		now = now->next;
		p = p->next;
	}
	return p;
}


int main(){
	Node* head = new Node();
	Node* now = head; now->a = 0;
	now->next = new Node(); now = now->next; now->a = 1;
	now->next = new Node(); now = now->next; now->a = 2;
	now->next = new Node(); now = now->next; now->a = 2;
	now->next = new Node(); now = now->next; now->a = 4;
	now->next = new Node(); now = now->next; now->a = 2;
	now->next = new Node(); now = now->next; now->a = 1;
	now->next = new Node(); now = now->next; now->a = 2;
	now->next = new Node(); now = now->next; now->a = 0;
	print(head);
	head = removeDupNoBuffer(head);
	std::cout << "haha" << std::endl;
	print(head);

	now = head; now->a = -1;
	for(int i = 0; i < 10; i++) {
		now->next = new Node(); now = now->next; now->a = i;
	}
	print(head);
	now = findK(head, 3);
	print(now);
}