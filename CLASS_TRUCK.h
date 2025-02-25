#pragma once
#include "CLASS_TRANSPORT.h"
#include "CLASS_CARGO.h"
#include "CLASS_CARGO.h"



class Truck : public CargoVehicle {
private:

	int height;
	int width;
	int length;

public:

	Truck();
	Truck(int id, const std::string& name, double dailyRate, int capacity, int height, int width, int length, bool isAvailable, bool inReq);
	Truck(const Truck& other);
	void SetHei(int height);
	void SetWi(int width);
	void setLe(int length);

	int GetHei()const;
	int GetWi()const;
	int GetLe()const;

	void showHeader();
	Truck& operator=(const Truck& other);
	friend std::ostream& operator<<(std::ostream& os, const Truck& Truck);
	friend std::istream& operator>>(std::istream& is,  Truck& Truck);



	static Truck fromFileString(const std::string& fileLine);
	void ToFile(std::ofstream& file) const;
	static Truck fromBinary(std::ifstream& file);
	void ToBinary(std::ofstream& file) const;


};