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
	numOfTrain = 0;
	newid = 0;
}
//---------------------------------------------------------------------------
bool checkfields(int day, int month, int year, int freep, int hours, int minutes)
{
	bool fl = false;
	if((day < 31 && day > 0) && (month > 0 && month < 13)
	&& year >= 2020 && freep > 0 && (hours >= 0 && hours < 24)
	&& (minutes >= 0 && minutes < 60)) fl = true;
	return fl;
}
bool checksecfields(int day, int month, int year, int hours, int minutes)
{
	bool fl = false;
	if((day < 31 && day > 0) && (month > 0 && month < 13)
	&& year >= 2020 && (hours >= 0 && hours < 24)
	&& (minutes >= 0 && minutes < 60)) fl = true;
	return fl;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonCloseClick(TObject *Sender)
{
   Close();
}

//---------------------------------------------------------------------------
 void TForm1::RefreshListBox()
{
	ListBox1->Items->Clear();
	List *current;
	current = HandTrain;
	while(current != NULL)
	{
		ListBox1->Items->Add(current->Train.ShowTrain());
		current = current->NextTrain;
	}
	delete current;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAddOKClick(TObject *Sender)
{
	if(checkfields(EditDay->Text.ToInt(),EditMonth->Text.ToInt(), EditYear->Text.ToInt(),
	EditFreePlaces->Text.ToInt(),EditHours->Text.ToInt(),EditMinutes->Text.ToInt()))
	{
	   train ThisTrain(EditDay->Text.ToInt(), EditMonth->Text.ToInt(), EditYear->Text.ToInt(), EditPlace->Text, EditHours->Text.ToInt(),EditMinutes->Text.ToInt(), EditFreePlaces->Text.ToInt());
	   ThisTrain.id = newid;
	   newid++;
	   if(numOfTrain == 0)
	   {
			LastTrain = new List;
			HandTrain = LastTrain;
	   }
	   else
	   {
			LastTrain->NextTrain = new List;
			LastTrain = LastTrain->NextTrain;
	   }
	   LastTrain->Train = ThisTrain ;
	   LastTrain->NextTrain = NULL;
	   numOfTrain++;

	   EditPlace->Text = "";
	   EditDay->Text = "";
	   EditMonth->Text = "";
	   EditYear->Text = "";
	   EditHours->Text = "";
	   EditMinutes->Text = "";
	   EditFreePlaces->Text = "";
	}
	else
	{
		Application->MessageBox(String("Вы ввели ошибочное число").w_str(), String("Ошибка").w_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonShowAllOKClick(TObject *Sender)
{
   RefreshListBox();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonShowNeededClick(TObject *Sender)
{
	if(checksecfields(EditSearchDay->Text.ToInt(),EditSearchMonth->Text.ToInt(), EditSearchYear->Text.ToInt(),
	EditNeededHour->Text.ToInt(),EditNeededMinutes->Text.ToInt()))
	{
	  AnsiString thisplacename = EditNeededPlace->Text;
	  int thishours = EditNeededHour->Text.ToInt();
	  int thisminutes = EditNeededMinutes->Text.ToInt();
	  int thisday = EditSearchDay->Text.ToInt();
	  int thismonth = EditSearchMonth->Text.ToInt();
	  int thisyear = EditSearchYear->Text.ToInt();

	  ListBox1->Items->Clear();
	  List *temp = HandTrain;
	  int total = thishours*100 + thisminutes;
	  int total_l = temp->Train.hours*100+ temp->Train.minutes;
	  while(temp != NULL)
	  {
		 if(temp->Train.placename == thisplacename && temp->Train.day == thisday
		 && temp->Train.month == thismonth && temp->Train.year == thisyear && total_l <= total)
		 {
			ListBox1->Items->Add(temp->Train.ShowTrain());
		 }
		 temp = temp->NextTrain;
	  }
	  delete temp;
	}
	else
	{
		Application->MessageBox(String("Вы ввели ошибочное число").w_str(), String("Ошибка").w_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSaveDialogClick(TObject *Sender)
{
    if(SaveDialog1->Execute())
	{
        List* current = HandTrain;
		TFileStream* fs=new TFileStream(SaveDialog1->FileName.c_str(), fmCreate);
		fs->Write(&numOfTrain, sizeof(numOfTrain));
		for(int i = 0; i < numOfTrain; i++)
		{
			fs->Write(&(current->Train), sizeof(train));
			current = current->NextTrain;
		}
		delete current;
		delete fs;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOpenDialogClick(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		train ThisTrain;
		TFileStream* fs=new TFileStream(OpenDialog1->FileName.c_str(), fmOpenRead);
		fs->Read(&numOfTrain, sizeof(numOfTrain));
		HandTrain = NULL;
		for(int i = 0; i < numOfTrain; i++)
		{
			fs->Read(&ThisTrain, sizeof(train));
			if(i == 0)
			{
				LastTrain = new List;
				HandTrain = LastTrain;
			}
			else
			{
				LastTrain->NextTrain = new List;
				LastTrain = LastTrain->NextTrain;
			}
			LastTrain->Train = ThisTrain ;
			LastTrain->NextTrain = NULL;
		}
		delete fs;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOrderingTrainClick(TObject *Sender)
{
	AnsiString thisstring = AnsiString(ListBox1->Items->Strings[ListBox1->ItemIndex]);;
	List *current = HandTrain;
	while(current != NULL)
	{
		if(thisstring == current->Train.ShowTrain())
		{
		   if(current->Train.freeplaces > 0) current->Train.freeplaces--;
		   else
		   {
			 Application->MessageBox(String("Свободных мест нет").w_str(), String("Ошибка").w_str(), MB_OK);
		   }
		}
		current = current->NextTrain;
	}
	delete current;
	RefreshListBox();
	EditNeededPlace->Text = "";
	EditSearchDay->Text = "";
	EditSearchMonth->Text = "";
	EditSearchYear->Text = "";
	EditNeededHour->Text = "";
	EditNeededMinutes->Text = "";
}
//---------------------------------------------------------------------------

