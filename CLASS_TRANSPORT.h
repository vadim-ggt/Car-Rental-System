#pragma once

#include <string>
#include "Metod.h"


class Transport {
protected:
    int id;                  // Уникальный идентификатор
    std::string name;        // Название транспорта
    double dailyRate;        // Стоимость аренды за день
    bool isAvailable;        // Статус (доступен/в аренде)
    bool inReq;

public:
    // Конструкторы
    Transport();
    Transport(int id, const std::string& name, double dailyRate, bool isAvailable,bool inReq);
    Transport(const Transport& other);

    // Виртуальный деструктор
    virtual ~Transport();

    // Геттеры
    int getId() const;
    std::string getName() const;
    double getDailyRate() const;
    bool getAvailability() const;
    bool getINreq()const;
    // Сеттеры
    void setAvailability(bool status);
    void setDailyRate(double daily);
    void setName(const std::string& name);
    void setId(int id);
    void setINreq(bool inReq);

    //Перегрузка знака =
    Transport& operator=(const Transport& other);

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Transport& Transport);

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Transport& Transport);

    void showHeader();
};