cmake_minimum_required(VERSION 4.1)
project(Task2_rebild_Aliev_Rauf)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Task2_rebild_Aliev_Rauf
        src/main.cpp
        src/Building.cpp
        include/Building.h
        include/Interfaces/IWorker.h
        src/Builder.cpp
        include/Interfaces/Builder.h
        src/Architector.cpp
        include/Interfaces/Architector.h
        src/Ingener.cpp
        include/Interfaces/Ingener.h
        src/IWorker.cpp
        src/Controller.cpp
        include/Controller.h
        src/ConstructionManager.cpp
        include/ConstructionManager.h
        tests/building_test.cpp
        tests/ConstructionManager_test.cpp
)
