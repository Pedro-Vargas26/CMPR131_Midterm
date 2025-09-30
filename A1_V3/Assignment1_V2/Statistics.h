#pragma once
#ifndef STATISTICS
#define STATISTICS

#include <map>
#include <iterator>
// Custom Headers
#include "DynamicArray.h"
#include "input.h"

template<class T>
class Statistics
{
private:
	
	// This should only be two states
	bool datasetType; // true is sample, False is population
	
	// For quartiles, This should be swapped to a function in the future... Data may stagnate and not properly reflect new changes...
	// Maybe using pair<string, int> [] to store the values would work
	// int q1; q2; q3;

public:
	DynamicArray<T> dArr;

	// Constructor
	Statistics() {
		datasetType = true;
	};

	// Destructor
	~Statistics() {};

	// OTHER ASSIGNMENT AND COPY CONSTRUCTORS... IN THE FUTURE?

// MUTATORS
public:
	
	
	

// Accessors
public:
	
	bool setDatasetType(const bool& populationOrSample) { datasetType = populationOrSample; return datasetType; }
	bool getDatasetType() const { return datasetType; }
	//Precondition :
	//Postcondition:

	// A - E
	//============================================
	T minimum() const; // 0 for the start
	T maximum() const; // Sorted arr max index
	double range() const;   // Min val to max val is the range.
	size_t size() const; // THis is basically how populated the array is or how many elements are in it.
	T sum() const; // Add all the elements 
	double sumPowSub(const double& exponent, const double& subtractValue) const; 
	double sumPowSubDiv(const double& exponent, const double& subtractValue, const double& divisor) const;
	//============================================

	// F - K
	//============================================
	double mean() const;
	double median() const;
	double mode() const;
	double standardDeviation() const;
	double variance() const;
	double midrange() const;
	//============================================

	// L - R
	//============================================

	struct QuartileValues
	{
		double Q1;
		double Q2;
		double Q3;
		bool q1Known;
		bool q3Known;
	};

	QuartileValues quartilesCalculation() const;
	void quartiles() const;	
	void interquartile() const;
	void outliers() const;
	void sumOfSquares() const;
	void meanAbsoluteDeviation() const;
	void rootMeanSquare() const;
	void standardErrorMean() const;

	//============================================

	// S - W
	//============================================
	double skewness() const;
	double kurtosis() const;
	double kurtosisExcess() const;
	double coefficientOfVariation() const;
	double relativeStandardDeviation() const;
	//============================================

	// X-Y

	map<double, size_t > displayFrequencyTable() const;
	void displayOut(ostream& out);

	// OTHER
	//============================================
	bool minDatasetSize(const int& minArraySize) const;
};

// A - E
//============================================
// Purpose			: Returns the smallest value in the dataset.
// Precondition		: dArr is not empty.
// Postcondition	: Returns dArr.front().
// Time Complexity	: O(1)
template<class T> 
T Statistics<T>::minimum() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 1)
			throw out_of_range("Requires at least (" + to_string(1) + ") data values.");

		return dArr.front();
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

}

// Purpose			: Returns the largest value in the dataset.
// Precondition		: dArr is not empty.
// Postcondition	: Returns dArr.back().
// Time Complexity	: O(1)
template<class T>
T Statistics<T>::maximum() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not initialized.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 1)
			throw out_of_range("Requires at least (" + to_string(1) + ") data values.");

		return dArr.back();
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

}

// Purpose			: Computes the difference between max and min values.
// Precondition		: dArr has at least one element (non-empty).
// Postcondition	: Returns maximum - minimum.
// Time Complexity	: O(1)
template<class T>
double Statistics<T>::range() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not initialized.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 2)
			throw out_of_range("Requires at least (" + to_string(2) + ") data values.");

		return maximum() - minimum();
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "Error: " << runtimeException.what() << " Default RETURN +/- MAX OR ZERO = ";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "Error: " << runtimeException.what() << " Default RETURN +/- MAX OR ZERO = ";
		reset_color();
	}

	
}

