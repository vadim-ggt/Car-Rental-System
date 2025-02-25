#include "Metod.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

namespace Correct 
{


    int GetCorrectInt(istream& is, int min, int max)
    {
        int value;
        while (true)
        {
            is >> value;
            try
            {
                if (is.fail())
                {
                    is.clear();
                    is.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw InputException("Not a number", ErrorID::INVALID_INPUT);
                }

                char check;
                if (is.get(check) && !isspace(check))
                {
                    is.clear();
                    is.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw InputException("Input contains invalid character", ErrorID::INVALID_INPUT);
                }

                if (value < min || value > max)
                {
                    throw InputException("Number out of range", ErrorID::OUT_OF_RANGE);
                }

                break;
            }
            catch (const InputException& error)
            {
                is.clear();
                error.ErrorOut();
                continue;
            }
        }

        return value;
    }

  



    string GetCorrectPassportNum(std::istream& is)
    {
        while (true)
        {
            try
            {
                std::cout << "Введите пасспортные данные: ";
                string input;
                is >> input;

                if (input.size() != 9)
                {
                    throw InputException("Passport number must have exactly 9 characters (XX0000000).", ErrorID::INVALID_FORMAT);
                }

                for (size_t i = 0; i < 2; ++i)
                {
                    if (!isupper(static_cast<unsigned char>(input[i])) || !isalpha(static_cast<unsigned char>(input[i])))
                    {
                        throw InputException("The first two characters must be uppercase English letters.", ErrorID::INVALID_FORMAT);
                    }
                }

                for (size_t i = 2; i < input.size(); ++i)
                {
                    if (!isdigit(static_cast<unsigned char>(input[i])))
                    {
                        throw InputException("The last seven characters must be numeric.", ErrorID::INVALID_FORMAT);
                    }
                }

                return input;
            }
            catch (const InputException& error)
            {
                is.clear();
                error.ErrorOut();
                continue;
            }
        }
    }






    string GetCorrectStr(istream& is)
    {
        string input;
        string invalidChars = "+-?:%:?.*"; // Запрещенные символы

        while (true) {
            getline(is, input);

            // Проверяем, чтобы строка не была пустой
            if (input.empty()) {
                cerr << "Ошибка: строка не может быть пустой. Попробуйте снова: ";
                continue;
            }

            // Проверяем, чтобы строка не содержала запрещенных символов
            if (input.find_first_of(invalidChars) != string::npos) {
                cerr << "Ошибка: строка содержит недопустимые символы. Попробуйте снова: ";
                continue;
            }

            // Если все проверки пройдены, возвращаем строку
            return input;
        }
    }



    string GetCorrectStr2(istream& is)
    {
        string input;
        string invalidChars = "+-?:%:?.*"; // Запрещенные символы

        while (true) {
            getline(is, input);

           
            // Проверяем, чтобы строка не содержала запрещенных символов
            if (input.find_first_of(invalidChars) != string::npos) {
                cerr << "Ошибка: строка содержит недопустимые символы. Попробуйте снова: ";
                continue;
            }

            // Если все проверки пройдены, возвращаем строку
            return input;
        }
    }




    double GetCorrectDouble(std::istream& is, double min, double max)
    {
        double value;
        while (true)
        {
            is >> value;
            try
            {
                // Проверка на ошибку при вводе
                if (is.fail())
                {
                    is.clear(); // Очистить флаг ошибки
                    is.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорировать оставшийся ввод
                    throw InputException("Not a valid number", ErrorID::INVALID_INPUT);
                }

                // Проверка на дополнительные символы после числа
                char check;
                if (is.get(check) && !isspace(check)) // Если после числа есть дополнительные символы
                {
                    is.clear(); // Очистить флаг ошибки
                    is.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорировать оставшийся ввод
                    throw InputException("Input contains invalid characters", ErrorID::INVALID_INPUT);
                }

                // Проверка на диапазон чисел
                if (value < min || value > max)
                {
                    throw InputException("Number out of range", ErrorID::OUT_OF_RANGE);
                }
    
                break; // Если все проверки пройдены, выход из цикла
            }
            catch (const InputException& error)
            {
                is.clear(); // Очистить флаг ошибки после обработки исключения
                error.ErrorOut(); // Вывод сообщения об ошибке
                continue; // Продолжить ввод
            }
        }

        return value;
    }






}