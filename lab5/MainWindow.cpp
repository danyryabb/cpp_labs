//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "queue.cpp"
#include "MainWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
  srand(time(0));
}
//---------------------------------------------------------------------------
void TForm1::InTwoCircle(Queue &InputQueue)
{
	Queue FirstQueue;
	Queue SecondQueue;
	element* max = InputQueue.GetMax();
	element* min = InputQueue.GetMin();
	EditMIN->Text = AnsiString(min->data);
	EditMAX->Text = AnsiString(max->data);
	InputQueue.SetHead(max->next);
	while(InputQueue.ShowFirst() != min->data)
	{
		FirstQueue.Push(InputQueue.Pop());
	}
	while(!InputQueue.IsEmpty())
	{
		ListBoxSecond->Items->Add(AnsiString(InputQueue.ShowFirst()));
		SecondQueue.Push(InputQueue.Pop());
	}
}
void __fastcall TForm1::ButtonRandomClick(TObject *Sender)
{

	ListBoxFirst->Clear();
	ListBoxSecond->Clear();
	Queue InputQueue;
	int temp;
	for(int i = 0; i < 40; i++)
	{
		temp = rand()%100;
		InputQueue.Push(temp);
		ListBoxFirst->Items->Add(AnsiString(temp));
	}
	InTwoCircle(InputQueue);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonCloseClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