// Purpose			: Returns the number of elements in the dataset.
// Precondition		: N/A (always valid).
// Postcondition	: Returns the size of the array/dataset.
// Time Complexity	: O(1)
template<class T>
size_t Statistics<T>::size() const
{
	return dArr.size();
}


// Purpose: Sums all values in the dataset.
// Precondition: dArr is not empty.
// Postcondition: Accumulates all elements of dArr.
// Time Complexity: O(n) where n = size().
template<class T>
T Statistics<T>::sum() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not initialized.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 1)
			throw out_of_range("Requires at least (" + to_string(1) + ") data values.");

		T temp = 0;
		for (int index = 0; index < dArr.size(); index++)
		{
			temp += dArr[index];
		}

		return temp;
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

}


template<class T>
double Statistics<T>::sumPowSub(const double& exponent, const double& subtractValue) const
{

	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not initialized.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 1)
			throw out_of_range("Requires at least (" + to_string(1) + ") data values.");

		double temp = 0;
		for (int index = 0; index < dArr.size(); index++)
		{
			temp += pow((static_cast<double>(dArr[index]) - subtractValue), exponent);
		}

		return temp;
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

}

template<class T>
double Statistics<T>::sumPowSubDiv(const double& exponent, const double& subtractValue, const double& divisor) const
{

	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 1)
			throw out_of_range("Requires at least (" + to_string(1) + ") data values.");

		double temp = 0;

		for (int index = 0; index < dArr.size(); index++)
		{
			temp += pow(((dArr[index] - subtractValue) / divisor), exponent);
		}

		return temp;
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

}

//============================================

// F - K
//============================================

// Purpose			: Computes the average of all values.
// Precondition		: dArr is not empty.
// Postcondition	: Returns sum / size().
// Time Complexity	: O(n)
template<class T>
double Statistics<T>::mean() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 2)
			throw out_of_range("Requires at least (" + to_string(2) + ") data values.");

		return sum() / static_cast<double>(size());
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

}

// Purpose			: Returns the middle value of a sorted dataset.
// Precondition		: dArr is pre-sorted; has at least one element.
// Postcondition	: For even size, returns average of two middle elements; for odd, returns central element.
// Time Complexity	: O(1)
template<class T>
double Statistics<T>::median() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 1)
			throw out_of_range("Requires at least (" + to_string(1) + ") data values.");

		double median = 0;

		// Checks if even
		if (dArr.size() % 2 == 0)
		{
			int index_P_One = dArr.size() / 2;
			int index_P_Two = index_P_One - 1;
			return median = static_cast<double>((dArr[index_P_One] + dArr[index_P_Two]) / 2.00);
		}
		else
		{
			return  median = dArr[dArr.size() / 2];
		}
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

	
}

// Purpose			: Identifies the most frequent value.
// Precondition		: dArr is sorted; contains at least one duplicate for meaningful output.
// Postcondition	: Returns the mode.
// Time Complexity	: O(n)
template<class T>
double Statistics<T>::mode() const // Ill rewrite this to a pair function later to return the specific value and the number of times it appears.
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 1)
			throw out_of_range("Requires at least (" + to_string(1) + ") data values.");

		// the maximum amount of times a number has been encountered
		// Only the most occurring number will be set to this.
		int maxEncountered = 0;
		int mode = -1;

		for (int index = 1; index < dArr.size(); index++) {
			int count = 0;

			if (dArr[index] == dArr[index - 1]) {		// check if current element is the same as previous one
				++count;									// increment count if it's the same
			}
			else
			{												// if different number, reset count to 1
				count = 1;
			}

			if (count > maxEncountered)
			{												// update if current element has higher frequency
				maxEncountered = count;
				mode = dArr[index];
			}
		}

		return mode;
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

	
}

