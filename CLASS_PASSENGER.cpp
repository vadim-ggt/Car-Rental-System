#include "CLASS_PASSENGER.h"
#include <iostream>
#include <iomanip>

PassengerVehicle::PassengerVehicle()
    : Transport(), passengerCapacity(0) {}

// Конструктор
PassengerVehicle::PassengerVehicle(int id, const std::string& name, double dailyRate, int capacity,bool isAvailable, bool inReq)
    : Transport(id, name, dailyRate, isAvailable, inReq), passengerCapacity(capacity) {}

// Метод установки вместимости пассажиров
void PassengerVehicle::setPassengerCapacity(int capacity) {
    passengerCapacity = capacity;
}

// Метод получения вместимости пассажиров
int PassengerVehicle::getPassengerCapacity() const {
    return passengerCapacity;
}

void PassengerVehicle::showHeader()
{
    using namespace std;
    Transport::showHeader();
    // Заголовки таблицы
    cout << "| "
        << setw(5) << left << "Количество пассажиров";

}

PassengerVehicle& PassengerVehicle::operator=(const PassengerVehicle& other)
{
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }

    // Вызов перегрузки оператора = базового класса Transport
    Transport::operator=(other);

    // Копирование специфичных полей PassengerVehicle
    this->passengerCapacity = other.passengerCapacity;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const PassengerVehicle& PassengerVehicle)
{
    os << static_cast<const Transport&>(PassengerVehicle);

    os << std::left
        << std::setw(15) << PassengerVehicle.passengerCapacity;
    return os;
}

std::istream& operator>>(std::istream& is, PassengerVehicle& PassengerVehicle)
{
    using namespace std;
    is >> static_cast< Transport&>(PassengerVehicle);

    cout << "Введите вместимоть пассажиров: ";
    PassengerVehicle.passengerCapacity = Correct::GetCorrectInt(is, 1, 1000);
    return is;
}
