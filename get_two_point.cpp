#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>
#include <fstream>

#include "./my_prot.h"

std::vector<int64_t> getTwoPoint(std::vector<std::vector<int64_t>> coord, bool *isPrintFirst, bool *isPrintSecond,
                                 bool isFileOpen, std::fstream &userFile, bool isFileClose,
                                 int64_t firstFilP, int64_t secondFilP)
{
    int64_t firstPoint, secondPoint;
    if (!isFileOpen)
    {
        std::cout << "¬ведите две разные точки через пробел: " << std::endl;
        while (1)
        {
            std::string inputString, stringFirstNum, stringSecondNum;
            getline(std::cin, inputString);
            std::stringstream stringNum;
            stringNum << inputString;

            if (getline(stringNum, stringFirstNum, ' ') && getline(stringNum, stringSecondNum))
            {
                firstPoint = getMyNum(stringFirstNum, 1, isFileOpen) - 1;
                secondPoint = getMyNum(stringSecondNum, 2, isFileOpen) - 1;
                if (firstPoint != secondPoint)
                    break;
            }
            std::cout << "ќшибка. ¬ведено неверное значение" << std::endl;
        }
    }
    else
    {
        firstPoint = firstFilP - 1;
        secondPoint = secondFilP - 1;
    }

    if (firstPoint < coord.size() && secondPoint < coord.size() && firstPoint > -1 && secondPoint > -1)
    {
        *isPrintFirst = isPrint(coord, firstPoint, secondPoint, true, isFileClose, userFile);
        *isPrintSecond = isPrint(coord, firstPoint, secondPoint, false, isFileClose, userFile);
    }
    else
    {
        std::cout << "ќшибка. ¬ведите существующие точки" << std::endl;
        if (!isFileOpen)
            return getTwoPoint(coord, isPrintFirst, isPrintSecond, false, userFile, isFileClose);
        exit(1);
    }
    return {firstPoint, secondPoint};
}