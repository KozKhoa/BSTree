#pragma once

#include <iostream>
#include "queue.h"

template <class type>
class  BSTree
{
public:
	struct Node {
		type key;
		Node* pLeft;
		Node* pRight;
	};
	BSTree();
	bool isLeaf(Node* node);
	bool isEmpty();
	void add(type val);
	void* search(type val);
	void remove(type val);
	void print_LNR();
	void print_NLR();
	void print_RNL();
	void print_Level();
private:
	Node* root;
	size_t numOfElements;
	void sub_remove(type val, Node*& node);
	void sub_print_LNR(const Node* node);
	void sub_print_NLR(const Node* node);
	void sub_print_RNL(const Node* node);
	void sub_print_Level(Node* node);
};

#include "BSTree.cpp"