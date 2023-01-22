#!/usr/bin/env bash

rm -rf build
mkdir build
cd build
conan install .. -pr:h=../conan/profiles/linux_debug
cd ..
cmake --preset debug
