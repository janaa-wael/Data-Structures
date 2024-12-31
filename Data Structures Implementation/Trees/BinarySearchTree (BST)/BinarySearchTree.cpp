/*
 * main.cpp
 *
 *  Created on: Dec 30, 2024
 *      Author: Jana Wael
 */
#include <iostream>
using namespace std;


class BinaryTreeNode {
public:
	int data;
	BinaryTreeNode* right;
	BinaryTreeNode* left;
};


class Queue {
private:
	int size;
	BinaryTreeNode** arr;
	int front;
	int back;
public:
	Queue()
	{
		size = 1000;
		front = -1;
		back = -1;
		arr = new BinaryTreeNode * [size];
	}

	~Queue()
	{
		delete[] arr;
	}
	BinaryTreeNode* getFront(void)
	{
		if (!isEmpty())
			return arr[front];
		cout << "Empty queue" << endl;
		return NULL;
	}

	BinaryTreeNode* getBack(void)
	{
		if (!this->isEmpty())
			return arr[back];
		cout << "Empty queue" << endl;
		return NULL;

	}

	bool isEmpty()
	{
		return front == -1;
	}

	bool isFull(void)
	{
		return back == size - 1;
	}

	void enqueue(BinaryTreeNode* node)
	{
		if (isEmpty())
		{
			front = 0;
			back = 0;
			arr[front] = node;
		}
		else if (isFull())
		{
			size *= 2;
			BinaryTreeNode** temp = new BinaryTreeNode * [size];
			for (int i = front; i <= back; i++) {
				temp[i - front] = arr[i]; // Shift indices to start from 0
			}
			back = back - front; // Update back index
			front = 0;           // Reset front index
			delete[] arr;        // Delete old array
			arr = temp;          // Point to the new array
			arr[++back] = node;
		}

		else
		{
			arr[++back] = node;
		}
	}

	BinaryTreeNode* dequeue(void)
	{
		BinaryTreeNode* element;
		if (isEmpty())
		{
			cout << "Empty queue!" << endl;
			return NULL;
		}
		else if (front == back)
		{
			element = arr[front];
			back = -1;
			front = -1;
		}
		else
		{
			element = arr[front];
			front++;
		}
		return element;
	}

	void print_queue()
	{
		Queue q;
		while (!isEmpty())
		{
			cout << getFront() << endl;
			q.enqueue(dequeue());
		}
		while (!q.isEmpty())
		{
			this->enqueue(q.dequeue());
		}

	}
};



class BinaryTree {
private:
	BinaryTreeNode* root;
public:
	BinaryTree(int data)
	{
		root = new BinaryTreeNode[1];
		root->data = data;
		root->right = NULL;
		root->left = NULL;
	}
	BinaryTreeNode* getRoot(void)
	{
		return root;
	}
	void addNode(int element, BinaryTreeNode* parent)
	{
		if (parent == NULL)
			return;
		if (element > parent->data)
		{
			if (parent->right == NULL)
			{
				parent->right = new BinaryTreeNode();
				parent->right->data = element;
				parent->right->left = NULL;
				parent->right->right = NULL;
			}
			else
				addNode(element, parent->right);
		}
		else
		{
			if (parent->left == NULL)
			{
				parent->left = new BinaryTreeNode();
				parent->left->data = element;
				parent->left->left = NULL;
				parent->left->right = NULL;
			}
			else
				addNode(element, parent->left);
		}
	}

	bool isLeafNode(BinaryTreeNode* node)
	{
		return (node->left == NULL) && (node->right == NULL);
	}

	bool Has1LeftChild(BinaryTreeNode* node)
	{
		return (node->left != NULL && node->right == NULL);
	}

	bool Has1RightChild(BinaryTreeNode* node)
	{
		return (node->left == NULL && node->right != NULL);
	}

	bool Has2Children(BinaryTreeNode* node)
	{
		return (node->left != NULL && node->right != NULL);
	}

	int getMin(void)
	{
		BinaryTreeNode* parent = root;
		while (parent->left != NULL)
		{
			parent = parent->left;
		}
		return parent->data;
	}

	BinaryTreeNode* getMinNode(BinaryTreeNode* node)
	{
		while (node->left != NULL)
		{
			node = node->left;
		}
		return node;
	}

	int getMaxValue(void)
	{
		BinaryTreeNode* parent = root;
		while (parent->right != NULL)
		{
			parent = parent->right;
		}
		return parent->data;
	}

	BinaryTreeNode* getMaxNode(BinaryTreeNode* node)
	{
		while (node->right != NULL)
		{
			node = node->right;
		}
		return node;
	}


	int getHeight(BinaryTreeNode* parent)
	{
		if (parent == NULL)
			return -1;
		else
			return max(getHeight(parent->left) + 1, getHeight(parent->right) + 1);
	}

