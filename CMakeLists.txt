cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(Monopoly)

include_directories(include)

add_library(${PROJECT_NAME} SHARED
  src/Casella.cpp
  src/Giocatore.cpp
  src/Turno.cpp
  src/Dadi.cpp
  src/Tabellone.cpp
  src/Banca.cpp
  )

add_executable(main src/main.cpp)

target_link_libraries(main ${PROJECT_NAME})
