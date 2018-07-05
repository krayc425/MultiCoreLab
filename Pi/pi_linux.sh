#!/bin/sh
g++ -c pi_linux.cpp -pthread -fpermissive
g++ pi_linux.o -o pi_linux -pthread
./pi_linux
