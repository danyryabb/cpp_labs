//---------------------------------------------------------------------------

#include <vcl.h>
#include <hashtab.h>

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
void __fastcall TForm1::ButtonSearchNodeClick(TObject *Sender)
{
    try
	{
		int thiskey = (EditKey->Text).ToInt();
		AnsiString str;
		if(hash.Search(hashtab, thiskey) != nullptr) str = hash.Search(hashtab, thiskey)->info;
		else
		{
		  Application->MessageBox(String("�������a � ����� ������ �� ����������").c_str(), String("������").c_str());
		  str = "------------";
		}
		LabelName->Caption =  str;
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("���� ������ ���� ������, � �� ����� �������, ��-��-�� ").c_str(), String("������").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddNewNodeClick(TObject *Sender)
{
	int thiskey = -10 + rand()%20;
	hash.insertNode(hashtab, thiskey, EditInfo->Text);
	int index = hash.hashFunction(thiskey);
	MemoGetALL->Lines->Add(hashtab[hash.hashFunction(thiskey)]->info + "\t" +
	hashtab[hash.hashFunction(thiskey)]->key + " index: " + index);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonCloseClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   srand(time(0));
   MemoGetALL->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonDeleteNodeClick(TObject *Sender)
{
	try
	{
		LabelName->Caption = "-------------";
		int thiskey = (EditKey->Text).ToInt();
		while(hash.Search(hashtab, thiskey) != nullptr)
		{
		   hash.deleteNode(hashtab, thiskey);
		}
		MemoGetALL->Lines->Clear();
		listnode * current;
		for(int i = 0; i < HASHTAB_SIZE; i++)
		{
		   if(hashtab[i] != nullptr)
		   {
			  for(current = hashtab[i]; current!=NULL;current=current->next)
			  {
				 MemoGetALL->Lines->Add(current->info + "\t" + current->key +
			  " index: " + i);
			  }
		   }
		}
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("���� ������ ���� ������, � �� ����� �������, ��-��-�� ").c_str(), String("������").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonDeleteNegativeClick(TObject *Sender)
{

   for(int key = -10; key < 0; key++)
   {
	  while(hash.Search(hashtab, key) != nullptr)
	  {
		hash.deleteNode(hashtab, key);
	  }
   }
   MemoGetALL->Lines->Clear();
   listnode * current;
   for(int i = 0; i < HASHTAB_SIZE; i++)
   {
	  if(hashtab[i] != nullptr)
	  {
		 for(current = hashtab[i]; current!=NULL;current=current->next)
		 {
			 MemoGetALL->Lines->Add(current->info + "\t" + current->key +
			 " index: " + i);
		 }
	  }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonFromArrayClick(TObject *Sender)
{
	hash.hashtab_init(hashtab);
	try
	{
		for(int i = 0; !(MemoKey->Lines->Strings[i]).IsEmpty() && !(MemoFIO->Lines->Strings[i]).IsEmpty(); i++)
		{
			int thiskey = (MemoKey->Lines->Strings[i]).ToInt();
			hash.insertNode(hashtab, thiskey, MemoFIO->Lines->Strings[i]);
		}
        MemoGetALL->Lines->Clear();
		listnode * current;
		for(int i = 0; i < HASHTAB_SIZE; i++)
		{
		   if(hashtab[i] != nullptr)
		   {
			  for(current = hashtab[i]; current!=NULL;current=current->next)
			  {
				 MemoGetALL->Lines->Add(current->info + "\t" + current->key +
				" index: " + i);
			  }
		   }
		}
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("���� ������ ���� ������, � �� ����� �������, ��-��-�� ").c_str(), String("������").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------
