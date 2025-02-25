#include "CLASS_EXEPTION.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;


// Реализация метода ErrorOut
void Exception::ErrorOut() const
{
    cerr << "[Error " << static_cast<int>(errorID) << "] " << errorMsg << endl;
}

// Реализация метода GetErrorID
ErrorID Exception::GetErrorID() const
{
    return errorID;
}

// Конструктор по умолчанию
Exception::Exception() noexcept
    : errorMsg("Unknown error"), errorID(ErrorID::INVALID_INPUT)
{
}

// Конструктор с параметрами
Exception::Exception(const string& msg, ErrorID id) noexcept
    : errorMsg(msg), errorID(id)
{
}

// Конструктор копирования
Exception::Exception(const Exception& other) noexcept
    : errorMsg(other.errorMsg), errorID(other.errorID)
{
}

// Деструктор
Exception::~Exception()
{
}

// Оператор присваивания
Exception& Exception::operator=(const Exception& other) noexcept
{
    if (this != &other)
    {
        errorMsg = other.errorMsg;
        errorID = other.errorID;
    }
    return *this;
}