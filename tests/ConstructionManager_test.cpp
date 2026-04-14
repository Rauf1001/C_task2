#include <gtest/gtest.h>
#include "../include/ConstructionManager.h"

using namespace BuilderSim;

// ТЕСТ 4: Проверка успешного найма рабочего и добавления его в вектор
TEST(ConstructionManagerTest, HireWorker_ValidProfession_ReturnsTrueAndAddsToTeam) {
    // 1. ARRANGE (Подготовка)
    ConstructionManager manager;
    int initialCount = manager.getWorkersCount(); // Ожидаем 0
    
    int architectorType = 1;
    std::string name = "Ivan";
    int age = 30;

    // 2. ACT (Действие)
    // Нанимаем валидного рабочего (Тип 1 - Архитектор)
    bool result = manager.hireWorker(architectorType, name, age);

    // 3. ASSERT (Проверка)
    EXPECT_TRUE(result) << "Метод должен вернуть true при успешном найме.";
    EXPECT_EQ(manager.getWorkersCount(), initialCount + 1) << "Размер массива рабочих должен увеличиться на 1.";
}

// ТЕСТ 5: Защита от дурака - попытка нанять несуществующую профессию
TEST(ConstructionManagerTest, HireWorker_InvalidProfession_ReturnsFalseAndDoesNotAdd) {
    // 1. ARRANGE (Подготовка)
    ConstructionManager manager;
    int initialCount = manager.getWorkersCount(); // Ожидаем 0
    
    int invalidType = 99; // Такой профессии нет в нашем if-else
    std::string name = "ErrorMan";
    int age = 25;

    // 2. ACT (Действие)
    // Пытаемся нанять рабочего с несуществующим кодом
    bool result = manager.hireWorker(invalidType, name, age);

    // 3. ASSERT (Проверка)
    EXPECT_FALSE(result) << "Метод должен вернуть false, так как профессия не найдена.";
    EXPECT_EQ(manager.getWorkersCount(), initialCount) << "Размер массива не должен измениться, рабочий не должен быть добавлен.";
}