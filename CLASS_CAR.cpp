#include "CLASS_CAR.h"
#include <string>
#include <iostream>
#include <iomanip>

#include <fstream>
#include <iostream>
#include <sstream>


Car::Car()
    : PassengerVehicle(), bodyType("Undefined") {}

// Конструктор
Car::Car(int id, const std::string& name, double dailyRate, int capacity, const std::string& bodyType, bool isAvailable, bool inReq)
    : PassengerVehicle(id, name, dailyRate, capacity, isAvailable, inReq), bodyType(bodyType){}

Car::Car(const Car& other)
    :bodyType(other.bodyType)
{
    PassengerVehicle::operator=(other);
}


// Методы доступа к bodyType
void Car::setBodyType(const std::string& type) {
    bodyType = type;
}

std::string Car::getBodyType() const {
    return bodyType;
}

void Car::showHeader()
{
    using namespace std;

    cout << string(111, '-') << endl;
    cout << setw(90) << right << "ИНФОРМАЦИЯ О МАШИНАХ" << endl;
    cout << string(111, '-') << endl;

    PassengerVehicle::showHeader();


    // Заголовки таблицы
    cout << "| "
        << setw(5) << left << "Тип кузова|\n";

}

Car& Car::operator=(const Car& other)
{
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }
    // Вызов перегрузки оператора = базового класса Transport
    PassengerVehicle::operator=(other);
    this->bodyType = other.bodyType;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Car& Car)
{
    os << static_cast<const PassengerVehicle&>(Car);

    os << std::left
        << std::setw(15) << Car.bodyType<<std::endl;
    return os;
}



std::istream& operator>>(std::istream& is, Car& Car)
{
    using namespace std;
    is >> static_cast< PassengerVehicle&> (Car);
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Введите тип кузова: ";
    // Очищаем поток для корректного ввода строки
    Car.bodyType = Correct::GetCorrectStr(is);
    return is;

}





Car Car::fromFileString(const std::string& fileLine)
{
    std::stringstream ss(fileLine); // Создаем поток для разбора строки
    int id;
    std::string name;
    double dailyRate;
    int passengerCapacity;
    std::string bodyType; // Учитываем тип кузова
    bool isAvailable;
    bool inReq;

    // Считываем значения из строки
    std::string temp; // Временная строка для преобразований

    // Считываем id
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    id = std::stoi(temp);

    // Считываем имя
    if (!std::getline(ss, name, ';')) throw std::runtime_error("Invalid input format");

    // Считываем стоимость
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    dailyRate = std::stod(temp);

    // Считываем доступность
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    isAvailable = (std::stoi(temp) != 0);

    // Считываем вместимость пассажиров
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    passengerCapacity = std::stoi(temp);

    // Считываем доступность
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    inReq = (std::stoi(temp) != 0);


    // Считываем тип кузова
    if (!std::getline(ss, bodyType, ';')) throw std::runtime_error("Invalid input format");
    // Создаем объект Car и возвращаем его
    return Car(id, name, dailyRate, passengerCapacity, bodyType, isAvailable, inReq);

}

void Car::ToFile(std::ofstream& file) const
{
    file << id << ";"
        << name << ";"
        << dailyRate << ";"
        << (isAvailable ? "1" : "0") << ";"
        << passengerCapacity << ";"
        << (inReq ? "1" : "0") << ";"
        << bodyType << "\n";
}



Car Car::fromBinary(std::ifstream& file)
{
    int id;
    size_t nameSize;
    std::string name;
    double dailyRate;
    bool isAvailable;
    int passengerCapacity;
    bool inReq;
    size_t bodyTypeSize;
    std::string bodyType;

    file.read(reinterpret_cast<char*>(&id), sizeof(id));

    file.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
    name.resize(nameSize);
    file.read(&name[0], nameSize);

    file.read(reinterpret_cast<char*>(&dailyRate), sizeof(dailyRate));
    file.read(reinterpret_cast<char*>(&isAvailable), sizeof(isAvailable));
    file.read(reinterpret_cast<char*>(&passengerCapacity), sizeof(passengerCapacity));
    file.read(reinterpret_cast<char*>(&inReq), sizeof(inReq));

    file.read(reinterpret_cast<char*>(&bodyTypeSize), sizeof(bodyTypeSize));
    bodyType.resize(bodyTypeSize);
    file.read(&bodyType[0], bodyTypeSize);

    return Car(id, name, dailyRate, passengerCapacity, bodyType, isAvailable, inReq);

}

void Car::ToBinary(std::ofstream& file) const
{
    file.write(reinterpret_cast<const char*>(&id), sizeof(id));
    size_t nameSize = name.size();
    file.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
    file.write(name.c_str(), nameSize);
    file.write(reinterpret_cast<const char*>(&dailyRate), sizeof(dailyRate));
    file.write(reinterpret_cast<const char*>(&isAvailable), sizeof(isAvailable));
    file.write(reinterpret_cast<const char*>(&passengerCapacity), sizeof(passengerCapacity));
    file.write(reinterpret_cast<const char*>(&inReq), sizeof(inReq));

    size_t bodyTypeSize = bodyType.size();
    file.write(reinterpret_cast<const char*>(&bodyTypeSize), sizeof(bodyTypeSize));
    file.write(bodyType.c_str(), bodyTypeSize);

}
