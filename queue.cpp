#pragma once
#include "queue.h"
//=======================================
template <class type>
Queue<type>::Queue() {
	head = tail = nullptr;
	numOfElemets = 0;
}
//=======================================
template <class type>
Queue<type>::~Queue() {
	remove();
	head = tail = nullptr;
	numOfElemets = 0;
}
//=======================================
template <class type>
bool Queue<type>::isEmpty() {
	return !(head && tail);
}
//=======================================
// push;
template <class type>
void Queue<type>::push(type val) {
	Node* newNode = createNode(val);
	numOfElemets++;
	if (isEmpty()) {
		head = tail = newNode;
		return;
	}
	tail->next = newNode;
	tail = newNode;
 }
//=======================================
// size;
template <class type>
size_t Queue<type>::size() {
	return numOfElemets;
}
//=======================================
// front
template <class type>
type Queue<type>::front() {
	return head->key;
}
//=======================================
// back()
template <class type>
type Queue<type>::back() {
	return tail->key;
}
//=======================================
// pop
template <class type>
void Queue<type>::pop() {
	if (!isEmpty()) {
		Node* del = head;
		head = head->next;
		delete del;
		numOfElemets--;
		if (!head) {
			tail = head = nullptr;
		}
	}
}
//=======================================
// remove
template <class type>
void Queue<type>::remove() {
	if (!isEmpty()) {
		while (head) {
			Node* del = head;
			head = head->next;
			delete del;
		}
	}
	head = tail = nullptr;
	numOfElemets = 0;
}
//========================================
// sort;
template <class type>
void Queue<type>::_sort(Node*& node) {
	if (!(node && node->next)) {
		return;
	}
	_sort(node->next);
	if (node->key <= node->next->key) {
		return;
	}
	Node* insertedNode = node;
	Node* currentNode = node->next;
	Node* prevNode = node;
	node = node->next;
	while (currentNode && currentNode->key < insertedNode->key) {
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	if (!currentNode) {
		tail = insertedNode;
	}
	insertedNode->next = prevNode->next;
	prevNode->next = insertedNode;
}
template<class type>
void Queue<type>::sort() {
	if (!isEmpty()) {
		_sort(head);
	}
}
//=====================================================
// print;
template <class type>
void Queue<type>::print() {
	if (!isEmpty()) {
		std::cout << "Head = " << head << ' ' << head->key << '\n';
		std::cout << "Tail = " << tail << ' ' << tail->key << '\n';
		for (Node* i = head; i; i = i->next) {
			std::cout << i->key << ' ';
		}
		std::cout << '\n';
	}
}
//=====================================================
// reverse;
template<class type>
void Queue<type>::_reverse(Node*& node) {
	if (!node->next) {
		return;
	}
	_reverse(node->next);
	Node* reverseNode = node;
	node = node->next;
	tail->next = reverseNode;
	reverseNode->next = nullptr;
	tail = reverseNode;
}
template<class type>
void Queue<type>::reverse() {
	if (!isEmpty()) {
		_reverse(head);
	}
}
//===================================================
