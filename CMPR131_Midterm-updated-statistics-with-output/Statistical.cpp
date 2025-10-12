#include "Statistical.h"
#include "DynamicArray.h"

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

#include <cmath> // for floor
#include <vector>

using namespace std;

Statistical::Statistical(const DynamicArray<int>& data) : dataset(data) {}

double Statistical::mean() const
{
    int size = dataset.size();
    if (size == 0) throw std::exception("Exception ERROR: Dataset is empty. ");

    double sum = 0.0;
    for (int i = 0; i < size; ++i)
        sum += dataset.retrieve(i);

    return sum / size;
}

double Statistical::variance(bool sample) const
{
    int n = dataset.size();
    if (n == 0)
        throw std::exception("\n\tEXCEPTION ERROR: Dataset is empty.\n");
    if (sample && n < 2)
        throw std::exception("\n\tEXCEPTION ERROR: Sample variance requires at least 2 values.\n");

    double m = mean();
    double totalSquaredDiff = 0.0;

    for (int i = 0; i < n; ++i) {
        double diff = dataset.retrieve(i) - m;
        totalSquaredDiff += diff * diff;
    }

    return sample ? (totalSquaredDiff / (n - 1))
        : (totalSquaredDiff / n);
}

double Statistical::standardDeviation(bool sample) const
{
    return std::sqrt(variance(sample));
}


double Statistical::midRange()
{
    int size = dataset.size();
    if (size == 0)
        throw std::exception("\n\tException ERROR: Dataset is empty. \n");

    double minVal = dataset.retrieve(0);
    double maxVal = dataset.retrieve(0);

    for (int i = 1; i < size; ++i)
    {
        double val = dataset.retrieve(i);
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
    }
    return (minVal + maxVal) / 2.0;
}

double Statistical::quartiles()
{
    int size = dataset.size();
    double q1 = 0, q2 = 0, q3 = 0, iqr = 0;

    if (size == 0)
        throw std::exception("\n\tERROR: Not enough values in dataset.\n");
    else if (size == 1) {
        throw std::exception("\n\tERROR: At least 2 values required to compute quartiles.\n");
    }

    int* sortedArr = new int[size];
    for (int i = 0; i < size; ++i)
        sortedArr[i] = dataset.retrieve(i);

    if (size == 2) {
        q2 = median(sortedArr, 0, 1);
        std::cout << "\n\tQ1 = empty";
        std::cout << "\n\tQ2 = " << q2;
        std::cout << "\n\tQ3 = empty";

    }
    else {
        q1 = median(sortedArr, 0, (size - 1) / 2);
        q2 = median(sortedArr, 0, size - 1);
        q3 = median(sortedArr, (size + 1) / 2, size - 1);
        iqr = q3 - q1;

        std::cout << "\n\tQ1 = " << q1;
        std::cout << "\n\tQ2 = " << q2;
        std::cout << "\n\tQ3 = " << q3;
        std::cout << "\n\t Interquartile = " << iqr;
    }

    delete[] sortedArr;
    return iqr;
}

double Statistical::outliers()
{
    int size = dataset.size();
    if (size < 4)
        throw std::exception("\n\tException ERROR: Dataset must contain more values. \n");

    int* sortedArr = new int[size];
    for (int i = 0; i < size; ++i)
        sortedArr[i] = dataset.retrieve(i);

    double q1 = median(sortedArr, 0, (size - 1) / 2);
    double q3 = median(sortedArr, (size + 1) / 2, size - 1);
    double iqr = q3 - q1;

    double lowerBound = q1 - 1.5 * iqr;
    double upperBound = q3 + 1.5 * iqr;

    int count = 0;
    bool foundOutlier = false;
    for (int i = 0; i < size; ++i)
    {
        double val = dataset.retrieve(i);
        if (val < lowerBound || val > upperBound)
        {
            std::cout << val << " ";
            foundOutlier = true;
        }
    }
    if (!foundOutlier)
        std::cout << setw(30) << "\tNo outliers detected.";

    std::cout << std::endl;
    delete[] sortedArr;
    return count;
}

double Statistical::SumOfSquares()
{
    int size = dataset.size();
    if (size == 0)
        throw std::exception("\n\tException ERROR: INVALID DATASET SIZE. \n");

    double mean = 0.0;
    for (int i = 0; i < size; ++i)
        mean += dataset.retrieve(i);

    mean /= size;

    double sumSquares = 0.0;
    for (int i = 0; i < size; ++i)
    {
        double diff = dataset.retrieve(i) - mean;
        sumSquares += diff * diff;
    }

    return sumSquares;
}

double Statistical::median(int arr[], int start, int end)
{
    int length = end - start + 1;
    int mid = start + length / 2;

    if (length % 2 == 0)
        return (arr[mid - 1] + arr[mid]) / 2.0;
    else
        return arr[mid];
}

double Statistical::meanAbsoluteDeviation() {
    int size = dataset.size();
    if (size == 0) throw std::exception("\n\tEXCEPTION ERROR:  Dataset must contain more values. \n");

    double m = Statistical::mean();

    double sumAbsoluteDiff = 0.0;
    for (int i = 0; i < size; ++i) {
        sumAbsoluteDiff += std::fabs(dataset.retrieve(i) - m);
    }

    return sumAbsoluteDiff / size;
}

