#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

std::fstream inputUserPath(std::string defaultPath, bool isOpen)
{
    std::string userFile;
    std::cout << "Введите путь к файлу: ";
    std::getline(std::cin, userFile);
    std::fstream myFile;
    if (userFile == "")
    {
        myFile.open(defaultPath, isOpen ? std::ifstream::in : std::ifstream::out);
        return myFile;
    }
    else
        myFile.open(userFile, isOpen ? std::ifstream::in : std::ifstream::out);

    if (myFile)
        return myFile;
    else
    {
        std::cout << "Неверно указан путь к файлу\n";
        return inputUserPath(defaultPath, isOpen);
    }
}