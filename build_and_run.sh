#!/bin/bash
cd build
cmake ..
cd ..
cmake --build build
build/bin/flight