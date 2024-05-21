cmake_minimum_required( VERSION 2.8 )

project(constraint_game_solver)

file( GLOB_RECURSE CGS_SOURCES src/*.cpp )


include_directories(include)

add_library( cgs
            ${CGS_SOURCES})

add_executable( constraint_game_solver
                apps/main.cpp)
                
target_link_libraries(constraint_game_solver
                        cgs)
