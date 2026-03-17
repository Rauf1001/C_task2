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
    IWorker *currentWorker = nullptr;

    choice = -1;
    countPower = 0;


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
            cin >> tempName;
            cout << "Введите количество этажей: ";
            cin >> tempFloor;
            cout << "Введите площадь этажа: ";
            cin >> tempSquare;

            myBuilding = new Building(tempName, tempFloor, tempSquare);
            cout << "\nУспешно создан объект " << myBuilding->getName() << "\nТекущая фаза: ";
            myBuilding->showCurrentPhase();
        } else if (choice == 2) {
            cout << "\n==== Нанять Рабочего ====\n";
            cout << "1. Архитектор\n2. Инженер\n3. Строитель\nВаш выбор: ";
            cin >> workerChoice;

            cout << "Введите Имя: ";
            cin >> tempName;
            cout << "Введите Возраст: ";
            cin >> tempAge;

            if (currentWorker != nullptr) delete currentWorker;

            if (workerChoice == 1) currentWorker = new Architector(tempName, tempAge);
            else if (workerChoice == 2) currentWorker = new Ingener(tempName, tempAge);
            else if (workerChoice == 3) currentWorker = new Builder(tempName, tempAge);
            else {
                cout << "Ошибка выбора профессии!" << endl;
                continue; // Начинаем цикл заново
            }
            countPower += currentWorker->getCoefficient();
            cout << "\nУспешно нанят: " << currentWorker->getName()
                    << " (Коэф: " << currentWorker->getCoefficient() << ")" << endl;
        } else if (choice == 3) {
            if (myBuilding == nullptr) {
                cout << "Ошибка: Сначала создайте объект (пункт 1)!" << endl;
                continue;
            }
            currentWeek += 1;
            cout << "\n==== Наступила Неделя " << currentWeek << " ====" << endl;
            bool phaseChanged = myBuilding->countCurrentPhase(countPower, currentWeek);
            if (phaseChanged) {
                cout << ">>> ПРОГРЕСС! Стройка перешла на новый этап: ";
                myBuilding->showCurrentPhase();
            } else {
                cout << "Работа идет. Фаза пока прежняя: ";
                myBuilding->showCurrentPhase();
            }
        }
        if (choice == 4) {
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
                cout << "Текущий рабочий: " << currentWorker->getName() << " (Сила: " << countPower << ")\n";
            } else {
                cout << "Рабочих нет.\n";
            }
        } else if (choice == 0) {
            cout << "Завершение Программы...\n";
        } else {
            cout << "Неверный ввод!\n";
        }
    }
    // Очистка памяти при выходе
    if (myBuilding != nullptr) delete myBuilding;
    if (currentWorker != nullptr) delete currentWorker;
}


// void Controller::clearMemorry() {
//     delete myBuilding;
//     delete myArchitector;
//     delete myIngener;
// }
