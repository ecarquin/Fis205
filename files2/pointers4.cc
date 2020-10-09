#include <iostream>
#include <string>
using namespace std;
 
int main()
 {
   int myarray[5] = {2, 4,6, 8,10};
   int* myptr;
   myptr = myarray;
   cout<<"First element in the array :"<<*myptr<<endl;
   myptr ++;
   cout<<"next element in the array :"<<*myptr<<endl;
   myptr +=1;
   cout<<"next element in the array :"<<*myptr<<endl;
   myptr--;
   cout<<"next element in the array :"<<*myptr<<endl;
   myptr -= 1;
   cout<<"next element in the array :"<<*myptr<<endl;
  
   return 0;
 }
