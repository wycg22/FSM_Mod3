#include "fsm_gen.h"

using namespace std;

/**
 * Default constructor for an FSM. Creates the MOD-Three FA specified in the assessment
 */

FSM::FSM() {
    Q = {"s0", "s1", "s2"}; //states are represented as a string in the format "s_"
    sigma = {0, 1};
    init_state = "s0";
    F = {"s0", "s1", "s2"};
    transitions = {
        {{"s0", 0}, "s0"}, //given a pair containing the current state and input, the next state is provided
        {{"s0", 1}, "s1"},
        {{"s1", 0}, "s2"}, 
        {{"s1", 1}, "s0"},
        {{"s2", 0}, "s1"}, 
        {{"s2", 1}, "s2"}
    };
}

/**
 * Given the number of states in your state machine, the initial state, a set of possible final states,
 * and a map of the transition functions, a new instance of an FSM is created.
 * 
 * @param states is greater than or equal to 1
 * @param inputs contains at least 1 element
 * @param first is a valid state (if there are 3 states, first has to be one of: s0, s1, or s2)
 * @param final_states is a subset of Q and represents the possible final states
 * @param trans is a map of transition functions that only involve posssible states and posssible inputs
 */

FSM::FSM(int states, set<int> inputs, string first, set<string> final_states, map<pair<string, int>, string> trans) {
    for (int i = 0; i < states; i++) {
        Q.insert("s" + to_string(i));
    }
    sigma = inputs;
    init_state = first;
    F = final_states;
    transitions = trans;
}

/**
 * Find the remainder of a binary input divided by 3 using an FSM implementation
 * 
 * @param inputs is a string of a binary number containing only 1s and 0s
 * 
 * @return the remainder of the binary number divided by three OR -1 if there is an invalid input.
 */
int FSM::Remainder(string inputs){
    string curr = init_state;
    if (inputs.empty()) return -1;
    for(int i = 0; i < inputs.size(); i++){
        int bin = inputs[i] - '0';
        auto next = transitions.find({curr, bin});
        if (next != transitions.end()){
            curr = next->second;
        }
        else{
            return -1;
        }
    }
    return curr[1] - '0'; //return the second digit in the string which is also teh ramainder
}
