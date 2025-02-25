#include "CLASS_RentalRequest.h"

#include <iostream>

// Конструкторы
RentalRequest::RentalRequest()
    : userName(""), rentalDays(0), finalSum(0), state(sos::no_considered), note(""),
    car(Car()), moto(MotoBike()), truck(Truck()), vehicleType(VehicleType:: None) {}

RentalRequest::RentalRequest(const std::string& userName, const std::string& passport_info, int rentalDays, sos state,
    const std::string& note, const Car& car)
    : userName(userName), rentalDays(rentalDays), state(state), note(note),
    car(car), moto(MotoBike()), truck(Truck()), vehicleType(VehicleType::Car), passport_info(passport_info)
{
    finalSum=car.getDailyRate()* rentalDays;
}

RentalRequest::RentalRequest(const std::string& userName, const std::string& passport_info, int rentalDays,  sos state,
    const std::string& note, const MotoBike& moto)
    : userName(userName), rentalDays(rentalDays), state(state), note(note),
    car(Car()), moto(moto), truck(Truck()), vehicleType(VehicleType::MotoBike), passport_info(passport_info)
{
    finalSum = moto.getDailyRate() * rentalDays;
}

RentalRequest::RentalRequest(const std::string& userName, const std::string& passport_info, int rentalDays,  sos state,
    const std::string& note, const Truck& truck)
    : userName(userName), rentalDays(rentalDays),  state(state), note(note),
    car(Car()), moto(MotoBike()), truck(truck) , vehicleType(VehicleType::Truck), passport_info(passport_info)
{
    finalSum = truck.getDailyRate() * rentalDays;
}

// Геттеры
std::string RentalRequest::getUserName() const {
    return userName;
}

int RentalRequest::getRentalDays() const {
    return rentalDays;
}

int RentalRequest::getFinalSum() const {
    return finalSum;
}

sos RentalRequest::getState() const {
    return state;
}

std::string RentalRequest::getNote() const {
    return note;
}

std::string RentalRequest::getPassport() const
{
    return passport_info;
}

Car RentalRequest::getCar() const  {
    return car;
}

MotoBike RentalRequest::getMoto() const {
    return moto;
}

Truck RentalRequest::getTruck() const {
    return truck;
}

// Сеттеры
void RentalRequest::setUserName(const std::string& name) {
    userName = name;
}

void RentalRequest::setRentalDays(int days) {
    rentalDays = days;
}

void RentalRequest::setFinalSum(int sum) {
    finalSum = sum;
}

void RentalRequest::setState(sos newState) {
    state = newState;
}

void RentalRequest::setNote(const std::string& newNote) {
    note = newNote;
}

void RentalRequest::setPassport(const std::string& passport_infoNEW)
{
    passport_info = passport_infoNEW;
}

void RentalRequest::setCar(const Car& newCar) {
    car = newCar;
}

void RentalRequest::setMoto(const MotoBike& newMoto) {
    moto = newMoto;
}

void RentalRequest::setTruck(const Truck& newTruck) {
    truck = newTruck;
}

void RentalRequest::setVehicleType(VehicleType newStatus)
{
    vehicleType = newStatus;
}



void RentalRequest::showHeader()
{

    using namespace std;
    cout << string(111, '-') << endl;
    cout << setw(90) << right << "ИНФОРМАЦИЯ О ЗАЯВКЕ" << endl;
    cout << string(111, '-') << endl;



    cout << "| "
        << setw(10) << left << "Пасспортная информация"
        << "| " << setw(15) << left << "Колличество дней аренды"
        << "| " << setw(30) << left << "Сумма платежа"
        << "| " << setw(30) << left << "Состояние"
        << "| " << setw(20) << left << "Примечание" << "\n";
}

std::ostream& operator<<(std::ostream& os, const RentalRequest& Request)
{

    os << std::left
        <<  "  " << std::setw(35) << Request.passport_info
        << std::setw(20) << Request.rentalDays
        << std::setw(14) << Request.finalSum;

    os << std::setw(36);
    switch (Request.state) {
    case sos::approved:
        os << "Одобрена ";
        break;
    case sos::rejected:
        os << "Отклонена ";
        break;
    case sos::no_considered:
        os << "Не рассмотрена ";
        break;
    }

    os << std::setw(10)
        << (Request.note.empty() ? "Примечаний нет" : Request.note);

    os << std::endl;

    switch (Request.getVehicleType()) {
    case VehicleType::Car: {
        Car car;
        car.showHeader();
        os << Request.car << "\n";  // Выводим данные о машине
        break;
    }
    case VehicleType::MotoBike: {
        MotoBike moto;
        moto.showHeader();
        os << Request.moto << "\n";  // Выводим данные о мотоцикле
        break;
    }
    case VehicleType::Truck: {
        Truck truck;
        truck.showHeader();
        os << Request.truck << "\n";  // Выводим данные о грузовике
        break;
    }
    default:
        os << "Не указан тип транспорта\n";
        break;
    }

    return os;
}
