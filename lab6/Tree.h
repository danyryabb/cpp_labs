//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
#include <vcl.h>
//---------------------------------------------------------------------------
struct Node
{
	int key;
	AnsiString name;
	Node* left;
	Node* right;
};
typedef Node* PNode;

class Tree
{
public:
	PNode head;
	int numOfNodes;

	Tree();

	void AddNode(int newkey, AnsiString newfio);
	int AddToMassFromTree(PNode current, int* keys, AnsiString* fios, int &numInMass);
	void MakeTreeByMass(int* keys, AnsiString* fios, int n);
	PNode MakeTreeByMassRecurtion(int* keys, AnsiString* fios, int from, int n);
	PNode SearchNewNode(int thiskey, PNode current);

	void BalanceTree();

	void DeleteTree();
	void DeleteNode(int key);
	void DeleteTreeRecurtion(PNode current);

	AnsiString SearchByKey(int key);

	void ShowTree(TTreeView *TreeView);
	void ShowTreeRecurtion(PNode current, TTreeView *TreeView, int &index);

	void TraversalPreOrder(TListBox *ListBox);
	void TraversalPostOrder(TListBox *ListBox);
	void TraversalInOrder(TListBox *ListBox);
	void TraversalPreOrderRecurtion(PNode current, TListBox *ListBox);
	void TraversalPostOrderRecurtion(PNode current, TListBox *ListBox);
	void TraversalInOrderRecurtion(PNode current, TListBox *ListBox);
};
class ExSolution : public Tree
{
public:
	 void DeleteNodeBranch(int key);
};
#endif
