//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"
Tree::Tree()
{
	head = NULL;
	numOfNodes = 0;
}

void Tree::AddNode(int newkey, AnsiString newname)
{
	PNode wantedNode;
	if(head == NULL)
	{
		head = new Node;
		head->key = newkey;
		head->name = newname;
		head->left = NULL;
		head->right = NULL;
		numOfNodes++;
	}
	else
	{
		wantedNode = SearchNewNode(newkey, head);
		if(wantedNode == NULL)
		{
			Application->MessageBox(String("Ёлемент с таким ключом уже существует").c_str(), String("ќшибка").c_str(), MB_OK);
		}
		else
		{
			wantedNode->key = newkey;
			wantedNode->name = newname;
			numOfNodes++;
		}
	}
}

PNode Tree::SearchNewNode(int thiskey, PNode current)
{
	if(thiskey == current->key) return NULL;
	if(thiskey < current->key)
	{
		if(current->left == NULL)
		{
			current->left = new Node;
			current->left->left = NULL;
			current->left->right = NULL;
			return current->left;
		}
		else
		{
			return SearchNewNode(thiskey, current->left);
		}
	}
	else
	{
		if(current->right == NULL)
		{
			current->right = new Node;
			current->right->left = NULL;
			current->right->right = NULL;
			return current->right;
		}
		else
		{
			return SearchNewNode(thiskey, current->right);
		}
	}

}

void Tree::BalanceTree()
{
	if(numOfNodes > 1)
	{
		int numInMass = 0;
		int *keys = new int[numOfNodes];
		AnsiString *names = new AnsiString[numOfNodes];
		AddToMassFromTree(head, keys, names, numInMass);
		MakeTreeByMass(keys, names, numOfNodes);
		delete[] keys;
	}
}

int Tree::AddToMassFromTree(PNode current, int *keys, AnsiString *names, int &numInMass)
{
	if(current->left != NULL) numInMass = AddToMassFromTree(current->left, keys, names, numInMass);
	keys[numInMass] = current->key;
	names[numInMass] = current->name;
	numInMass++;
	if(current->right != NULL) numInMass = AddToMassFromTree(current->right, keys, names, numInMass);
	return numInMass;
}

void Tree::MakeTreeByMass(int *keys, AnsiString *names, int n)
{
	DeleteTree();
	head = MakeTreeByMassRecurtion(keys, names, 0, n);
}

PNode Tree::MakeTreeByMassRecurtion(int *keys, AnsiString *names, int from, int n)
{
	PNode Tree;
	int n1, n2;
	if (n == 0) return NULL;
	Tree = new Node;
	Tree->key = keys[from + n/2];
	Tree->name = names[from + n/2];
	numOfNodes++;
	n1 = n / 2;
	n2 = n - n1 - 1;
	Tree->left = MakeTreeByMassRecurtion(keys, names, from, n1);
	Tree->right = MakeTreeByMassRecurtion(keys, names, from + n1 + 1, n2);
	return Tree;
}

void Tree::DeleteTree()
{
	DeleteTreeRecurtion(head);
	numOfNodes = 0;
}

void Tree::DeleteTreeRecurtion(PNode current)
{
	if(current != NULL)
	{
		DeleteTreeRecurtion(current->left);
		DeleteTreeRecurtion(current->right);
		current->left = NULL;
		current->right = NULL;
		if(current == head) head = NULL;
		else delete current;
	}
}

void ExSolution::DeleteNodeBranch(int key)
{
	PNode current = head, oldcurrent = NULL;
    while(current != NULL && current->key != key)
	{
		oldcurrent = current;
		if(key < current->key) current = current->left;
		else current = current->right;
	}
	if(current == NULL)
	{
		Application->MessageBox(String("Ёлемент с таким ключом не существует").c_str(), String("ќшибка").c_str(), MB_OK);
	}
	else if(current->key == key)
	{
		if(current->left != NULL && current->right != NULL){
		 current->left = NULL;
		 current->right = NULL;
		}
		else if(current->right != NULL && current->left == NULL) current->right = NULL;
		else if(current->left != NULL && current->right == NULL) current->left = NULL;

		if(oldcurrent->right == current) oldcurrent->right = NULL;
		else oldcurrent->left = NULL;
	}
}

