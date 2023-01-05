cmake_minimum_required(VERSION 3.23)
project(mud_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(mud_game main.cpp origin_define.h Role.cpp Role.h Skills.cpp Skills.h Elixir.cpp Elixir.h Bag.cpp Bag.h Map.cpp Map.h Boss.h Boss.cpp Save_data.cpp Save_data.h Read_data.cpp Read_data.h Drug_store.cpp Drug_store.h Learning_skills.cpp Learning_skills.h Task.cpp Task.h Fight.cpp Fight.h origin_define.cpp)
