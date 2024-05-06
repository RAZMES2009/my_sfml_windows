#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdint>

int64_t getMyNum(std::string inputString, short count = 0, bool isFileOpen = false);
std::vector<std::vector<int64_t>> getCoordPoints();
bool isPrint(std::vector<std::vector<int64_t>> coord, int64_t firstPoint, int64_t secondPoint, bool is_i_j,
             bool isFileClose, std::fstream &userFile);
std::vector<int64_t> getTwoPoint(std::vector<std::vector<int64_t>> coord, bool *isPrintFirst, bool *isPrintSecond,
                                 bool isFileOpen, std::fstream &userFile, bool isFileClose,
                                 int64_t firstFilP = 0, int64_t secondFilP = 0);
std::fstream inputUserPath(std::string defaultPath, bool isOpen);
std::vector<std::vector<int64_t>> getCoordPointsFile(std::string *s1, std::string *s2);