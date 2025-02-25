#include "CLASS_CAR_RENTAL_SYSTEM.h"
#include <iostream>

using namespace std;







void CarRentalSystem::showMainMenu()
{
    readFile();
    while (true) {  // Зацикливаем меню
        system("cls");
        int choice = 0;
        std::cout << "Добро пожаловать в систему аренды транспорта!\n";
        std::cout << "1. Войти как Пользователь\n";
        std::cout << "2. Войти как Администратор\n";
        std::cout << "3. Выйти\n";
        std::cout << "Выберите опцию: ";
        choice = Correct::GetCorrectInt(cin, 1, 3);
        switch (choice) {
        case 1:
            showUserMenu();  // Меню для пользователя
            break;
        case 2:
            showAdminMenu(); // Меню для администратора
            break;
        case 3:
            std::cout << "Выход из системы...\n";
            saveFile();
            std::cout << "\nEND\n";
            return;  // Завершаем программу
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    }
}




void CarRentalSystem::showUserMenu() {
    while (true) {
        system("cls");
        int choice = 0;
        std::cout << "\nМеню пользователя\n";
        std::cout << "1. Оформить заявку на аренду\n";
        std::cout << "2. Просмотр моих заявок\n";
        std::cout << "3. Поиск транспортного средства\n";
        std::cout << "4. Информация о пользователе\n";
        std::cout << "5. Выйти\n";
        std::cout << "Выберите опцию: ";
            choice = Correct::GetCorrectInt(cin, 1, 5);

        switch (choice) {
        case 1:
            requestRental();   // //
            system("pause");
            break;
        case 2:
             showAllRequests();
             system("pause");
            break;
        case 3:
            searchVehicle();  //  метод для поиска  // //
            break;
        case 4:
            showUser();
            system("pause");
            break;
        case 5:
            return; // Выход из меню пользователя
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    }
}








void CarRentalSystem::showAdminMenu()
{
    while (true) {
        int choice = 0;
        system("cls");
        std::cout << "\nМеню администратора\n";
        std::cout << "1. Работа с заявками\n";
        std::cout << "2. Управление транспортом\n";
        std::cout << "3. Выйти\n";
        std::cout << "Выберите опцию: ";
            choice = Correct::GetCorrectInt(cin, 1, 3);
              
        switch (choice) {
        case 1:
            handleRequestsMenu(); // Работа с заявками
            break;
        case 2:
            ChoiceVehc(); // Управление транспортом
            break;
        case 3:
            return;  // Выход из меню администратора
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    }
}










void CarRentalSystem::handleRequestsMenu() {
    while (true) {
        system("cls");
        int choice = 0;
        std::cout << "\nУправление заявками\n";
        std::cout << "1. Просмотр всех заявок\n";
        std::cout << "2. Одобрение/нет заявок\n";
        std::cout << "3. Удалить отклонённые заявки\n";
        std::cout << "4. Вернуться в главное меню\n";
        std::cout << "Выберите опцию: ";
        choice = Correct::GetCorrectInt(cin, 1, 4);
           
        system("cls");
        switch (choice) {
        case 1:
            showAllRequests();
            system("pause");
            break;
        case 2:
            processRequest();
            system("pause");
            break;
        case 3:
            deleteRejectedRequests();
            system("pause");
            break;
        case 4:
            return; // Возврат в главное меню
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    }
}





template <typename T>
void CarRentalSystem::handleVehiclesMenu(List<T>& vehicleList,int i) {
    while (true) {
        int choice = 0;
        system("cls");
        std::cout << "\nУправление транспортом\n";
        std::cout << "1. Добавить транспорт\n";
        std::cout << "2. Удалить транспорт\n";
        std::cout << "3. Просмотр всех транспортных средств\n";
        std::cout << "4. Редактировать информацию о транспорте\n";
        std::cout << "5. Отменить последнее действие\n";
        std::cout << "6. Вернуться в главное меню\n";
        std::cout << "Выберите опцию: ";
            choice = Correct::GetCorrectInt(cin, 1, 6);

        system("cls");
        switch (choice) {
        case 1: {
           addVehicle(vehicleList, i);
            system("pause");
        }
            break;
        case 2:
            deleteVehicle(vehicleList, i);
            system("pause");
            break;
        case 3:
            showAvailableVehicles(vehicleList);
            system("pause");
            break;
        case 4:
            editVehicle(i);
            system("pause");
            break;
        case 5:
            admin.HistoryStackBack(carList,motoList,truckList);
            system("pause");
            break;
        case 6:
            return; // Возврат в главное меню
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    }
}

template<typename T>
void CarRentalSystem::addVehicle(List<T>& vehicleList, int i)
{
    T value;
    std::cin >> value;
    vehicleList.push_back(value);
    std::cout << " Элемент добавлен: ";
    int index = vehicleList.GetSize();
    if (i == 0) {
        admin.history.addAction(Action(Action::Type::Add, Action::VehicleType::Car, value, index - 1));
    }
    else if (i == 1) {
        admin.history.addAction(Action(Action::Type::Add, Action::VehicleType::MotoBike, value, index - 1));
    }
    else if (i == 2) {
        admin.history.addAction(Action(Action::Type::Add, Action::VehicleType::Truck, value, index - 1));
    }
}





template<typename T>
void CarRentalSystem::deleteVehicle(List<T>& vehicleList, int i)
{
    showAvailableVehicles(vehicleList);
   std::cout << "Введите индекс элемента для удаления: ";
    int index=0;

    index = Correct::GetCorrectInt(cin, 0, 100);

    if (!vehicleList.at(index).getAvailability() || vehicleList.at(index).getINreq()) {
        std::cout << "Транспорт арендован или на рассмотрении, изменения приватезированы пользователем\n";
        return;
    }
    // Проверка на корректность индекса
    if (index < 0 || index >= vehicleList.GetSize()) {
        std::cout << "Ошибка: Некорректный индекс.\n";
        return;
    }
    T value = vehicleList.at(index);
    vehicleList.remove_by_index(index);
    std::cout << "Транспортное средство успешно удалено.\n";
    if (i == 0) {
        admin.history.addAction(Action(Action::Type::Delete, Action::VehicleType::Car, value, index ));
    }
    else if (i == 1) {
        admin.history.addAction(Action(Action::Type::Delete, Action::VehicleType::MotoBike, value, index ));
    }
    else if (i == 2) {
        admin.history.addAction(Action(Action::Type::Delete, Action::VehicleType::Truck, value, index ));
    }
}



template<typename T>
void CarRentalSystem::showAvailableVehicles(List<T>& vehicleList)
{
    if (vehicleList.GetSize() == 0) {
        std::cout << "Список пуст\n";
        return;
    }
    vehicleList.at(0).showHeader();
    vehicleList.show();
}













void CarRentalSystem::showAllRequests()
{
    system("cls");
    admin.showRequest(rentalRequests);
}







void CarRentalSystem::requestRental()
{

    std::cout << "=== Оформление аренды ===\n";

    // Выбор типа транспорта
    int days=0;
    std::string passport_info;
    int vehicleType=0;
    system("cls");
    std::cout << "Выберите тип транспорта для аренды:\n";
    std::cout << "1 - Автомобиль\n";
    std::cout << "2 - Мотоцикл\n";
    std::cout << "3 - Грузовик\n";
    std::cout << "Ваш выбор: ";

    vehicleType = Correct::GetCorrectInt(cin, 1, 3);

    system("cls");
    switch (vehicleType) {
    case 1: {
        rentCar(days,passport_info);
        break;
    }
    case 2: {
        rentMoto(days, passport_info);
        break;
    }
    case 3: {
        rentTruck(days, passport_info);
        break;
    }
    default:
        std::cout << "Некорректный выбор.\n";
        break;
    }
}






void CarRentalSystem::rentCar(int days, std::string passport_info)
{
    // Показываем список автомобилей
    if (carList.GetSize() == 0) {
        std::cout << "Список автомобилей пуст.\n";
        return;
    }
    Car car;
    car.showHeader();
    carList.show();
    int index=0;
    std::cout << "Введите индекс автомобиля для аренды: ";
        index = Correct::GetCorrectInt(cin, 0, 100);
    try {
        Car& selectedCar = carList.at(index);
        if (selectedCar.getAvailability() == false) {
            std::cout << "\nТранспорт забронирован!!!\n";
            return;
        }
        std::cout << "Введите количество дней аренды: ";
        days = Correct::GetCorrectInt(cin, 1, 100);
        
        passport_info = Correct::GetCorrectPassportNum(cin);
        
        
        RentalRequest request(user.getName(), passport_info, days, sos::no_considered, "", selectedCar);
        user.addRequest(request, rentalRequests);
        std::cout << "Заявка успешно добавлена.\n";
        selectedCar.setINreq(true);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";    
    }
}






void CarRentalSystem::rentMoto(int days, std::string passport_info)
{
    // Показываем список мотоциклов
    if (motoList.GetSize() == 0) {
        std::cout << "Список мотоциклов пуст.\n";
        return;
    }
    MotoBike moto;
    moto.showHeader();
    motoList.show();
    int index=0;
    std::cout << "Введите индекс мотоцикла для аренды: ";
        index = Correct::GetCorrectInt(cin, 0, 100);

    try {
        MotoBike& selectedMoto = motoList.at(index);
        if (selectedMoto.getAvailability() == false) {
            std::cout << "\nТранспорт забронирован!!!\n";
            return;
        }
        std::cout << "Введите количество дней аренды: ";
        days = Correct::GetCorrectInt(cin, 1, 100);
       
        std::cin.ignore();
        passport_info = Correct::GetCorrectPassportNum(cin);
        
        RentalRequest request(user.getName(), passport_info, days, sos::no_considered, "", selectedMoto);
        user.addRequest(request, rentalRequests);
        std::cout << "Заявка успешно добавлена.\n";
        selectedMoto.setINreq(true);
    }

    catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }
}







void CarRentalSystem::rentTruck(int days, std::string passport_info)
{
    
    // Показываем список грузовиков
    if (truckList.GetSize() == 0) {
        std::cout << "Список грузовиков пуст.\n";
        return;
    }
    Truck truck;
    truck.showHeader();
    truckList.show();
    int index=0;
    std::cout << "Введите индекс грузовика для аренды: ";

        index = Correct::GetCorrectInt(cin, 0, 100);

    try {
        Truck& selectedTruck = truckList.at(index);
        if (selectedTruck.getAvailability() == false) {
            std::cout << "\nТранспорт забронирован!!!\n";
            return;
        }
        std::cout << "Введите количество дней аренды: ";
            days = Correct::GetCorrectInt(cin, 1, 100);
        
       
        std::cin.ignore();
            passport_info = Correct::GetCorrectPassportNum(cin);
        
        RentalRequest request(user.getName(), passport_info, days, sos::no_considered, "", selectedTruck);
        user.addRequest(request, rentalRequests);
        std::cout << "Заявка успешно добавлена.\n";
        selectedTruck.setINreq(true);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }
}




void CarRentalSystem::searchVehicle()
{


    while (true) {
        system("cls");
        int choice = 0;
        std::cout << "\nВыберите список для поиска:\n";
        std::cout << "1. Машины\n";
        std::cout << "2. Мотоциклы\n";
        std::cout << "3. Грузовики\n";
        std::cout << "4. Вернуться в главное меню\n";
        std::cout << "Ваш выбор: ";
            choice = Correct::GetCorrectInt(cin, 1, 4);
                 
        system("cls");
        switch (choice) {
        case 1:
            user.searchCar(carList); // Метод для поиска в списке машин
            system("pause");

            break;
        case 2:
            user.searchMoto(motoList); // Метод для поиска в списке мотоциклов
            system("pause");

            break;
        case 3:
            user.searchTruck(truckList); // Метод для поиска в списке грузовиков
            system("pause");

            break;
        case 4:
            return; // Возврат в главное меню
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    }
}

void CarRentalSystem::showUser()
{
    system("cls");

    user.showHeader();
    std::cout << user;
}






void CarRentalSystem::editVehicle(int i)
{
  
    int index;

    switch (i)
    {
    case 0: 
        {
            Car car;
            car.showHeader();
            carList.show();
            std::cout << "Введите индекс машины, в которой хотите изменить параметры: ";
                index = Correct::GetCorrectInt(cin, 0, 100);
               
            admin.replaceCar(carList,index);
        break;
        } 
    case 1: 
        {
            MotoBike moto;
            moto.showHeader();
            motoList.show();
            std::cout << "Введите индекс мотоцикла, в котором хотите изменить параметры: ";
                index = Correct::GetCorrectInt(cin, 0, 100);    
            admin.replaceMoto(motoList, index);
            break;
        } 
    case 2: 
        {
            Truck truck;
            truck.showHeader();
            truckList.show();
            std::cout << "Введите индекс грузовика, в котором хотите изменить параметры: ";
                index = Correct::GetCorrectInt(cin, 0, 100);
            admin.replaceTruck(truckList, index);
            break;
        }
    default:
        std::cout << "Некорректный выбор.\n";
        break;
    }
}



void CarRentalSystem::deleteRejectedRequests()
{
    admin.deleteRequest_sos(rentalRequests);
}

void CarRentalSystem::processRequest() 
{
    system("cls");
    admin.RequestStateUst(rentalRequests, carList, motoList, truckList);
}


void CarRentalSystem::readFile()
{
    loadF.loadFromFileTXT(carList, "D:/VADIM/visual/Kursovoi_Project/Car_list.txt");

    //loadF.loadCars("D:/VADIM/visual/Kursovoi_Project/Car_list.txt", carList);
    loadF.loadMotorbikes("D:/VADIM/visual/Kursovoi_Project/Moto_list.txt", motoList);
    loadF.loadTrucks("D:/VADIM/visual/Kursovoi_Project/Truck_list.txt", truckList);
    loadF.loadRentalRequests("D:/VADIM/visual/Kursovoi_Project/Requests.txt", rentalRequests, carList, motoList, truckList);


}

void CarRentalSystem::saveFile()
{
    loadF.saveCars("D:/VADIM/visual/Kursovoi_Project/Car_list.txt", carList);
    loadF.saveMotobikes("D:/VADIM/visual/Kursovoi_Project/Moto_list.txt", motoList);
    loadF.saveTrucks("D:/VADIM/visual/Kursovoi_Project/Truck_list.txt", truckList);
    loadF.saveRentalRequests("D:/VADIM/visual/Kursovoi_Project/Requests.txt", rentalRequests);
}

void CarRentalSystem::ChoiceVehc()
{

    while (true) {
        system("cls");
        int choice = 0;
        std::cout << "=== Главное меню ===\n";
        std::cout << "1. Управление автомобилями\n";
        std::cout << "2. Управление мотоциклами\n";
        std::cout << "3. Управление грузовиками\n";
        std::cout << "4. Выход\n";
        std::cout << "Выберите опцию: ";
            choice = Correct::GetCorrectInt(cin, 1, 4);
       
        switch (choice) {
        case 1:
            handleVehiclesMenu(carList,0); // Работа с автомобилями
            break;
        case 2:
            handleVehiclesMenu(motoList,1); // Работа с мотоциклами
            break;
        case 3:
            handleVehiclesMenu(truckList,2); // Работа с грузовиками
            break;
        case 4:
            return; // Завершение программы
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    }

}
