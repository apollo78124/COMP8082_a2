#include "CuckooHashTable.h"
#include "Graph.h"
#include "SequenceAlignment.h"
#include <iostream>
using namespace std;

int main() {
    cout << "***** Part 1: Modified Cuckoo Hashing *****" << endl;
    HashTable<string, StringHashFamily<2>> h1(3);
    HashTable<string, StringHashFamily<2>> h2(11);
    h1.insert("A");
    h1.insert("A");
    h1.insert("Banana");
    h1.insert("Cucumber");
    h1.insert("Dessert");
    h1.insert("Egg");
    h1.insert("Fudge");
    h1.insert("Gnu");

    cout << h1.print();
    int keys_1[] = { 20,50,53,75,100,67,105,3,36,39 };
    for (auto k:keys_1)
        h2.insert(std::to_string(k));
    cout << h2.print();

    HashTable<string, StringHashFamily<2>> h3(111);
    cout << "Insertion start" << endl;
    for (int j = 0; j < 15; j++) {
        h3.insert(to_string(j));
    }
    cout << "Insertion done" << endl;
    for (int j = 0; j < 15; j++) {
        if (h3.contains(std::to_string(j))) {
            continue;
        } else {
            cout << "missing element!" << std::to_string(j) << endl;
        }
    }
    cout << h3.print();

    HashTable<string, StringHashFamily<2>> h4(11);
    cout << "Insertion start" << endl;
    for (int j = 0; j < 15; j++) {
        h4.insert(to_string(j));
    }
    for (int j = 55; j < 65; j++) {
        h4.insert(to_string(j));
    }

    cout << "Insertion done" << endl;
    for (int j = 0; j < 15; j++) {
        if (h4.contains(std::to_string(j))) {
            continue;
        } else {
            cout << "missing element!" << std::to_string(j) << endl;
        }
    }
    for (int j = 55; j < 65; j++) {
        if (h4.contains(std::to_string(j))) {
            continue;
        } else {
            cout << "missing element!" << std::to_string(j) << endl;
        }
    }

    cout << h4.print();
    /*
     The output of my implementation:
        Contents of Cuckoo hash table:
         | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | [] | A | B | C | D | E | F | G | [] | []
        Contents of Cuckoo hash table:
         | [] | [] | [] | [] | 50 | [] | 36 | 53 | [] | 39 | [] | [] | [] | 75 | [] | [] | [] | [] | [] | 67 | [] | 100 | 3 | [] | [] | [] | 105 | 20 | []
     */
    cout << "***** Part 2: Topological Sorting *****" << endl;

    // int adjacencyMatrix[4][4] = {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0};
    int adjacencyMatrix[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int adjacencyMatrix2[7][7] = {0,1,1,1,0,0,0,
                                  0,0,0,1,1,0,0,
                                  0,0,0,0,0, 1,0,
                                  0,0,1,0,0,1,1,
                                  0,0,0,1,0,0,1,
                                  0,0,0,0,0,0,0,
                                  0,0,0,0,0,1,0};
/**
 * Expected result
 * 0 1 4 3 2 6 5
 */
    Graph graph;
    graph.CreateGraph(adjacencyMatrix);
    cout << "Result of topological sort: ";
    cout << graph.TopologicalSort() << endl;
    graph.CreateGraph(adjacencyMatrix2);
    cout << "Result of topological sort: ";
    cout << graph.TopologicalSort() << endl;
    /*
     The output of my implementation:
        Result of topological sorting: 0 1 2 3
     */
    cout << "***** Part 3: Sequence Alignment *****" << endl;
    string s1 = "HELLO";
    string s2 = "HeLO";
    int penalty_mismatch = 2;
    int penalty_gap = 1;
    cout << s1 << endl;
    cout << s2 << endl;
    int cost = alignSequenceAndGetMinCost(s1, s2, penalty_mismatch, penalty_gap);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << cost << endl;


    s1 = "HeLLO How ARE YOU?";
    s2 = "HELO How are yo?";
    cout << s1 << endl;
    cout << s2 << endl;
    penalty_mismatch = 1;
    penalty_gap = 2;
    cost = alignSequenceAndGetMinCost(s1, s2, penalty_mismatch, penalty_gap);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << cost << endl;

    s1 = "ATGCTAGT";
    s2 = "ATGTTAT";
    cout << s1 << endl;
    cout << s2 << endl;
    penalty_mismatch = 1;
    penalty_gap = 1;
    cost = alignSequenceAndGetMinCost(s1, s2, penalty_mismatch, penalty_gap);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << cost << endl;
    /*
    The output of my implementation:
     HELLO
     HeLO
     HEL_LO
     H__eLO
     3
    */
    /*
     *  "HeLLO How AR_ YOU?"
     *  "HEL_O How are yo_?"
     *  11
     */
    return 0;
}
