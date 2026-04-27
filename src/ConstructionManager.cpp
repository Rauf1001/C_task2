#include "../include/ConstructionManager.h"

#include <iostream>
#include <format>

#include "../include/Building.h"
#include "../include/Interfaces/Architector.h"
#include "../include/Interfaces/Builder.h"
#include "../include/Interfaces/Ingener.h"

using namespace std;

namespace BuilderSim {
    ConstructionManager::~ConstructionManager() {
        delete myBuilding;
        delete currentWorker;

        for (IWorker *worker: workers) {
            delete worker;
        }
        workers.clear();
    }

    void ConstructionManager::startProgram(string name, int floor, double square) {
        delete myBuilding;
        myBuilding = new Building(name, floor, square);
        cout << format("\nУспешно создан объект {}\nТекущая фаза: ", myBuilding->getName());
        myBuilding->showCurrentPhase();
    }

    bool ConstructionManager::hireWorker(int type, string name, int age) {
        delete currentWorker;
        currentWorker = nullptr;

        if (type == 1) {
            currentWorker = new Architector(name, age);
            powerArch += currentWorker->getCoefficient();
            workers.push_back(currentWorker);
        } else if (type == 2) {
            currentWorker = new Ingener(name, age);
            powerIng += currentWorker->getCoefficient();
            workers.push_back(currentWorker);
        } else if (type == 3) {
            currentWorker = new Builder(name, age);
            powerBuild += currentWorker->getCoefficient();
            workers.push_back(currentWorker);
        } else {
            cout << format("Ошибка выбора профессии!\n");
            return false;
        }
        cout << format("\nУспешно нанят: {} (Коэф: {})", currentWorker->getName(), currentWorker->getCoefficient());

        return true;
    }

    void ConstructionManager::phaseChanged() {
        if (myBuilding == nullptr) {
            cout << format("Ошибка: Сначала создайте объект (пункт 1)!\n");
            return;
        }
        currentWeek += 1;

        cout << format("\n==== Наступила Неделя {} ====\n", currentWeek);
        bool phaseChanged = myBuilding->countCurrentPhase(powerArch, powerIng, powerBuild, currentWeek);
        if (phaseChanged) {
            cout << format(">>> ПРОГРЕСС! Стройка перешла на новый этап: ");
            myBuilding->showCurrentPhase();
        } else {
            cout << format("Работа идет. Фаза пока прежняя: ");
            myBuilding->showCurrentPhase();
        }
    }

    void ConstructionManager::printStatics() {
        cout << format("\n==== СТАТИСТИКА ====\n");
        cout << format("Текущая неделя: {}\n", currentWeek);
        cout << format("====Текущая Фаза====\n");

        if (myBuilding != nullptr) {
            cout << format("Объект: {} ({} эт., {} м2)\n", myBuilding->getName(), myBuilding->getFloor(),
                           myBuilding->getSquare());
            cout << format("Статус: ");
            myBuilding->showCurrentPhase();
        } else {
            cout << format("Объектов нет.\n");
        }

        if (currentWorker != nullptr) {
            for (int i = 0; i < workers.size(); i++) {
                cout << format("Текущий рабочий: {} (Сила: {})\n", currentWorker->getName(),
                               currentWorker->getCoefficient());
            }
        } else {
            cout << format("Рабочих нет.\n");
        }
    }
}
