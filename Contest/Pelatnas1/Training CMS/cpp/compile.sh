#!/bin/bash

problem=towns
grader_name=stub

g++ -std=gnu++11 -O2 -Wall -pipe -static -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"