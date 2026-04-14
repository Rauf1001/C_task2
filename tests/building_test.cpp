#include <gtest/gtest.h>
#include "../include/Building.h"

using namespace BuilderSim;

// ТЕСТ 1: Стандартный объект (ЖК Финист) и расчет времени перехода первой фазы
TEST(BuildingTest, CountCurrentPhase_FinistComplex_TransitionsOnCalculatedWeek) {
    // 1. ARRANGE (Подготовка)
    // Объект: 16 этажей, 1000 кв.м.
    // Формула фазы: (16 * 1000) / 3.0 = 5333.33
    Building finist("ЖК_Финист", 16, 1000.0);
    
    // Имитируем 10 рабочих каждого типа. Допустим, средний коэффициент = 1.0.
    double powerArch = 10.0; 
    double powerIng = 10.0;
    double powerBuild = 10.0;
    
    // Сила за неделю = powerArch * (week * 5.0).
    // Нам нужно: 10.0 * (week * 5.0) >= 5333.33 -> 50.0 * week >= 5333.33
    // Ожидаемая неделя перехода = 107 (50 * 107 = 5350.0).
    int weekBeforeTransition = 106;
    int weekOfTransition = 107;

    // 2. ACT & ASSERT (Действие и Проверка)
    
    // Проверяем 106-ю неделю (силы должно чуть-чуть не хватить: 5300 < 5333.33)
    bool isChangedBefore = finist.countCurrentPhase(powerArch, powerIng, powerBuild, weekBeforeTransition);
    EXPECT_FALSE(isChangedBefore) << "Фаза не должна была смениться на 106 неделе.";
    EXPECT_EQ(finist.getCurrentPhase(), 0) << "Объект должен оставаться в Архитектурной фазе.";

    // Проверяем 107-ю неделю (силы хватает: 5350 >= 5333.33)
    bool isChangedNow = finist.countCurrentPhase(powerArch, powerIng, powerBuild, weekOfTransition);
    EXPECT_TRUE(isChangedNow) << "Фаза должна была смениться на 107 неделе.";
    EXPECT_EQ(finist.getCurrentPhase(), 1) << "Объект должен перейти в Инженерную фазу.";
}

// ТЕСТ 2: Краевой случай (Сверхмассивный объект 1000x1000)
TEST(BuildingTest, CountCurrentPhase_MassiveProject_RequiresProportionalPower) {
    // 1. ARRANGE (Подготовка)
    // Объект: 1000 этажей, 1000 кв.м.
    // Формула фазы: (1000 * 1000) / 3.0 = 333333.33
    Building megaTower("MegaTower", 1000, 1000.0);
    
    double powerArch = 10.0; // 10 архитекторов
    double powerIng = 0.0;
    double powerBuild = 0.0;

    // Требуемая неделя: 50.0 * week >= 333333.33 -> week = 6667
    int exactTransitionWeek = 6667; 

    // 2. ACT (Действие)
    bool result = megaTower.countCurrentPhase(powerArch, powerIng, powerBuild, exactTransitionWeek);

    // 3. ASSERT (Проверка)
    EXPECT_TRUE(result) << "Огромный объект должен переходить на следующую фазу при накоплении гигантской силы.";
    EXPECT_EQ(megaTower.getCurrentPhase(), 1);
}

// ТЕСТ 3: Защита от выхода за пределы массива фаз (Безопасность методов)
TEST(BuildingTest, CountCurrentPhase_MaxPhaseReached_ReturnsFalseAndIgnoresPower) {
    // 1. ARRANGE (Подготовка)
    Building b("FinishedHouse", 5, 100.0);
    
    // Искусственно переводим здание в максимальную фазу (3 - Завершено)
    b.setCurrentPhase(3); 
    
    // Имитируем колоссальную силу, которая могла бы пробить лимиты
    double maxPower = 999999.0;
    int currentWeek = 100;

    // 2. ACT (Действие)
    // Пытаемся продолжить стройку
    bool result = b.countCurrentPhase(maxPower, maxPower, maxPower, currentWeek);

    // 3. ASSERT (Проверка)
    EXPECT_FALSE(result) << "Метод обязан возвращать false, если стройка уже завершена (защита от переполнения фаз).";
    EXPECT_EQ(b.getCurrentPhase(), 3) << "Фаза не должна увеличиваться больше 3.";
}