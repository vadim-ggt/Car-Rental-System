#include "CLASS_PERSON.h"
#include <string>
#include <iostream>
#include <iomanip>


// Конструкторы
Person::Person() : name(""), id(""), contactInfo("") {}

Person::Person(const std::string& name, const std::string& id, const std::string& contactInfo)
    : name(name), id(id), contactInfo(contactInfo) {}

Person::~Person() {};

// Сеттеры
void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setId(const std::string& id) {
    this->id = id;
}

void Person::setContactInfo(const std::string& contactInfo) {
    this->contactInfo = contactInfo;
}

// Геттеры
std::string Person::getName() const {
    return name;
}

std::string Person::getId() const {
    return id;
}

std::string Person::getContactInfo() const {
    return contactInfo;
}


void Person::showHeader() const {
    using namespace std;
    cout << string(63, '-') << endl;
    cout << "| "
        << setw(25) << left << "ФИО"
        << "| " << setw(15) << left << "ID(№паспорта)"
        << "| " << setw(30) << left << "Контактная информация|\n";
}





std::ostream& operator<<(std::ostream& os, const Person& person) {
    using namespace std;
    os << "| " << left
        << setw(25) << person.name            // Увеличил ширину до 50
        << setw(15) << left << person.id  // Увеличил ширину до 25
        << setw(30) << left << person.contactInfo;  // Увеличил ширину до 50
      
    return os;
}



std::istream& operator>>(std::istream& is, Person& person) {
    std::cout << "Введите имя: ";
    std::getline(is, person.name);

    std::cout << "Введите ID: ";
    std::getline(is, person.id);

    std::cout << "Введите контактные данные: ";
    std::getline(is, person.contactInfo);

    return is;
}
