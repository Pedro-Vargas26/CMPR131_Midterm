//Group Names: Angel, Jessy, Jorge, Nicolas, Cristine
//Group Chapter: Chapter 2 - Abstract data Types and C++ Classes
//Date: 9/23/2025
#include <iostream>
#include "input.h"
//include the dynamic array file
//include the statisticain file
using namespace std;

void DynamicArray();
void Statistician();

int main()
{
    do
    {
        system("cls");
        cout << "\n\tMidTerm Chatper 2: Utilizing and Implementing Abstract data Types and Classes";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t 1. Dynaimc array";
        cout << "\n\t 2. Statistician ";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t 0. Exit";
        cout << "\n\t" << string(80, char(205)) << "\n";

        switch (inputInteger("\tOption: ", 0, 2))
        {
        case 0:
            exit(0);
            break;
        case 1:
            DynamicArray();
            break;
        case 2:
            Statistician();
            break;
        default: cout << "ERROR: Invalid input. Must be a number from 0...2";
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

void DynamicArray()
{
    //create the dynamic class

    do
    {
        system("cls");
        cout << "\n\tMidTerm Chatper 2: Dyanmic Array";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t 1. Create Dynamic Array";
        cout << "\n\t 2. Insert into the array";
        cout << "\n\t 3. Remove from the array";
        cout << "\n\t 4. Find value in the array";
        cout << "\n\t 5. Display all current values";
        cout << "\n\t 6. Clear the array";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t 0. Return";
        cout << "\n\t" << string(80, char(205)) << "\n";

        switch (inputInteger("\tOption: ", 0, 2))
        {
        case 0:
            return;
            break;
        case 1:
            //call funciton
            break;
        case 2:
            //call function
            break;
        case 3:
            //call funciton
            break;
        case 4:
            //call function
            break;
        case 5:
            //call funciton
            break;
        case 6:
            //call function
            break;
        default: cout << "ERROR: Invalid input. Must be a number from 0...2";
        }
        cout << "\n";
        system("pause");
    } while (true);
}

void Statistician()
{
    //create the Statistician class

    do
    {
        system("cls");
        cout << "\n\tMidTerm Chatper 2: Statistician";  //include all functions for statistician
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t 1. Insert all Numbers";
        cout << "\n\t 2. ";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t 0. Return";
        cout << "\n\t" << string(80, char(205)) << "\n";

        switch (inputInteger("\tOption: ", 0, 2))
        {
        case 0:
            return;
            break;
        case 1:
            //call function
            break;
        case 2:
            //call function
            break;
        default: cout << "ERROR: Invalid input. Must be a number from 0...2";
        }
        cout << "\n";
        system("pause");
    } while (true);

    cout << "";
}

