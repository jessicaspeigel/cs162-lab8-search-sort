/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_lab8_search_sort
** Date: 03/03/2018
** Description: 
****************************************************/

#include "HelperFunctions.hpp"
#include "InputValidation.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

/****************************************************
** Description: Searches a vector for a value using
** linear search.
****************************************************/

int linearSearch(vector<int> *values, int val) {
    // Set the default to -1, not found
    int searchResult = -1;
    // Start the search at index 0
    int index = 0;
    // Start the search
    while (index < values->size() && searchResult == -1) {
        if (values->at(index) == val) {
            searchResult = index;
        }
        index++;
    }

    return searchResult;
}

/****************************************************
** Description: Sorts a vector using selection sort.
** Adapted from C++ Early Objects p.619 to work
** with vector input and sort it in place.
****************************************************/

void selectionSort(vector<int> *values) {
    // Declare variables
    int startScan, minIndex, minValue;
    // Start the sort
    for (startScan = 0; startScan < (values->size() - 1); startScan++) {
        minIndex = startScan;
        minValue = values->at(startScan);
        // Inner loop
        for (int index = startScan + 1; index < values->size(); index++) {
            if (values->at(index) < minValue) {
                minValue = values->at(index);
                minIndex = index;
            }
        }
        values->at(minIndex) = values->at(startScan);
        values->at(startScan) = minValue;
    }
}

/****************************************************
** Description: Searches a vector using binary search.
** Adapted from C++ Early Objects p.609 to work
** with vector input.
****************************************************/

int binarySearch(std::vector<int> *values, int val) {
    // Set the default to -1, not found
    int searchResult = -1;
    // Declare variables
    int first = 0;
    int last = values->size() - 1;
    int middle;

    // Start the search
    while (first <= last && searchResult == -1) {
        middle = (first + last) / 2;
        if (values->at(middle) == val) {
            // Val is found in the middle
            searchResult = middle;
        } else if (values->at(middle) > val) {
            // val is in lower half
            last = middle - 1;
        } else {
            // val is in upper half
            first = middle + 1;
        }
    }

    return searchResult;
}
