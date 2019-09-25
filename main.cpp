#include "header.h"
#include "BinaryTreeSearch.h"
int main()
{
	BinaryTreeSearch *tree = new BinaryTreeSearch();
	//, 13, 888, 109, 55, 118, 89, 33, 1001, 18, 44, 88, 12, 24, 49, 7, 25, 59, 28
	tree->insert(19);
	tree->insert(13);
	tree->insert(888);
	tree->insert(109);
	tree->insert(55);
	tree->insert(118);
	tree->insert(89);
	tree->insert(33);
	tree->insert(1001);
	tree->insert(18);
	tree->insert(44);
	tree->insert(88);
	tree->insert(12);
	tree->insert(24);
	tree->insert(49);
	tree->insert(7);
	tree->insert(25);
	tree->insert(59);
	tree->insert(28);

	cout << "PRINTING IN ORDER\n";

	tree->printInorder(tree->getRoot());
	cout << endl;

	cout << "PRINTING POST ORDER\n";
	tree->printPostorder(tree->getRoot());
	cout << endl;

	cout << "PRINTING PRE ORDER\n";
	tree->printPreorder(tree->getRoot());
	cout << endl;

	cout << "PRINTING FIRST BREADTH\n";
	tree->printFirstBreadth(tree->getRoot());

	cout << endl << endl;
	tree->printLevelorder(tree->getRoot());

	cout << endl << endl;

	tree->parentChild(tree->getRoot());
return 0;
}
