#include <iostream>
using namespace std;
int main()
{

    char str[] = "abcdef";
    char* pstr = "abcdef";
    
    int a[] = {1,2,3}; 
    char c[]= "abc";
    cout<< a << endl;
    cout<< c << endl;
    
    char* p = &c[0];
    cout << p << endl;

    char c1 = 'a';
    char * pc = &c1;

    cout << c1 << endl;
    cout << pc << endl;

}