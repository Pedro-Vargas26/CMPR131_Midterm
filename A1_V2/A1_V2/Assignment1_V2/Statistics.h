#pragma once
#ifndef STATISTICS
#define STATISTICS
//#include "DArray.h"
#include "DynamicArray.h"
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
	Statistics() {
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

	/*
	T quartiles() const;			//... may need to return a set...
	T interquartileRange() const; 
	T outliers() const;
	T sumOfSquares() const;
	T meanAbsoluteDeviation() const;
	T rootMeanSquare() const;
	T standardErrorMean() const;
	*/
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
double Statistics<T>::sumPow(const double & value, const double& exponent) const
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
		(Standard Deviation = √Variance)
	*/

	return sqrt(sumPow(mean(),2) / (size() - datasetType));
	
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

	return sumPow(mean(),2) / (size() - datasetType);
}

template<class T>
double Statistics<T>::midrange() const
{
	return (dArr.front() + dArr.back()) / 2.00;
}

//============================================

// L - R
//============================================

//template<class T>
//T Statistics<T>::quartiles() const;			//... may need to return a set...
//
//template<class T>
//T Statistics<T>::interquartileRange() const;
//
//template<class T>
//T Statistics<T>::outliers() const;
//
//template<class T>
//T Statistics<T>::sumOfSquares() const;
//
//template<class T>
//T Statistics<T>::meanAbsoluteDeviation() const;
//
//template<class T>
//T Statistics<T>::rootMeanSquare() const;
//
//template<class T>
//T Statistics<T>::standardErrorMean() const;
//============================================

// S - W
//============================================
template<class T>
double Statistics<T>::skewness() const
{
	if (datasetType)
	{
		return (size() / ((size() - 1) * (stsize() - 2))) * sumPowDiv(mean(), standardDeviation(), 3);
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
		return sumPow(mean(), 4) / (size() * pow(standardDeviation(), 4) ) -3;
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


