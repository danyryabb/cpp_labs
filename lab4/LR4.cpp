#pragma hdrstop
#include "string.h"
#include "stdlib.h"
#include "LR4.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void Stack::Stack_init()
{
  t1=0;
  t2=0;
  s=new char[100];
  sv=new char[100];
  err_code=all_true;
}
//-------------------------------------------------------------------------
Stack::~Stack()
{
  delete[] s;
  delete[] sv;
}
//---------------------------------------------------------------------------
void Stack::first1(char c)
{
  Node_op* pv=new Node_op;
  pv->c=c;
  pv->p=0;
  t1=pv;
}
//---------------------------------------------------------------------------
void Stack::push1(char c)
{
  Node_op* pv=new Node_op;
  pv->c=c;
  pv->p=t1;
  t1=pv;
}
//--------------------------------------------------------------------------
char Stack::pop1()
{
  char z=t1->c;
  Node_op* pv=t1;
  t1=t1->p;
  delete pv;
  return z;
}
//--------------------------------------------------------------------------
void Stack::first2(float c)
{
  Node_num* pv=new Node_num;
  pv->c=c;
  pv->p=0;
  t2=pv;
}
//---------------------------------------------------------------------------
void Stack::push2(float c)
{
  Node_num* pv=new Node_num;
  pv->c=c;
  pv->p=t2;
  t2=pv;
}
//--------------------------------------------------------------------------
float Stack::pop2()
{
  float z=t2->c;
  Node_num* pv=t2;
  t2=t2->p;
  delete pv;
  return z;
}
//--------------------------------------------------------------------------
bool Stack:: operand_true(char c)
{
  if((c>='0'&&c<='9') || (c>='A' && c<='Z') || (c>='a'&&c<='z') || c=='.') return true;
  else return false;
}
//---------------------------------------------------------------------------
int Stack::prioritet_stack()
{
  if(t1->c=='(')return 3;
  if(t1->c=='+'||t1->c=='-')return 1;
  return 2;
}
//---------------------------------------------------------------------------
void Stack::check()
{
 int sk=0;
 int rang=0;
 int l=strlen(s);
 int i;
 if(s[0]==')') {err_code=much_brackets; return;}
 if(s[0]=='*'||s[0]=='/') {err_code=few_operands; return;}
 for(i = 0; i<l; i++)
 {
   if(s[i]=='(')
   {
   if(i>0&&operand_true(s[i-1]))  {err_code=few_operators; return;}
   if(s[i+1]=='*'||s[i+1]=='/'||s[i+1]==')')  {err_code=few_operands; return;}
   sk++; continue;
   }
   if(s[i]==')')
   {
	if((i>0)&&(s[i-1]=='*'||s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='/')) {err_code=few_operands; return;}
	if(operand_true(s[i+1])||s[i+1]=='(') {err_code=few_operators; return;}
	sk--; continue;
   }
   if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-') {rang++; continue;}
   if(operand_true(s[i]))
   {
	 while (operand_true(s[++i]));
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
  if(rang>-1) {err_code=few_operands; return;}
  if(rang<-1) {err_code=few_operators; return;}
  if(sk>0) {err_code=few_brackets; return;}
  if(sk<0) {err_code=much_brackets; return;}
}
//--------------------------------------------------------------------------
void Stack::bspaces()
{
  int l=strlen(s);
  int i,j=0;
  for(i = 0;i<l;i++)
  {
	if((s[i]>='(' && s[i]<='+') || s[i]=='-' || s[i]=='/') { sv[j++]=s[i]; sv[j++]=' '; continue;}
	else
	{
	  sv[j++]=s[i];
	  while(operand_true(s[++i])==1&&s[i]!='\0')
	  sv[j++]=s[i];
	  sv[j++]=' ';
	}
	i--;
  }
  sv[j]='\0';
}
//--------------------------------------------------------------------------
void Stack::postfix()
{
int i,j=0,pr=0;
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
		   if(!t1) {first1(s[i]);}
		   else {push1(s[i]);}
		   break;
		 }
		 case '*':
		 case '/':
		 {
		   if(!t1) {first1(s[i]); break;}
		   pr=prioritet_stack();
		   if(pr==3||pr==1) {push1(s[i]); break;}
		   if(t1->c=='/') sv[j++]=pop1();
		   if(t1) {push1(s[i]); break;}
		   else {first1(s[i]); break;}
		 }
		 case '+':
		 case '-':
		 {
		   if(!t1) {first1(s[i]); break;}
		   pr=prioritet_stack();
		   if(pr==3) {push1(s[i]); break;}
		   else
		   {
			 while(pr<3&&t1)
			 {
			   sv[j++]=pop1();
			   if(t1) pr=prioritet_stack();
			 }
		   }
		  if(t1) {push1(s[i]); break;}
		  else {first1(s[i]); break;}
		 }
		 case ')':
		 {
		   pr=prioritet_stack();
		   while(pr!=3)
		   {
			 sv[j++]=pop1();
			 pr=prioritet_stack();
		   }
		   sv[j]= pop1();
		 }
	  }
	}
	else {sv[j++]=s[i]; continue;}
  }
  if(t1){ while(t1) sv[j++]=pop1();}
  sv[j]='\0';
  strcpy(s,sv);
}
//-------------------------------------------------------------------------
float Stack::calc()
{
  int i,j=0,l=strlen(s);
  char sc[10];
  float a,b;
  for(i=0; i < l ;i++)
  {
	if(s[i]==' ') continue;
	else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
	{
	  a=pop2();
	  b=pop2();
	  switch(s[i])
	  {
	   case '+': {a=a+b; break;}
	   case '-': {a=b-a; break;}
	   case '*': {a=a*b; break;}
	   case '/': {a=b/a; break;}
	  }
	  if(!t2) first2(a);
	  else push2(a);
	}
	else
	{
	   while(operand_true(s[i])&&s[i]!='\0')
	   {
		 sc[j++]=s[i];
		 i++;
	   }
	  sc[j]='\0';
	  a=atof(sc);
	  j=0;
	  if(!t2) {first2(a);}
	  else {push2(a); }
	}
  }
  return pop2();
}
