#include "InputEx.h"

// Конструктор с параметром типа string
InputException::InputException(const string& msg, ErrorID id)
    : Exception(msg, id) // Вызов конструктора родительского класса
{
}

// Конструктор с параметром типа const char*
InputException::InputException(const char* msg, ErrorID id)
    : Exception(msg, id) // Вызов конструктора родительского класса
{
}