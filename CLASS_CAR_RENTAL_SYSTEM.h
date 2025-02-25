#pragma once
#include <vector>
#include "CLASS_CAR.h"
#include "CLASS_TRUCK.h"
#include "CLASS_MOTOBIKE.h"
#include "CLASS_USER.h"
#include "CLASS_ADMIN.h"
#include "CLASS_FILEMANAGER.h"
#include "CLASS_HISTORY.h"
#include <string>
#include <memory>
#include <iostream>
#include "LIST.h"
#include <cstdlib>
#include "Metod.h"



class CarRentalSystem 
{
private:

    User user;                          // Пользователь системы
    Admin admin;                        // Администратор системы
    List<Car> carList;                  // Список автомобилей
    List<MotoBike> motoList;            // Список мотоциклов
    List<Truck> truckList;              // Список грузовиков
    FileManager loadF;  
    std::vector <RentalRequest> rentalRequests;
public:

    // галавный интерфейс//
    void showMainMenu();
    void showUserMenu();
    void showAdminMenu();
    void handleRequestsMenu();
    void showAllRequests();

    /////////пользователь//////////
    
    //для пользователя//
    void requestRental();
    void rentCar(int days,std::string passport_info);
    void rentMoto(int days, std::string passport_info);
    void rentTruck(int days, std::string passport_info);
    void searchVehicle();
    void showUser();

    /////////админ////////
   
    void editVehicle(int i);


    // работа с заявками //
     void deleteRejectedRequests();
     void processRequest();

     // работа с файлами //
     void readFile();
     void saveFile();

     void ChoiceVehc();

     template <typename T>
     void handleVehiclesMenu(List<T>& vehicleList,int i);

     template <typename T>
     void addVehicle(List<T>& vehicleList, int i);

     template <typename T>
     void deleteVehicle(List<T>& vehicleList, int i);

     template <typename T>
     void showAvailableVehicles(List<T>& vehicleList);
  
};