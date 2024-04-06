cmake_minimum_required(VERSION 3.26)
project(LaboratoriesWorks C)

set(CMAKE_C_STANDARD 11)

add_executable(LaboratoriesWorks main.c)
add_subdirectory(libs)
target_link_libraries(LaboratoriesWorks data_structures)
target_link_libraries(LaboratoriesWorks algorithms)

add_library(str string/string_.h string/string_.c
        # string/tasks/digitToStartTransform.h
        # string/tasks/reverseWords.h
        # string/tasks/replaceDigitsBySpaces.h
        # ...
        # < файл с решением задачи >
        # ...
        # string/tasks/hasPairOfWordsWithEqualLetterSet.h
        # string/tasks/printWordsNonEqualLastWord.h
)

target_link_libraries(LaboratoriesWorks str)