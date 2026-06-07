cmake_minimum_required(VERSION 4.1)
project(todo_list_c C)

set(CMAKE_C_STANDARD 11)

add_executable(todo_list_c main.c
        list.h
        list.c
        storage.c
        storage.h)
