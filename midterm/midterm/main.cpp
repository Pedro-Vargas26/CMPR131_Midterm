//Name: Jessy Zuniga
//Date: 09/09/2025
//Description: Assignment 1

// Standard Included files
#include <iostream>
#include <iomanip>
#include <fstream>

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
void dataDelete(Statistics<int>& stats);
vector<double> readNumbersFromFile(const string& filename);

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

		case '3':
		{
			dataDelete(stats);
			break;
		}

		case 'Y':
		{

			if (!(stats.dArr.empty()))
			{
				stats.dataDisplay(cout);
			}
			else
				cout << "\n\tArray is empty or ptr is null\n\n";
			break;
		}

		case 'A':
		{
			try
			{
				int data = stats.minimum();
				cout << left <<setw(setw_DisplayWidth) << "\n\tMinimum" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'B':
		{
			try
			{
				int data = stats.maximum();
				cout << left << setw(setw_DisplayWidth) << "\n\tMaximum" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'C':
		{
			try
			{
				int data = stats.range();
				cout << left << setw(setw_DisplayWidth) << "\n\tRange" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'D':
		{
			try
			{
				int data = stats.size();
				cout << left << setw(setw_DisplayWidth) << "\n\tSize" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'E':
		{
			try
			{
				int data = stats.sum();
				cout << left << setw(setw_DisplayWidth) << "\n\tSum" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'F':
		{
			try
			{
				double data = stats.mean();
				cout << left << setw(setw_DisplayWidth) << "\n\tMean" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'G':
		{
			try
			{
				double data = stats.median();
				cout << left << setw(setw_DisplayWidth) << "\n\tMedian" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'H':
		{
			try
			{
				cout << setw(setw_DisplayWidth) << "\n\tMode" << "= ";

				DynamicArray<int> modes = stats.mode();
				if (modes.empty()) {
					cout << "No mode";
				}
				else if (modes.size() == 1) {
					cout << modes[0];
				}
				else {

					for (size_t i = 0; i < modes.size(); ++i) {
						cout << modes[i];
						if (i < modes.size() - 1) {
							cout << ", ";
						}
					}

				}
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}


		case 'I':
		{
			try
			{
				double data = stats.standardDeviation();
				cout << left << setw(setw_DisplayWidth) << "\n\tStandard Deviation" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'J':
		{
			try
			{
				double data = stats.variance();
				cout << left << setw(setw_DisplayWidth) << "\n\tVariance" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}


		case 'K':
		{
			try
			{
				int data = stats.midrange();
				cout << left << setw(setw_DisplayWidth) << "\n\tMidrange" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'L':
		{
			try
			{
				//quartiles
				Statistics<int>::QuartileValues q = stats.quartilesCalculation();
				cout << setw(setw_DisplayWidth) << "\n\tQuartiles";
				cout << "Quartiles:\n";
				//Q1
				cout << setw(setw_DisplayWidth) << " " << "\t Q1 --> ";
				if (q.q1Known)
				{
					cout << fixed << setprecision(1) << q.Q1 << "\n";
				}
				else
					cout << "unknown\n";
				//Q2
				cout << setw(setw_DisplayWidth) << " " << "\t Q2 --> " << fixed << setprecision(1) << q.Q2 << "\n";
				//Q3
				cout << setw(setw_DisplayWidth) << " " << "\t Q3 --> ";
				if (q.q3Known)
				{
					cout << fixed << setprecision(1) << q.Q3 << "\n";
				}
				else
					cout << "unknown\n";

				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'M':
		{
			try
			{
				//interquartile range
				if (stats.size() < 4)
				{
					cout << setw(setw_DisplayWidth) << "\n\tInterquartile Range" << "= ";
					cout << "unknown";
				}
				else
				{
					cout << setw(setw_DisplayWidth) << "\n\tInterquartile Range" << "= ";
					cout << stats.interquartile();
				}
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'N':
		{
			try
			{
				DynamicArray<int> outlierList = stats.outliers();
				cout << setw(setw_DisplayWidth) << "\n\tOutliers" << "= ";
				if (outlierList.empty())
				{
					cout << "None\n";
				}
				else
				{
					for (size_t i = 0; i < outlierList.size(); ++i)
						cout << outlierList[i] << " ";
				}
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'O':
		{
			try
			{
				//sum of squares
				if (stats.size() < 2)
				{
					cout << setw(setw_DisplayWidth) << "\n\tSum of Squares" << "= ";
					cout << "unknown";
				}
				else
				{
					cout << setw(setw_DisplayWidth) << "\n\tSum of Squares" << "= ";
					cout << stats.sumOfSquares();
				}

				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'P':
		{
			try
			{
				//mean absolute deviation
				if (stats.size() < 2)
				{
					cout << setw(setw_DisplayWidth) << "\n\tMean Absolute Deviation" << "= ";
					cout << "unknown";
				}
				else
				{
					cout << setw(setw_DisplayWidth) << "\n\tMean Absolute Deviation" << "= ";
					cout << stats.meanAbsoluteDeviation();
				}

				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'Q':
		{
			try
			{
				//root mean square
				if (stats.size() < 2)
				{
					cout << setw(setw_DisplayWidth) << "\n\tRoot Mean Square" << "= ";
					cout << "unknown";
				}
				else
				{
					cout << setw(setw_DisplayWidth) << "\n\tRoot Mean Square" << "= ";
					cout << stats.rootMeanSquare();
				}

				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'R':
		{
			try
			{
				//Standard Error of the Mean
				if (stats.size() < 2)
				{
					cout << setw(setw_DisplayWidth) << "\n\tStandard Error of the Mean" << "= ";
					cout << "unknown";
				}
				else
				{
					cout << setw(setw_DisplayWidth) << "\n\tStandard Error of the Mean" << "= ";
					cout << stats.standardErrorMean();
				}

				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'S':
		{
			try
			{
				double data = stats.skewness();
				cout << left << setw(setw_DisplayWidth) << "\n\tSkewness" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'T':
		{
			try
			{
				double data = stats.kurtosis();
				cout << left << setw(setw_DisplayWidth) << "\n\tKurtosis" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'U':
		{
			try
			{
				double data = stats.kurtosisExcess();
				cout << left << setw(setw_DisplayWidth) << "\n\tKurtosis Excess" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'V':
		{
			try
			{
				double data = stats.coefficientOfVariation();
				cout << left << setw(setw_DisplayWidth) << "\n\tCoefficient of Variation" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'W':
		{
			try
			{
				double data = stats.relativeStandardDeviation();
				cout << left << setw(setw_DisplayWidth) << "\n\tRelative Standard Deviation" << "= ";
				cout << data << "\n";
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'X':
		{
			try
			{
				
				cout << left << setw(setw_DisplayWidth) << "\n\tFrequency Table" << "= \n";
				stats.displayFrequencyTableOut(cout);
				break;
			}
			catch (invalid_argument runtimeException)
			{
				set_txt_color(Red);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}
			catch (out_of_range runtimeException)
			{
				set_txt_color(BrightRed);
				cout << "\n\tError: " << runtimeException.what() << "\n";
				reset_color();
				break;
			}

			break;
		}

		case 'Z':
		{
			if (!(stats.dArr.empty()))
			{
				string fileName = inputString("\n\tSpecify a text file to save results: ", true);

				ofstream out(fileName);


				if (!out)
				{
					cout << "\n\tERROR: Unable to open file for writing.\n";
					system("pause");
					break;
				}

				stats.dataDisplay(out);


				if (out)  // checks if stream is still in a good state (no write errors)
				{
					cout << "\n\tCONFIRMATION: File, " << fileName << ", has been generated.\n\n";
				}
				else
				{
					cout << "\n\tERROR: File may not have written successfully.\n";
				}
			}
			else
				cout << "\n\tArray is empty or ptr is null\n\n";

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
		for (int index = 0; index < stats.dArr.size(); ++index)
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

void dataDelete(Statistics<int>& stats)
{
	int lineLength = 50;
	while (true)
	{
		system("cls");
		cout << "\n\tDelete Dataset Menu";
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
		bool otherInput;

		switch (toupper(inputChar("\n\t\tOption: ", "ABCR")))
		{
		case 'R': cout << "\n\tNo change to the Data Set.";  return;
		case 'A':
		{
			if (stats.dArr.empty())
			{
				cout << "\n\tERROR: Dataset is empty.\n";
				break;
			}


			//ask user to input a value for the array
			value = inputInteger("\n\tSpecify an integer value to find and be deleted from the Dataset: ");

			//ask user to input a option for the array
			value2 = inputInteger("\n\tDelete (1)-all elements or (2)-one element found with value? ", 1, 2);

			bool deleteAll = (value2 == 1);
			int removedCount = stats.dArr.remove(value, deleteAll);

			// CONFIRNATION: All 1 instance() of element:  9 have been found and deleted.



			if (removedCount > 0)
			{
				if (removedCount == 1)
					cout << "\n\tCONFIRMATION: One element " << value << " has been found and deleted.\n\n";
				else
					cout << "\n\tCONFIRMATION: All " << removedCount << " instance of element(s) " << value << " have been found and deleted.\n\n";
			}
			else
			{
				cout << "\n\tERROR: No element " << value << " has been found and deleted.\n\n";
			}




			return;
		}
		case 'B':
		{
			if (stats.dArr.empty())
			{
				cout << "\n\tERROR: Dataset is empty.\n";
				system("pause");
				break;
			}

			//ask user to input a start valkue for the array
			value = inputInteger("\n\tSpecify a starting integer value to be deleted from the Dataset: ");

			//ask user to input a end value for the array
			value2 = inputInteger("\n\tSpecify an ending integer value to be deleted from the Dataset: ");

			//delete value's if possible
			//display confirmation/error message

			return;
		}
		case 'C': 
		{
			if (stats.dArr.empty())
			{
				cout << "\n\tERROR: Dataset is already empty.\n\n";
			}
			else
			{
				stats.dArr.clear();
				//Dataset has been purged of all elements.
				cout << "\n\tDataset has been purged of all elements.\n\n";
			}
			return; //call function 
		}

		default: cout << "ERROR: Invalid input. Must be one of \"abr\" characters."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
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
			stats.dArr.sorted_insert(input);
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
				stats.dArr.sorted_insert(randNumb);
			}
			system("pause");
			break;
		}
		case 'C':
		{
			try
			{
				vector<double> temp = readNumbersFromFile(inputString("\n\tEnter the file name to read from: ", false));

				for (size_t index = 0; index < temp.size(); index++)
				{
					stats.dArr.sorted_insert(temp[index]);
				}

				cout << "\n\tA total of " + to_string(temp.size()) + " numbers have been put into the array.";



				system("pause");
			}
			catch (runtime_error error)
			{
				cout << error.what();
			}



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

/*
  Purpose:
  The readNumbersFromFile function reads a file containing numerical values (integers or doubles)
  separated by common delimiters (spaces, commas, tabs, newlines, or semicolons) and returns
  these numbers as a vector of doubles.

  Preconditions:
  1. Input Parameter:
	- The filename parameter must be a valid string representing the path to an existing text file.
  2. File Accessibility:
	- The file specified by filename must exist and be readable by the program.
  3. File Content:
	- The file may contain numerical values (integers or doubles) in text format.
	- Numbers may be separated by one or more delimiters (spaces, commas, tabs, newlines, or semicolons).
	- The file may contain non-numeric tokens, which will be ignored.

  Postconditions:
  1. Return Value:
	- If successful, the function returns a std::vector<double> containing all valid numbers
	- If the file contains no valid numbers, an empty vector is returned.
  2. File State:
	- The input file is closed after processing.
  3. Error Handling:
   - If the file cannot be opened, a std::runtime_error is thrown with the message
	"Unable to open file: " followed by the filename.
   - If a number in the file is out of the valid range for a double, a std::runtime_error
	 is thrown with the message "Number out of range in file: " followed by the filename.
 */
vector<double> readNumbersFromFile(const string& filename)
{
	vector<double> numbers;
	ifstream file(filename);

	if (!file.is_open())
	{
		throw std::runtime_error("Unable to open file: " + filename);
	}

	char c;
	std::string token;

	while (file.get(c))
	{
		// Handle common delimiters: space, comma, tab, newline, semicolon
		if (c == ' ' || c == ',' || c == '\t' || c == '\n' || c == ';')
		{
			if (!token.empty())
			{
				try
				{
					// Convert string to double
					size_t pos;
					double number = std::stod(token, &pos);

					// Check if the entire token was converted
					if (pos == token.length())
					{
						numbers.push_back(number);
					}
				}
				catch (const std::invalid_argument&)
				{
					// Skip non-numeric tokens
				}
				catch (const std::out_of_range&)
				{
					throw std::runtime_error("Number out of range in file: " + filename);
				}
				token.clear();
			}
			continue;
		}
		// Remove carriage return
		if (c != '\r') {
			token += c;
		}
	}

	// Process the last token if exists
	if (!token.empty()) {
		try {
			size_t pos;
			double number = std::stod(token, &pos);
			if (pos == token.length()) {
				numbers.push_back(number);
			}
		}
		catch (const std::invalid_argument&) {
			// Skip non-numeric tokens
		}
		catch (const std::out_of_range&) {
			throw std::runtime_error("Number out of range in file: " + filename);
		}
	}

	file.close();
	return numbers;
}