cmake_minimum_required(VERSION 3.10)
project(battleship_ivonnegattringer)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(battleship_ivonnegattringer
        battleship.cpp
        battleship.h
        battleship_test_driver.cpp
        mainpage.h
        shortcut.cpp
        shortcut.h
        test_battleship.cpp
        test_battleship.h
        test_file_setup.cpp
        test_file_setup.h)
