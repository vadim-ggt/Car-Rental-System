#include "CLASS_FILEMANAGER.h"


void FileManager::loadCars(const std::string& filePath, List<Car>& carList)
{
	std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filePath << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        carList.push_back(readCar(line));
    }

    file.close();
    
}



Car FileManager::readCar(const std::string& line)
{
    std::stringstream ss(line); // Создаем поток для разбора строки
    int id;
    std::string name;
    double dailyRate;
    int passengerCapacity;
    std::string bodyType; // Учитываем тип кузова
    bool isAvailable;
    bool inReq;

    // Считываем значения из строки
    std::string temp; // Временная строка для преобразований

    // Считываем id
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    id = std::stoi(temp);

    // Считываем имя
    if (!std::getline(ss, name, ';')) throw std::runtime_error("Invalid input format");

    // Считываем стоимость
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    dailyRate = std::stod(temp);

    // Считываем доступность
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    isAvailable = (std::stoi(temp) != 0);

    // Считываем вместимость пассажиров
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    passengerCapacity = std::stoi(temp);

    // Считываем доступность
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    inReq = (std::stoi(temp) != 0);


    // Считываем тип кузова
    if (!std::getline(ss, bodyType, ';')) throw std::runtime_error("Invalid input format");
    // Создаем объект Car и возвращаем его
    return Car(id, name, dailyRate, passengerCapacity, bodyType, isAvailable, inReq);
}




void FileManager::loadMotorbikes(const std::string& filePath, List<MotoBike>& motoList)
{

    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filePath << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        motoList.push_back(readMotoBike(line));
    }
    file.close();
}



MotoBike FileManager::readMotoBike(const std::string& line)
{

    std::stringstream ss(line); // Создаем поток для разбора строки
    int id;
    std::string name;
    double dailyRate;
    int passengerCapacity;
    int  speed; 
    bool isAvailable;
    bool inReq;

    // Считываем значения из строки
    std::string temp; // Временная строка для преобразований

    // Считываем id
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    id = std::stoi(temp);

    // Считываем имя
    if (!std::getline(ss, name, ';')) throw std::runtime_error("Invalid input format");

    // Считываем стоимость
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    dailyRate = std::stod(temp);

    // Считываем доступность
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    isAvailable = (std::stoi(temp) != 0);

    // Считываем вместимость пассажиров
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    passengerCapacity = std::stoi(temp);

    // Считываем доступность
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    inReq = (std::stoi(temp) != 0);

    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    speed = std::stoi(temp);

    return MotoBike(id, name, dailyRate, passengerCapacity, speed, isAvailable, inReq);
}



void FileManager::loadTrucks(const std::string& filePath, List<Truck>& truckList)
{
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filePath << "\n";
        return;
    }


    std::string line;
    while (std::getline(file, line)) {
        truckList.push_back(readTruck(line));

    }
    file.close();

}



Truck FileManager::readTruck(const std::string& line)
{
    std::stringstream ss(line); // Создаем поток для разбора строки
    int id;
    std::string name;
    double dailyRate;
    int liftingCapacity;
    int  h,w,l;
    bool isAvailable;
    bool inReq;

    // Считываем значения из строки
    std::string temp; // Временная строка для преобразований

    // Считываем id
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    id = std::stoi(temp);

    // Считываем имя
    if (!std::getline(ss, name, ';')) throw std::runtime_error("Invalid input format");

    // Считываем стоимость
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    dailyRate = std::stod(temp);

    // Считываем доступность
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    isAvailable = (std::stoi(temp) != 0);

    // Считываем вместимость пассажиров
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    liftingCapacity = std::stoi(temp);

    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    inReq = (std::stoi(temp) != 0);

    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    h = std::stoi(temp);
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    w = std::stoi(temp); 
    if (!std::getline(ss, temp, ';')) throw std::runtime_error("Invalid input format");
    l = std::stoi(temp);

    return Truck(id, name, dailyRate, liftingCapacity, h, w, l, isAvailable, inReq);
}

















void FileManager::loadRentalRequests(const std::string& filePath,
    std::vector<RentalRequest>& rentalRequests,
    List<Car>& carList,
    List<MotoBike>& motoList,
    List<Truck>& truckList)
{
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения: " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::string field;

        // Считываем основные данные заявки
        RentalRequest request;
        std::getline(lineStream, field, ';');
        request.setUserName(field);

        std::getline(lineStream, field, ';');
        request.setPassport(field);

        std::getline(lineStream, field, ';');
        request.setRentalDays(std::stoi(field));

        std::getline(lineStream, field, ';');
        request.setFinalSum(std::stod(field));

        std::getline(lineStream, field, ';');
        request.setState(parseState(field)); // Парсинг состояния заявки

        // Считываем тип транспорта
        std::getline(lineStream, field, ';');
        request.setVehicleType(parseType(field));

        // Считываем идентификатор транспорта
        std::getline(lineStream, field, ';');
        int vehicleId = std::stoi(field);

        // Поиск транспорта по идентификатору
        if (request.getVehicleType() == VehicleType::Car) {
            for (const auto& car : carList) {
                if (car.getId() == vehicleId) {
                    request.setCar(car); // Связываем машину с заявкой
                    break;
                }
            }
        }
        else if (request.getVehicleType() == VehicleType::MotoBike) {
            for (const auto& moto : motoList) {
                if (moto.getId() == vehicleId) {
                    request.setMoto(moto); // Связываем мотоцикл с заявкой
                    break;
                }
            }
        }
        else if (request.getVehicleType() == VehicleType::Truck) {
            for (const auto& truck : truckList) {
                if (truck.getId() == vehicleId) {
                    request.setTruck(truck); // Связываем грузовик с заявкой
                    break;
                }
            }
        }
        else {
            request.setVehicleType(VehicleType::None);
        }

        // Добавляем заявку в список
        rentalRequests.push_back(request);
    }

    file.close();
}














