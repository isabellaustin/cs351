# Project 1: Joule Thief (CS351 - Algorithms)
BY: Isabell Austin, Noah Baker, and Anna Vadella

DUE: Tuesday, October 10th, 2023

# Deliverables
item.h: our implementation of provided base code

fileBuilder.cpp: program to generate text files

driver.cpp: greedy algorithm program for 0-1 knapsack <!-- (digital) -->

jouleTest10.txt: text file input for knapsackRun10.txt

knapsackRun10.txt: sample run with 10 items

jouleTest20.txt: text file input for knapsackRun20.txt

knapsackRun20.txt: sample run with 20 items

# How to Run (Format & Instructions) <!-- (digital) -->

## Format:
itemArray: array of items to be enqueued into the main priority queue pq

chosenArray: array of items chosen to be in the knapsack (dequeued from priority queue pq and enqueued into the knapsack priority queue knapsack)

sackArray: array of items in the priority queue knapsack

## Instructions:
To generate text files for testing:
```bash
g++ fileBuilder.cpp
a.out
```

To generate final knapsack run output:
```bash
g++ driver.cpp
a.out
```