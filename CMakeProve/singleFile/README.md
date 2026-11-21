# firs Project for understand CMake

single file build

## usage

1. create an  **CMakeList.txt**  to make it read to the CMake build

2. configure the file

    to require a minimun of an version

    ``` CMake
        cmake_minimun_require( VERSION 4.4.5 )
    ```

    set a project and the executable name

    ```CMake
        project( Project )
        add_executable( Project )
    ```

    target the executable to the file

    ```CMake
        target_source( Project PRIVATE main.c  )
    ```

3. biuld the CMake directory

    for build the directory, pass in the call " build "

    ```bash
        cmake -S . -B build
    ```

    for build the executable wiht the cmake specification

    ```bash
        cmake --build build
    ```

