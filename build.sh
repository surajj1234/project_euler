#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Example usage : $./build.sh problem1.cpp"
    exit
fi

cd libHelper/
make
cd ..
g++ -fdiagnostics-color=always -std=c++11 $1 -IlibHelper/include -LlibHelper/lib -lHelper -o temp.out && ./temp.out && rm temp.out
