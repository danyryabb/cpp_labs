//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Tree.h>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *LabelFIO;
	TLabel *Label5;
	TMemo *MemoKey;
	TButton *ButtonTreeFromArray;
	TMemo *MemoFIO;
	TEdit *EditNewNodeKey;
	TEdit *EditNewNodeFIO;
	TButton *ButtonAddNewNode;
	TEdit *EditKey;
	TButton *ButtonSearch;
	TButton *ButtonDelete;
	TLabel *Label6;
	TButton *ButtonBalance;
	TButton *ButtonExit;
	TTreeView *TreeView;
	TListBox *ListBox;
	TButton *ButtonWritePostOrder;
	TButton *ButtonWritePreOrder;
	TButton *ButtonWriteInOrder;
	TButton *ButtonDeleteBranch;

    void __fastcall ButtonTreeFromArrayClick(TObject *Sender);
	void __fastcall ButtonAddNewNodeClick(TObject *Sender);
	void __fastcall ButtonBalanceClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall ButtonWritePreOrderClick(TObject *Sender);
	void __fastcall ButtonWritePostOrderClick(TObject *Sender);
	void __fastcall ButtonWriteInOrderClick(TObject *Sender);
	void __fastcall ButtonDeleteBranchClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
      Tree ThisTree;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
