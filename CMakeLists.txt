cmake_minimum_required(VERSION 3.14)
project(Task2_rebild_Aliev_Rauf)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

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
)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(
        RunTests
        tests/building_test.cpp
        tests/ConstructionManager_test.cpp
        src/Building.cpp
        src/ConstructionManager.cpp
        src/IWorker.cpp
        src/Architector.cpp
        src/Ingener.cpp
        src/Builder.cpp
)

target_link_libraries(RunTests PRIVATE gtest_main)