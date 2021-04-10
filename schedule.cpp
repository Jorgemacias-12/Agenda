#include <iostream>
#include <locale.h>

using namespace std;

void initLocale()
{
    setlocale(LC_ALL, "");
}

void clearScreen(int os)
{
    switch (os)
    {
        case 1:
            system("clear");
            break;
        case 2:
            system("cls");
            break;
    }
}

void appMenu()
{
i:
    int menuOption = 0;
    cout << "---Menú---" << endl;
    cout << "1. Ingresar contactos." << endl;
    cout << "2. Mostrar  contactos." << endl;
    cout << "3. Salir." << endl;
    cin >> menuOption;
    switch (menuOption)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        cout << "Saliendo..." << endl;
        break;
    default:
        #ifdef __linux__
            clearScreen(1);
        #elif _WIN32
            clearScreen(2);
        #endif
        goto i;
        break;
    }
}

int main()
{
    initLocale();
    appMenu();
}