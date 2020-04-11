//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonRandom;
	TLabel *Label2;
	TLabel *Label3;
	TButton *ButtonClose;
	TEdit *EditMAX;
	TEdit *EditMIN;
	TListBox *ListBoxFirst;
	TListBox *ListBoxSecond;
	void __fastcall ButtonRandomClick(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	void ShowOnListBox();
	void InTwoCircle(Queue &InputQueue);
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
