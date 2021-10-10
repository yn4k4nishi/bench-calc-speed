cmake_minimum_required(VERSION 3.10)
project(SolveSimultaneousLinearEq)

find_package(Eigen3 REQUIRED)

add_library(matplotlib_cpp INTERFACE)
target_include_directories(matplotlib_cpp
  INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/examples>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(matplotlib_cpp INTERFACE
  cxx_std_11
)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
target_link_libraries(matplotlib_cpp INTERFACE
  Python3::Python
  Python3::Module
)
find_package(Python3 COMPONENTS NumPy)
if(Python3_NumPy_FOUND)
  target_link_libraries(matplotlib_cpp INTERFACE
    Python3::NumPy
  )
else()
  target_compile_definitions(matplotlib_cpp INTERFACE WITHOUT_NUMPY)
endif()
install(
  TARGETS matplotlib_cpp
  EXPORT install_targets
)

include_directories(
    EIGEN3_INCLUDE_DIR
    matplotlib_cpp
)

add_executable(problem_generator problem_generator/main.cpp)
target_link_libraries(problem_generator Eigen3::Eigen matplotlib_cpp)
