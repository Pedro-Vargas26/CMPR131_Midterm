//Group Names: Angel, Jessy, Jorge, Nicolas, Cristine
//Group Chapter: Chapter 1 - The Phases of Software Development
//Date: 9/23/2025
#include <iostream>
#include "input.h"
//include the dynamic array file
//include the Statistics file
using namespace std;
 
void Option1();
void Option2();
void Option3();

int main()
{
    //create the statictics class

    //Display the menu options
    do
    {
        system("cls");
        cout << "\n\tMidTerm";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t 0. Exit";
        cout << "\n\t 1. Inset sort value(s) to the Dataset";
        cout << "\n\t 2. Delete value(s) from the Data set";
        cout << "\n\t 3. find value / sort from the Data set";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t A. Find Minimum                   N. Find Outliers";
        cout << "\n\t B. Find Maximum                   O. Find Sum of Squares";
        cout << "\n\t C. Find Range                     P. Find Mean Absolute Deviation";
        cout << "\n\t D. Find Sum                       Q. Find Root Mean Square";
        cout << "\n\t F. Find Mean                      R. Find Standard Error of Mean";
        cout << "\n\t G. Find Median                    S. Find Skewness";
        cout << "\n\t H. Find Mode(s)                   T. Find Kurtosis";
        cout << "\n\t I. Find Standard Deviation        U. Find Kurtosis Excess";
        cout << "\n\t J. Find Variance                  V. Find Coefficient of Variation";
        cout << "\n\t K. Find Midrange                  W. Find Relative Standard Deviation";
        cout << "\n\t L. Find Quartiles                 X. Display Frequency Table";
        cout << "\n\t" << string(80, char(205)) << "\n";

        char userinput = inputChar("\t\tOption: ");

        if (isdigit(userinput))
        {
            int input = userinput - '0';

            switch (input)
            {
            case 0: exit(1);
            case 1: Option1(); break;
            case 2: Option2(); break;
            case 3: Option3(); break;
            default:;
            }

        }
        else
        {
            switch (userinput)
            {
                //Call functions for statictics here
                //ex. case 'A': class.findMin(); break;
            case 'A': ; break;
            case 'B': ; break;
            case 'C': ; break;
            case 'D': ; break;
            case 'E': ; break;
            case 'F': ; break;
            case 'G': ; break;
            default: cout << "ERROR: Invalid input. Must be one of \"01234ABCDEFGHIJKLMNOPQRSTUVWXYZ\" characters.";
            }
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

void Option1()
{
    do
    {
        system("cls");
        cout << "\n\tInsert Dataset Menu";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t\tA. insert a value";
        cout << "\n\t\tB. insert a specified number of random values";
        cout << "\n\t\tC. read data from file and insert values";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t\tR. return";
        cout << "\n\t" << string(80, char(205));

        int value;

        switch (toupper(inputChar("\n\t\tOption: ", "ABCR")))
        {
        case 'R': cout << "\n\tNo change to the Data Set.";  return;
        case 'A':
            //ask user to input a value for the array
            value = inputInteger("\n\tSpecify an integer value to be inserted to the Dataset: ");

            //insert the value into the array

            //display confirmaiton message
            cout << "\n\t" << value << " has been inserted...";

            return;
        case 'B':
            //ask user for the amount of random numbers to be inserted into the array
            value = inputInteger("\n\tSpecify an integer value to be inserted to the Dataset: ");

            //insert the value's into the array

            //display confirmaiton message
            cout << "\n\t CONFIRMATION: Inserted " << value << " random values into the Dataset.";

            return;
        case 'C':


            return;
        default: cout << "ERROR: Invalid input. Must be one of \"abr\" characters."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

void Option2()
{
    do
    {
        system("cls");
        cout << "\n\tDe;ete Dataset Menu";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t\tA. delete a value";
        cout << "\n\t\tB. delete a range of values";
        cout << "\n\t\tC. delete all values";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t\tR. return";
        cout << "\n\t" << string(80, char(205));

        //values use for finding values to delete
        int value;
        int value2;
        bool otherinput;

        switch (toupper(inputChar("\n\t\tOption: ", "ABCR")))
        {
        case 'R': cout << "\n\tNo change to the Data Set.";  return;
        case 'A':
            //ask user to input a value for the array
            value = inputInteger("\n\tSpecify an integer value to find and be deleted from the Dataset:");

            //ask user to input a option for the array
            value2 = inputInteger("\n\tDelete (1)-all elements or (2)-one element found with value? ", 1, 2);

            if (value2 == 1)
                otherinput = true;
            else
                otherinput = false;

            //delete value if possible
            //display confirmation/error message

            return;
        case 'B':
            //ask user to input a start valkue for the array
            value = inputInteger("\n\tSpecify a starting integer value to be deleted from the Dataset:");

            //ask user to input a end value for the array
            value2 = inputInteger("\n\tSpecify an ending integer value to be deleted from the Dataset: ");

            //delete value's if possible
            //display confirmation/error message

            return;
        case 'C':
            //call delete all function

            return;
        default: cout << "ERROR: Invalid input. Must be one of \"abr\" characters."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

void Option3()
{
    do
    {
        system("cls");
        cout << "\n\tFind / sort";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t\tA. Find";
        cout << "\n\t\tB. sort";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t\tR. return";
        cout << "\n\t" << string(80, char(205));

        int value;

        switch (toupper(inputChar("\n\t\tOption: ", "ABR")))
        {
        case 'R': cout << "\n\tNo change to the Data Set.";  return;
        case 'A':
            //ask user to input a value 
            value = inputInteger("\n\tSpecify an integer value to find in the data set: ");

            //call function to find value

            //display confirmaiton / error message

            return;
        case 'B':
            //call sort function

            //display confirmaiton / error message

            return;
        default: cout << "ERROR: Invalid input. Must be one of \"abr\" characters."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}