double Statistical::rootMeanSquare() {
    int n = dataset.size();
    if (n == 0) throw std::exception("\n\tException Error: Dataset must contain more values. \n");

    double sumSquares = 0.0;
    for (int i = 0; i < n; ++i) {
        double val = dataset.retrieve(i);
        sumSquares += val * val;
    }

    return std::sqrt(sumSquares / n);
}

double Statistical::minimum()
{
    double minVal = dataset.retrieve(0);
    return minVal;
}

double Statistical::maximum()
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
    }
    return dataset.retrieve(dataset.size() - 1);
}

double Statistical::range()
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
    }

    double minVal = dataset.retrieve(0);
    double maxVal = dataset.retrieve(dataset.size() - 1);
    return maxVal - minVal;
}

double Statistical::sum()
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
    }

    double sum = 0.0;
    for (int i = 0; i < dataset.size(); i++)
    {
        sum += dataset.retrieve(i);
    }

    return sum;
}

double Statistical::median()
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
    }

    double median = 0.0;
    median = dataset.retrieve(dataset.size() / 2);
    if (dataset.size() % 2 == 0)
    {
        median = (median + dataset.retrieve(dataset.size() / 2 - 1)) / 2;
    }

    return median;
}

double* Statistical::mode(int& modeCount)
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
    }

    int maxCount = 1;
    int currentCount = 1;

    // First pass: find the highest frequency
    for (int i = 1; i < dataset.size(); i++)
    {
        if (dataset.retrieve(i) == dataset.retrieve(i - 1))
            currentCount++;
        else
            currentCount = 1;

        if (currentCount > maxCount)
            maxCount = currentCount;
    }

    // Second pass: count how many numbers appear maxCount times
    currentCount = 1;
    modeCount = 0;
    for (int i = 1; i <= dataset.size(); i++)
    {
        if (i < dataset.size() && dataset.retrieve(i) == dataset.retrieve(i - 1))
            currentCount++;
        else
        {
            if (currentCount == maxCount)
                modeCount++;

            currentCount = 1;
        }
    }

    // Allocate dynamic array to hold the modes
    double* modes = new double[modeCount];

    // Third pass: fill the array
    currentCount = 1;
    int index = 0;
    for (int i = 1; i <= dataset.size(); i++)
    {
        if (i < dataset.size() && dataset.retrieve(i) == dataset.retrieve(i - 1))
            currentCount++;
        else
        {
            if (currentCount == maxCount)
                modes[index++] = dataset.retrieve(i - 1);

            currentCount = 1;
        }
    }

    return modes; // caller must delete[]
}
double Statistical::standardErrorOfMean(bool sample) const {
    double p_standard_Dev = standardDeviation(sample);
    int p_size = dataset.size();
    if (p_size == 0) throw std::exception("ERROR: EMPTY DATASET");
    return p_standard_Dev / sqrt(p_size);
}

double Statistical::skewness(bool sample) const {
    int p_size = dataset.size();
    if (p_size < 2) throw std::exception("ERROR: INVALID DATASET SIZE");

    double p_mean = mean();
    double p_standard_Dev = standardDeviation(sample);
    if (p_standard_Dev == 0.0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < p_size; i++) {
        sum += pow((dataset.retrieve(i) - p_mean) / p_standard_Dev, 3);
    }

    if (sample) {
        if (p_size < 3) throw std::exception("ERROR: NEED AT LEAST 3 ENTRIES FOR SKEWNESS");
        return (static_cast<double>(p_size) / ((p_size - 1) * (p_size - 2))) * sum;
    }
    else {
        // Population skewness
        return sum / p_size;
    }
}

double Statistical::kurtosis(bool sample) const {
    int p_size = dataset.size();
    if (p_size < 2) throw std::exception("ERROR: INVALID DATASET SIZE");

    double p_mean = mean();
    double p_standard_Dev = standardDeviation(sample);
    if (p_standard_Dev == 0.0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < p_size; i++) {
        sum += pow((dataset.retrieve(i) - p_mean) / p_standard_Dev, 4);
    }

    if (sample) {
        if (p_size < 4) throw std::exception("ERROR: 4 ENTRIES IN DATASET REQUIRED. ");
        double numerator = (p_size * (p_size + 1)) * sum;
        double denominator = (p_size - 1) * (p_size - 2) * (p_size - 3);
        double offset = (3.0 * (p_size - 1) * (p_size - 1)) / ((p_size - 2) * (p_size - 3));
        return (numerator / denominator) - offset;
    }
    else {
        // Population kurtosis
        return sum / p_size;
    }
}

double Statistical::kurtosisExcess(bool sample) const {
    return kurtosis(sample) - 3.0;
}

double Statistical::coefficientVariation(bool sample) const {
    double p_mean = mean();
    if (p_mean == 0.0) throw std::exception("ERROR: INVALID DATA PRESENTED. ");
    return standardDeviation(sample) / p_mean;
}

double Statistical::relativeStandardDeviation(bool sample) const {
    double p_mean = mean();
    if (p_mean == 0.0) throw std::exception("ERROR: INVALID DATA PRESENTED. ");
    return (standardDeviation(sample) / p_mean) * 100.0;
}

unordered_map<int, int> Statistical::getFrequency() {
    unordered_map<int, int> freq;
    for (int i = 0; i < dataset.size();i++) {
        freq[dataset.retrieve(i)]++;
    }
    return freq;
}
