#pragma once
#include "CLASS_EXEPTION.h"


// Класс для обработки исключений ввода
class InputException : public Exception
{
public:
    // Конструкторы
    explicit InputException(const string& msg, ErrorID id);
    explicit InputException(const char* msg, ErrorID id);
};