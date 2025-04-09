#!/bin/bash

g++ -march=native -Wall -o avx/sum_matrix ./avx/sum_matrix.cpp
g++ -march=native -Wall -o avx/sum_two_matrix ./avx/sum_two_matrix.cpp

g++ -Wall -o std/sum_matrix ./std/sum_matrix.cpp
g++ -Wall -o std/sum_two_matrix ./std/sum_two_matrix.cpp
