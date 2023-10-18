cmake_minimum_required(VERSION 3.0)
project(csv_to_dgz)

set(CMAKE_CXX_STANDARD 20)

# cppファイルをビルド対象に加える
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 実行ファイルを作る
add_executable(csv_to_dgz ${SOURCES})

