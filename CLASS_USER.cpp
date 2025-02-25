#include "CLASS_USER.h"
#include <iostream>
#include <vector>



User::User() : Person()
{
    name = "Koval Vadim";
    id="111";
    contactInfo="+375445660819";
}

User::User(const std::string& name, const std::string& id, const std::string& contactInfo)
    : Person(name, id, contactInfo)  {}


void User::addRequest(const RentalRequest& request, std::vector<RentalRequest>& systemRequests)
{
    systemRequests.push_back(request);
    std::cout << "Заявка успешно добавлена в систему.\n";
}





void User::searchCar(List<Car>& carList)
{
    std::cout << "Введите параметры для поиска машины:\n";

    std::string name, bodyType;
    double minDailyRate = 0, maxDailyRate = 0;
    bool searchByAvailability = false;
    bool availability = false;
    int passengerCapacity = 0;

    // Запрашиваем параметры поиска
    std::cout << "Название (или оставьте пустым для игнорирования): ";
    std::cin.ignore();
    name = Correct::GetCorrectStr2(cin);
    std::cout << "Минимальная цена за день (0 для игнорирования): ";
    minDailyRate = Correct::GetCorrectDouble(cin, 0, 1000);

    std::cout << "Максимальная цена за день (0 для игнорирования): ";
     maxDailyRate=Correct::GetCorrectDouble(cin,0,1000);

    std::cout << "Искать только доступные машины? (1 - да, 0 - нет): ";
        searchByAvailability = Correct::GetCorrectInt(cin, 0, 1);
    
    std::cout << "Вместимость пассажиров (0 для игнорирования): ";
        passengerCapacity = Correct::GetCorrectInt(cin, 0, 10);
    
    std::cout << "Тип кузова (или оставьте пустым для игнорирования): ";
    std::cin.ignore();
    bodyType = Correct::GetCorrectStr2(cin);
    // Используем алгоритм поиска
    auto results = List<Car>::Algorithms::find(carList, [&](const Car& car) {
        bool matches = true;

        // Применяем фильтры
        if (!name.empty()) matches &= (car.getName() == name);
        if (minDailyRate > 0) matches &= (car.getDailyRate() >= minDailyRate);
        if (maxDailyRate > 0) matches &= (car.getDailyRate() <= maxDailyRate);
        if (searchByAvailability) matches &= car.getAvailability();
        if (passengerCapacity > 0) matches &= (car.getPassengerCapacity() == passengerCapacity);
        if (!bodyType.empty()) matches &= (car.getBodyType() == bodyType);

        return matches;
    });

    // Вывод результатов поиска
    if (results.empty()) {
        std::cout << "Машины по заданным параметрам не найдены.\n";
    }
    else {
        std::cout << "Результаты поиска:\n";
        Car c;
        c.showHeader();
        for ( auto& car : results) {
            std::cout << car; // Метод для вывода информации о машине
        }
    }
}




void User::searchMoto(List<MotoBike>& motoList)
{
    std::cout << "Введите параметры для поиска мотоцикла:\n";

    std::string name;
    double minDailyRate = 0, maxDailyRate = 0;
    bool searchByAvailability = false;
    bool availability = false;
    int passengerCapacity = 0;
    int speed = 0;
    
    // Запрашиваем параметры поиска
    std::cout << "Название (или оставьте пустым для игнорирования): ";
    std::cin.ignore();
    name = Correct::GetCorrectStr2(cin);

    std::cout << "Минимальная цена за день (0 для игнорирования): ";
    minDailyRate = Correct::GetCorrectDouble(cin, 0, 1000);

    std::cout << "Максимальная цена за день (0 для игнорирования): ";
    maxDailyRate = Correct::GetCorrectDouble(cin, 0, 1000);

    std::cout << "Искать только доступные мотоциклы? (1 - да, 0 - нет): ";
        searchByAvailability = Correct::GetCorrectInt(cin, 0, 1);
    
    std::cout << "Вместимость пассажиров (0 для игнорирования): ";
        passengerCapacity = Correct::GetCorrectInt(cin, 0, 10);
    
    std::cout << "Скорость (0 для игнорирования): ";
        speed = Correct::GetCorrectInt(cin, 0, 500);
    
    // Используем алгоритм поиска
    auto results = List<MotoBike>::Algorithms::find(motoList, [&](const MotoBike& moto) {
        bool matches = true;

        // Применяем фильтры
        if (!name.empty()) matches &= (moto.getName() == name);
        if (minDailyRate > 0) matches &= (moto.getDailyRate() >= minDailyRate);
        if (maxDailyRate > 0) matches &= (moto.getDailyRate() <= maxDailyRate);
        if (searchByAvailability) matches &= moto.getAvailability();
        if (passengerCapacity > 0) matches &= (moto.getPassengerCapacity() == passengerCapacity);
        if (speed > 0) matches &= (moto.getSpeed() == speed);

        return matches;
    });

    // Вывод результатов поиска
    if (results.empty()) {
        std::cout << "Мотоциклы по заданным параметрам не найдены.\n";
    }
    else {
        std::cout << "Результаты поиска:\n";
        MotoBike m;
        m.showHeader();
        for (auto& moto : results) {
            std::cout << moto; // Метод для вывода информации о машине
        }
    }

}



