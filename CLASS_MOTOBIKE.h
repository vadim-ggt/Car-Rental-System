#pragma once

#include "CLASS_TRANSPORT.h"
#include "CLASS_PASSENGER.h"

#include <string>



class MotoBike : public PassengerVehicle {
private:
	int speed;
public:

	MotoBike();

	MotoBike(int id, const std::string& name, double dailyRate, int capacity, int speed, bool isAvailable, bool inReq);
	MotoBike(const MotoBike& other);
	void setSpeed(int speed);
	int getSpeed()const;
	void showHeader();
	MotoBike& operator=(const MotoBike& other);
	friend std::ostream& operator<<(std::ostream& os, const MotoBike& MotoBike);
	friend std::istream& operator>>(std::istream& is, MotoBike& MotoBike);
	static MotoBike fromFileString(const std::string& fileLine);
	void ToFile(std::ofstream& file) const;

	static MotoBike fromBinary(std::ifstream& file);
	void ToBinary(std::ofstream& file) const;

};