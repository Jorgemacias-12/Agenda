#include <iostream>
using namespace std;

int main()
{
    #ifdef __linux__
        cout << "Estoy en linux :u" << endl;
    #endif
    #ifdef __WIN32
        cout << "Estoy en windows :u" << endl;
    #endif
}