//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Train.cpp"
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TLabel *Label1;
	TEdit *EditDay;
	TEdit *EditPlace;
	TEdit *EditHours;
	TEdit *EditFreePlaces;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TButton *ButtonAddOK;
	TButton *ButtonClose;
	TButton *ButtonShowAllOK;
	TLabel *Label6;
	TEdit *EditNeededPlace;
	TEdit *EditNeededHour;
	TLabel *Label7;
	TLabel *Label8;
	TButton *ButtonShowNeeded;
	TButton *ButtonSaveDialog;
	TButton *ButtonOpenDialog;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TEdit *EditMonth;
	TEdit *EditYear;
	TEdit *EditMinutes;
	TEdit *EditNeededMinutes;
	TButton *ButtonOrderingTrain;
	TEdit *EditSearchDay;
	TEdit *EditSearchMonth;
	TEdit *EditSearchYear;
	TLabel *Label9;
	TLabel *Label10;
	void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall ButtonAddOKClick(TObject *Sender);
	void __fastcall ButtonShowAllOKClick(TObject *Sender);
	void __fastcall ButtonShowNeededClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonSaveDialogClick(TObject *Sender);
	void __fastcall ButtonOpenDialogClick(TObject *Sender);
	void __fastcall ButtonOrderingTrainClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
   
	int numOfTrain;
	int newid;
	__fastcall TForm1(TComponent* Owner);
	void RefreshListBox();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
