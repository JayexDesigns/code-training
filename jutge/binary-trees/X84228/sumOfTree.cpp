#include "BinaryTree.hpp"
#include <queue>

int sumOfTree(BinaryTree<int> t) {
	queue<BinaryTree<int>> q;
	q.push(t);
	int sum = 0;
	while (!q.empty()) {
		BinaryTree<int> tree = q.front();
		if (!tree.isEmpty()) {
			q.push(tree.getLeft());
			q.push(tree.getRight());
			sum += tree.getRoot();
		}
		q.pop();
	}
	return sum;
}