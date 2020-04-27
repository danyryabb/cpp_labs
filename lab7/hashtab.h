//---------------------------------------------------------------------------
#ifndef hashtabH
#define hashtabH
#include <string.h>
#include <vcl.h>
#define HASHTAB_SIZE 20
#define MAX_NEGATIVE -10
//---------------------------------------------------------------------------
struct listnode {
	AnsiString info;
	int key;
	listnode *next;
};
 listnode *hashtab[HASHTAB_SIZE];

class Hash
{
public:
   Hash();
   void hashtab_init(listnode **hashtab);
   int hashFunction(int key);
   void insertNode(struct listnode **hashtab, int key, AnsiString info);
   void deleteNode(struct listnode **hashtab, int key);
   listnode* Search(struct listnode **hashtab, int key);
};
class ExSolution : public Hash
{
public:
  void deleteNegative(struct listnode **hashtab);
};
#endif