// Purpose			: Measures spread from the mean.
// Precondition		: dArr is not empty; datasetType (sample/population) set correctly.
// Postcondition	: Returns sqrt(variance).
// Time Complexity	: O(n)
template<class T>
double Statistics<T>::standardDeviation() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 2)
			throw out_of_range("Requires at least (" + to_string(2) + ") data values.");

		/*
	Step 1: Calculate mean of observation using the data
		(Mean = Sum of Observations / Number of Observations)
			mean()

	Step 2 : Calculate squared differences of data values from the mean.
		(Data Value - Mean)2
			sumSqr(mean())

	Step 3 : Calculate average of squared differences
		(Variance = Sum of Squared Differences / Number of Observations)
			sumSqr(mean()) / size()

	Step 4 : Calculate square root of variance this gives the Standard Deviation
		(Standard Deviation = √Variance)
	*/


		long double variance = sumPowSub(2, mean()) / (size() - datasetType);
		return sqrt(variance);
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	
}

template<class T>
double Statistics<T>::variance() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 2)
			throw out_of_range("Requires at least (" + to_string(2) + ") data values.");

		/*
	Step 1: Calculate mean of observation using the data
		(Mean = Sum of Observations / Number of Observations)

	Step 2 : Calculate squared differences of data values from the mean.
		(Data Value - Mean)2
			sumSqr(mean())

	Step 3 : Calculate average of squared differences = variance
		(Variance = Sum of Squared Differences / Number of Observations)
			variance = sumSqr(mean()) / size()

	*/

		double variance = sumPowSub(2, mean()) / static_cast<double>(size() - datasetType);
		return variance;
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	
}

// Purpose			: Computes the midpoint between min and max.
// Precondition		: dArr has at least one element.
// Postcondition	: Returns (minimum + maximum)/2.
// Time Complexity	: O(1)
template<class T>
double Statistics<T>::midrange() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 2)
			throw out_of_range("Requires at least (" + to_string(2) + ") data values.");

		return (dArr.front() + dArr.back()) / 2.00;
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

}

//============================================

// L - R
//============================================

//precondition: data set must have at least 2 values 
//postcondition: returns Q1, Q2, Q3, and if Q1 and Q3 are known or unknown
template<class T>
typename Statistics<T>::QuartileValues Statistics<T>::quartilesCalculation() const	//... may need to return a set...
{
	size_t n = dArr.size();

	if (n == 0)
	{
		cout << "\n\tError: Dataset is empty.\n";
	}

	if (n == 1)
	{
		cout << "\n\tError: Requires at least 2 data values.\n";
	}

	//Q2
	double Q2 = median();

	//Q1
	double Q1 = 0.0;
	bool q1Known = false; //starts as false because we don't know Q1 yet
	size_t lowerHalf = n / 2;

	if (lowerHalf >= 2)
	{
		q1Known = true;
		if (lowerHalf % 2 == 1) //if lower half is odd
		{
			Q1 = dArr[lowerHalf / 2];
		}
		else //if its even 
		{
			double mid1 = dArr[(lowerHalf / 2) - 1];
			double mid2 = dArr[(lowerHalf / 2)];
			Q1 = (mid1 + mid2) / 2.0;
		}
	}

	//Q3
	double Q3 = 0.0;
	bool q3Known = false;
	size_t upperStart; //decides where upper half begins 
	if (n % 2 == 0) //if n is even, upper half starts exactly at n/2
	{
		upperStart = n / 2;
	}
	else //if odd, start at n/2 + 1
	{
		upperStart = (n / 2) + 1;
	}

	size_t upperHalf = n - upperStart; //calculates how many elements are in upper half

	if (upperHalf >= 2)
	{
		q3Known = true;
		if (upperHalf % 2 == 1)
		{
			Q3 = dArr[upperStart + upperHalf / 2];
		}
		else
		{
			double mid1 = dArr[upperStart + (upperHalf / 2) - 1];
			double mid2 = dArr[upperStart + (upperHalf / 2)];
			Q3 = (mid1 + mid2) / 2.0;
		}
	}
	return { Q1, Q2, Q3, q1Known, q3Known };
}

