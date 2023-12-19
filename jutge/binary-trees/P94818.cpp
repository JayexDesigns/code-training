#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class BST {
	private:
	struct node{
		node* left;
		node* right;
		T value;
	};

	node* root;

	bool insertRecursive(node* n, T &value) {
		if (n == nullptr) return true;
		if (value < n->value) {
			if (insertRecursive(n->left, value)) {
				node* nptr = new node;
				nptr->left = nullptr;
				nptr->right = nullptr;
				nptr->value = value;
				n->left = nptr;
			}
		}
		else if (value > n->value) {
			if (insertRecursive(n->right, value)) {
				node* nptr = new node;
				nptr->left = nullptr;
				nptr->right = nullptr;
				nptr->value = value;
				n->right = nptr;
			}
		}
		return false;
	}

	void printRecursive(node* n, int level) {
		if (n != nullptr) {
			printRecursive(n->right, level + 1);
			cout << setw(level * 10) << n->value << endl;
			printRecursive(n->left, level + 1);
		}
	}

	public:
	BST() {
		root = nullptr;
	}

	~BST() {
		this->deleteTree(root);
	}

	void deleteTree(node* n) {
		if (n == nullptr) return;
		deleteTree(n->left);
		deleteTree(n->right);
		delete n;
	}

	void insert(T value) {
		if (root == nullptr) {
			root = new node;
			root->left = nullptr;
			root->right = nullptr;
			root->value = value;
		}
		else this->insertRecursive(root, value);
	}

	void print() {
		int level = 1;
		this->printRecursive(root, level);
	}
};

int main() {
	BST<int> bst;
	int n;
	while (cin >> n) {
		bst.insert(n);
	}
	bst.print();
	return 0;
}
