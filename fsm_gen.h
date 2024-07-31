#ifndef FSM_GEN_H
#define FSM_GEN_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <iostream>

using namespace std;

class FSM {
    public: 
        set<string> Q;          // Set of states (s0, s1, s2, etc.)
        set<int> sigma;              // Set of inputs
        string init_state;           // Initial state
        set<string> F;          // Set of final states
        map<pair<string, int>, string> transitions; // Map of transition functions

        FSM(); // Default constructor, generates the "MOD-THREE FA"
        FSM(int states, set<int> inputs, string first, set<std::string> final_states, map<pair<string, int>, string> trans); // Constructor for generating other FSMs
        int Remainder(string inputs);
};

#endif 