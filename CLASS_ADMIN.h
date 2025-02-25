
#pragma once
#include "CLASS_PERSON.H"
#include "CLASS_CAR.h"
#include "CLASS_TRUCK.h"
#include "CLASS_MOTOBIKE.h"
#include "LIST.h"
#include "CLASS_HISTORY.h"
#include "Metod.h"


class Admin : public Person {

public:

    History history;

public:

    Admin();
    Admin(const std::string& name, const std::string& id, const std::string& contactInfo);

    void HistoryStackBack(List<Car>& carList, List<MotoBike>& motoList, List<Truck>& truckList);


    History getHistory() { return history; }
    

    //редакция
    void replaceCar(List<Car>& carList, int index);
    void replaceMoto(List<MotoBike>& motoList, int index);
    void replaceTruck(List<Truck>& truckList, int index);

    ////////////////////////// Заявки ////////////////////////

    void showRequest(std::vector<RentalRequest>& systemRequests);

    void deleteRequest_sos(std::vector<RentalRequest>& systemRequests);
    void RequestStateUst(std::vector<RentalRequest>& systemRequests, 
                                            List<Car>& carList,
                                            List<MotoBike>& motoList,
                                            List<Truck>& truckList);

    void rentVehicle(List<Car>& carList,
        List<MotoBike>& motoList,
        List<Truck>& truckList, RentalRequest& request);

    // Деструктор
    ~Admin();
};


