cmake_minimum_required(VERSION 3.15)
project(cpp-ui-libraries CXX)

add_executable(cpp-ui-libraries src/cpp-ui-libraries.cpp src/main.cpp)

find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)

target_link_libraries(cpp-ui-libraries glad::glad glfw)

install(TARGETS cpp-ui-libraries DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
