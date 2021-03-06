cmake_minimum_required (VERSION 3.10)
project (HubballBot CXX)

set(CMAKE_CXX_STANDARD 17)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.14/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_check(VERSION 1.14.4 REQUIRED)
conan_add_remote(NAME bincrafters
                 URL https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP
                BUILD missing)

file(GLOB bot_SRC
    "src/*.h"
    "src/*.cpp")

add_compile_definitions(ASIO_STANDALONE)
add_executable(hb WIN32 ${bot_SRC})
target_link_libraries(hb ${CONAN_LIBS})

file(GLOB bot_assets ${CMAKE_CURRENT_SOURCE_DIR}/assets/*.*)

file(COPY ${bot_assets}
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
