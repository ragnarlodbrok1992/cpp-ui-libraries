cmake_minimum_required(VERSION 3.15)
project(cpp-ui-libraries CXX)



add_executable(cpp-ui-libraries src/cpp-ui-libraries.cpp src/main.cpp)



install(TARGETS cpp-ui-libraries DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
