//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <hashtab.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *MemoGetALL;
	TEdit *EditKey;
	TLabel *Label3;
	TLabel *Label4;
	TButton *ButtonAddNewNode;
	TButton *ButtonSearchNode;
	TButton *ButtonDeleteNode;
	TButton *ButtonDeleteNegative;
	TLabel *LabelGetALL;
	TButton *ButtonClose;
	TLabel *Label1;
	TLabel *LabelName;
	TLabel *Label2;
	TMemo *MemoKey;
	TButton *ButtonFromArray;
	TMemo *MemoArrNames;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TMemo *MemoForNames;
	void __fastcall ButtonSearchNodeClick(TObject *Sender);
	void __fastcall ButtonAddNewNodeClick(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonDeleteNodeClick(TObject *Sender);
	void __fastcall ButtonDeleteNegativeClick(TObject *Sender);
	void __fastcall ButtonFromArrayClick(TObject *Sender);
private:	// User declarations
     ExSolution hash;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
