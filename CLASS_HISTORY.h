#pragma once

#include <stack>
#include <string>
#include <vector>
#include "CLASS_CAR.h"
#include "CLASS_TRUCK.h"
#include "CLASS_MOTOBIKE.h"
#include "LIST.h"


class Action {
public:
    enum class Type { Add, Delete, Edit }; // Тип действия
    enum class VehicleType { Car, MotoBike, Truck }; // Тип объекта

private:
    Type actionType;
    VehicleType vehicleType;
    int index; // Индекс для восстановления 

    // Храним конкретный объект транспортного средства 
    Car car;
    MotoBike moto;
    Truck truck;

public:
    // Конструкторы для разных типов транспортных средств
    Action(Type actionType, VehicleType vehicleType, const Car& car, int index )
        : actionType(actionType), vehicleType(vehicleType), car(car), index(index) {}

    Action(Type actionType, VehicleType vehicleType, const MotoBike& moto, int index )
        : actionType(actionType), vehicleType(vehicleType), moto(moto), index(index) {}

    Action(Type actionType, VehicleType vehicleType, const Truck& truck, int index )
        : actionType(actionType), vehicleType(vehicleType), truck(truck), index(index) {}
     
    // Получаем тип действия
    Type getActionType() const { return actionType; }

    // Получаем тип транспортного средства
    VehicleType getVehicleType() const { return vehicleType; }

    // Получаем индекс для восстановления
    int getIndex() const { return index; }

    // Получаем данные объекта (в зависимости от типа транспортного средства)
    Car& getCarData() {
        if (vehicleType == VehicleType::Car) {
            return car;
        }
        throw std::runtime_error("Wrong vehicle type");
    }

    MotoBike& getMotoData() {
        if (vehicleType == VehicleType::MotoBike) {
            return moto;
        }
        throw std::runtime_error("Wrong vehicle type");
    }

    Truck& getTruckData() {
        if (vehicleType == VehicleType::Truck) {
            return truck;
        }
        throw std::runtime_error("Wrong vehicle type");
    }
};





// Класс для управления историей действий
class History {

private:
    std::stack<Action> actionStack; // Стек действий


public:

    void addAction(const Action& action) { actionStack.push(action); }
    void undo(List<Car>& carList, List<MotoBike>& motoList, List<Truck>& truckList);
};
