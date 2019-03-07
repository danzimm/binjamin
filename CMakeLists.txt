cmake_minimum_required(VERSION 3.13)

find_package(LLVM CONFIG REQUIRED)

add_library(objectFile SHARED lib/ObjectFile.cpp)
target_include_directories(objectFile PUBLIC include)
target_include_directories(objectFile SYSTEM PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_features(objectFile PRIVATE cxx_std_14)
if(NOT LLVM_ENABLE_RTTI)
  target_compile_options(objectFile PRIVATE -fno-rtti)
endif()
target_link_libraries(objectFile PRIVATE LLVMObject)
