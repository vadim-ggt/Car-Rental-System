#include "CLASS_ADMIN.h"
#include <iostream>

// Конструкторы
Admin::Admin() : Person() {}

Admin::Admin(const std::string& name, const std::string& id, const std::string& contactInfo)
    : Person(name, id, contactInfo) {}





void Admin::HistoryStackBack(List<Car>& carList, List<MotoBike>& motoList, List<Truck>& truckList)
{
    history.undo(carList, motoList, truckList);
}




void Admin::replaceCar(List<Car>& carList, int index)
{
    Car& car = carList.at(index);
    if (!car.getAvailability()  || car.getINreq()) { 
        std::cout << "Машина арендована или на рассмотрении, изменения приватезированы пользователем";
        return;
    }
    history.addAction(Action(Action::Type::Edit, Action::VehicleType::Car, car, index));


    int choice=0;
    do {
        system("cls");
        std::cout << "\nВыберите параметр для изменения:\n";
        std::cout << "1. ID\n";
        std::cout << "2. Название\n";
        std::cout << "3. Стоимость аренды\n";
        std::cout << "4. Вместимоть пассажиров\n";
        std::cout << "5. Тип кузова\n";
        std::cout << "6. Завершить изменения\n";
        std::cout << "Ваш выбор: ";
            choice = Correct::GetCorrectInt(cin, 1, 6);
        
        switch (choice) {
        case 1: {
            int newId=0;
            std::cout << "Введите новый ID: ";  
                newId = Correct::GetCorrectInt(cin, 0, 1000);
          
            car.setId(newId);
            std::cout << "ID успешно изменён на " << newId << ".\n";
            system("pause");
            break;
        }
        case 2: {
            std::string newName;
            std::cout << "Введите новое название: ";
            std::cin.ignore(); // Очищаем буфер перед вводом строки
            newName = Correct::GetCorrectStr(cin);
            car.setName(newName);
            std::cout << "Название успешно изменено на " << newName << ".\n";
            system("pause");
            break;
        }
        case 3: {
            double newDailyRate;
            std::cout << "Введите новую стоимость аренды: ";
             newDailyRate=Correct::GetCorrectDouble(cin,0,1000);
            car.setDailyRate(newDailyRate);
            std::cout << "Стоимость аренды успешно изменена на " << newDailyRate << ".\n";
            system("pause");
            break;
        }
        case 4: {
            int passanger=0;
            std::cout << "Введите новую вместимоть: ";
                passanger = Correct::GetCorrectInt(cin, 1, 10);
             
            car.setPassengerCapacity(passanger);
            std::cout << "Новая вместимость: " << passanger << ".\n";
            system("pause");
            break;
        }
        case 5: {
            std::string body;
            std::cout << "Введите новый тип кузова: ";
            body = Correct::GetCorrectStr(cin);
            car.setBodyType(body);
            std::cout << "Тип кузова успешно изменена на " << body << ".\n";
            system("pause");
            break;
        }
        case 6:
            std::cout << "Изменение параметров завершено.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    } while (choice != 6);
    

}

void Admin::replaceMoto(List<MotoBike>& motoList, int index)
{


    MotoBike& bike = motoList.at(index);

    if (!bike.getAvailability()  || bike.getINreq()) {
        std::cout << "Мотоцикл арендована или на рассмотрении, изменения приватезированы пользователем";
        return;
    }

    history.addAction(Action(Action::Type::Edit, Action::VehicleType::MotoBike, bike, index));

  
    int choice=0;
    do {
        system("cls");
        std::cout << "\nВыберите параметр для изменения:\n";
        std::cout << "1. ID\n";
        std::cout << "2. Название\n";
        std::cout << "3. Стоимость аренды\n";
        std::cout << "4. Вместимоть пассажиров\n";
        std::cout << "5. Скорость\n";
        std::cout << "6. Завершить изменения\n";
        std::cout << "Ваш выбор: ";
            choice = Correct::GetCorrectInt(cin, 1, 6);
        
        switch (choice) {
        case 1: {
            int newId=0;
            std::cout << "Введите новый ID: ";
                newId = Correct::GetCorrectInt(cin, 1, 1000);
            
            bike.setId(newId);
            std::cout << "ID успешно изменён на " << newId << ".\n";
            system("pause");
            break;
        }
        case 2: {
            std::string newName;
            std::cout << "Введите новое название: ";
            std::cin.ignore(); // Очищаем буфер перед вводом строки
            newName = Correct::GetCorrectStr(cin);
            bike.setName(newName);
            std::cout << "Название успешно изменено на " << newName << ".\n";
            system("pause");
            break;
        }
        case 3: {
            double newDailyRate;
            std::cout << "Введите новую стоимость аренды: ";
            newDailyRate = Correct::GetCorrectDouble(cin, 0, 1000);
            bike.setDailyRate(newDailyRate);
            std::cout << "Стоимость аренды успешно изменена на " << newDailyRate << ".\n";
            system("pause");
            break;
        }
        case 4: {
            int passanger=0;
            std::cout << "Введите новую вместимоть: ";
                passanger = Correct::GetCorrectInt(cin, 1, 10);
             
            bike.setPassengerCapacity(passanger);
            std::cout << "Вместимость успешно изменена на " << passanger << ".\n";
            system("pause");
            break;
        }
        case 5: {
            int speed=0;
            std::cout << "Введите новую скорость: ";
                speed = Correct::GetCorrectInt(cin, 1, 1000);
            
            bike.setSpeed(speed);
            std::cout << "Скорость успешно изменена на " << speed << ".\n";
            system("pause");
            break;
        }
        case 6:
            std::cout << "Изменение параметров завершено.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    } while (choice != 6);

}



void Admin::replaceTruck(List<Truck>& truckList, int index)
{

    Truck& truck = truckList.at(index);

    if (!truck.getAvailability()  || truck.getINreq()) {
        std::cout << "Грузовик арендован или на рассмотрении, изменения приватезированы пользователем";
        return;
    }

    history.addAction(Action(Action::Type::Edit, Action::VehicleType::Truck, truck, index));

   
    int choice=0;
    do {
        system("cls");
        std::cout << "\nВыберите параметр для изменения:\n";
        std::cout << "1. ID\n";
        std::cout << "2. Название\n";
        std::cout << "3. Стоимость аренды\n";
        std::cout << "4. Вместимоть \n";
        std::cout << "5. Высота\n";
        std::cout << "6. Ширина\n";
        std::cout << "7. Длина\n";
        std::cout << "8. Завершить изменения\n";
        std::cout << "Ваш выбор: ";
            choice = Correct::GetCorrectInt(cin, 1, 8);
        
        switch (choice) {
        case 1: {
            int newId=0;
            std::cout << "Введите новый ID: ";
                newId = Correct::GetCorrectInt(cin, 1, 1000);
              
            truck.setId(newId);
            std::cout << "ID успешно изменён на " << newId << ".\n";
            system("pause");
            break;
        }
        case 2: {
            std::string newName;
            std::cout << "Введите новое название: ";
            std::cin.ignore(); // Очищаем буфер перед вводом строки
            newName = Correct::GetCorrectStr(cin);
            truck.setName(newName);
            std::cout << "Название успешно изменено на " << newName << ".\n";
            system("pause");
            break;
        }
        case 3: {
            double newDailyRate;
            std::cout << "Введите новую стоимость аренды: ";
            newDailyRate = Correct::GetCorrectDouble(cin, 0, 1000);
            truck.setDailyRate(newDailyRate);
            std::cout << "Стоимость аренды успешно изменена на " << newDailyRate << ".\n";
            system("pause");
            break;
        }
        case 4: {
            int lifting=0;
            std::cout << "Введите новую вместимоть груза: ";
                lifting = Correct::GetCorrectInt(cin, 1, 1000);
               
            truck.setLifting(lifting);
            std::cout << "Вместимость успешно изменена на " << lifting << ".\n";
            system("pause");
            break;
        }
        case 5: {
            int h=0;
            std::cout << "Введите новую высоту: ";
                h = Correct::GetCorrectInt(cin, 1, 100);
                     
            truck.SetHei(h);
            std::cout << "Высота успешно изменена на " << h << ".\n";
            system("pause");
            break;
        }
        case 6: {
            int w=0;
            std::cout << "Введите новую ширину: ";
                w = Correct::GetCorrectInt(cin, 1, 100);
            truck.SetWi(w);
            std::cout << "Ширина успешно изменена на " << w << ".\n";
            system("pause");
            break;
        }
        case 7: {
            int l=0;
            std::cout << "Введите новую длину: ";
                l = Correct::GetCorrectInt(cin, 1, 100);
                
            truck.setLe(l);
            std::cout << "Длина успешно изменена на " << l << ".\n";
            system("pause");
            break;
        }
        case 8:
            std::cout << "Изменение параметров завершено.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            system("pause");
            break;
        }
    } while (choice != 8);

}


void Admin::showRequest(std::vector<RentalRequest>& systemRequests)
{
    if (systemRequests.empty()) {
        std::cout << "Нет заявок для отображения.\n";
        return;
    }
    RentalRequest rrr;
    int i = 0;
    for (const auto& request : systemRequests) {
        std::cout << "Заявка №" << i << std :: endl;
        rrr.showHeader();
        std::cout << request << "\n";  // Используется перегрузка оператора <<
        i++;
    }
    std::cout << "=====================\n";
}



void Admin::deleteRequest_sos(std::vector<RentalRequest>& systemRequests)
{

    auto initialSize = systemRequests.size(); // Для отображения количества удалённых заявок
    systemRequests.erase(
        std::remove_if(
            systemRequests.begin(),
            systemRequests.end(),
            [](const RentalRequest& request) {
                return request.getState() == sos::rejected;
            }),
        systemRequests.end()
    );
    std::cout << "Удалено " << (initialSize - systemRequests.size()) << " отклонённых заявок.\n";
}




void Admin::RequestStateUst(std::vector<RentalRequest>& systemRequests, List<Car>& carList,
    List<MotoBike>& motoList,
    List<Truck>& truckList)
{
    if (systemRequests.empty()) {
        std::cout << "Список заявок пуст.\n";
        return;
    }

    std::cout << "=== Управление заявками ===\n";
    showRequest(systemRequests); // Показать все заявки (уже реализованный метод)

    int index;
    std::cout << "Введите индекс заявки для обработки: ";
    std::cin >> index;

    if (index < 0 || index >= systemRequests.size()) {
        std::cout << "Некорректный индекс. Попробуйте снова.\n";
        return;
    }
    system("cls");

    RentalRequest& request = systemRequests[index]; // Получаем выбранную заявку
    request.showHeader();
    std::cout << "Выбрана заявка:\n" << request << "\n";

    if (request.getState() != sos::no_considered) {
        std::cout << "\nДанная заявка уже была рассмотрена!!!\n";
        return;
    }

    int choice=0;
    std::cout << "Выберите действие:\n";
    std::cout << "1. Одобрить заявку\n";
    std::cout << "2. Отклонить заявку\n";
    std::cout << "Ваш выбор: ";
        choice = Correct::GetCorrectInt(cin, 1, 2);
    
    switch (choice) {
    case 1: {

        rentVehicle(carList, motoList, truckList, request);
        
        break;
    }
    case 2: {
        request.setState(sos::rejected); // Устанавливаем состояние "Отклонена"
        std::cout << "Введите причину отклонения: ";
        std::cin.ignore(); // Убираем остаток ввода после `std::cin`
        std::string reason;
        reason = Correct::GetCorrectStr(cin);
        request.setNote(reason); // Сохраняем причину в примечании

        // Найти транспортное средство и сбросить его inReq
        if (request.getVehicleType() == VehicleType::Car) {
            for (auto& car : carList) {
                if (car.getId() == request.getCar().getId()) {
                    car.setINreq(false); // Указываем, что машина больше не в заявке
                    break;
                }
            }
        }
        else if (request.getVehicleType() == VehicleType::MotoBike) {
            for (auto& moto : motoList) {
                if (moto.getId() == request.getMoto().getId()) {
                    moto.setINreq(false);
                    break;
                }
            }
        }
        else if (request.getVehicleType() == VehicleType::Truck) {
            for (auto& truck : truckList) {
                if (truck.getId() == request.getTruck().getId()) {
                    truck.setINreq(false);
                    break;
                }
            }
        }
        std::cout << "Заявка отклонена с причиной: " << reason << "\n";
        break;
    }
    default:
        std::cout << "Некорректный выбор. Попробуйте снова.\n";
        break;
    }


}






void Admin::rentVehicle( List<Car>& carList,
    List<MotoBike>& motoList,
    List<Truck>& truckList, RentalRequest& request) {
    request.setState(sos::approved); // Устанавливаем состояние "Одобрена"
    std::cout << "Заявка одобрена.\n";

    // Забронировать транспорт (сделать его недоступным)
    if (request.getVehicleType() == VehicleType::Car) {
        // Ищем машину в списке carList по ID или другим критериям
        for (auto& car : carList) {
            if (car.getId() == request.getCar().getId()) {
                car.setAvailability(false); // Делаем машину недоступной в списке
                request.setCar(car); // Так же обновляем доступность в заявке
                break;
            }
        }
    }
    else if (request.getVehicleType() == VehicleType::MotoBike) {
        request.getMoto().setAvailability(false);
        // Ищем мотоцикл в списке motoList по ID или другим критериям
        for (auto& moto : motoList) {
            if (moto.getId() == request.getMoto().getId()) {
                moto.setAvailability(false); // Делаем мотоцикл недоступным
                request.setMoto(moto);
                break;
            }
        }
    }
    else if (request.getVehicleType() == VehicleType::Truck) {
        request.getTruck().setAvailability(false);
        // Ищем грузовик в списке truckList по ID или другим критериям
        for (auto& truck : truckList) {
            if (truck.getId() == request.getTruck().getId()) {
                truck.setAvailability(false); // Делаем грузовик недоступным
                request.setTruck(truck);
                break;
            }
        }
    }
 }




// Деструктор
Admin::~Admin() {}