#pragma once

#include <string>
#include <vector>
#include <memory>
#include "CLASS_TRANSPORT.h"
#include "CLASS_PERSON.h"
#include "CLASS_CAR.h"
#include "CLASS_TRUCK.h"
#include "CLASS_MOTOBIKE.h"
#include "LIST.h"
#include <fstream>
#include <iostream>
#include <sstream>


class FileManager {
public:
    // Метод для загрузки автомобилей
    void loadCars(const std::string& filePath, List<Car>& carList);
    Car readCar(const std::string& line);

    // Метод для загрузки мотоциклов
    void loadMotorbikes(const std::string& filePath, List<MotoBike>& motoList);
    MotoBike readMotoBike(const std::string& line);

    // Метод для загрузки грузовиков
    void loadTrucks(const std::string& filePath, List<Truck>& truckList);
    Truck readTruck(const std::string& line);

    // Метод для загрузки заявок
    void loadRentalRequests(const std::string& filePath, std::vector <RentalRequest>& rentalRequests, List<Car>& carList, List<MotoBike>& motoList, List<Truck>& truckList);

    sos parseState(const std::string& stateStr);
    VehicleType parseType(const std::string& type);

    std::string trim(const std::string& str);
    // Метод для записи автомобилей обратно в файл
    void saveCars(const std::string& filePath, const List<Car>& carList);

    // Метод для записи мотоциклов обратно в файл
    void saveMotobikes(const std::string& filePath, const List<MotoBike>& motoList);

    // Метод для записи грузовиков обратно в файл
    void saveTrucks(const std::string& filePath, const List<Truck>& truckList);

    // Метод для записи заявок обратно в файл
    void saveRentalRequests(const std::string& filePath, std::vector <RentalRequest>& rentalRequests);
    std::string toStateString(sos state);
    std::string toTypeString(VehicleType type);



    template<typename T>
    static void saveToFileTXT(const List<T>& list, const std::string& filename);

    template<typename T>
    static void loadFromFileTXT(List<T>& list, const std::string& filename);


    };




template<typename T>
inline void FileManager::saveToFileTXT(const List<T>& list, const std::string& filename)
{

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }



    Node<T>* current = list.getHead(); // Получаем голову списка

    while (current) {
        current->data.ToFile(file);
        current = current->next;
    }

    file.close();
    std::cout << "Data saved to " << filename << ".\n";

}

template<typename T>
inline void FileManager::loadFromFileTXT(List<T>& list, const std::string& filename)
{


    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for reading.\n";
        return;
    }

    list.clear();  // Очистить список перед загрузкой новых данных

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            try {
                T item = T::fromFileString(line); // Метод для создания объекта из строки
                list.push_back(item); // Добавляем объект в список
            }
            catch (const std::exception& e) {
                std::cerr << "Error parsing line: " << line << ". Exception: " << e.what() << std::endl;
            }
        }
    }

    file.close();
    std::cout << "Data loaded from " << filename << ".\n";

}




