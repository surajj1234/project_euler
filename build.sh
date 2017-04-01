#!/bin/bash

# Example usage : $./build.sh problem1.cpp

g++ -std=c++11 $1 -o temp.out && ./temp.out && rm temp.out
