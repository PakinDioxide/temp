#!/bin/bash


for idk in {1..25}; do
    g++ gen.cpp -o gen && ./gen > inp.txt
    g++ solution_bug.cpp -o solution.out && python3 testing_tool.py ./solution.out < inp.txt > out.txt && cat out.txt
done
