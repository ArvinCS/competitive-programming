#!/bin/bash

set NAME=timbang

g++ -o %NAME% grader.cpp %NAME%.cpp -O2 -lm -std=c++11