cmake_minimum_required(VERSION 4.1)
project(Task2_rebild_Aliev_Rauf)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Task2_rebild_Aliev_Rauf
        main.cpp
        Building.cpp
        Building.h
        Interfaces/IWorker.cpp
        Interfaces/IWorker.h
        Builder.cpp
        Builder.h
        Interfaces/Architector.cpp
        Interfaces/Architector.h
        Interfaces/Ingener.cpp
        Interfaces/Ingener.h
)
