#include "ConstructionManager.h"

#include <iostream>

#include "Building.h"
#include "Interfaces/Architector.h"
#include "Interfaces/Builder.h"
#include "Interfaces/Ingener.h"
using namespace std;

namespace BuilderSim {
    ConstructionManager::~ConstructionManager() {
        delete myBuilding;
        delete currentWorker;
    }

    void ConstructionManager::startProgram(string name ,int floor,double square) {
        delete myBuilding;
        myBuilding = new Building(name, floor, square);
        cout << "\nУспешно создан объект " << myBuilding->getName() << "\nТекущая фаза: ";
        myBuilding->showCurrentPhase();


    }
    // void Construction::showCurrentPhase() {
    //     if (currentPhase == 0) {
    //         cout << ("Архтектурная Фаза") << endl;
    //     } else if (currentPhase == 1) {
    //         cout << ("Инженерная Фаза") << endl;
    //     } else if (currentPhase == 2) {
    //         cout << ("Строительная Фаза") << endl;
    //     } else {
    //         cout << ("Строительство Успешно Закончено") << endl;
    //     }
    // }

    bool ConstructionManager::hireWorker(int type,string name, int  age) {
        delete currentWorker;
        currentWorker = nullptr;

        if (type == 1) {
            currentWorker = new Architector(name, age);
            powerArch += currentWorker->getCoefficient();
        }else if (type == 2) {
            currentWorker = new Ingener(name, age);
            powerIng += currentWorker->getCoefficient();
        }else if (type == 3) {
            currentWorker = new Builder(name, age);
            powerBuild += currentWorker->getCoefficient();
        }else {
            cout << "Ошибка выбора профессии!" << endl;
            return false;
            // continue; // Начинаем цикл заново
        }
        cout << format("\nУспешно нанят: {} (Коэф: {})",currentWorker->getName(),currentWorker->getCoefficient());

        return true;

    }

    // bool Construction::hireWorker(double powerArch, double powerIng, double powerBuild, int currentWeek) {
    //     if (currentPhase >= 3)
    //         return false;
    //
    //     // double powerInWeek = 0.0;
    //
    //     // const double phaseRequirement = (floor * square) / 3.0;
    //     // // const double powerInWeek = countArch * (currentWeek * 5.0);
    //     if (currentPhase == 0) {
    //         powerInWeek = powerArch * (currentWeek * 5.0);
    //     } else if (currentPhase == 1) {
    //         powerInWeek = powerIng * (currentWeek * 5.0);
    //     }else if  (currentPhase == 2){
    //         powerInWeek = powerBuild * (currentWeek * 5.0);
    //     }
    //
    //     const double phaseRequirement = (floor * square) / 3.0;
    //
    //
    //
    //     if (powerInWeek >= phaseRequirement) {
    //         currentPhase += 1;
    //         return true;
    //     }
    //     return false;
    // }

    void ConstructionManager::phaseChanged() {
        if (myBuilding == nullptr) {
            cout << "Ошибка: Сначала создайте объект (пункт 1)!" << endl;
            return;
        }
        currentWeek += 1;

        cout << "\n==== Наступила Неделя " << currentWeek << " ====" << endl;
        bool phaseChanged = myBuilding->countCurrentPhase(powerArch, powerIng, powerBuild, currentWeek);
        if (phaseChanged) {
            cout << ">>> ПРОГРЕСС! Стройка перешла на новый этап: ";
            myBuilding->showCurrentPhase();
        } else {
            cout << "Работа идет. Фаза пока прежняя: ";
            myBuilding->showCurrentPhase();
        }
    }

    void ConstructionManager::printStatics() {
        cout << "\n==== СТАТИСТИКА ====\n";
        cout << "Текущая неделя: " << currentWeek << "\n";
        cout << "====Текущая Фаза====\n";

        if (myBuilding != nullptr) {
            cout << "Объект: " << myBuilding->getName() << " (" << myBuilding->getFloor() << " эт., " << myBuilding
                    ->getSquare() << " м2)\n";
            cout << "Статус: ";
            myBuilding->showCurrentPhase();
        } else {
            cout << "Объектов нет.\n";
        }

        if (currentWorker != nullptr) {
            cout << "Текущий рабочий: " << currentWorker->getName() << " (Сила: " << powerInWeek << ")\n";
        } else {
            cout << "Рабочих нет.\n";
        }
    }
}
// void Construction::clearMemory() {
//     delete myBuilding;
//     myBuilding = nullptr;
//
//     delete currentWorker;
//     currentWorker = nullptr;
// }