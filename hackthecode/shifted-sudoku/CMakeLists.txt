project(ShiftedSudoku)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
include_directories(src/utils)

file(GLOB SOURCES
    src/*.cpp
    src/utils/*.cpp
)

add_executable(shifted_sudoku ${SOURCES})