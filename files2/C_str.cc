// returns (the base address of) a char 
// array containing the characters stored in s, 
// terminated by a null character.

#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "Anatoliy";
    char *ary = new char[str.length()+1];

    // strcpy ( ary, str ); that is wrong way
    strcpy ( ary, str.c_str() ); // that is correct

    cout << ary << endl;
    
    return 0;
}
