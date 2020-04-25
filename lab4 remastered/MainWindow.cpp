#include <vcl.h>
#pragma hdrstop
#include "MainWindow.h"
#include "LR4.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString S1="� ��������� ���� �������� ��������! ��������� ������������ ������.";
AnsiString S2="� ��������� �� ������� ������! ��������� ������������ ������.";
AnsiString S3="� ��������� ������ ������! ��������� ������������ ������.";
AnsiString S4="� ��������� ������������ ���������! ��������� ������������ ������.";
AnsiString S5="� ��������� ������������ ������ ��������! ��������� ������������ ������.";
AnsiString S6="���� ���������.";

Stack S;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void Stack::out_err_code()
{
   switch(err_code)
   {
	case all_true: {ShowMessage(S6); break;}
	case bad_operands: {ShowMessage(S1); break;}
	case few_brackets: {ShowMessage(S2); break;}
	case much_brackets: {ShowMessage(S3); break;}
	case few_operands: {ShowMessage(S4); break;}
	case few_operators: {ShowMessage(S5); break;}
   };
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   EditForEx->Text="";
   EditAnswer->Text="";
   EditTranslated->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonToSolveClick(TObject *Sender)
{
  S.Stack_init();
  AnsiString field = EditForEx->Text;
  S.s = field.c_str();
  S.check();
  if(S.err_code==all_true)
  {
	S.bspaces();
	S.s=S.sv;
	S.postfix();
	EditTranslated->Text=S.s;
	float result=S.calc();
	EditAnswer->Text=FloatToStr(result);
  }
  else
  S.out_err_code();
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
   EditAnswer->Text="";
   EditTranslated->Text="";
}
//---------------------------------------------------------------------------