//precondition: data set must have at least 2 values 
//postcondition: displays quartiles and if known/unknown
template<class T>
void Statistics<T>::quartiles() const
{
	QuartileValues q = quartilesCalculation();

	//output
	cout << "\n\tQuartiles           Quartiles:\n";
	cout << fixed << setprecision(1);

	cout << "\t" << setw(20) << "Q1 --> ";
	if (q.q1Known)
		cout << q.Q1 << "\n";
	else
		cout << "unknown\n";

	cout << "\t" << setw(20) << "Q2 --> " << q.Q2 << "\n";

	cout << "\t" << setw(20) << "Q3 --> ";
	if (q.q3Known)
		cout << q.Q3 << "\n";
	else
		cout << "unknown\n";
}

//precondition: data set must have at least 4 values
//postcondition: displays interquartile 
template<class T>
void Statistics<T>::interquartile() const
{
	size_t n = dArr.size();
	QuartileValues q = quartilesCalculation();

	if (n < 4)
	{
		cout << "\n\tInterquartile Range         = unknown\n\n";
	}
	else
	{
		cout << "\n\tInterquartile Range         = " << q.Q3 - q.Q1 << "\n\n";
	}
}

//precondition: data set must have at least 2 values 
//postcondition: calculates IQR and finds upper and lower fence. displays outliers if not in that range
template<class T>
void Statistics<T>::outliers() const
{
	QuartileValues q = quartilesCalculation();
	size_t n = dArr.size();

	double IQR = q.Q3 - q.Q1;

	double upperFence = q.Q3 + (1.5 * IQR);
	double lowerFence = q.Q1 - (1.5 * IQR);

	cout << "\n\tOutliers                    = ";
	bool searchOutlier = false;
	for (size_t i = 0; i < n; i++)
	{
		if (dArr[i] < lowerFence || dArr[i] > upperFence)
		{
			cout << dArr[i] << " ";
			searchOutlier = true;
		}
	}
	if (!searchOutlier)
		cout << "None";

	cout << "\n";
}

//precondition: data set must have at least 2 values 
//postcondition: calculates and displays the sum of squares
template<class T>
void Statistics<T>::sumOfSquares() const
{
	size_t n = dArr.size();

	if (n < 2)
	{
		cout << "\n\tSum of Squares              = unknown\n";
		return;
	}

	double m = mean();
	double sos = sumPowSub(2, m);

	cout << "\n\tSum of Squares              = " << sos << "\n";
}

//precondition: data set must have at least 2 values 
//postcondition: calculates and displays mean absolute deviation
template<class T>
void Statistics<T>::meanAbsoluteDeviation() const
{
	size_t n = dArr.size();

	if (n < 2)
	{
		cout << "\n\tMean Absolute Deviation     = unknown\n";
		return;
	}

	double m = mean();
	double mad = 0.0;

	for (size_t i = 0; i < n; i++)
	{
		mad += abs(dArr[i] - m); //abs - absolute difference 
	}

	mad /= n;

	cout << fixed << setprecision(2);
	cout << "\n\tMean: " << m << "\n";
	cout << "\n\tMean Absolute Deviation     = " << mad << "\n";
}

//precondition: data set must have at least 2 values 
//postcondition: calculates and displays root mean square
template<class T>
void Statistics<T>::rootMeanSquare() const
{
	size_t n = dArr.size();

	if (n < 2)
	{
		cout << "\n\tRoot Mean Square            = unknown\n";
		return;
	}

	double rms = 0.0;
	double squaredValuesAdded = 0.0;

	for (size_t i = 0; i < n; i++)
	{
		squaredValuesAdded += pow(dArr[i], 2);
	}

	rms = sqrt((squaredValuesAdded / n));

	cout << "\n\tRoot Mean Square            = " << rms << "\n";

}

