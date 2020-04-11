//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonTreeFromArrayClick(TObject *Sender)
{
	ThisTree.DeleteTree();
	try
	{
		for(int i = 0; !(MemoKey->Lines->Strings[i]).IsEmpty() && !(MemoFIO->Lines->Strings[i]).IsEmpty(); i++)
		{
			int thiskey = (MemoKey->Lines->Strings[i]).ToInt();
			ThisTree.AddNode(thiskey, MemoFIO->Lines->Strings[i]);
		}
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String(" люч должен быть числом, а вы ввели символы, ай-€й-€й ").c_str(), String("ќшибка").c_str(), MB_OK);
	}
	ThisTree.ShowTree(TreeView);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAddNewNodeClick(TObject *Sender)
{
	try
	{
		int thiskey = (EditNewNodeKey->Text).ToInt();
		ThisTree.AddNode(thiskey, EditNewNodeFIO->Text);
		ThisTree.ShowTree(TreeView);
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String(" люч должен быть числом, а вы ввели символы, ай-€й-чй ").c_str(), String("ќшибка").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonBalanceClick(TObject *Sender)
{
	ThisTree.BalanceTree();
	ThisTree.ShowTree(TreeView);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	try
	{
		int thiskey = (EditKey->Text).ToInt();
		ThisTree.DeleteNode(thiskey);
		ThisTree.ShowTree(TreeView);
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String(" люч должен быть числом, а вы ввели символы, ай-€й-чй ").c_str(), String("ќшибка").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSearchClick(TObject *Sender)
{
	try
	{
		int thiskey = (EditKey->Text).ToInt();
		LabelFIO->Caption = ThisTree.SearchByKey(thiskey);
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String(" люч должен быть числом, а вы ввели символы, ай-€й-чй ").c_str(), String("ќшибка").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonExitClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonWritePreOrderClick(TObject *Sender)
{
	ThisTree.TraversalPreOrder(ListBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonWritePostOrderClick(TObject *Sender)
{
	ThisTree.TraversalPostOrder(ListBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonWriteInOrderClick(TObject *Sender)
{
	ThisTree.TraversalInOrder(ListBox);
	ThisTree.ShowTree(TreeView);
}
void __fastcall TForm1::ButtonDeleteBranchClick(TObject *Sender)
{

   try
	{
		int thiskey = (EditKey->Text).ToInt();
		ThisTree.DeleteNodeBranch(thiskey);
		ThisTree.ShowTree(TreeView);
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String(" люч должен быть числом, а вы ввели символы, ай-€й-чй ").c_str(), String("ќшибка").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

