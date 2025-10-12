#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include <unordered_map>
#pragma once

#ifndef STATSTICAL_H
#define STATISTICAL_H
class Statistical {
private:
    DynamicArray<int> dataset;
    double median(int arr[], int start, int end);

public:
    Statistical(const DynamicArray<int>& dataset);

    /*Anthony's Portion*/
    double minimum();
    double maximum();
    double range();
    double sum();
    double mean() const;
    double median();
    double* mode(int& modeCount);

    /*Daisy's Portion*/
    double variance(bool sample = true) const;    
    double standardDeviation(bool sample = true) const;  
    double midRange();
    double quartiles();
    double outliers();
    double SumOfSquares();
    double meanAbsoluteDeviation();
    double rootMeanSquare();

    /*Pedro's Portion*/
    double standardErrorOfMean(bool sample = true) const; 
    double skewness(bool sample = true) const;             
    double kurtosis(bool sample = true) const;             
    double kurtosisExcess(bool sample = true) const;
    double coefficientVariation(bool sample = true) const;
    double relativeStandardDeviation(bool sample = true) const;
    std::unordered_map<int, int> getFrequency();

};


#endif

