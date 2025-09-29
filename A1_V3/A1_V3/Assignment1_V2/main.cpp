//Name: Jessy Zuniga
//Date: 09/09/2025
//Description: Assignment 1

// Standard Included files
#include <iostream>
#include <iomanip>

// My Headers
#include "DynamicArray.h"
#include "DynamicArray.cpp"

#include "Statistics.h"

// Prof input, Handles user input and other things
#include "input.h"

using namespace std;

// Prototypes
// Im redoing the name scheme for the group project... along with thorough explanations of what each functions does and why........
char mainMenu_Display(Statistics<int>& stats);
// Support Functions
void samOrPop(Statistics<int>& stats);
void dataInsert(Statistics<int>& stats);


int main()
{
	srand(9242025);

	Statistics<int> stats;
	int setw_DisplayWidth = 35;

	do
	{
		// Menu Choice
		switch (mainMenu_Display(stats))
		{ 
		// Switch Start

		// Exit program
		case '0': exit(0);

			// Data Set Control - START
			//=========================================================
		case '1':
		{
			samOrPop(stats);
			break;
		}
		case '2':
		{
			dataInsert(stats);
			break;
		}
		case 'Z':
		{
			cout << "\n\t ArrayContents: ";
			for(int index = 0; index < stats.dArr.size(); ++index)
			{
				cout << stats.dArr[index] << " ";
			}

			system("pause");
			break;
		}

		case 'Y':
		{

			if (!(stats.dArr.empty()))
			{
				// REMOVE AFTER FIXING INSERT
				stats.dArr.sort();
				cout << setw(setw_DisplayWidth) << "\n\tMinimum" << "= "; cout << stats.dArr.front();
				cout << setw(setw_DisplayWidth) << "\n\tMaximum" << "= "; cout << stats.dArr.back();
				cout << setw(setw_DisplayWidth) << "\n\tRange" << "= "; cout << stats.range();
				cout << setw(setw_DisplayWidth) << "\n\tSize" << "= "; cout << stats.size();
				cout << setw(setw_DisplayWidth) << "\n\tSum" << "= "; cout << stats.sum();
				cout << setw(setw_DisplayWidth) << "\n\tMean" << "= "; cout << stats.mean();
				cout << setw(setw_DisplayWidth) << "\n\tMedian" << "= "; cout << stats.median();
				cout << setw(setw_DisplayWidth) << "\n\tMode" << "= "; cout << stats.mode();
				cout << setw(setw_DisplayWidth) << "\n\tStandard Deviation" << "= "; cout << stats.standardDeviation();
				cout << setw(setw_DisplayWidth) << "\n\tVariance" << "= "; cout << stats.variance();
				cout << setw(setw_DisplayWidth) << "\n\tMidrange" << "= "; cout << stats.midrange();
				
				// When done quartiles go here...
				//cout << setw(setw_DisplayWidth) << "\n\tQuartile" << "= ";
				//cout << setw(setw_DisplayWidth) << "\n\tInterquartile Range" << "= ";
				//cout << setw(setw_DisplayWidth) << "\n\tOutliers" << "= ";
				//cout << setw(setw_DisplayWidth) << "\n\tSum of Squares" << "= ";
				//cout << setw(setw_DisplayWidth) << "\n\tMean Absolute Deviation" << "= ";
				//cout << setw(setw_DisplayWidth) << "\n\tRoot Mean Square" << "= ";
				//cout << setw(setw_DisplayWidth) << "\n\tStandard Error of the Mean" << "= ";

				stats.quartiles();
				stats.interquartile();
				stats.outliers();
				stats.sumOfSquares();
				stats.meanAbsoluteDeviation();
				stats.rootMeanSquare();
				stats.standardErrorMean();

				cout << setw(setw_DisplayWidth) << "\n\tSkewness" << "= " << stats.skewness(); // Broken
				cout << setw(setw_DisplayWidth) << "\n\tKurtosis" << "= " << stats.kurtosis(); // Broken

				cout << setw(setw_DisplayWidth) << "\n\tKurtosis Excess" << "= "; cout << stats.kurtosisExcess(); // Broken
				cout << setw(setw_DisplayWidth) << "\n\tCoefficient Variation" << "= "; cout << stats.coefficientOfVariation(); // EH
				cout << setw(setw_DisplayWidth) << "\n\tRelative Standard Deviation" << "= "; cout << stats.relativeStandardDeviation(); // EHHHH
				cout << setw(setw_DisplayWidth) << "\n\tFrequency Table" << "= "; stats.displayFrequencyTable();
				cout << "\n\n";
			}
			else
				cout << "\n\tArray is empty or ptr is null";
			break;
		}

		default:
		{
			set_txt_color(BrightRed);
			cout << "\n\tERROR: Invalid option.\n";
			reset_color();
			break;
		}

		}// Switch End
		system("pause");
	} while (true);
}

// Menu Option displays

