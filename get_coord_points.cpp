#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>

#include "./my_prot.h"

std::vector<std::vector<int64_t>> getCoordPoints()
{
    std::cout << "������� ����������� ����� ���������� ����� �1,y1,...�n,yn: " << std::endl;
    std::vector<std::vector<int64_t>> tmpCoord;
    for (short i = 0;; i++)
    {
        printf("������� x%i � y%i ����� ������: ", i + 1, i + 1);
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
            std::cout << "������. ������� �������� ��������" << std::endl;
            i--;
            continue;
        }
        tmpCoord.push_back(std::vector<int64_t>{coordX, coordY});
    }
    return tmpCoord;
}