# PS3: DNA Sequence Alignment

## What is this assignment:  
The purpose of this assignment was to create a program to compute the optimal sequence
alignment of two DNA strings. In this assignment we measured the similarity of two genetic
sequences by their edit distance. If there is a gap in the DNA sequence a two will be produced, if
the characters are mismatched a one is produced, and if they match a zero is produced.

## What was accomplished:  
What I accomplished in this assignment was creating a program that is able to read a file with
two sequences and have it compare it with one another. I was also able to have it calculate and
print the cost when comparing both sequences. As well as getting the final total of the cost/score.

## Key algorithms:  
The algorithm used in this assignment was the Needleman-Wunsch method. It was an algorithm
that was used to keep an alignment of sequences and have them be compared easier. My program
read each string from the example input file provided. Took each string and compared it to one
another for a gap, match, or difference.

## Data Structures:  
In this assignment it was needed to use dynamic programming in order to accomplish this. When
comparing the strings you needed to figure out if they matched, mismatched or if there was a
gap. Using a stack data structure method was also key because in order to compare the strings
they needed to be kept in the same order as they were originally.

![p3](https://github.com/JustinCheok/PS3-DNA-Sequence-Alignment/assets/80936005/8f97a182-1d38-499d-a602-24bcafc5575e)
