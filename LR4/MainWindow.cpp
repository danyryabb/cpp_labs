#include <vcl.h>
#pragma hdrstop
#include "MainWindow.h"
#include "Stack.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Stack MyStack;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonToSolveClick(TObject *Sender)
{
  MyStack.InitializeStack();
  AnsiString ed_txt = EditForEx->Text;
  MyStack.s = ed_txt.c_str();
  MyStack.Check();
  if(MyStack.err_code == all_true)
  {
	  MyStack.PlacingSpaces();
	  MyStack.s = MyStack.sv;
	  MyStack.MakePostfix();
	  EditForTranslated->Text=MyStack.s;
  }
  MyStack.s = ed_txt.c_str();
  if(MyStack.err_code == all_true)
  {
	  MyStack.PlacingSpaces();
	  MyStack.s = MyStack.sv;
	  MyStack.MakePostfix();
	  EditForTranslated->Text=MyStack.s;
	  float result=MyStack.CalculateExample(StrToFloat(EditForA->Text), StrToFloat(EditForB->Text),
	  StrToFloat(EditForC->Text), StrToFloat(EditForD->Text), StrToFloat(EditForE->Text));
	  EditForAnswer->Text=FloatToStr(result);
  }
  else MyStack.FindErrCode();
}
//---------------------------------------------------------------------------

void Stack::FindErrCode()
{
   switch(err_code)
   {
		case all_true: {ShowMessage("Correct input."); break;}
		case bad_operands: {ShowMessage("Incorrect operand!"); break;}
		case few_brackets: {ShowMessage("Not enough ( or )!"); break;}
		case much_brackets: {ShowMessage("A lot of ( or )!"); break;}
		case few_operands: {ShowMessage("Not enough operands!"); break;}
		case few_operators: {ShowMessage("Not enough operations signs!"); break;}
   };
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   EditForEx->Text="";
   EditForAnswer->Text="";
   EditForTranslated->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClearClick(TObject *Sender)
{
   EditForEx->Text="";
   EditForAnswer->Text="";
   EditForTranslated->Text="";
   EditForA->Text="";
   EditForB->Text="";
   EditForC->Text="";
   EditForD->Text="";
   EditForE->Text="";
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

