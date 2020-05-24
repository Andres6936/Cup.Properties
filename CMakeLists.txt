CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(Cup VERSION 2020.523 LANGUAGES CXX)

ADD_LIBRARY(Cup Source/Readable.cpp)
SET_TARGET_PROPERTIES(Cup PROPERTIES CXX_STANDARD 17)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
TARGET_INCLUDE_DIRECTORIES(Cup
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include/>
            $<INSTALL_INTERFACE:Include/>
        PRIVATE
            # Used for the .cpp for avoid include from root
            Include/)


ADD_EXECUTABLE(ReadBinary Test/TestReadBinary.cpp)
SET_TARGET_PROPERTIES(ReadBinary PROPERTIES CXX_STANDARD 17)
TARGET_INCLUDE_DIRECTORIES(ReadBinary PRIVATE Include/)
TARGET_LINK_LIBRARIES(ReadBinary PRIVATE Cup)