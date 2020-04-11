//---------------------------------------------------------------------------
#pragma hdrstop
#include "queue.h"
//---------------------------------------------------------------------------
Queue::Queue()
{
	head = NULL;
}

void Queue::Push(int x)
{
	if(head != NULL)
	{
		element* NewElement = new element;
		NewElement->data= x;
		NewElement->prev = head->prev;
		NewElement->next = head;
		head->prev->next = NewElement;
		head->prev = NewElement;
		if(NewElement->data > max->data) max = NewElement;
		if(NewElement->data < min->data) min = NewElement;
	}
	else
	{
		element* NewElement = new element;
		head = NewElement;
		head->next = head;
		head->prev = head;
		head->data = x;
		max = head;
		min = head;
	}
}

int Queue::Pop()
{
	int result = head->data;
	if(head == head->next)
	{
		head = NULL;
	}
	else
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
	}
	return result;
}

int Queue::ShowFirst()
{
	return head->data;
}

bool Queue::IsEmpty()
{
	if(head == NULL) return true;
	else return false;
}

element* Queue::GetMax()
{
	return max;
}

element* Queue::GetMin()
{
	return min;
}

void Queue::SetHead(element* newhead)
{
	head = newhead;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
