#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>

using namespace std;

void initLocale()
{
    setlocale(LC_ALL, "");
}

void clearScreen()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif
}

void insertContact() 
{
    string name;
    string address;
    string phone;
    string email;
    start:
        int insertAnotherContact = 0;
        ofstream outputFile("diary/schedule.txt", ios_base::app);
        ifstream inputFile("tempData.txt", ios_base::app);
        if (outputFile.fail() && inputFile.fail()) 
        {
            cout << "Algo ha salido mal, vuelve a ejecutar el programa" << endl;
            system("pause");
        }
        cout << "Introduce tu nombre" << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Introduce tu direccion" << endl;
        getline(cin, address);
        cout << "Introduce tu numero de telefono" << endl;
        getline(cin, phone);
        cout << "Introduce tu email" << endl;
        getline(cin, email);
        outputFile << name << "  " << address << "  " << phone << "  " << email << "\n";
        outputFile << inputFile.rdbuf();
        cout << "¿Desea ingresar otro contacto en la agenda?" << endl;
        cout << "--Si = 1-- --No = 2--" << endl;
        cin >> insertAnotherContact;
        if (insertAnotherContact == 1) 
        {
            clearScreen();
            goto start;
        }  
        inputFile.close();
        outputFile.close();
        remove("tempData.txt");
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
        insertContact();
        break;
    case 2:
        break;
    case 3:
        cout << "Saliendo..." << endl;
        break;
    default:
        clearScreen();
        goto i;
        break;
    }
}

int main()
{
    initLocale();
    appMenu();
}