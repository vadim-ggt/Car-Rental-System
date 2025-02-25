#include "CLASS_MOTOBIKE.h"

#include <iostream>
#include <iomanip>


MotoBike::MotoBike()
: PassengerVehicle(), speed(0) {}

MotoBike::MotoBike(int id, const std::string& name, double dailyRate, int capacity, int speed, bool isAvailable, bool inReq)
:PassengerVehicle(id, name, dailyRate, capacity, isAvailable, inReq), speed(speed) {}

MotoBike::MotoBike(const MotoBike& other)
    :speed(other.speed)
{
    PassengerVehicle::operator=(other);
}

void MotoBike::setSpeed(int speed)
{
	this->speed = speed;
}

int MotoBike::getSpeed() const
{
	return this->speed;
}



void MotoBike::showHeader()
{
    using namespace std;

    cout << string(113, '-') << endl;
    cout << setw(90) << right << "ИНФОРМАЦИЯ О МОТОЦИКЛАХ" << endl;
    cout << string(113, '-') << endl;

    PassengerVehicle::showHeader();


    // Заголовки таблицы
    cout << "| "
        << setw(5) << left << "MAX скорость|\n";
}

MotoBike& MotoBike::operator=(const MotoBike& other)
{
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }
    // Вызов перегрузки оператора = базового класса Transport
    PassengerVehicle::operator=(other);
    this->speed = other.speed;
    return *this;
}

MotoBike MotoBike::fromFileString(const std::string& fileLine)
{
    return MotoBike();
}

void MotoBike::ToFile(std::ofstream& file) const
{
}

MotoBike MotoBike::fromBinary(std::ifstream& file)
{
    return MotoBike();
}

void MotoBike::ToBinary(std::ofstream& file) const
{

}

std::ostream& operator<<(std::ostream& os, const MotoBike& MotoBike)
{
    os << static_cast<const PassengerVehicle&>(MotoBike);

    os << std::left
        << std::setw(15) << MotoBike.speed<<std::endl;
    return os;

}

std::istream& operator>>(std::istream& is, MotoBike& MotoBike)
{
    using namespace std;
    is >> static_cast<PassengerVehicle&> (MotoBike);
    cout << "Введите максимальную скорость: ";
    MotoBike.speed=Correct::GetCorrectInt(is,1,1000);
    return is;
}
