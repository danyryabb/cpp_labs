//---------------------------------------------------------------------------

#ifndef LR4H
#define LR4H
//---------------------------------------------------------------------------
struct Node_operations
{
  char c;
  Node_operations* p;
};


struct Node_numerals
{
  float c;
  Node_numerals* p;
};

typedef enum
{
  all_true=1,
  bad_operands,
  few_brackets,
  much_brackets,
  few_operands,
  few_operators
}errors;

class Stack
{
public:
  char* s;
  char* sv;
  Node_operations* t1;
  Node_numerals* t2;
  void Stack_init();
  void check();
  void bspaces();
  void postfix();
  float calc(); //���������� ��������� � ����������� ������
  void out_err_code();
  errors err_code;
  ~Stack();
private:
  int prioritet_stack();
  bool operand_true(char c);
  void first1(char c); //�������� ����� ��������
  void push1(char c); //���������� � ���� ��������
  char pop1(); //������������ �� ����� ��������
  void first2(float c); //�������� ����� �����
  void push2(float c); //���������� � ���� �����
  float pop2(); //������������ �� ����� �����
};
#endif
