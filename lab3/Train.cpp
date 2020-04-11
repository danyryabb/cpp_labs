//---------------------------------------------------------------------------

#pragma hdrstop
#include <time.h>
#include <vcl.h>
#include "Train.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

train::train(int mday, int mmonth, int myear, AnsiString mplacename, int mhours, int mminutes, int mfreeplaces)
{
	day=mday;
	month=mmonth;
	year=myear;
	placename = mplacename;
	//strcpy(placename, mplacename.c_str());
	hours=mhours;
	minutes=mminutes;
	freeplaces = mfreeplaces;
}
AnsiString train::ShowTrain()
{
	return "В пункт " + AnsiString(placename) + " свободных мест " + AnsiString(freeplaces) + " № поезда " + AnsiString(id + 1);
}

