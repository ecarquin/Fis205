#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "Alexander Stepanov";
    cout << "str is: " << str << endl;
    cout << "size of str is: "
         << str.size() << endl;

    str.resize(11);

    cout << "after str.resize(11)" << endl;
    cout << "str is: " << str << endl;
    cout << "size of str is: "
         << str.size() << endl;

    str.resize(20,'.');

    cout << "after str.resize(20,'.')" << endl;
    cout << "str is: " << str << endl;
    cout << "size of str is: "
         << str.size() << endl;

    return 0;
}
