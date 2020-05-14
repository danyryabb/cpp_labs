//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
//---------------------------------------------------------------------------

struct NodeOperations
{
  char c;
  NodeOperations* p;
};

struct NodeNumerals
{
  float c;
  NodeNumerals* p;
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
  NodeOperations* t1;
  NodeNumerals* t2;
  void InitializeStack();
  void Check();
  void PlacingSpaces();
  void MakePostfix();
  float CalculateExample(float A, float B, float C, float D, float E);
  void FindErrCode();
  errors err_code;
  ~Stack();
private:
  int PriotitetStack();
  bool CheckForTrueOperand(char c);
  void OperationsStackCreate(char c);
  void PushToOperationStack(char c);
  char PopFromOperationStack();
  void NumStackCreate(float c);
  void PushToNumStack(float c);
  float PopFromNumStack();
};
#endif

