#include "CLASS_HISTORY.h"







void History::undo(List<Car>& carList, List<MotoBike>& motoList, List<Truck>& truckList)
{
    if (actionStack.empty()) {
        std::cout << "Нет действий для отмены.\n";
        return;
    }

    // Извлекаем последнее действие из стека
    Action lastAction = std::move(actionStack.top());    
    actionStack.pop(); // Удаляем последнее действие из стека

    switch (lastAction.getActionType()) {
    case Action::Type::Add: {
        // Отмена добавления (удаляем объект из списка)
        if (lastAction.getVehicleType() == Action::VehicleType::Car) {
            carList.remove_by_index(lastAction.getIndex());
            std::cout << "Удален автомобиль с индексом " << lastAction.getIndex() << std::endl;
        }
        else if (lastAction.getVehicleType() == Action::VehicleType::MotoBike) {
            motoList.remove_by_index(lastAction.getIndex());
            std::cout << "Удален мотоцикл с индексом " << lastAction.getIndex() << std::endl;
        }
        else if (lastAction.getVehicleType() == Action::VehicleType::Truck) {
            truckList.remove_by_index(lastAction.getIndex());
            std::cout << "Удален грузовик с индексом " << lastAction.getIndex() << std::endl;
        }
        break;
    }

    case Action::Type::Delete: {
        // Отмена удаления (восстановление объекта в список)
        if (lastAction.getVehicleType() == Action::VehicleType::Car) {
            carList.insert(lastAction.getIndex(), lastAction.getCarData());

            std::cout << "Восстановлен автомобиль с индексом " << lastAction.getIndex() << std::endl;
        }
        else if (lastAction.getVehicleType() == Action::VehicleType::MotoBike) {
            motoList.insert(lastAction.getIndex(), lastAction.getMotoData());
            std::cout << "Восстановлен мотоцикл с индексом " << lastAction.getIndex() << std::endl;
        }
        else if (lastAction.getVehicleType() == Action::VehicleType::Truck) {
            truckList.insert(lastAction.getIndex(), lastAction.getTruckData());
            std::cout << "Восстановлен грузовик с индексом " << lastAction.getIndex() << std::endl;
        }
        break;
    }

    case Action::Type::Edit: {
        // Отмена редактирования (восстановление старых данных)
        if (lastAction.getVehicleType() == Action::VehicleType::Car) {
            int index = lastAction.getIndex();
            if (index < 0 || index >= carList.GetSize()) {
                std::cerr << "Ошибка: индекс " << index << " вне диапазона. Размер списка: " << carList.GetSize() << std::endl;
                return;
            }
            // Заменить текущий объект автомобиля на его прошлое состояние
            carList.replace(lastAction.getIndex(), lastAction.getCarData());     
            std::cout << "Восстановлен автомобиль с индексом " << lastAction.getIndex() << std::endl;
        }
        else if (lastAction.getVehicleType() == Action::VehicleType::MotoBike) {
            int index = lastAction.getIndex();
            if (index < 0 || index >= motoList.GetSize()) {
                std::cerr << "Ошибка: индекс " << index << " вне диапазона. Размер списка: " << motoList.GetSize() << std::endl;
                return;
            }
            // Заменить текущий объект мотоцикла на его прошлое состояние
            motoList.replace(lastAction.getIndex(), lastAction.getMotoData());
            std::cout << "Восстановлен мотоцикл с индексом " << lastAction.getIndex() << std::endl;
        }
        else if (lastAction.getVehicleType() == Action::VehicleType::Truck) {
            int index = lastAction.getIndex();
            if (index < 0 || index >= truckList.GetSize()) {
                std::cerr << "Ошибка: индекс " << index << " вне диапазона. Размер списка: " << truckList.GetSize() << std::endl;
                return;
            }
            // Заменить текущий объект грузовика на его прошлое состояние
            truckList.replace(lastAction.getIndex(), lastAction.getTruckData());
            std::cout << "Восстановлен грузовик с индексом " << lastAction.getIndex() << std::endl;
        }
        break;
    }

    default:
        std::cout << "Неизвестный тип действия.\n";
        break;
    }
}
