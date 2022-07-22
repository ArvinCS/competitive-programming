set NAME=communication

g++ -o %NAME% sample_grader.cpp %NAME%_sample.cpp %NAME%.h -O2 -lm -std=c++11