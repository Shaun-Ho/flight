#!/bin/bash
cd build
cmake ..
cd ..
cmake --build build && ctest --test-dir build