	bool isNodeFound_rec(BinaryTreeNode* node, int value)
	{
		if (node == NULL)
			return false;
		else if (node->data == value)
			return true;
		else if (node->data >= value)
			search_recursive(root->left, value);
		else if (node->data < value)
			search_recursive(node->right, value);
	}

	bool isNodeFound(int value)
	{
		return isNodeFound_rec(root, value);
	}

	BinaryTreeNode* search_recursive(BinaryTreeNode* node, int value)
	{
		if (node == NULL)
			return NULL;
		else if (node->data == value)
			return node;
		else if (node->data >= value)
			search_recursive(root->left, value);
		else if (node->data < value)
			search_recursive(node->right, value);
	}

	BinaryTreeNode* search(int value)
	{
		return search_recursive(root, value);
	}

	void InOrderTraversal(BinaryTreeNode* parent)
	{
		if (parent == NULL)
			return;
		InOrderTraversal(parent->left);  //Visit left subtree
		cout << parent->data << endl;    //Visit current node
		InOrderTraversal(parent->right); //Bisit right subtree
	}

	void PreorderTraversal(BinaryTreeNode* parent)
	{
		if (parent == NULL)
			return;
		cout << parent->data << endl;    //Visit current node
		PreorderTraversal(parent->left);  //Visit left subtree
		PreorderTraversal(parent->right); //Visit right subtree

	}

	void PostorderTraversal(BinaryTreeNode* parent)
	{
		if (parent == NULL)
			return;
		PostorderTraversal(parent->left);  //Visit left subtree
		PostorderTraversal(parent->right); //Visit right subtree
		cout << parent->data << endl;    //Visit current node
	}

	void BreadthFirstTraversal(BinaryTreeNode* parent)
	{
		if (parent == NULL)
			return;
		Queue q;
		q.Queue::enqueue(parent);
		while (!q.Queue::isEmpty())
		{
			BinaryTreeNode* node = q.Queue::dequeue();
			cout << node->data << endl;
			if (node->left != NULL)
				q.enqueue(node->left);
			if (node->right != NULL)
				q.Queue::enqueue(node->right);
		}
	}

	int Count_Leaf_Node(BinaryTreeNode* node)
	{
		if (node == NULL)
			return 0;
		else if (node->right == NULL && node->left == NULL)
			return 1;
		else
		{
			return Count_Leaf_Node(node->left) + Count_Leaf_Node(node->right);
		}
	}

	int Count_Nodes(BinaryTreeNode* node)
	{
		if (node == NULL)
		{
			return 0;
		}

		return 1 + Count_Nodes(node->left) + Count_Nodes(node->right);
	}

	void debug(void)
	{
		cout << "**********************************" << endl;
		cout << "* Number of nodes: " << Count_Nodes(root) << endl;
		cout << "* Number of leaf nodes: " << Count_Nodes(root) << endl;
		cout << "* Max Node: " << getMaxValue() << endl;
		cout << "* Min Node: " << getMin() << endl;
		cout << "* Height: " << getHeight(root) << endl;
		cout << "**********************************" << endl;
	}

	BinaryTreeNode* deleteNode(BinaryTreeNode* node, int value)
	{
		if (node == NULL)
			return node;
		if (value > node->data)
		{
			node->right = deleteNode(node->right, value);
		}
		else if (value < node->data)
		{
			node->left = deleteNode(node->left, value);
		}
		else
		{
			if (isLeafNode(node))
			{
				delete node;
				return NULL;
			}
			else if (Has1RightChild(node))
			{
				BinaryTreeNode* temp = node->right;
				delete(node);
				return temp;
			}
			else if (Has1LeftChild(node))
			{
				BinaryTreeNode* temp = node->left;
				delete(node);
				return temp;
			}
			BinaryTreeNode* temp = getMinNode(node->right);
			node->data = temp->data;
			node->right = deleteNode(node->right, temp->data);
		}
		return node;
	}



};

int main() {
	BinaryTree tree(5);
	BinaryTreeNode* root = tree.getRoot();
	tree.addNode(2, root);
	tree.addNode(8, root);
	tree.addNode(1, root);
	tree.addNode(3, root);
	tree.addNode(10, root);
	tree.addNode(7, root);
	tree.addNode(15, root);
	tree.addNode(16, root);
	tree.addNode(0, root);
	tree.addNode(-1, root);
	cout << "In-order Traversal" << endl;
	tree.InOrderTraversal(root);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Pre-order Traversal" << endl;
	tree.PreorderTraversal(root);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Post-order Traversal" << endl;
	tree.PostorderTraversal(root);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Breadth-First Traversal" << endl;
	tree.BreadthFirstTraversal(root);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	tree.debug();
	cout << "Result of searching of 10: " << (tree.search(10) ? "true" : "false") << endl;
	cout << "Result of searching of 20: " << (tree.search(20) ? "true" : "false") << endl;
	cout << "After deleting element 8: " << endl;
	tree.deleteNode(root, 8);
	tree.PostorderTraversal(root);
	return 0;
}