//precondition: data set must have at least 2 values 
//postcondition: calculates amd displays standard error mean 
template<class T>
void Statistics<T>::standardErrorMean() const
{
	size_t n = dArr.size();

	if (n < 2)
	{
		cout << "\n\tStandard Error of the Mean  = unknown\n";
		return;
	}

	double s = standardDeviation();
	double sem = s / (sqrt(n));
	cout << "\n\tStandard Error of the Mean  = " << sem << "\n";
}
//============================================


// S - W
//============================================

// Purpose			: Measures asymmetry in the dataset.
// Precondition		: dArr is not empty; datasetType set correctly.
// Postcondition	: Returns skewness (sample or population).
// Time Complexity	: O(n)
template<class T>
double Statistics<T>::skewness() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 3)
			throw out_of_range("Requires at least (" + to_string(3) + ") data values.");

		if (datasetType)
		{
			double n = size();
			long double fraction = (n / ((n - 1) * (n - 2)));
			long double total = fraction * sumPowSubDiv(3, mean(), standardDeviation());
			return total;
		}
		else // Population
		{
			return sumPowSub(3, mean()) / (size() * pow(standardDeviation(), 3));
		}
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

}

// Purpose: Computes kurtosis of the dataset.
//          - For sample data, applies unbiased correction.
//          - For population data, computes raw kurtosis.
// Precondition 1:	dArr must contain at least 3 elements (size() >= 3).
// Precondition 2:	mean() and standardDeviation() must return valid values.
//					standardDeviation() != 0 to avoid division by zero.
// Postcondition: Returns sample/population kurtosis
template<class T>
double Statistics<T>::kurtosis() const {

	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 4)
			throw out_of_range("Requires at least (" + to_string(4) + ") data values.");

		if (datasetType)
		{
			double n = size();
			long double fraction = (n * (n + 1)) / ((n - 1) * (n - 2) * (n - 3));
			long double sum = sumPowSubDiv(4, mean(), standardDeviation());
			return fraction * sum;
		}
		else // Population
		{
			return sumPowSub(4.0, mean()) / (size() * pow(standardDeviation(), 4.0));
		}
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

}


// Purpose			: Measures "tail end" relative to normal distribution.
// Precondition		: dArr has >=4 elements; datasetType set correctly.
// Postcondition	: Returns excess kurtosis (sample or population).
// Time Complexity	: O(n)
template<class T>
double Statistics<T>::kurtosisExcess() const {

	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not intializied.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 4)
			throw out_of_range("Requires at least (" + to_string(4) + ") data values.");

		if (datasetType)
		{
			long double n = size();
			long double fractionL = (n * (n + 1)) / ((n - 1) * (n - 2) * (n - 3));
			long double fractionR = (3 * (pow((n - 1), 2))) / ((n - 2) * (n - 3));
			long double sum = sumPowSubDiv(4, mean(), standardDeviation());
			sum = fractionL * sum;
			sum = sum - fractionR;
			return sum;
		}
		else // Population
		{
			return sumPowSub(4, mean()) / (size() * pow(standardDeviation(), 4)) - 3;
		}
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}

	
}

// Purpose			: Normalizes standard deviation by mean.
// Precondition		: dArr is not empty; mean != 0.
// Postcondition	: Returns σ/μ.
// Time Complexity	: O(n)
template<class T>
double Statistics<T>::coefficientOfVariation() const
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not initialized.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		if (dArr.size() < 2)
			throw out_of_range("Requires at least (" + to_string(2) + ") data values.");

		return (standardDeviation() / mean());
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
}