// Вспомогательные функции
std::string FileManager::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}




sos FileManager::parseState(const std::string& stateStr) {
    if (stateStr == "approved") return sos::approved;
    if (stateStr == "rejected") return sos::rejected;
    return sos::no_considered;
}





VehicleType FileManager::parseType(const std::string& type)
{
    if (type=="Car") return VehicleType::Car;
    if (type == "Moto") return VehicleType::MotoBike;
    if (type == "Truck") return VehicleType::Truck;
    return VehicleType();
}





void FileManager::saveCars(const std::string& filePath, const List<Car>& carList)
{
    std::ofstream file(filePath, std::ios::trunc); // Открываем файл в режиме перезаписи
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи: " << filePath << std::endl;
        return;
    }
        
    Node<Car>* current = carList.getHead(); // Доступ к головному элементу списка
    while (current) {
        const Car& car = current->data;
        file << car.getId() << ";"
            << car.getName() << ";"
            << car.getDailyRate() << ";"
            << (car.getAvailability() ? "1" : "0") << ";"
            << car.getPassengerCapacity() << ";" // Пример записи с пассажирской вместимостью
            << car.getINreq() << ";"
            << car.getBodyType() << "\n";
            current = current->next;
    }

    file.close();
    std::cout << "Список автомобилей успешно записан в файл: " << filePath << std::endl;
}





void FileManager::saveMotobikes(const std::string& filePath, const List<MotoBike>& motoList)
{

    std::ofstream file(filePath, std::ios::trunc); // Открываем файл в режиме перезаписи
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи: " << filePath << std::endl;
        return;
    }

    Node<MotoBike>* current = motoList.getHead(); // Доступ к головному элементу списка

    while (current) {
        const MotoBike& moto = current->data;
        file << moto.getId() << ";"
            << moto.getName() << ";"
            << moto.getDailyRate() << ";"
            << (moto.getAvailability() ? "1" : "0") << ";"
            << moto.getPassengerCapacity() << ";" // Пример записи с пассажирской вместимостью
            << moto.getINreq() << ";"
            << moto.getSpeed()<< "\n";
        current = current->next;
    }

    file.close();
    std::cout << "Список мотоциклов успешно записан в файл: " << filePath << std::endl;

}




void FileManager::saveTrucks(const std::string& filePath, const List<Truck>& truckList)
{

    std::ofstream file(filePath, std::ios::trunc); // Открываем файл в режиме перезаписи
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи: " << filePath << std::endl;
        return;
    }

    Node<Truck>* current = truckList.getHead(); // Доступ к головному элементу списка

    while (current) {
       const Truck& truck = current->data;
       file << truck.getId() << ";"
            << truck.getName() << ";"
            << truck.getDailyRate() << ";"
            << (truck.getAvailability() ? "1" : "0") << ";"
            << truck.getLifting() << ";" // Пример записи с вместимостью
           << truck.getINreq() << ";"
            << truck.GetHei() << ";"
            << truck.GetWi() << ";"
            << truck.GetLe() << "\n";
        current = current->next;
    }

    file.close();
    std::cout << "Список грузовиков успешно записан в файл: " << filePath << std::endl;
}





void FileManager::saveRentalRequests(const std::string& filePath, std::vector<RentalRequest>& rentalRequests)
{


        std::ofstream file(filePath, std::ios::trunc); // Открываем файл в режиме перезаписи
        if (!file.is_open()) {
            std::cerr << "Ошибка открытия файла для записи: " << filePath << std::endl;
            return;
        }

        for (const auto& request : rentalRequests) {
            // Записываем основные данные заявки
            file << request.getUserName() << ";"
                << request.getPassport()<< ";"
                << request.getRentalDays() << ";"
                << request.getFinalSum() << ";"
                << toStateString(request.getState()) << ";"
                << toTypeString(request.getVehicleType())<<";";

            // Записываем данные транспорта в зависимости от типа
            if (request.getVehicleType() == VehicleType::Car) {
                const Car& car = request.getCar();
                file << car.getId() << ";\n";
                   
            }

            else if (request.getVehicleType() == VehicleType::MotoBike) {
                const MotoBike& moto = request.getMoto();
                file << moto.getId() << ";\n";
                    
            }
            else if (request.getVehicleType() == VehicleType::Truck) {
                const Truck& truck = request.getTruck();
                file << truck.getId() << ";\n";
            }
        }
        file.close();
        std::cout << "Список заявок успешно сохранён в файл: " << filePath << std::endl;
}

std::string FileManager::toStateString(sos state)
{
   switch (state) {
    case sos::approved: return "approved";
    case sos::rejected: return "rejected";
    case sos::no_considered: return "no_considered";
    default: return "unknown";
    }
}

std::string FileManager::toTypeString(VehicleType type)
{
    switch (type) {
    case VehicleType::Car: return "Car";
    case VehicleType::MotoBike: return "MotoBike";
    case VehicleType::Truck: return "Truck";
    case VehicleType::None: return "None";
    default: return "unknown";
    }
}



