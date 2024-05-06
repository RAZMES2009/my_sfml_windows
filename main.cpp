#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "./my_prot.h"
#include "./app_window.h"

using namespace std;

#define SIZE_WIDTH 720

bool choice()
{
    string tmp;
    getline(cin, tmp);
    if (tmp.size() == 1 && (tmp[0] == 'y' || tmp[0] == 'n'))
        return tmp == "y" ? true : false;
    cout << "Неверное значение\n";
    return choice();
}

int main()
{
    system("chcp 1251"); // windows encode 1251

    while (1)
    {
        cout << "***************" << endl;

        cout << "Cчитать данные с файла? (y/n) ";
        bool isFileOpen = choice();
        string *s1 = new string("");
        string *s2 = new string("");
        vector<vector<int64_t>> coord;

        if (isFileOpen)
            coord = getCoordPointsFile(s1, s2);
        else
            coord = getCoordPoints();

        cout << "вывести данные в файл? (y/n) ";
        bool isFileClose = choice();
        fstream userOutputFile;
        if (isFileClose)
            userOutputFile = inputUserPath("./res/out.txt", false);

        bool *isPrintFirst = new bool(true), *isPrintSecond = new bool(true);
        vector<int64_t> twoPoint = getTwoPoint(coord, isPrintFirst, isPrintSecond,
                                               !isFileOpen ? false : true, userOutputFile,
                                               isFileClose ? true : false,
                                               !isFileOpen ? 0 : getMyNum(*s1, 1, true),
                                               !isFileOpen ? 0 : getMyNum(*s2, 2, true));

        delete s1;
        delete s2;

        if (!*isPrintFirst && !*isPrintSecond)
        {
            if (isFileOpen)
                break;

            cout << "Повторить? ";
            if (!choice())
                break;

            delete isPrintFirst;
            delete isPrintSecond;

            continue;
        }
        delete isPrintFirst;
        delete isPrintSecond;

        int scale = 1;
        for (scale;; scale++)
        {
            if (!(coord[twoPoint[0]][0] / scale >= SIZE_WIDTH || coord[twoPoint[0]][1] / scale >= SIZE_WIDTH || coord[twoPoint[1]][0] / scale >= SIZE_WIDTH || coord[twoPoint[1]][1] / scale >= SIZE_WIDTH))
                break;
        }

        if (isFileClose)
        {
            userOutputFile << "Масштаб изобрашения 1 к " << scale << endl;
            userOutputFile.close();
        }
        else
            cout << "Масштаб изобрашения 1 к " << scale << endl;

        AppWindow myAppWindow = AppWindow(coord, twoPoint, scale, SIZE_WIDTH);
        myAppWindow.runApp();

        if (isFileOpen)
            break;

        cout << "Повторить? ";
        if (!choice())
            break;
    }
    return 0; // windows
}