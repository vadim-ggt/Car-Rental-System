#pragma once

#include "CLASS_TRANSPORT.h"
#include "string"
#include<iostream>

class PassengerVehicle : public Transport {
protected:
    int passengerCapacity; // Вместимость пассажиров

public:
    // Конструкторы
    PassengerVehicle();
    PassengerVehicle(int id, const std::string& name, double dailyRate, int capacity,bool isAvailable, bool inReq);

    // Метод установки вместимости пассажиров
    void setPassengerCapacity(int capacity);

    // Метод получения вместимости пассажиров
    int getPassengerCapacity() const;
    void showHeader();

    ///////////////////////

    PassengerVehicle& operator=(const PassengerVehicle& other);

    ////////////////////////////////


    friend std::ostream& operator<<(std::ostream& os, const PassengerVehicle& PassengerVehicle);
    friend std::istream& operator>>(std::istream& is, PassengerVehicle& PassengerVehicle);


};
