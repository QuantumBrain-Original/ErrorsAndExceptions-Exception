#include <iostream>
#include <cstring>
#include <exception>
#include <Windows.h>

#define cPRINTs std::cout <<
#define cPRINTe << std::endl
#define cINPUT std::cin >>

int function(std::string &str, int &forbidden_length)
{
    if (str.length() == forbidden_length)
        throw std::exception("Вы ввели слово запретной длины! До свидания");

    return str.length();
}

int main()
{
//    SetConsoleCP(CP_UTF8);
//    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str_word;
    static int const_lenght = 0, current_lenght = 0;
    cPRINTs "Введите запретную длину: ";
    cINPUT const_lenght;

    while (true)
    {
        cPRINTs "Введите слово: ";
        cINPUT str_word;

        try
        {
            current_lenght = function(str_word, const_lenght);
            cPRINTs "Длина слова \"" << str_word << "\" равна " << current_lenght cPRINTe;
        }
        catch (const std::exception& bad_length)
        {
            cPRINTs bad_length.what() cPRINTe;
            break;
        }
    }
}
