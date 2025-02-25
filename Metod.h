#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <string>
#include "InputEx.h"
#include "CLASS_EXEPTION.h"


using namespace std;

namespace Correct
{
    


    int GetCorrectInt(istream& is, int min, int max);

    string GetCorrectPassportNum(std::istream& is);

    string GetCorrectStr(istream& is);

    string GetCorrectStr2(istream& is);
    double GetCorrectDouble(std::istream& is, double min, double max);


};