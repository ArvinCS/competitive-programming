set NAME=backup

g++ -o %NAME% grader.cpp server.cpp client.cpp -O2 -lm -std=c++11