// Purpose			: Expresses standard deviation as a percentage of the mean.
// Precondition		: dArr is not empty; mean != 0.
// Postcondition	: Returns (σ/μ)*100.
// Time Complexity	: O(n)
template<class T>
double Statistics<T>::relativeStandardDeviation() const 
{
	try
	{
		if (dArr.ptr() == nullptr)
			throw invalid_argument("The array is not initialized.");

		if (dArr.size() == 0)
			throw out_of_range("Dataset is empty.");

		return abs((standardDeviation() / mean()) * 100);
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
	catch (out_of_range runtimeException)
	{
		set_txt_color(BrightRed);
		cout << "\n\tError: " << runtimeException.what() << "\n";
		reset_color();
	}
}

//============================================

// Purpose			: Displays frequency distribution of values.
// Precondition		: dArr is sorted; not empty.
// Postcondition	: Returns a map with {value -> count} pairs and prints the table.
// Time Complexity	: O(n log n) due to map insertions.
template<class T>
map<double, size_t > Statistics<T>::displayFrequencyTable() const
{
	map<double, size_t > frequencyTable;

	

	for (size_t index = 0; index < size(); index++)
	{
		frequencyTable[dArr[index]]++;
	}

	size_t setw1 = 15;
	cout  << setw(setw1) << "\n\tValue" << setw(setw1) << "Frequency" << setw(setw1) << "Frequency %";
	for (std::map<double,size_t>::iterator it = frequencyTable.begin(); it != frequencyTable.end(); ++it)
	{
		cout << "\n\t"
			<< setw(setw1) << ( to_string(it->first))<< setw(setw1) 
			<< ( to_string(it->second)) << setw(setw1) << (it->second/ static_cast<double>(size())) * 100;
	}

	
	return frequencyTable;
}

template<class T>
void Statistics<T>::displayOut(ostream& out)
{
	int setw_DisplayWidth = 31;

	out << setw(setw_DisplayWidth) << "\n\tMinimum" << "= "; out << minimum();
	out << setw(setw_DisplayWidth) << "\n\tMaximum" << "= "; out << maximum();
	out << setw(setw_DisplayWidth) << "\n\tRange" << "= "; out << range();
	out << setw(setw_DisplayWidth) << "\n\tSize" << "= "; out << size();
	out << setw(setw_DisplayWidth) << "\n\tSum" << "= "; out << sum();
	out << setw(setw_DisplayWidth) << "\n\tMean" << "= "; out << mean();
	out << setw(setw_DisplayWidth) << "\n\tMedian" << "= "; out << median();
	out << setw(setw_DisplayWidth) << "\n\tMode" << "= "; out << mode();
	out << setw(setw_DisplayWidth) << "\n\tStandard Deviation" << "= "; out << standardDeviation();
	out << setw(setw_DisplayWidth) << "\n\tVariance" << "= "; out << variance();
	out << setw(setw_DisplayWidth) << "\n\tMidrange" << "= "; out << midrange();



	//stats.quartiles();
	//stats.interquartile();
	//stats.outliers();
	//stats.sumOfSquares();
	//stats.meanAbsoluteDeviation();
	//stats.rootMeanSquare();
	//stats.standardErrorMean();

	out << setw(setw_DisplayWidth) << "\n\tSkewness" << "= "; out << skewness(); // Broken
	out << setw(setw_DisplayWidth) << "\n\tKurtosis" << "= "; out << kurtosis(); // Broken

	out << setw(setw_DisplayWidth) << "\n\tKurtosis Excess" << "= "; out << kurtosisExcess(); // Broken
	out << setw(setw_DisplayWidth) << "\n\tCoefficient Variation" << "= "; out << coefficientOfVariation(); // EH
	out << setw(setw_DisplayWidth) << "\n\tRelative Standard Deviation" << "= "; out << relativeStandardDeviation(); // EHHHH
	out << setw(setw_DisplayWidth) << "\n\tFrequency Table" << "= "; //displayFrequencyTable();
	out << "\n\n";
}

template<class T>
bool Statistics<T>::minDatasetSize(const int& minArraySize) const
{
	try
	{
		if (dArr.size() == 0)
			throw invalid_argument("Dataset is empty.") ;

		if (dArr.size() < minArraySize)
			throw invalid_argument("Requires at least (" + to_string(minArraySize) + ") data values.");
	}
	catch (invalid_argument runtimeException)
	{
		set_txt_color(Red);
		cout << "\n\tError: " << runtimeException.what() << "\n"; 
		reset_color();
	}

	return true;
}
#endif // !MATHMATICS


