#pragma once

#include <iostream>
#include <vector>
#include "CLASS_Rentalrequest.h"


class Person {
protected:
    std::string name;
    std::string id;
    std::string contactInfo;
public:
    // Конструкторы
    Person();
    Person(const std::string& name, const std::string& id, const std::string& contactInfo);
    
    ~Person();

    // Сеттеры
    void setName(const std::string& name);
    void setId(const std::string& id);
    void setContactInfo(const std::string& contactInfo);

    // Геттеры
    std::string getName() const;
    std::string getId() const;
    std::string getContactInfo() const;

    void showHeader() const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Person& person);



    

};