#ifndef BINARYTREESEARCH_H_
#define BINARYTREESEARCH_H_

#include "header.h"
#include <queue>
class BinaryTreeSearch
{
private:
	struct TreeNode
	{
		int value;
		TreeNode *left;
		TreeNode *right;

		TreeNode(int value, TreeNode *left = nullptr, TreeNode *right = nullptr)
		{
			this->value = value;
			this->left = left;
			this->right = right;
		}
	};

	TreeNode *root;
	//inserting values
	void insert(TreeNode *&tree, int value)
	{
		//if the tree is empty BASE CASE 1
		if(tree == nullptr)
		{
		tree = new TreeNode(value);
		return;
		}

		//if the value is already the tree BASE CASE 2
		if(value == tree->value)
		{
			insert(tree->left, value);
		}

		//if the value is being inserted is less than the value of the current node
		if(value < tree->value)
		{
			insert(tree->left, value);
		}
		//if the value is greater
		else
		{
			insert(tree->right,value);
		}

	}

	void displayInOrder(TreeNode *tree)
	{
		//if the tree is empty BASE CASE 1
		if(tree==nullptr)
		{
			return;
		}
		else
		{
			displayInOrder(tree->left);
			cout << tree->value << " ";
			displayInOrder(tree->right);
		}
	}

public:

	BinaryTreeSearch()
	{
		root = nullptr;
	}

	//this is done so the user does not have direct access to root
	void insert(int value)
	{
		insert(root, value);
	}

	void showInOrder()
	{
		displayInOrder(root);
	}

	void search()
	{
		//ask user for the letter
		//if letter is in the tree, then return a found message
		TreeNode *tree = root;
		int userInput;
		bool found = false;

		//prompt user
		cout << "\nPlease enter a value that you would like to search for: ";
		cin >> userInput;


		//search for the letter
		while(tree!=nullptr)
		{
			if(tree->value == userInput)
			{
				found = true;
				break;
			}
			else if(userInput < tree->value)
			{
				tree = tree->left;
			}
			else
			{
				tree = tree->right;
			}
		}

		if(found)
		{
			cout << "The value " << userInput << " has been found in the tree!\n";
		}
		else
		{
			cout << "The value " << userInput << " was not found!\n";
		}
	}

	void printPostorder(TreeNode* tree)
	{
	    if (tree == NULL)
	        return;

	    // first recur on left subtree
	    printPostorder(tree->left);

	    // then recur on right subtree
	    printPostorder(tree->right);

	    // now deal with the node
	    cout << tree->value << " ";
	}

	/* Given a binary tree, print its nodes in inorder*/
	void printInorder(TreeNode* tree)
	{
	    if (tree == NULL)
	        return;

	    /* first recur on left child */
	    printInorder(tree->left);

	    /* then print the data of node */

	    cout << tree->value << " ";

	    /* now recur on right child */
	    printInorder(tree->right);
	}

	/* Given a binary tree, print its nodes in preorder*/
	void printPreorder(TreeNode* tree)
	{
	    if (tree == NULL)
	        return;

	    /* first print data of node */
	    cout << tree->value << " ";

	    /* then recur on left sutree */
	    printPreorder(tree->left);

	    /* now recur on right subtree */
	    printPreorder(tree->right);
	}

	void printFirstBreadth(TreeNode* tree)
	{


		queue<TreeNode *> queue;

		if(root == NULL) {
			return;
		}

		queue.push(root);
		while(!queue.empty())
		{
			TreeNode *temp = queue.front();
			cout << " " << temp->value << " ";
			queue.pop();

			if(temp->left != nullptr)
			{
				queue.push(temp->left);
			}

			if(temp->right != nullptr)
			{
				queue.push(temp->right);
			}
		}
	}

	void printLevelorder(TreeNode *root)
	{
		int i = 1;
		if(root == NULL)
		{
			return;
		}


		queue<TreeNode *> currentLevel;
		queue<TreeNode *>  nextLevel;
		currentLevel.push(root);
		cout << "Level " << i <<": ";

		while(!currentLevel.empty())
		{
			TreeNode *currNode = currentLevel.front();
			currentLevel.pop();

			if(currNode)
			{
		        cout << currNode->value << " ";
				nextLevel.push(currNode->left);
				nextLevel.push(currNode->right);
			}

			if(currentLevel.empty() == true)
			{
				i++;
				cout << endl;
				cout << "Level " << i <<": ";
				swap(currentLevel, nextLevel);
			}
		}
	}

	void parentChild(TreeNode *ptr)
	{
		//basically iteratively doing breadth first
		if(root == NULL)
		{
			return;
		}

		queue<TreeNode *> parent;
		queue<TreeNode *> child;

		parent.push(root); //used to enter loop
		while(!parent.empty())
		{
			TreeNode *currNode = parent.front();
			parent.pop();
			if(currNode)
			{
		        cout << "Parent: " << currNode->value << endl;
				child.push(currNode->left);

		        if(currNode->left != NULL)
		        {
		        		cout << "Child (LEFT): " << currNode->left->value << endl;
		        }
		        else
		        {
		        		cout << "No child left node." << endl;
		        }

				child.push(currNode->right);

				if(currNode->right != NULL)
				{
					cout << "Child (RIGHT): " << currNode->right->value << endl;
				}
				else
				{
					cout << "No child right node." << endl;
				}

				cout << endl;
			}

			if(parent.empty())
			{
				swap(parent, child);
			}
		}
	}

	 TreeNode*& getRoot()
	 {
		return root;
	 }
};


#endif /* BINARYTREESEARCH_H_ */
