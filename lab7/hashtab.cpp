//---------------------------------------------------------------------------

#pragma hdrstop
#include "hashtab.h"
//---------------------------------------------------------------------------

Hash::Hash()
{
   hashtab_init(hashtab);
}
//---------------------------------------------------------------------------
void Hash :: hashtab_init(listnode **hashtab)
{
   for (int i = 0; i < HASHTAB_SIZE; i++) {
	  hashtab[i] = NULL;
   }
}
//---------------------------------------------------------------------------
int Hash :: hashFunction(int key)
{
   if(key > 0) return key % HASHTAB_SIZE;
   else return abs(key % HASHTAB_SIZE);
}
//------------------------------------------------------------------------------
void Hash :: insertNode(listnode **hashtab, int key, AnsiString info)  // функция поиска местоположения и вставки вершины в таблицу
 {
	// вставка вершины в начало списка
	int index = hashFunction(key);
	listnode *current = new listnode();
	if(current != NULL)
	{
	  current->key = key;
	  current->info = info;
	  current->next = hashtab[index];
	  hashtab[index] = current;
	}
}
//------------------------------------------------------------------------------
void Hash :: deleteNode(listnode **hashtab, int key) // функция удаления записи по ключу
{
	listnode *oldcurrent, *current;
	oldcurrent = NULL;
	int index = hashFunction(key);
	for (current = hashtab[index]; current != NULL; current = current->next)
	{
		 if (current->key == key)
		 {
			if (oldcurrent == NULL) hashtab[index] = current->next;
			else oldcurrent->next = current->next;
			current = NULL;
			return;
		 }
		 oldcurrent = current;
	}
}
//------------------------------------------------------------------------------
listnode* Hash :: Search(listnode **hashtab, int key) // функция поиска вершины со значением key
{
	listnode *current;
	current = hashtab[hashFunction(key)];
	while (current)
	{
	  if(current->key == key) return current;
	  current = current->next;
	}
	if(current == NULL) return NULL;
}

void ExSolution :: deleteNegative(listnode **hashtab)
{
   	listnode* current;
	for(int i = 0; i < HASHTAB_SIZE; i++)
	{
	   if(hashtab[i] != nullptr)
	   {
		  for(current = hashtab[i]; current!=NULL;current=current->next)
		  {
			 if(current->key < 0)
			 {
			   deleteNode(hashtab, current->key);
			 }
		  }
	   }
	}
}
//------------------------------------------------------------------------------
#pragma package(smart_init)

