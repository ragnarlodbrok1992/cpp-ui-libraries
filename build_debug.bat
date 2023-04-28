@echo off
conan install . -s build_type=Debug
cmake --preset conan-default
cmake --build --preset conan-debug
.\build\Debug\cpp-ui-libraries.exe

