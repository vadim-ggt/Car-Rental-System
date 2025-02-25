#pragma once

#include "CLASS_TRANSPORT.h"
#include "CLASS_PASSENGER.h"



class Car : public PassengerVehicle {
private:
    std::string bodyType; // Тип кузова (седан, хэтчбек, внедорожник и т.д.)

public:
    // Конструкторы
    Car();

    Car(int id, const std::string& name, double dailyRate, int capacity, const std::string& bodyType, bool isAvailable, bool inReq);
    Car(const Car& other);
   
    // Методы доступа к bodyType
    void setBodyType(const std::string& type);

    std::string getBodyType() const;

    void showHeader();
    Car& operator=(const Car& other);
    friend std::ostream& operator<<(std::ostream& os, const Car& Car);
    friend std::istream& operator>>(std::istream& is, Car& Car);

    static Car fromFileString(const std::string& fileLine);
    void ToFile(std::ofstream& file) const;

    static Car fromBinary(std::ifstream& file);
    void ToBinary(std::ofstream& file) const;


};