char mainMenu_Display(Statistics<int>& stats)
{
	system("cls");

	int setw1 = 40;		// Controls spacing 
	int lineLength = 100; // Controls length of the lines printed for the UI.

	cout << "\n";

	cout << "\tAddress of Dynamic array: "; //<< //stats.dArr.ptr();
	cout << "\n\tDataset: ("; string type = (stats.getDatasetType() == false ? "Population" : "Sample"); cout << type + ")";
	cout << "\n";

	if (stats.dArr.empty() || stats.dArr.size() < 2)
		cout << "\n\tERROR: Data Set requires at least 2 values.";
	else
	{
		cout << "\n\tDATA: ";
		for (size_t index = 0; index < stats.dArr.size(); ++index)
		{
			cout << stats.dArr[index] << " ";
		}
	}

	// Menu Display
	cout << "\n\n\tDescriptive Statistics Calculator Main Menu";

	// Data control
	cout << "\n\t" << string(lineLength, char(205));
	cout << "\n\t 0. Exit";
	cout << "\n\t 1. Configure Dataset to Sample or Population";
	cout << "\n\t 2. Insert sort value(s) to the Dataset"; // INCOMPLETE
	cout << "\n\t 3. Delete value(s) from the Dataset";    // NOT DONE
	cout << "\n\t" << string(lineLength, char(196));

	// Calculations and display output
	cout << left << setw(setw1) << "\n\t A. Find Minimum" << left << "N. Find Outliers";
	cout << left << setw(setw1) << "\n\t B. Find Maximum" << left << "O. Find Sum of Squares";
	cout << left << setw(setw1) << "\n\t C. Find Range" << left << "P. Find Mean Absolute Deviation";
	cout << left << setw(setw1) << "\n\t D. Find Size" << left << "Q. Find Root Mean Square";
	cout << left << setw(setw1) << "\n\t E. Find Sum" << left << "R. Find Standard Error of Mean";
	cout << left << setw(setw1) << "\n\t F. Find Mean" << left << "S. Find Skewness";
	cout << left << setw(setw1) << "\n\t G. Find Median" << left << "T. Find Kurtosis";
	cout << left << setw(setw1) << "\n\t H. Find Mode(s)" << left << "U. Find Kurtosis Excess";
	cout << left << setw(setw1) << "\n\t I. Find Standard Deviation" << left << "V. Find Coefficient of Variation";
	cout << left << setw(setw1) << "\n\t J. Find Variance" << left << "W. Find Relative Standard Deviation";
	cout << left << setw(setw1) << "\n\t K. Find Midrange" << left << "X. Display Frequency Table";
	cout << left << setw(setw1) << "\n\t L. Find Quartiles" << left << "Y. Display ALL statical results";
	cout << left << setw(setw1) << "\n\t M. Find Interquartile Range" << left << "Z. Output ALL statical results to text file";
	cout << "\n\t" << string(lineLength, char(205));
	cout << "\n";

	// Menu Choice
	return toupper(inputChar("\t\tOption: "));
}

void samOrPop(Statistics<int>& stats)
{
	// Clears the screen, returns screen to a basic state unpainted canvas like state.
	system("cls");

	int lineLength = 50;

	// 
	cout
		<< "\n\tIn statistics, Population refers to the entire group of data"
		<< "\n\tpoints that a study is interested in, while a Sample is a"
		<< "\n\tsubset of that population that is actually used in the study.\n";

	cout << "\n\tConfigure Dataset Menu";
	cout << "\n\t" << string(lineLength, char(205));
	cout << "\n\t\tA. sample";
	cout << "\n\t\tB. population";
	cout << "\n\t" << string(lineLength, char(196));
	cout << "\n\t\tR. return";
	cout << "\n\t" << string(lineLength, char(205));

	// Menu Choice selection
	switch (toupper(inputChar("\n\tOption: ", string("ABR"))))
	{
	case 'A':
	{
		stats.setDatasetType(true);
		cout << "\n\n\tData Set configured for Sample.\n\n";
		break;
	}
	case 'B':
	{
		cout << "\n\n\tData Set configured for Population.\n\n";
		stats.setDatasetType(false);
		break;
	}
	case 'R':
	{
		cout << "Back to main menu";
		return;
		break;
	}

	}

	return;


}

void dataInsert(Statistics<int>& stats)
{
	int lineLength = 50;
	while (true)
	{
		system("cls");

		cout << "\n\tInsert (sort) Dataset Menu";
		cout << "\n\t" << string(lineLength, char(205));
		cout << "\n\t\tA. insert a value";
		cout << "\n\t\tB. insert a specified number of random values";
		cout << "\n\t\tC. read data from file and insert values"; // Incomplete
		cout << "\n\t" << string(lineLength, char(196));

		cout << "\n\tDataset Values: ";

		cout << "\n\t" << string(lineLength, char(196));
		cout << "\n\t\tR. return";
		cout << "\n\t" << string(lineLength, char(205));

		// Menu Choice selection
		switch (toupper(inputChar("\n\tOption: ", string("ABR"))))
		{
		case 'A':
		{
			int input = inputInteger("\n\tSpecify an integer value to be inserted to the Dataset: ", true);
			stats.dArr.append(input);
			cout << "\n\t" << input << " has been inserted...\n\n";
			
			system("pause");
			break;
		}
		case 'B':
		{
			// limited to 32K ints
			int minRange = 0, maxRange = 100;
			int randNumb;

			int totalNumbersToGenerate = inputInteger("Specify a number of values to be randomly generated into the Dataset: ", true);

			for (int index = 0; index < totalNumbersToGenerate; index++)
			{
				randNumb = minRange + rand() / (RAND_MAX / (maxRange - minRange + 1) + 1);
				stats.dArr.append(randNumb);
			}

			break;
		}
		case 'C':
		{
			cout << "\n\tFut";
			break;
		}
		case 'R':
		{
			cout << "\n\n\tBack to main menu\n\n";
			return;
			break;
		}

		}


	}
}