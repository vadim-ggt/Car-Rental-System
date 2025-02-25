#include "CLASS_CARGO.h"
#include <iostream>
#include <iomanip>



CargoVehicle::CargoVehicle()
    : Transport(), liftingCapacity(0) {}


CargoVehicle::CargoVehicle(int id, const std::string& name, double dailyRate, int liftingCapacity, bool isAvailable, bool inReq)
: Transport(id, name, dailyRate, isAvailable, inReq), liftingCapacity(liftingCapacity) {}


void CargoVehicle::setLifting(int liftingCapacity)
{
	this->liftingCapacity = liftingCapacity;
}

int CargoVehicle::getLifting() const
{
	return liftingCapacity;
}




void CargoVehicle::showHeader()
{
    using namespace std;
    Transport::showHeader();
    // Заголовки таблицы
    cout << "| "
        << setw(5) << left << "Грузоподъемность";
}





CargoVehicle& CargoVehicle::operator=(const CargoVehicle& other)
{
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }
    // Вызов перегрузки оператора = базового класса Transport
    Transport::operator=(other);
    this->liftingCapacity = other.liftingCapacity;

    return *this;
}



std::ostream& operator<<(std::ostream& os, const CargoVehicle& CargoVehicle)
{
    os << static_cast<const Transport&>(CargoVehicle);

    os << std::left
        << std::setw(10) << CargoVehicle.liftingCapacity;
    return os;
}



std::istream& operator>>(std::istream& is, CargoVehicle& CargoVehicle) {
    using namespace std;

    // Используем оператор ввода базового класса
    is >> static_cast<Transport&>(CargoVehicle);

    // Читаем грузоподъемность
    cout << "Введите максимальную грузоподъемность (в тоннах): ";
     CargoVehicle.liftingCapacity=Correct::GetCorrectInt(is,1,1000);

    return is;
}
