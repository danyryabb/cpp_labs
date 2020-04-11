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
private:
	PNode head;
	int numOfNodes;
	int AddToMassFromTree(PNode current, int* keys, AnsiString* fios, int &numInMass);
	PNode MakeTreeByMassRecurtion(int* keys, AnsiString* fios, int from, int n);
	void DeleteTreeRecurtion(PNode current);
	void ShowTreeRecurtion(PNode current, TTreeView *TreeView, int &index);
	PNode SearchNewNode(int thiskey, PNode current);
	void MakeTreeByMass(int* keys, AnsiString* fios, int n);
	void TraversalPreOrderRecurtion(PNode current, TListBox *ListBox);
	void TraversalPostOrderRecurtion(PNode current, TListBox *ListBox);
	void TraversalInOrderRecurtion(PNode current, TListBox *ListBox);

public:
	Tree();
	void AddNode(int newkey, AnsiString newfio);
	void BalanceTree();
	void DeleteTree();
	void DeleteNode(int key);
    void DeleteNodeBranch(int key);
	AnsiString SearchByKey(int key);
	void ShowTree(TTreeView *TreeView);
	void TraversalPreOrder(TListBox *ListBox);
	void TraversalPostOrder(TListBox *ListBox);
	void TraversalInOrder(TListBox *ListBox);
};

#endif
