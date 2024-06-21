#pragma once
#include "BSTree.h"

template <class type>
BSTree<type>::BSTree() {
	root = nullptr;
	numOfElements = 0;
}
// isEmpty;
template <class type>
bool BSTree<type>::isEmpty() {
	return root == nullptr;
}
// isLeaf;
template <class type>
bool BSTree<type>::isLeaf(BSTree<type>::Node* node) {
	if (node->pLeft || node->pRight) {
		return false;
	}
	return true;
}
// add;
template <class type>
void BSTree<type>::add(type val) {
	if (isEmpty()) {
		Node* new_node = new (std::nothrow) Node;
		if (new_node == nullptr) {
			throw std::invalid_argument("Can't allocate");
		}
		new_node->key = val;
		new_node->pRight = new_node->pLeft = nullptr;
		root = new_node;
		numOfElements++;
		return;
	}
	Node* node = root;
	Node* prev_node = root;
	while (node) {
		if (node->key == val) {
			return;
		}
		if (val < node->key) {
			prev_node = node;
			node = node->pLeft;
			continue;
		}
		if (val > node->key) {
			prev_node = node;
			node = node->pRight;
			continue;
		}
	}
	Node* new_node = new (std::nothrow) Node;
	if (new_node == nullptr) {
		throw std::invalid_argument("Can't allocate");
	}
	new_node->key = val;
	new_node->pRight = new_node->pLeft = nullptr;
	if (val < prev_node->key) {
		prev_node->pLeft = new_node;
	}
	else if (val > prev_node->key) {
		prev_node->pRight = new_node;
	}
	numOfElements++;
}
// search;
template <class type>
void* BSTree<type>::search(type val) {
	if (isEmpty()) {
		return nullptr;
	}
	Node* node = root;
	while (node) {
		if (node->key == val) {
			return node;
		}
		if (val < node->key) {
			node = node->pLeft;
			continue;
		}
		if (val > node->key) {
			node = node->pRight;
			continue;
		}
	}
	return node;
}
//======================================================================
// remove;
template<class type>
void BSTree<type>::sub_remove(type val, BSTree<type>::Node* &node) {
	if (node == nullptr) {
		return;
	}
	if (val < node->key) {
		sub_remove(val, node->pLeft);
	}
	else if (val > node->key){
		sub_remove(val, node->pRight);
	}
	else {
		Node* del = node;
		if (!node->pLeft) {
			node = node->pRight;
			numOfElements--;
			delete del;
		}
		else if (!node->pRight) {
			node = node->pLeft;
			numOfElements--;
			delete del;
		}
		else {
			Node* tempNode = node->pLeft;
			while (tempNode->pRight) {
				tempNode = tempNode->pRight;
			}
			node->key = tempNode->key;
			sub_remove(tempNode->key, node->pRight);
		}			
	}
}
template <class type> 
void BSTree<type>::remove(type val) {
	sub_remove(val, root);
}
//=====================================================================
//  print_LNR;
template<class type>
void BSTree<type>::sub_print_LNR(const Node* node) {
	if (node) {
		sub_print_LNR(node->pLeft);
		std::cout << node->key << ' ';
		sub_print_LNR(node->pRight);
	}
}
template<class type>
void BSTree<type>::print_LNR() {
	if (isEmpty()) {
		return;
	}
	sub_print_LNR(root);
}
//======================================================================
// print_NLR
template<class type>
void BSTree<type>::sub_print_NLR(const Node* node) {
	if (node) {
		std::cout << node->key << ' ';
		sub_print_NLR(node->pLeft);
		sub_print_NLR(node->pRight);
	}
}
template <class type> 
void BSTree<type> ::print_NLR() {
	if (isEmpty()) {
		return;
	}
	sub_print_NLR(root);
}
//=========================================================================
// print_RNL
template<class type>
void BSTree<type>::sub_print_RNL(const Node* node) {
	if (node) {
		sub_print_RNL(node->pRight);
		std::cout << node->key << ' ';
		sub_print_RNL(node->pLeft);
	}
}
template <class type>
void BSTree<type>::print_RNL() {
	if (isEmpty()) {
		return;
	}
	sub_print_RNL(root);
}
//=========================================================================
// print_Level;
template <class type>
void BSTree<type>::sub_print_Level(Node* root) {
	Queue<Node*> queue;
	queue.push(root);
	while (!queue.isEmpty()) {
		Node* node = queue.front();
		queue.pop();
		std::cout << node->key << ' ';
		if (node->pLeft) {
			queue.push(node->pLeft);
		}
		if (node->pRight) {
			queue.push(node->pRight);
		}
	}
	std::cout << '\n';
	queue.remove();
}
template <class type>
void BSTree<type>::print_Level() {
	if (!isEmpty()) {
		sub_print_Level(root);
	}
}