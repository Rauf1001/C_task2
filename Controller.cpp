#include "Controller.h"
#include "Interfaces/Builder.h"
#include "Interfaces/Architector.h"
#include "Interfaces/Ingener.h"
#include "Building.h"
#include <iostream>

using namespace std;

void Controller::writeController() {
    setlocale(LC_ALL, "");

    Building *myBuilding = nullptr;
    // Builder* myBuilder = nullptr;
    // Architector* myArchitector = nullptr;
    // Ingener* myIngener = nullptr;
    IWorker *currentWorker = nullptr;

    choice = -1;
    countPower = 0;


    while (choice != 0) {
        // cout << "====Управление Строительной Компанией====\n";
        // cout << "1.Создать объект стройки, 2.Нанять Рабочего, "
        //         "3.Начать следующую неделю, 4. Посмотреть Статистику, 0 - Выход \n";
        // cin >> choice;
        cout << "\n==== Управление Строительной Компанией ====\n";
        cout << "1. Создать объект стройки\n"
                << "2. Нанять Рабочего\n"
                << "3. Начать следующую неделю\n"
                << "4. Посмотреть Статистику\n"
                << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 1) {
            // cout << "====Новая Стройка====\n";
            // cout << "Введите Имя Объекта: \n";
            // cin >> tempName;
            // cout << "Введите количество этажей: \n";
            // cin >> tempFloor;
            // cout << "Введите площадь этажа: \n";
            // cin >> tempSquare;
            cout << "\n==== Новая Стройка ====\n";
            cout << "Введите Имя Объекта (одним словом): ";
            cin >> tempName;
            cout << "Введите количество этажей: ";
            cin >> tempFloor;
            cout << "Введите площадь этажа: ";
            cin >> tempSquare;

            myBuilding = new Building(tempName, tempFloor, tempSquare);
            cout << "\nУспешно создан объект " << myBuilding->getName() << "\nТекущая фаза: ";
            << myBuilding->showCurrentPhase(myBuilding->getCurrentPhase())
        }
        if (choice == 2) {
            cout << "====Нанять====\n";
            cout << "====1.Архитектора====\n";
            cout << "====2.Инженера====\n";
            cout << "====3.Строителя====\n" << endl;
            cin >> workerChoice;
            if (workerChoice == 1) {
                cout << "\nВведите Имя Архитектора: ";
                cin >> tempName;
                cout << "Введите Возраст: ";
                cin >> tempAge;

                myArchitector = new Architector(tempName, tempAge);
                countPower += myArchitector->getCoefficient();
                cout << "\nУспешно нанят " << myArchitector->getName()
                        << "\n(Коэффициент: " << myArchitector->getCoefficient() << ")" << endl;
            } else if (workerChoice == 2) {
                cout << "\nВведите Имя Строителя: ";
                cin >> tempName;
                cout << "Введите Возраст: ";
                cin >> tempAge;

                myBuilder = new Builder(tempName, tempAge);
                countPower += myBuilder->getCoefficient();
                cout << "\nУспешно нанят " << myBuilder->getName()
                        << "\n(Коэффициент: " << myBuilder->getCoefficient() << ")" << endl;
            } else if (workerChoice == 2) {
                cout << "\nВведите Имя Инженера: ";
                cin >> tempName;
                cout << "Введите Возраст: ";
                cin >> tempAge;

                myIngener = new Ingener(tempName, tempAge);
                countPower += myIngener->getCoefficient();
                cout << "\nУспешно нанят " << myIngener->getName()
                        << "\n(Коэффициент: " << myIngener->getCoefficient() << ")" << endl;
            }
        }
        if (choice == 3) {
            currentWeek += 1;
            cout << "====Текущая Неделя 'currentWeek'===='f'" << endl;
            myBuilding->countCurrentPhase(tempFloor, tempSquare, countPower, currentWeek);
            myBuilding->showCurrentPhase(myBuilding->getCurrentPhase());
        }
        if (choice == 4) {
            cout << "====Статистика====\n";
            cout << "====Текущая Неделя 'currentWeek'===='f'\n" << endl;
            cout << "====Текущая Фаза====\n";
            myBuilding->showCurrentPhase(myBuilding->getCurrentPhase());
            cout << "====Рабочие====\n";
            myArchitector->getName();
            myIngener->getName();
            myBuilder->getName();
            cout << "====Объекты====\n";
            myBuilding->getName();
            myBuilding->getFloor();
            myBuilding->getSquare();
        } else {
            cout << "====Завершение Программы====";
            choice = 0;
        }
    }
    delete myBuilding;
    delete myArchitector;
    delete myIngener;
    delete myBuilder;
}

// void Controller::clearMemorry() {
//     delete myBuilding;
//     delete myArchitector;
//     delete myIngener;
// }
