#include <iostream>
using namespace std;

int main()
{
  int firstvalue, secondvalue;
  int *mypointer;

  mypointer  = &firstvalue;
  *mypointer = 10;
  mypointer  = &secondvalue;
  *mypointer = 20;
  cout << "first value is: " << firstvalue << '\n';
  cout << "second value is: " << secondvalue << '\n';
  return 0;
}
