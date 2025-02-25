#pragma once

#include "CLASS_TRANSPORT.h"
#include <string>
#include <iostream>


class CargoVehicle : public Transport {
protected:

	int liftingCapacity;

public:

	CargoVehicle();
	CargoVehicle(int id, const std::string& name, double dailyRate, int liftingCapacity, bool isAvailable, bool inReq);


	void setLifting(int liftingCapacity);
	int getLifting()const;

	void showHeader();
	CargoVehicle& operator=(const CargoVehicle& other);
	friend std::ostream& operator<<(std::ostream& os, const CargoVehicle& CargoVehicle);
	friend std::istream& operator>>(std::istream& is,  CargoVehicle& CargoVehicle);


};