cmake_minimum_required(VERSION 3.20)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project
        main.cpp
        Event.cpp
        EventScheduling.cpp
        HashMap.cpp
        MinHeap.cpp
        Note.cpp
        NoteManager.cpp
        TaskLinkedList.cpp
        TaskNode.cpp
)