void User::searchTruck(List<Truck>& truckList)
{
    std::cout << "Введите параметры для поиска грузовика:\n";

    std::string name;
    double minDailyRate = 0, maxDailyRate = 0;
    bool searchByAvailability = false;
    bool availability = false;
    int liftingCapacity = 0;
    int h(0),l(0),w(0);

    // Запрашиваем параметры поиска
    std::cout << "Название (или оставьте пустым для игнорирования): ";
    std::cin.ignore();
    name = Correct::GetCorrectStr2(cin);

    std::cout << "Минимальная цена за день (0 для игнорирования): ";
    minDailyRate = Correct::GetCorrectDouble(cin, 0, 1000);

    std::cout << "Максимальная цена за день (0 для игнорирования): ";
    maxDailyRate = Correct::GetCorrectDouble(cin, 0, 1000);

    std::cout << "Искать только доступные грузовики? (1 - да, 0 - нет): ";
        searchByAvailability = Correct::GetCorrectInt(cin, 0, 1);
    
    std::cout << "Вместимость груза (0 для игнорирования): ";
        liftingCapacity = Correct::GetCorrectInt(cin, 0, 1000);
    
    std::cout << "Высота (0 для игнорирования): ";
        h = Correct::GetCorrectInt(cin, 0, 10);
    
    std::cout << "Длина (0 для игнорирования): ";
        l = Correct::GetCorrectInt(cin, 0, 10);
    
    std::cout << "Ширина (0 для игнорирования): ";
        w = Correct::GetCorrectInt(cin, 0, 10);
 

    // Используем алгоритм поиска
    auto results = List<Truck>::Algorithms::find(truckList, [&](const Truck& truck) {
        bool matches = true;

        // Применяем фильтры
        if (!name.empty()) matches &= (truck.getName() == name);
        if (minDailyRate > 0) matches &= (truck.getDailyRate() >= minDailyRate);
        if (maxDailyRate > 0) matches &= (truck.getDailyRate() <= maxDailyRate);
        if (searchByAvailability) matches &= truck.getAvailability();
        if (liftingCapacity > 0) matches &= (truck.getLifting() == liftingCapacity);
        if (h > 0) matches &= (truck.GetHei() == h);
        if (l > 0) matches &= (truck.GetLe() == l);
        if (w > 0) matches &= (truck.GetWi() == w);

        return matches;
        });

    // Вывод результатов поиска
    if (results.empty()) {
        std::cout << "Грузовики по заданным параметрам не найдены.\n";
    }
    else {
        std::cout << "Результаты поиска:\n";
        Truck t;
        t.showHeader();
        for (auto& truck : results) {
            std::cout << truck; // Метод для вывода информации о машине
        }
    }
}





void User::showHeader() const {
    using namespace std;

    // Заголовок "Информация о пользователях"
    cout << string(63, '-') << endl;
    cout << "| " << setw(83) << left << "Информация о пользователе" << "|" << endl;

    // Вызов метода showHeader() базового класса Person для вывода общих полей
    Person::showHeader();  // Показывает "ФИО", "ID", "Контактная информация"


    cout << string(63, '-') << endl;
}




User::~User() {}

std::ostream& operator<<(std::ostream& os, const User& user) {
    // Вызов оператора вывода базового класса Person для вывода общих полей
    os << static_cast<const Person&>(user);  // Приводим user к типу Person и вызываем его оператор <<


    os << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, User& User)
{
    is >> static_cast<Person&>(User);
    return is;
}
