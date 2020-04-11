//---------------------------------------------------------------------------

#ifndef TrainH
#define TrainH
#include <vcl.h>
//---------------------------------------------------------------------------
//using namespace std;
class train
{
public:
	int day;
	int month;
	int year;
	int hours;
	int minutes;
	AnsiString placename;
	int freeplaces;
	int id;

	train(){}
	train(int mday, int mmonth, int myear, AnsiString mplacename, int mhours, int mminutes, int mfreeplaces);
	AnsiString ShowTrain();
};

 struct List
 {
	train Train;
	List *NextTrain;
 };
 List *HandTrain, *LastTrain;
#endif
