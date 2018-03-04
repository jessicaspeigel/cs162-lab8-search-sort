/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 Lab_8
** Date: 03/4/2018
** Description: Lab 8 main
****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Menu.hpp"
#include "InputValidation.hpp"
#include "HelperFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ios;

int main() {
    // MENU
//    vector<string> promptMenuItems = {"Yes", "No"};
//    Menu promptMenu(promptMenuItems);

    // READ VALUES FROM FILES AND STORE THEM IN VECTORS
    // Make vectors to hold the values from the text files
    vector<int> *values = new vector<int>;
    vector<int> *valuesEarly = new vector<int>;
    vector<int> *valuesMid = new vector<int>;
    vector<int> *valuesEnd = new vector<int>;

    // Make input file objects for each text file
    ifstream fileValues;
    ifstream fileValuesEarly;
    ifstream fileValuesMid;
    ifstream fileValuesEnd;
    // First read the text files
    fileValues.open("values.txt", ios::in);
    fileValuesEarly.open("values_early.txt", ios::in);
    fileValuesMid.open("values_middle.txt", ios::in);
    fileValuesEnd.open("values_end.txt", ios::in);
    // Make sure the file is in a good state
    if (fileValues && fileValuesEarly && fileValuesMid && fileValuesEnd) {
        // Make an int to hold the current value
        int num = 0, numEarly = 0, numMid = 0, numEnd = 0;
        // Add values to the appropriate vector
        while (fileValues >> num) {
            values->push_back(num);
        }
        while (fileValuesEarly >> num) {
            valuesEarly->push_back(num);
        }
        while (fileValuesMid >> num) {
            valuesMid->push_back(num);
        }
        while (fileValuesEnd >> num) {
            valuesEnd->push_back(num);
        }
        // Close the file
        fileValues.close();
        fileValuesEarly.close();
        fileValuesMid.close();
        fileValuesEnd.close();
    } else {
        cout << "An error occurred reading the files." << endl;
    }

    // PROMPT THE USER FOR A TARGET VALUE TO SEARCH FOR
    int target = getInteger("What target value would you like to search for?");

    // SEARCH EACH VECTOR FOR THE USER-SPECIFIED TARGET
    // We use linear search here because the lists aren't yet sorted, and it would be slower to sort THEN search
    // Search each file separately
    int searchResultValues = linearSearch(values, target);
    int searchResultValuesEarly = linearSearch(valuesEarly, target);
    int searchResultValuesMid = linearSearch(valuesMid, target);
    int searchResultValuesEnd = linearSearch(valuesEnd, target);
    // Output the results for each file
    cout << "values.txt: ";
    if (searchResultValues > -1) {
        cout << target << " found at position " << searchResultValues;
    } else {
        cout << target << " not found.";
    }
    cout << endl;
    // Output the results for each file
    cout << "values_early.txt: ";
    if (searchResultValuesEarly > -1) {
        cout << target << " found at position " << searchResultValuesEarly;
    } else {
        cout << target << " not found.";
    }
    cout << endl;
    // Output the results for each file
    cout << "values_middle.txt: ";
    if (searchResultValuesMid > -1) {
        cout << target << " found at position " << searchResultValuesMid;
    } else {
        cout << target << " not found.";
    }
    cout << endl;
    // Output the results for each file
    cout << "values_end.txt: ";
    if (searchResultValuesEnd > -1) {
        cout << target << " found at position " << searchResultValuesEnd;
    } else {
        cout << target << " not found.";
    }
    cout << endl;

    // SORT THE VECTORS, DISPLAY THEM, AND SAVE THEM
    // Sort each vector separately
    selectionSort(values);
    selectionSort(valuesEarly);
    selectionSort(valuesMid);
    selectionSort(valuesEnd);

    int i;
    cout << "Values sorted!" << endl << endl;
    // Create an output file object
    ofstream valuesOutputFile ("values_sorted.txt");
    cout << "New order of values vector:" << endl;
    i = 0;
    while (i < values->size()) {
        cout << values->at(i) << endl;
        valuesOutputFile << values->at(i) << "\n";
        i++;
    }
    // Close the file
    valuesOutputFile.close();
    cout << "values_sorted.txt written." << endl;
    cout << endl;
    cout << "New order of valuesEarly vector:" << endl;
    i = 0;
    // Create an output file object
    ofstream valuesEarlyOutputFile ("values_early_sorted.txt");
    while (i < valuesEarly->size()) {
        cout << valuesEarly->at(i) << endl;
        valuesEarlyOutputFile << valuesEarly->at(i) << "\n";
        i++;
    }
    // Close the file
    valuesEarlyOutputFile.close();
    cout << "values_early_sorted.txt written." << endl;
    cout << endl;
    cout << "New order of valuesMiddle vector:" << endl;
    i = 0;
    // Create an output file object
    ofstream valuesMidOutputFile ("values_middle_sorted.txt");
    while (i < valuesMid->size()) {
        cout << valuesMid->at(i) << endl;
        valuesMidOutputFile << valuesMid->at(i) << "\n";
        i++;
    }
    // Close the file
    valuesMidOutputFile.close();
    cout << "values_middle_sorted.txt written." << endl;
    cout << endl;
    cout << "New order of valuesEnd vector:" << endl;
    i = 0;
    // Create an output file object
    ofstream valuesEndOutputFile ("values_end_sorted.txt");
    while (i < valuesEnd->size()) {
        cout << valuesEnd->at(i) << endl;
        valuesEndOutputFile << valuesEnd->at(i) << "\n";
        i++;
    }
    // Close the file
    valuesEndOutputFile.close();
    cout << "values_end_sorted.txt written." << endl;
    cout << endl;

    // BINARY SEARCH

    // Prompt the user for a target value to search for
    target = getInteger("What target value would you like to binary search for?");
    // Search each file separately
    searchResultValues = binarySearch(values, target);
    searchResultValuesEarly = binarySearch(valuesEarly, target);
    searchResultValuesMid = binarySearch(valuesMid, target);
    searchResultValuesEnd = binarySearch(valuesEnd, target);
    // Output the results for each file
    cout << "values_sorted.txt: ";
    if (searchResultValues > -1) {
        cout << target << " found at position " << searchResultValuesEarly;
    } else {
        cout << target << " not found.";
    }
    cout << endl;
    // Output the results for each file
    cout << "values_early_sorted.txt: ";
    if (searchResultValuesEarly > -1) {
        cout << target << " found at position " << searchResultValuesEarly;
    } else {
        cout << target << " not found.";
    }
    cout << endl;
    // Output the results for each file
    cout << "values_middle_sorted.txt: ";
    if (searchResultValuesMid > -1) {
        cout << target << " found at position " << searchResultValuesMid;
    } else {
        cout << target << " not found.";
    }
    cout << endl;
    // Output the results for each file
    cout << "values_end_sorted.txt: ";
    if (searchResultValuesEnd > -1) {
        cout << target << " found at position " << searchResultValuesEnd;
    } else {
        cout << target << " not found.";
    }
    cout << endl;

    // CLEANUP
    // Delete the vectors
    delete values;
    delete valuesEarly;
    delete valuesMid;
    delete valuesEnd;

    return 0;
}