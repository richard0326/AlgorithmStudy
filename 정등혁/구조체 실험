#include <iostream>

typedef struct tagTest
{
   int mA;
   char mB;
   int mC;
} TEST;

int main()
{
   char* a = new char;
   int* b = new int;
   char* c = new char;

   *a = 1;
   *b = 2;
   *c = 3;

   TEST* t = new TEST;

   t->mA = 5;
   t->mB = 6;
   t->mC = 7;

   delete t;
   delete c;
   delete b;
   delete a;
   
   return 0;
}
