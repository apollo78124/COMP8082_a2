#ifndef SEQUENCEALIGNMENT_H
#define SEQUENCEALIGNMENT_H

#include <string>
#include <iostream>

using namespace std;

/**
 * This question requires you to implement the Needleman-Wunsch String Alignment Algorithm for two sequences s1 and s2.
 *  This algorithm has many applications including one in Genome Sequencing.
 *  You are given two sequences like "HeLLO How ARE YOU?" and "HELO How are yo?"
 *  You intend to align the two sequences like the following.
 *  "HeLLO How AR_ YOU?"
 *  "HEL_O How are yo_?"
 *  In this process, you also find the minimum cost of performing this mapping considering two parameters:
 *    1. mismatch penalty: the penalty for each letter if it is matched to another letter other than itself.
 *    2. gap penalty: the penalty for inserting a gap character ("_") between the two characters.
 *
 *  You will be able to calculate the alignment cost like the following example, given a mismatch penalty of 1 and a
 *   gap penalty of 2:
 *  " H e L L O H o w A R _ Y O U ?"
 *  " H E L _ O H o w a r e y o _ ?"
 *    0+1+0+2+0+0+0+0+1+1+2+1+1+2+0 = 11
 *
 *  However, you could also do a very bad job at alignment:
 *  " H e L L O H o w A R _ Y O U ?"
 *  " H E L O H o w a r e y o _ ? _"
 *    0+1+0+1+1+1+1+1+1+1+2+1+2+1+2 = 16
 *  You want to choose the alignment that leads to the least value for the total cost.
 *
 *  Once your implementation is done you must have transformed the passed in strings into a perfectly aligned pair,
 *   and you must return the minimum cost of performing the alignment.
 */

int alignSequenceAndGetMinCost(string &s1, string &s2, int mismatch_penalty, int gap_penalty) {
    // TODO use the given mismatch_penalty and gap_penalty to calculate the alignment cost.
    for (char& ch : s1)
    	ch = '_';
    for (char& ch : s2)
    	ch = '_';
    return 42;
}

#endif //SEQUENCEALIGNMENT_H
