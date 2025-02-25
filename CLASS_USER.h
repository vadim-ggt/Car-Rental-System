#pragma once
#include "CLASS_PERSON.h"
#include "CLASS_Rentalrequest.h"
#include <vector>
#include <string>
#include <memory>
#include <iomanip>
#include "LIST.h"


class User : public Person {
private:

public:

    // Конструкторы
    User();
    User(const std::string& name, const std::string& id, const std::string& contactInfo);

   
   
    void addRequest(const RentalRequest& request, std::vector<RentalRequest>& systemRequests);
    
    void searchCar(List<Car>& carList);
    void searchMoto(List<MotoBike>& motoList);
    void searchTruck(List<Truck>& truckList);

    void showHeader()const;
    ~User();

    friend std::ostream& operator<<(std::ostream& os, const User& User);
    friend std::istream& operator>>(std::istream& is,  User& User);

};
