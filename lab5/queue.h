//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef queueH
#define queueH
//---------------------------------------------------------------------------
struct element
{
	element* next;
	element* prev;
	int data;
};

class Queue
{
	public:
		element* head;
		element* max;
		element* min;
		Queue();
		void Push(int x);
		int Pop();
		int ShowFirst();
		bool IsEmpty();
		element* GetMax();
		element* GetMin();
		void SetHead(element* newhead);
};
#endif
