cmake_minimum_required(VERSION 3.0)
project(csv_to_dgz)

set(CMAKE_CXX_STANDARD 20)

# cppファイルをビルド対象に加える
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 実行ファイルを作る
add_executable(csv_to_dgz ${SOURCES})

# 静的リンクする
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS) # Clear shared library flags
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS) # Clear shared library flags