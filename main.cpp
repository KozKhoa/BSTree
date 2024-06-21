#include <iostream>
#include "BSTree.h"
#include <stdint.h>
#include <fstream>

using int4 = int32_t;
using int8 = int64_t;

void readFie(const char inFile[], BSTree<int4> &tree) {
	std::ifstream fi;
	fi.open(inFile, std::ios::in);

	if (!fi.is_open()) {
		throw std::invalid_argument("Can't open file to read");
	}

	while (!fi.eof()) {
		int4 val = 0;
		fi >> val;
		tree.add(val);
	}
	fi.close();
}

int4 main() {
	srand(time(0));
	const char inFile[] = "input.txt";
	BSTree<int4> tree;
	Queue<int4> queue;
	int4 n = rand() % 20;
	std::cout << "N = " << n << '\n';
	for (int4 i = 0; i < n; i++) {
		queue.push(rand() * rand() % 100);
	}
	queue.print();
	std::cout << "After sort:\n";
	queue.sort();
	queue.print();
	std::cout << "After reverse:\n";
	queue.reverse();
	queue.print();
	return 0;
}
