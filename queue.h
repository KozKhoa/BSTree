#pragma once

#include <iostream> 
#include <stdint.h>

using int4 = int32_t;

template <class type>
class Queue {
public:
	Queue();
	~Queue();
	bool isEmpty();
	void push(type val);
	size_t size();
	type front();
	type back();
	void pop();
	void remove();
	void sort();
	void print();
	void reverse();

private:
	struct Node {
		type key;
		Node* next;
	};	
	Node* createNode(type val) {
		Node* node = new (std::nothrow) Node;
		if (!node) {
			throw std::invalid_argument("Can't allocate");
		}
		node->key = val;
		node->next = nullptr;
		return node;
	}
	Node* head;
	Node* tail;
	size_t numOfElemets;

	void _sort(Node*& node);
	void _reverse(Node*& node);
};

#include "queue.cpp"