#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>
#include <cmath>
#include <fstream>

inline int64_t toInt64(double x)
{
    int64_t a;
    memcpy(&a, &x, 8);
    uint64_t mask = (uint64_t)(a >> 63) >> 1;
    return a ^ mask;
}

inline bool isSmaller(double x1, double x2)
{
    return toInt64(x1) < toInt64(x2);
}

bool isPrint(std::vector<std::vector<int64_t>> coord, int64_t firstPoint, int64_t secondPoint, bool is_i_j,
             bool isFileClose, std::fstream &userFile)
{
    int64_t distanceX_ij = abs(coord[secondPoint][0]) - abs(coord[firstPoint][0]);
    int64_t distanceY_ij = abs(coord[secondPoint][1]) - abs(coord[firstPoint][1]);
    double distance_ij = sqrt(pow(distanceX_ij, 2) + pow(distanceY_ij, 2));

    if (is_i_j)
    {
        if (isFileClose)
            userFile << "дистанция между i и j = " << distance_ij << std::endl;
        else
            std::cout << "дистанция между i и j = " << distance_ij << std::endl;
    }

    uint64_t secondArg = is_i_j ? firstPoint : secondPoint;
    for (int j = 0; j < coord.size(); j++)
    {
        if (j == firstPoint || j == secondPoint)
            continue;
        distanceX_ij = abs(coord[j][0]) - abs(coord[secondArg][0]);
        distanceY_ij = abs(coord[j][1]) - abs(coord[secondArg][1]);

        double buffDistance_ij = sqrt(pow(distanceX_ij, 2) + pow(distanceY_ij, 2));
        if (isSmaller(distance_ij, buffDistance_ij))
        {
            std::stringstream errMsg;
            std::string firSec = is_i_j ? "первое " : "второе ";
            errMsg << "не выполняется " << firSec << "условие, так как дистанция между точкой "
                   << secondArg + 1 << " и " << j + 1 << " больше или равно дистанции между точками "
                   << firstPoint + 1 << " и " << secondPoint + 1 << std::endl;

            if (!isFileClose)
                std::cout << errMsg.str();
            else
                userFile << errMsg.str();
            return false;
        }
    }
    return true;
}