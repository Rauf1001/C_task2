#cmake_minimum_required(VERSION 3.14)
#project(BuilderSim)
#
## Включаем C++20 (обязательно для <format>!)
#set(CMAKE_CXX_STANDARD 20)
#
## 1. СКАЧИВАЕМ GOOGLE TEST
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG        release-1.12.1
#)
#FetchContent_MakeAvailable(googletest)
#
## 2. СОБИРАЕМ ТЕСТОВЫЙ ФАЙЛ
## Здесь нужно перечислить файл с тестами И все твои .cpp файлы, которые ты тестируешь!
#add_executable(RunTests
#        tests/building_test.cpp         # Твой файл с тестами
#        src/Building.cpp                # Файл реализации здания
#        src/ConstructionManager.cpp     # Файл реализации менеджера
#        # src/Interfaces/IWorker.cpp    # (Раскомментируй, если у тебя IWorker в отдельном .cpp)
#)
#
## 3. ЛИНКУЕМ БИБЛИОТЕКУ
## Привязываем скачанный GTest к нашему исполняемому файлу RunTests
#target_link_libraries(RunTests PRIVATE gtest_main)