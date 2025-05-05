# ADA-Lab

A curated collection of programs focused on Advanced Design and Algorithms (ADA). This repository is developed as part of academic coursework and includes algorithmic problem solutions and performance evaluation.

## Table of Contents

- [Introduction](#introduction)
- [Program Structure](#program-structure)
  - [Lab 1](#lab-1)
  - [Lab 2](#lab-2)
  - [Lab 3](#lab-3)
  - [Lab 4](#lab-4)
  - [Lab 5](#lab-5)
  - [Lab 6](#lab-6)
  - [LeetCode Practice](#leetcode-practice)

## Introduction

This repository contains various programs implemented in C, aimed at understanding and applying advanced algorithmic techniques such as sorting, stack manipulation, queue handling, greedy methods, divide and conquer, and graph algorithms. The repository includes visual outputs for performance evaluation of sorting algorithms.

## Program Structure

### Lab 1

- **946. Validate Stack Sequences** (`946. Validate Stack Sequences.c`): Implements stack simulation to validate whether a given pop sequence is valid for a given push sequence.
- **1944. Number of Visible People in a Queue** (`1944. Number of Visible People in a Queue.c`): Solves a queue-based problem using a monotonic stack to determine visibility counts efficiently.

### Lab 2

- **700. Number of Students Unable to Eat Lunch** (`700. Number of Students Unable to Eat Lunch.c`): Implements queue simulation to find how many students cannot eat lunch based on preference matching.
- **Selection Sort Implementation**:
  - `SelectionSort.c`: Core implementation of the selection sort algorithm. This program provides options for manual entry of array elements and displays the time taken to sort arrays of different sizes.
  - `SelectionSort.exe`: Executable for Windows users to run the program directly.
  - `SelectionSortGraph.pdf`: Performance graph showing time taken for various input sizes.
  - `SelectionSortOutput.png`: Sample output screenshot of the program execution.

### Lab 3

- **Merge Sort Implementation**:
  - `MergeSort.c`: C implementation of the merge sort algorithm using divide and conquer. Efficient for large datasets with a time complexity of O(n log n).
  - `MergeSort.exe`: Executable version for running the program on Windows.
  - `MergeSort graph.pdf`: Graph illustrating the time complexity and performance of merge sort for varying input sizes.
  - `Merge Sort vs Selection Sort graph.pdf`: Comparative graph analyzing the performance of merge sort versus selection sort across different datasets.

### Lab 4

- **Stack and Queue Problems**: Additional stack and queue-based algorithmic problems and their C implementations.

### Lab 5

- **Prim's Algorithm** (`Prims.c`): C program to find the Minimum Spanning Tree (MST) of a graph using Prim's algorithm. Takes user input for the adjacency matrix.
- **Other Greedy Algorithms**: Implementations of classic greedy algorithms.

### Lab 6

- **Knapsack Problem** (`Knapsack.c`): C program for the 0/1 Knapsack problem using dynamic programming. Takes user input and displays the DP table and selected items in tabular format.
- **Dijkstra's Algorithm** (`Dijkstra.c`): C program to find the shortest path from a source vertex to all other vertices using Dijkstra's algorithm. Accepts adjacency matrix input with 9999 as infinity.

### LeetCode Practice

- **155. Min Stack** (`155_MINSTACK.c`): Implementation of a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Feel free to explore the folders and files to understand the implementation of various algorithms and solutions to different problems.
