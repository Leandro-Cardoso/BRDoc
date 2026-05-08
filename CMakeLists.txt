cmake_minimum_required(VERSION 3.20)
project(brdoc
    VERSION 1.0.0
    DESCRIPTION "Brazilian Document Library (CPF, CNPJ, RG)"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# =========================
# Biblioteca
# =========================
add_library(brdoc
    src/CPF.cpp
    src/CNPJ.cpp
    src/RG.cpp
    src/Validators.cpp
)

# INCLUDE HEADERS:
target_include_directories(brdoc
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# =========================
# Examples
# =========================
add_executable(cpf_example examples/cpf_example.cpp)
target_link_libraries(cpf_example PRIVATE brdoc)

add_executable(cnpj_example examples/cnpj_example.cpp)
target_link_libraries(cnpj_example PRIVATE brdoc)

add_executable(rg_example examples/rg_example.cpp)
target_link_libraries(rg_example PRIVATE brdoc)

add_executable(validators_example examples/validators_example.cpp)
target_link_libraries(validators_example PRIVATE brdoc)

add_executable(document_example examples/document_example.cpp)
target_link_libraries(document_example PRIVATE brdoc)

# =========================
# Tests
# =========================
enable_testing()

# GOOGLE TEST:
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# EXECUTABLES:
add_executable(tests
    tests/CPFTests.cpp
    tests/CNPJTests.cpp
    tests/RGTests.cpp
    tests/ValidatorsTests.cpp
    tests/DocumentTests.cpp
)

# LINK LIBRARIES:
target_link_libraries(tests
    PRIVATE
        brdoc
        gtest
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

# BUILD INSTRUCTIONS:
# cmake -S . -B build -G "MinGW Makefiles"
# cmake --build build
