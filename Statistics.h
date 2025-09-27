#pragma once
#ifndef STATISTICS
#define STATISTICS
//#include "DArray.h"
#include "DynamicArray.h"
#include <cmath>
#include "input.h"



template<class T>
class Statistics
{
private:
	// Placeholder for the array


	// This should only be two states
	bool datasetType; // true is sample, False is population

	// For quartiles, This should be swapped to a function in the future... Data may stagnate and not properly reflect new changes...
	// Maybe using pair<string, int> [] to store the values would work
	// int q1; q2; q3;

public:

	DynamicArray<T> dArr;
	// Constructor
	Statistics() 
	{
		datasetType = true;
	};

	// Destructor
	~Statistics() {};

	// OTHER ASSIGNMENT AND COPY CONSTRUCTORS... IN THE FUTURE?

	// SCOPE : Handles all the array functions.
public:

	//
	bool setDatasetType(const bool& populationOrSample) { datasetType = populationOrSample; return datasetType; }
	bool getDatasetType() const { return datasetType; }

	// Accessors
public:

	//Precondition :
	//Postcondition:

	// A - E
	//============================================
	T minimum() const; // 0 for the start
	T maximum() const; // Sorted arr max index
	double range() const;   // Min val to max val is the range.
	size_t size() const; // THis is basically how populated the array is or how many elements are in it.
	T sum() const; // Add all the elements 
	double sumPow(const double& value, const double& exponent) const; // This is just a placeholder for the functions that require a - 1 or 3 for their specific functions.
	double sumPowDiv(const double& value, const double& divisior, const double& exponent) const;
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
	void quartiles() const;			//... may need to return a set...
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
	double coeficientOfVariation() const;
	double relativeStandardDeviation() const;
	//============================================


};



// A - E
//============================================

template<class T>
T Statistics<T>::minimum() const
{
	return dArr.front();
}

template<class T>
T Statistics<T>::maximum() const
{
	return dArr.back();
}

template<class T>
double Statistics<T>::range() const
{
	return dArr.back() - dArr.front();
}

template<class T>
size_t Statistics<T>::size() const
{
	return dArr.size();
}

template<class T>
T Statistics<T>::sum() const
{
	T temp = 0;
	for (size_t index = 0; index < dArr.size(); index++)
	{
		temp += dArr[index];
	}

	return temp;
}

template<class T>
double Statistics<T>::sumPow(const double& value, const double& exponent) const
{
	T temp = 0;
	for (size_t index = 0; index < dArr.size(); index++)
	{
		temp += pow((dArr[index] - value), exponent);
	}

	return temp;
}

template<class T>
double Statistics<T>::sumPowDiv(const double& value, const double& divisor, const double& exponent) const
{
	T temp = 0;

	for (size_t index = 0; index < dArr.size(); index++)
	{
		temp += (pow((dArr[index] - value), exponent)) / divisor;
	}

	return temp;
}

//============================================

// F - K
//============================================

template<class T>
double Statistics<T>::mean() const
{
	if (!(dArr.empty()))
		return sum() / static_cast<double>(dArr.size());
	else
		return 0.0;
}

template<class T>
double Statistics<T>::median() const
{
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

template<class T>
double Statistics<T>::mode() const // Ill rewrite this to a pair function later to return the specific value and the number of times it appears.
{
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

template<class T>
double Statistics<T>::standardDeviation() const
{

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
		(Standard Deviation = ?Variance)
	*/

	return sqrt(sumPow(mean(), 2) / (size() - datasetType));

}

template<class T>
double Statistics<T>::variance() const
{

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

	return sumPow(mean(), 2) / (size() - datasetType);
}

template<class T>
double Statistics<T>::midrange() const
{
	return (dArr.front() + dArr.back()) / 2.00;
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
		cout << "\n\tSum of Squares              = unknown\n\n";
		return;
	}

	double m = mean();
	double sos = sumPow(m, 2);

	cout << "\n\tSum of Squares              = " << sos << "\n\n";
}

//precondition: data set must have at least 2 values 
//postcondition: calculates and displays mean absolute deviation
template<class T>
void Statistics<T>::meanAbsoluteDeviation() const
{
	size_t n = dArr.size();

	if (n < 2)
	{
		cout << "\n\tMean Absolute Deviation     = unknown\n\n";
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
		cout << "\n\tRoot Mean Square            = unknown\n\n";
		return;
	}
	
	double rms = 0.0;
	double squaredValuesAdded = 0.0;

	for (size_t i = 0; i < n; i++)
	{
		squaredValuesAdded += pow(dArr[i], 2);
	}

	rms = sqrt((squaredValuesAdded / n));

	cout << "\n\tRoot Mean Square            = " << rms << "\n\n";

}

//precondition: data set must have at least 2 values 
//postcondition: calculates amd displays standard error mean 
template<class T>
void Statistics<T>::standardErrorMean() const
{
	size_t n = dArr.size();

	if (n < 2)
	{
		cout << "\n\tStandard Error of the Mean  = unknown\n\n";
		return;
	}

	double s = standardDeviation();
	double sem = s / (sqrt(n));
	cout << "\n\tStandard Error of the Mean  = " << sem << "\n\n";
}
//============================================

// S - W
//============================================
template<class T>
double Statistics<T>::skewness() const
{
	if (datasetType)
	{
		return (size() / ((size() - 1) * (size() - 2))) * sumPowDiv(mean(), standardDeviation(), 3);
	}
	else // Population
	{
		return sumPow(mean(), 3) / (size() * pow(standardDeviation(), 3));
	}
}

template<class T>
double Statistics<T>::kurtosis() const {

	if (datasetType)
	{
		return 0.0;//return (size() / ((size() - 1) * (size() - 2) * (size() - 3)) * sumPowDiv(mean(), standardDeviation(), 4));
	}
	else // Population
	{
		return sumPow(mean(), 4) / (size() * pow(standardDeviation(), 4));
	}
}

template<class T>
double Statistics<T>::kurtosisExcess() const {

	if (datasetType)
	{
		return 0.0;
	}
	else // Population
	{
		return sumPow(mean(), 4) / (size() * pow(standardDeviation(), 4)) - 3;
	}
}

template<class T>
double Statistics<T>::coeficientOfVariation() const
{
	return (standardDeviation() / mean());
}

template<class T>
double Statistics<T>::relativeStandardDeviation() const
{
	return abs((standardDeviation() / mean()) * 100);
}
//============================================
#endif // !MATHMATICS


