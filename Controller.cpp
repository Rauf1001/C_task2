#include "Controller.h"

#include "Building.h"
#include <iostream>
#include <format>

#include "ConstructionManager.h"

using namespace std;

namespace BuilderSim {
    void Controller::writeController() {
        setlocale(LC_ALL, "");

        ConstructionManager company;

        while (choice != 0) {
            cout << format("\n==== Управление Строительной Компанией ====\n");
            cout << format("1. Создать объект стройки\n"
                           "2. Нанять Рабочего\n"
                           "3. Начать следующую неделю\n"
                           "4. Посмотреть Статистику\n"
                           "0. Выход\n");
            cout << format("Ваш выбор: ");
            cin >> choice;

            if (choice == 1) {
                cout << format("\n==== Новая Стройка ====\n");
                cout << format("Введите Имя Объекта (одним словом): ");

                cin.ignore();
                getline(cin, tempName);

                cout << format("Введите количество этажей: ");
                cin >> tempFloor;
                cout << format("Введите площадь этажа: ");
                cin >> tempSquare;

                company.startProgram(tempName, tempFloor, tempSquare);
            } else if (choice == 2) {
                cout << format("\n==== Нанять Рабочего ====\n");
                cout << format("1. Архитектор\n2. Инженер\n3. Строитель\nВаш выбор: ");
                cin >> workerChoice;

                cout << format("Введите Имя: ");
                cin.ignore();
                getline(cin, tempName);

                cout << format("Введите Возраст: ");
                cin >> tempAge;

                company.hireWorker(workerChoice, tempName, tempAge);
            } else if (choice == 3) {
                company.phaseChanged();
            } else if (choice == 4) {
                company.printStatics();
            } else if (choice == 0) {
                cout << format("Завершение Программы...\n");
            } else {
                cout << format("Неверный ввод!\n");
            }
        }
    }
}