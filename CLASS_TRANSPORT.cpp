#include "CLASS_TRANSPORT.h"
#include <string>
#include <iostream>
#include <iomanip>

Transport::Transport()
    : id(0), name("Undefined"), dailyRate(0.0), isAvailable(true), inReq(false) {}

// Конструктор
Transport::Transport(int id, const std::string& name, double dailyRate, bool isAvailable, bool inReq)
    : id(id), name(name), dailyRate(dailyRate), isAvailable(isAvailable), inReq(inReq) {}

Transport::Transport(const Transport& other)
    : id(other.id), name(other.name), dailyRate(other.dailyRate), isAvailable(other.isAvailable), inReq(inReq) {} ///

// Виртуальный деструктор
Transport::~Transport() {}

// Геттеры
int Transport::getId() const {
    return id;
}

std::string Transport::getName() const {
    return name;
}

double Transport::getDailyRate() const {
    return dailyRate;
}

bool Transport::getAvailability() const {
    return isAvailable;
}

bool Transport::getINreq() const
{
    return inReq;
}

// Сеттеры
void Transport::setAvailability(bool status) {
    isAvailable = status;
}

void Transport::setDailyRate(double daily) {
    dailyRate = daily;
}


void Transport::setName(const std::string& name) {
    this->name = name;
}

void Transport::setId(int id) {
    this->id = id;
}

void Transport::setINreq(bool inReq)
{
    this->inReq = inReq;
}

Transport& Transport::operator=(const Transport& other)
{
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }
    this->id = other.id;
    this->name = other.name;
    this->dailyRate = other.dailyRate;
    this->isAvailable = other.isAvailable;
    this->inReq = other.inReq;

    return *this;
}

void Transport::showHeader()
{
    using namespace std;
    // Заголовки таблицы
    cout << "| "
        << setw(5) << left << "Стоимость (доллар/в час)"
        << "| " << setw(10) << left << "Идентификатор"
        << "| " << setw(15) << left << "Аренда"
        << "| " << setw(30) << left << "Название";
}

std::ostream& operator<<(std::ostream& os, const Transport& Transport)
{
    os << std::left
        << "            " << std::setw(20) << Transport.dailyRate
        << std::setw(10) << Transport.id
        << std::setw(20) << (Transport.isAvailable ? "Свободен" : "Арендован")
        << std::setw(35) << Transport.name;
    return os;
}

std::istream& operator>>(std::istream& is, Transport& transport) {
    using namespace std;

    // Запрашиваем значения полей
    cout << "Введите ID: ";
     transport.id=Correct::GetCorrectInt(is,1,1000);

    // Очищаем поток для корректного ввода строки
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Введите название: ";

    transport.name = Correct::GetCorrectStr(is);
    

    cout << "Введите стоимость аренды за день: ";
     transport.dailyRate=Correct::GetCorrectDouble(is, 0, 1000);

    // Очищаем поток перед следующим вводом
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Доступен ли транспорт (1 - да, 0 - нет): ";

    transport.isAvailable = Correct::GetCorrectInt(is, 0, 1);
           
    return is;
}
