#include "CLASS_TRUCK.h"

#include <iostream>
#include <iomanip>



Truck::Truck()
:CargoVehicle(), height(0),width(0),length(0){}

Truck::Truck(int id, const std::string& name, double dailyRate, int capacity, int height, int width, int length, bool isAvailable, bool inReq)
: CargoVehicle(id, name, dailyRate, capacity,  isAvailable, inReq), height(height), width(width), length(length) {}



Truck::Truck(const Truck& other)
:      height(other.height),
      width(other.width),
      length(other.length) 
{
	CargoVehicle::operator=(other);
}




void Truck::SetHei(int height)
{
	this->height = height;
}

void Truck::SetWi(int width)
{
	this->width = width;
}

void Truck::setLe(int length)
{
	this->length = length;
}

int Truck::GetHei()const
{
	return this->height;
}

int Truck::GetWi()const
{
	return this->width;
}

int Truck::GetLe()const
{
	return this->length;
}




void Truck::showHeader()
{

	using namespace std;

	cout << string(118, '-') << endl;
	cout << setw(90) << right << "ИНФОРМАЦИЯ О ГРУЗОВИКАХ" << endl;
	cout << string(118, '-') << endl;

	CargoVehicle::showHeader();
	cout << "| "
		<< setw(5) << left << "Высота"
		<< "| " << setw(10) << left << "Ширина"
		<< "| " << setw(10) << left << "Длина|\n";

}

Truck& Truck::operator=(const Truck& other)
{
	if (this == &other) {
		return *this; // Защита от самоприсваивания
	}
	// Вызов перегрузки оператора = базового класса Transport
	CargoVehicle::operator=(other);
	this->height = other.height;
	this->width = other.width;
	this->length = other.length;
	return *this;
}

Truck Truck::fromFileString(const std::string& fileLine)
{
	return Truck();
}

void Truck::ToFile(std::ofstream& file) const
{
}

Truck Truck::fromBinary(std::ifstream& file)
{
	return Truck();
}

void Truck::ToBinary(std::ofstream& file) const
{
}

std::ostream& operator<<(std::ostream& os, const Truck& Truck)
{
	os << static_cast<const CargoVehicle&>(Truck);

	os << std::left
		<< std::setw(7) << Truck.height
		<< std::setw(7) << Truck.width
		<< std::setw(15) << Truck.length<<std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Truck& Truck)
{
	using namespace std;
	is >> static_cast<CargoVehicle&>(Truck);

	cout << "Введите высоту: ";
	 Truck.height=Correct::GetCorrectInt(is,1,20);
	cout << "Введите ширину: ";
    Truck.width = Correct::GetCorrectInt(is, 1, 20);
	cout << "Введите длину: ";
	Truck.length = Correct::GetCorrectInt(is, 1, 20);
	return is;


}
