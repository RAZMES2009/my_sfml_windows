#include <iostream>
#include <cstdint>
#include <string>

int64_t getMyNum(std::string inputString, short count, bool isFileOpen)
{
    try
    {
        bool minusFlag = false;
        for (int j = 0; j < inputString.size(); j++)
        {
            if (inputString[0] == '-' && !minusFlag)
            {
                minusFlag = true;
                continue;
            }
            if (!isdigit(inputString[j]))
                throw std::runtime_error("err");
        }
        return stoi(inputString);
    }
    catch (...)
    {
        if (isFileOpen)
        {
            std::cout << "�������� ���� ������ � �����" << std::endl;
            exit(1);
        }
        std::cout << "�������� ������� " << count << " �� ������� ������� �����������"
                                                     " ������� ����������� ��������"
                  << std::endl;
        std::getline(std::cin, inputString);
        return getMyNum(inputString, count, isFileOpen);
    }
}