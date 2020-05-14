#pragma hdrstop
#include "string.h"
#include "stdlib.h"
#include "Stack.h"
#pragma package(smart_init)


//--------------------------------------------------------------------------
void Stack::MakePostfix()
{
int i;
int j=0;
int pr=0;
int l=strlen(s);
  for(i=0;i<l;i++)
  {
	if(s[i]==' ') {sv[j++]=s[i]; continue;}
	if((s[i]>='('&&s[i]<='+')||s[i]=='-'||s[i]=='/')
	{
	  switch(s[i])
	  {
		 case '(':
		 {
		   if(!t1) {OperationsStackCreate(s[i]);}
		   else {PushToOperationStack(s[i]);}
		   break;
		 }
		 case '*':
		 case '/':
		 {
		   if(!t1) {OperationsStackCreate(s[i]); break;}
		   pr=PriotitetStack();
		   if(pr==3||pr==1) {PushToOperationStack(s[i]); break;}
		   if(t1->c=='/') sv[j++]=PopFromOperationStack();
		   if(t1) {PushToOperationStack(s[i]); break;}
		   else {OperationsStackCreate(s[i]); break;}
		 }
		 case '+':
		 case '-':
		 {
		   if(!t1) {OperationsStackCreate(s[i]); break;}
		   pr=PriotitetStack();
		   if(pr==3) {PushToOperationStack(s[i]); break;}
		   else
		   {
			 while(pr<3&&t1)
			 {
			   sv[j++]=PopFromOperationStack();
			   if(t1) pr=PriotitetStack();
			 }
		   }
		  if(t1) {PushToOperationStack(s[i]); break;}
		  else {OperationsStackCreate(s[i]); break;}
		 }
		 case ')':
		 {
		   pr=PriotitetStack();
		   while(pr!=3)
		   {
			 sv[j++]=PopFromOperationStack();
			 pr=PriotitetStack();
		   }
		   sv[j]= PopFromOperationStack();
		 }
	  }
	}
	else {sv[j++]=s[i]; continue;}
  }
  if(t1){ while(t1) sv[j++]=PopFromOperationStack();}
  sv[j]='\0';
  strcpy(s,sv);
}

//-------------------------------------------------------------------------
float Stack::CalculateExample(float A, float B, float C, float D, float E)
{
int i,j=0,l=strlen(s);
char sc[10];
float a,b;
  for(i=0;i<l;i++)
  {
	if(s[i]==' ') continue;
	else
	if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
	{
		  a=PopFromNumStack();
		  b=PopFromNumStack();
		  switch(s[i])
		  {
			   case '+': {a=a+b; break;}
			   case '-': {a=b-a; break;}
			   case '*': {a=a*b; break;}
			   case '/': {a=b/a; break;}
		  }
		  if(!t2) {NumStackCreate(a); }
		  else {PushToNumStack(a); }
	}
	else
	{
	   while(CheckForTrueOperand(s[i])&&s[i]!='\0')
	   {
		 if (s[i] == 'a' || s[i] == 'A') a = A; else
		 if (s[i] == 'b' || s[i] == 'B') a = B; else
		 if (s[i] == 'c' || s[i] == 'C') a = C; else
		 if (s[i] == 'd' || s[i] == 'D') a = D; else
		 if (s[i] == 'e' || s[i] == 'E') a = E;
		 i++;
	   }

	  j=0;
	  if(!t2) { NumStackCreate(a); }
	  else { PushToNumStack(a); }
	}
  }
  return PopFromNumStack();
}
//---------------------------------------------------------------------------
void Stack::InitializeStack()
{
  t1=0; t2=0;
  s=new char[100]; sv=new char[100];
  err_code = all_true;
}
//-------------------------------------------------------------------------
Stack::~Stack()
{
  delete[] s; delete[] sv;
}
//---------------------------------------------------------------------------
void Stack::OperationsStackCreate(char c)
{
  NodeOperations* pv = new NodeOperations;
  pv->c=c; pv->p=0; t1=pv;
}
//---------------------------------------------------------------------------
void Stack::PushToOperationStack(char c)
{
  NodeOperations* pv=new NodeOperations;
  pv->c=c;
  pv->p=t1;
  t1=pv;
}
//--------------------------------------------------------------------------
char Stack::PopFromOperationStack()
{
  char z=t1->c;
  NodeOperations* pv=t1;
  t1=t1->p;
  delete pv;
  return z;
}
//--------------------------------------------------------------------------
void Stack::NumStackCreate(float c)
{
  NodeNumerals* pv = new NodeNumerals;
  pv->c=c; pv->p=0; t2=pv;
}
//---------------------------------------------------------------------------
void Stack::PushToNumStack(float c)
{
  NodeNumerals* pv = new NodeNumerals;
  pv->c=c; pv->p=t2; t2=pv;
}
//--------------------------------------------------------------------------
float Stack::PopFromNumStack()
{
  float z = t2->c;
  NodeNumerals* pv=t2;
  t2=t2->p;
  delete pv;
  return z;
}
//--------------------------------------------------------------------------
bool Stack::CheckForTrueOperand(char c)
{
  if((c>='0'&&c<='9') || (c>='A' && c<='Z') || (c>='a'&&c<='z') || c=='.') return true;
  else return false;
}
//---------------------------------------------------------------------------
int Stack::PriotitetStack()
{
  if(t1->c == '(')return 3;
  if(t1->c == '+'||t1->c=='-')return 1;
  return 2;
}
//---------------------------------------------------------------------------
void Stack::Check()
{
 int sk=0, rang=0, i;
 int l=strlen(s);
 if(s[0] == ')') {err_code = much_brackets; return;}
 if(s[0] == '*'||s[0]=='/') {err_code = few_operands; return;}
 for(i = 0; i<l; i++)
 {
   if(s[i]=='(')
   {
	   if(i > 0 && CheckForTrueOperand(s[i-1]))  {err_code = few_operators; return;}
	   if(s[i+1] == '*' || s[i+1] == '/' || s[i+1] == ')')  {err_code = few_operands; return;}
	   sk++;
	   continue;
   }
   if(s[i] == ')')
   {
		if((i > 0) && (s[i-1] == '*' || s[i-1] == '+' || s[i-1] == '-' || s[i-1] == '/')) {err_code = few_operands; return;}
		if(CheckForTrueOperand(s[i+1])||s[i+1]=='(') {err_code=few_operators; return;}
		sk--;
		continue;
   }
   if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-') {rang++; continue;}
   if(CheckForTrueOperand(s[i]))
   {
	 while (CheckForTrueOperand(s[++i]));
	 i--;
	 rang--;
   }
   else
   {
	err_code=bad_operands;
	return;
   }
 }
  s[i]='\0';
  if(rang>-1) {err_code = few_operands; return;}
  if(rang<-1) {err_code = few_operators; return;}
  if(sk>0) {err_code = few_brackets; return;}
  if(sk<0) {err_code = much_brackets; return;}
}
//--------------------------------------------------------------------------
void Stack::PlacingSpaces()
{
  int l=strlen(s);
  int i,j=0;
  for(i = 0;i<l;i++)
  {
	if((s[i]>='(' && s[i]<='+') || s[i]=='-' || s[i]=='/')
	{
	  sv[j++]=s[i];
	  sv[j++]=' ';
	  continue;
	}
	else
	{
	  sv[j++]=s[i];
	  while(CheckForTrueOperand(s[++i])==1&&s[i]!='\0')
	  sv[j++]=s[i];
	  sv[j++]=' ';
	}
	i--;
  }
  sv[j]='\0';
}


