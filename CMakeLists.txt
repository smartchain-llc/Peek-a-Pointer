cmake_minimum_required(VERSION 3.20)

project(peekapointer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(core)

option(BUILD_TESTS "Build BDD Test Executables" OFF)
if(${BUILD_TESTS})
  message("== [PAP] Building Test Files")
  include(FetchContent)
  FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )
  FetchContent_MakeAvailable(googletest)
  
  enable_testing()

  include(GoogleTest)
  add_subdirectory(tests)
endif()
