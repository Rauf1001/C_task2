#include "Controller.h"
#include "Interfaces/Builder.h"
#include "Interfaces/Architector.h"
#include "Interfaces/Ingener.h"
#include "Building.h"
#include <iostream>
#include <format>

#include "ConstructionManager.h"

using namespace std;
namespace BuilderSim {
    void Controller::writeController() {
        setlocale(LC_ALL, "");

        // Building *myBuilding = nullptr;
        // IWorker *currentWorker = nullptr;
        ConstructionManager company;

        // choice = -1;
        // countPower = 0;
        // workerChoice = -1;
        // currentWeek = 1;


        while (choice != 0) {
            cout << "\n==== Управление Строительной Компанией ====\n";
            cout << "1. Создать объект стройки\n"
                    << "2. Нанять Рабочего\n"
                    << "3. Начать следующую неделю\n"
                    << "4. Посмотреть Статистику\n"
                    << "0. Выход\n";
            cout << "Ваш выбор: ";
            cin >> choice;

            if (choice == 1) {
                cout << "\n==== Новая Стройка ====\n";
                cout << "Введите Имя Объекта (одним словом): ";

                cin.ignore();
                getline(cin,tempName);
                // cin >> tempName;

                cout << "Введите количество этажей: ";
                cin >> tempFloor;
                cout << "Введите площадь этажа: ";
                cin >> tempSquare;

                // myBuilding = new Building(tempName, tempFloor, tempSquare);
                // cout << "\nУспешно создан объект " << myBuilding->getName() << "\nТекущая фаза: ";
                company.startProgram(tempName,tempFloor,tempSquare);
                // company.showCurrentPhase();
                // myBuilding->showCurrentPhase();
            } else if (choice == 2) {
                cout << "\n==== Нанять Рабочего ====\n";
                cout << "1. Архитектор\n2. Инженер\n3. Строитель\nВаш выбор: ";
                cin >> workerChoice;

                cout << "Введите Имя: ";
                cin.ignore();
                getline(cin,tempName);

                // cin >> tempName;
                cout << "Введите Возраст: ";
                cin >> tempAge;

                company.hireWorker(workerChoice,tempName,tempAge);

                // if (currentWorker != nullptr) delete currentWorker;
                // delete currentWorker;
                // currentWorker = nullptr;
                //
                // if (workerChoice == 1) {
                //     currentWorker = new Architector(tempName, tempAge);
                //     powerArch += currentWorker->getCoefficient();
                // }else if (workerChoice == 2) {
                //     currentWorker = new Ingener(tempName, tempAge);
                //     powerIng += currentWorker->getCoefficient();
                // }else if (workerChoice == 3) {
                //     currentWorker = new Builder(tempName, tempAge);
                //     powerBuild += currentWorker->getCoefficient();
                // }else {
                //     cout << "Ошибка выбора профессии!" << endl;
                //     continue; // Начинаем цикл заново
                // }
                // countPower += currentWorker->getCoefficient();



                // cout << format("\nУспешно нанят: {} (Коэф: {})",currentWorker->getName(),currentWorker->getCoefficient());


                // cout << "\nУспешно нанят: " << currentWorker->getName()
                //         << " (Коэф: " << currentWorker->getCoefficient() << ")" << endl;
            } else if (choice == 3) {
                // if (myBuilding == nullptr) {
                //     cout << "Ошибка: Сначала создайте объект (пункт 1)!" << endl;
                //     continue;
                // }
                company.phaseChanged();


                // currentWeek += 1;
                // powerInWeek = myBuilding->countCurrentPhase(powerArch, powerIng, powerBuild, currentWeek);

                // cout << "\n==== Наступила Неделя " << currentWeek << " ====" << endl;
                // company.phaseChanged();
                // bool phaseChanged = myBuilding->countCurrentPhase(powerArch, powerIng, powerBuild, currentWeek);
                // if (phaseChanged) {
                //     cout << ">>> ПРОГРЕСС! Стройка перешла на новый этап: ";
                //     myBuilding->showCurrentPhase();
                // } else {
                //     cout << "Работа идет. Фаза пока прежняя: ";
                //     myBuilding->showCurrentPhase();
                //

            } else if (choice == 4) {
                // cout << "\n==== СТАТИСТИКА ====\n";
                // cout << "Текущая неделя: " << currentWeek << "\n";
                // cout << "====Текущая Фаза====\n";
                //
                // if (myBuilding != nullptr) {
                //     cout << "Объект: " << myBuilding->getName() << " (" << myBuilding->getFloor() << " эт., " << myBuilding
                //             ->getSquare() << " м2)\n";
                //     cout << "Статус: ";
                //     myBuilding->showCurrentPhase();
                // } else {
                //     cout << "Объектов нет.\n";
                // }
                //
                // if (currentWorker != nullptr) {
                //     cout << "Текущий рабочий: " << currentWorker->getName() << " (Сила: " << powerInWeek << ")\n";
                // } else {
                //     cout << "Рабочих нет.\n";
                // }
                company.printStatics();
            } else if (choice == 0) {
                cout << "Завершение Программы...\n";
            } else {
                cout << "Неверный ввод!\n";
            }
        }


        // Очистка памяти при выходе
        // if (myBuilding != nullptr)
        //     delete myBuilding;
        // myBuilding = nullptr;
        // if (currentWorker != nullptr)
        //     delete currentWorker;

        // company.clearMemory();
        // delete myBuilding;
        // myBuilding = nullptr;
        //
        // delete currentWorker;
        // currentWorker = nullptr;

    }
}

// void Controller::clearMemorry() {
//     delete myBuilding;
//     delete myArchitector;
//     delete myIngener;
// }
