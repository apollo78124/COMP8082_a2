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


    int m = s1.length();
    int n = s2.length();

    int size = n + m + 1;
    // table for storing optimal substructure answers
    int scoreTable[size][size] = {0};
    int i = 0;
    // Initialize the table.
    for (i = 0; i <= (n+m); i++)
    {
        scoreTable[i][0] = i * gap_penalty;
        scoreTable[0][i] = i * gap_penalty;
    }
    int j = 0;

    // Calculate minimum penalty.
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if ((int)s1[i - 1] == (int)s2[j - 1])
            {
                scoreTable[i][j] = scoreTable[i - 1][j - 1];
            }
            else
            {
                /**
                 * Get minimum from 3 possible choice:
                 * 1. xm and ym
                 * 2. xm and gap
                 * 3. gap and yn
                 */
                scoreTable[i][j] = min({
                                               scoreTable[i - 1][j] + gap_penalty    ,
                                               scoreTable[i][j - 1] + gap_penalty  ,
                                               scoreTable[i - 1][j - 1] + mismatch_penalty
                });
            }
        }
    }

    int l = n + m; // maximum possible length

    i = m; j = n;

    int xpos = l;
    int ypos = l;

    // string to store results
    int s1Ans[l + 1], s2Ans[l + 1];

    while ( !(i == 0 || j == 0))
    {
        if (scoreTable[i - 1][j] + gap_penalty == scoreTable[i][j])
        {
            s1Ans[xpos--] = (int)s1[i - 1];
            s2Ans[ypos--] = (int)'_';
            i--;
        }
        else if (scoreTable[i][j - 1] + gap_penalty == scoreTable[i][j])
        {
            s1Ans[xpos--] = (int)'_';
            s2Ans[ypos--] = (int)s2[j - 1];
            j--;
        }
        else if (scoreTable[i - 1][j - 1] + mismatch_penalty == scoreTable[i][j])
        {
            s1Ans[xpos--] = (int)s1[i - 1];
            s2Ans[ypos--] = (int)s2[j - 1];
            i--; j--;
        }
        else if (s1[i - 1] == s2[j - 1])
        {
            s1Ans[xpos--] = (int)s1[i - 1];
            s2Ans[ypos--] = (int)s2[j - 1];
            i--; j--;
        }

    }
    while (xpos > 0)
    {
        if (i > 0) s1Ans[xpos--] = (int)s1[--i];
        else s1Ans[xpos--] = (int)'_';
    }
    while (ypos > 0)
    {
        if (j > 0) s2Ans[ypos--] = (int)s2[--j];
        else s2Ans[ypos--] = (int)'_';
    }

    /**
     * Removing extra gaps caused from extra characters to allow maximum possible length.
     */
    int id = 1;
    for (i = l; i >= 1; i--)
    {
        if ((char)s2Ans[i] == '_' && (char)s1Ans[i] == '_')
        {
            id = i + 1;
            break;
        }
    }
    string result1 = "";
    for (i = id; i <= l; i++)
    {
        result1 += (char)s1Ans[i];
    }
    s1 = result1;

    string result2 = "";
    for (i = id; i <= l; i++)
    {
        result2 += (char)s2Ans[i];
    }
    s2 = result2;

    return scoreTable[m][n];
}

#endif //SEQUENCEALIGNMENT_H