void Tree::DeleteNode(int key)
{
	PNode current = head, oldcurrent = NULL;
	while(current != NULL && current->key != key)
	{
		oldcurrent = current;
		if(key < current->key) current = current->left;
		else current = current->right;
	}
	if(current == NULL)
	{
		Application->MessageBox(String("Ёлемент с таким ключом не существует").c_str(), String("ќшибка").c_str(), MB_OK);
		numOfNodes++;
	}
	else if(current == head && current->left == NULL && current->right == NULL)
	{
		head = NULL;
	}
	else if(current == head && current->left != NULL && current->right == NULL)
	{
		head = current->left;
	}
	else if(current == head && current->left == NULL && current->right != NULL)
	{
		head = current->right;
	}
	else if(current->left == NULL && current->right == NULL)
	{
		if(oldcurrent->right == current) oldcurrent->right = NULL;
		else oldcurrent->left = NULL;
	}
	else if(current->left == NULL && current->right != NULL)
	{
		if(oldcurrent->right == current) oldcurrent->right = current->right;
		else oldcurrent->left = current->right;
	}
	else if(current->left != NULL && current->right == NULL)
	{
		if(oldcurrent->right == current) oldcurrent->right = current->left;
		else oldcurrent->left = current->left;
	}
	else
	{
		PNode newcurrent = current->left, newoldcurrent = current;
		while(newcurrent->right != NULL)
		{
			newoldcurrent = newcurrent;
			newcurrent = newcurrent->right;
		}
		if(newoldcurrent == current)
		{
        	newoldcurrent->left = newcurrent->left;
		}
		else
		{
			newoldcurrent->right = newcurrent->left;
		}
		current->key = newcurrent->key;
		current->name = newcurrent->name;
	}
	numOfNodes--;
}

AnsiString Tree::SearchByKey(int key)
{
	PNode current = head;
	while(current != NULL && current->key != key)
	{
		if(key < current->key) current = current->left;
		else current = current->right;
	}
	if(current == NULL)
	{
		Application->MessageBox(String("Ёлементa с таким ключом не существует").c_str(), String("ќшибка").c_str(), MB_OK);
		return "---";
	}
	else return current->name;
}

void Tree::ShowTree(TTreeView *TreeView)
{
	int index = 0;
	TreeView->Items->Clear();
	if(head != NULL)
	{
		TreeView->Items->Add(NULL, head->name);
		ShowTreeRecurtion(head, TreeView, index);
	}
}

void Tree::ShowTreeRecurtion(PNode current, TTreeView *TreeView, int &index)
{
	int thisindex = index;
	if(current->left != NULL)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[thisindex], current->left->name);
		index++;
		ShowTreeRecurtion(current->left, TreeView, index);
	}
	if(current->right != NULL)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[thisindex], current->right->name);
		index++;
		ShowTreeRecurtion(current->right, TreeView, index);
	}
}

void Tree::TraversalPreOrder(TListBox *ListBox)
{
	ListBox->Items->Clear();
	if(head != NULL)
		TraversalPreOrderRecurtion(head, ListBox);
}

void Tree::TraversalPreOrderRecurtion(PNode current, TListBox *ListBox)
{
	ListBox->Items->Add(AnsiString(current->key) + " " + current->name);
	if(current->left != NULL) TraversalPreOrderRecurtion(current->left, ListBox);
	if(current->right != NULL) TraversalPreOrderRecurtion(current->right, ListBox);
}

void Tree::TraversalPostOrder(TListBox *ListBox)
{
	ListBox->Items->Clear();
	if(head != NULL)
		TraversalPostOrderRecurtion(head, ListBox);
}

void Tree::TraversalPostOrderRecurtion(PNode current, TListBox *ListBox)
{
	if(current->left != NULL) TraversalPostOrderRecurtion(current->left, ListBox);
	if(current->right != NULL) TraversalPostOrderRecurtion(current->right, ListBox);
	ListBox->Items->Add(AnsiString(current->key) + " " + current->name);
}

void Tree::TraversalInOrder(TListBox *ListBox)
{
	ListBox->Items->Clear();
	BalanceTree();
	if(head != NULL)
		TraversalInOrderRecurtion(head, ListBox);
}

void Tree::TraversalInOrderRecurtion(PNode current, TListBox *ListBox)
{
	if(current->left != NULL) TraversalInOrderRecurtion(current->left, ListBox);
	ListBox->Items->Add(AnsiString(current->key) + " " + current->name);
	if(current->right != NULL) TraversalInOrderRecurtion(current->right, ListBox);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
