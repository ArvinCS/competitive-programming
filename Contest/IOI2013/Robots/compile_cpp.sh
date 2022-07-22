#!/bin/bash

NAME=robots

g++ -std=gnu++11 -O2 -Wall -pipe -static -o "${NAME}" "grader.cpp" "${NAME}.cpp"