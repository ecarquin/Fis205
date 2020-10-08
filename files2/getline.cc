#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main () 
{
    string str;
    cout << "Enter string (EOL = $) : ";
    getline (cin, str, '$');
    cout << "Str is : " << str << endl;

    ifstream In("data.dat");
    vector<string> v;

    cout << endl << "Read data from file" << endl;
    while ( ! In.eof() )
    {
    	getline (In, str);
    	v.push_back(str);
    }

    ostream_iterator<string> out_it (std::cout,"\n");
    copy (v.begin(),v.end(),out_it);
    cout << endl;
    	

    return 0;
}
