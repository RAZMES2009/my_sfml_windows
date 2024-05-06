#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>

#include "./my_prot.h"

std::vector<std::vector<int64_t>> getCoordPoints()
{
    std::cout << "¬ведите натуральное число координаты точки х1,y1,...хn,yn: " << std::endl;
    std::vector<std::vector<int64_t>> tmpCoord;
    for (short i = 0;; i++)
    {
        printf("¬ведите x%i и y%i через пробел: ", i + 1, i + 1);
        std::string inputString, stringFirstNum, stringSecondNum;
        getline(std::cin, inputString);
        if (inputString == "" && tmpCoord.size() > 1)
            break;
        std::stringstream stringNum;
        stringNum << inputString;

        int64_t coordX, coordY;
        if (getline(stringNum, stringFirstNum, ' ') && getline(stringNum, stringSecondNum))
        {
            coordX = getMyNum(stringFirstNum, 1);
            coordY = getMyNum(stringSecondNum, 2);
        }
        else
        {
            std::cout << "ќшибка. ¬ведено неверное значение" << std::endl;
            i--;
            continue;
        }
        tmpCoord.push_back(std::vector<int64_t>{coordX, coordY});
    }
    return tmpCoord;
}