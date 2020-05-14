//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
	TEdit *EditForEx;
	TButton *ButtonToSolve;
	TEdit *EditForTranslated;
	TButton *ButtonClear;
	TButton *ButtonExit;
	TEdit *EditForAnswer;
	TLabel *LabelForTranslated;
	TLabel *LabelForExercise;
	TEdit *EditForA;
	TLabel *LabelForA;
	TEdit *EditForB;
	TLabel *LabelForB;
	TEdit *EditForC;
	TLabel *LabelForC;
	TEdit *EditForD;
	TLabel *LabelForD;
	TEdit *EditForE;
	TLabel *LabelForE;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonToSolveClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);


private:
public:
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
