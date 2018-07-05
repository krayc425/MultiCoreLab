#!/bin/sh
g++ -c pi_omp.cpp -fopenmp -fpermissive
g++ pi_omp.o -o pi_omp -fopenmp
./pi_omp