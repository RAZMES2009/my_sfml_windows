#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>
#include <fstream>

#include "./my_prot.h"

using namespace std;

vector<vector<int64_t>> getCoordPointsFile(string *s1, string *s2)
{
    fstream input = inputUserPath("./res/in.txt", true);
    string myArrFile;
    vector<vector<int64_t>> returnCoord;
    while (getline(input, myArrFile, '\n') && getline(input, *s1, ' ') && getline(input, *s2))
    {
        string tmpNum = "";
        int64_t j = 0;
        int32_t count = 0;
        vector<int64_t> tmpCoord;
        for (char i : myArrFile)
        {
            count++;
            if (i == ',' || i == ';' || count == myArrFile.size())
            {
                if (count == myArrFile.size())
                {
                    tmpNum += i;
                    tmpCoord.push_back(getMyNum(tmpNum, 1, true));
                    returnCoord.push_back(tmpCoord);
                    break;
                }
                tmpCoord.push_back(getMyNum(tmpNum, 1, true));
                if (i == ';')
                {
                    if (j != 1)
                    {
                        cout << "Неверный ввод данных в файле" << endl;
                        exit(1);
                    }
                    returnCoord.push_back(tmpCoord);
                    tmpCoord.clear();
                    j = 0;
                }
                else
                    j++;

                tmpNum = "";
            }
            else
                tmpNum += i;
        }
    }
    input.close();
    return returnCoord;
}