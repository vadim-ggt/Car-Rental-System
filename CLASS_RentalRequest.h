#pragma once

#include <string>
#include <iostream>
#include "CLASS_TRANSPORT.h" 
#include "CLASS_CAR.h"
#include "CLASS_TRUCK.h"
#include "CLASS_MOTOBIKE.h"
#include <iomanip>


enum class sos{approved,rejected,no_considered };

enum class VehicleType { Car, MotoBike, Truck, None };

class RentalRequest {
private:
    std::string userName;            // ФИО пользователя
    std::string passport_info;
    int rentalDays;                  // Количество дней аренды
    double finalSum;                 // сум ма после поддсчета всех дней
    sos state;                       //состояние заявки
    std::string note;

    Car car;
    MotoBike moto;
    Truck truck;

    VehicleType vehicleType;

public:
    // Конструкторы
    RentalRequest();
    RentalRequest(const std::string& userName, const std::string& passport_info, int rentalDays, sos state,
        const std::string& note, const Car& car);
    RentalRequest(const std::string& userName, const std::string& passport_info, int rentalDays,  sos state,
        const std::string& note, const MotoBike& moto);
    RentalRequest(const std::string& userName, const std::string& passport_info, int rentalDays, sos state,
        const std::string& note, const Truck& truck);

    // Геттеры
    std::string getUserName() const;
    int getRentalDays() const;
    int getFinalSum() const;
    sos getState() const;
    std::string getNote() const;
    std::string getPassport()const;
    Car getCar() const;
    MotoBike getMoto() const;
    Truck getTruck() const;
    VehicleType getVehicleType() const { return vehicleType; }

    // Сеттеры
    void setUserName(const std::string& name);
    void setRentalDays(int days);
    void setFinalSum(int sum);
    void setState(sos newState);
    void setNote(const std::string& newNote);
    void setPassport(const std::string& passport_infoNEW);
    void setCar(const Car& newCar);
    void setMoto(const MotoBike& newMoto);
    void setTruck(const Truck& newTruck);
    void setVehicleType(VehicleType newStatus);

    void showHeader();

    friend std::ostream& operator<<(std::ostream& os, const RentalRequest& Request);


};