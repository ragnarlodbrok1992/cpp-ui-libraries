@echo off
rem NOT -  rmdir /s /q build\
rem NOT - rm CMakeUserPresets.json

conan install . -s build_type=Debug --build=missing
cmake --preset conan-default
cmake --build --preset conan-debug
.\build\Debug\cpp-ui-libraries.exe

