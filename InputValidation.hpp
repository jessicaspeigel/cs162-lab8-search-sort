/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 Lab_5
** Date: 02/06/2018
** Description: Input validation header.
****************************************************/

#ifndef LAB_5_INPUTVALIDATION_HPP
#define LAB_5_INPUTVALIDATION_HPP

#include <iostream>
#include <string>

int getInteger(std::string promptText);

int getIntegerWithMin(std::string promptText, int minVal);

int getIntegerWithMinMax(std::string promptText, int minVal, int maxVal);

std::string getString(std::string promptText, int minLength = 1);


#endif //LAB_5_INPUTVALIDATION_HPP
